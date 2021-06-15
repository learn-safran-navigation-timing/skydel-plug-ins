#include "skydel_default_instrumentation_plugin.h"

#include <QDir>
#include <QFile>
#include <QTextStream>

#include <stdexcept>

void SkydelDefaultInstrumentationPlugin::setLogPath(const QString& path)
{
  m_path = path;

  m_queueSizeReference.reset();
  auto filename = "queue_sizes.csv";
  QFile file(QDir(m_path).filePath(filename));

  if (file.open(QFile::WriteOnly | QFile::Append))
  {
    QTextStream out(&file);
    out << "Timestamp (ms),Pipe name,Pipe size\n";
  }
}

void SkydelDefaultInstrumentationPlugin::setEngineGraph(const std::vector<Node>& nodes, const std::vector<Pipe>& pipes)
{
  static const auto indexOf = [&nodes](const Node* node) { return node - &nodes.front(); };
  static constexpr auto typeLabel = [](PipeType type) {
    switch (type)
    {
      case IQBlock:
        return "IQ";
      case ModulationOrder:
        return "MO";
      default:
        return "???";
    }
  };
  auto filename = "engine_graph.dot";

  QFile file(QDir(m_path).filePath(filename));

  if (file.open(QFile::WriteOnly))
  {
    QTextStream out(&file);
    out << "digraph skydel {\n";
    for (size_t i = 0; i < nodes.size(); ++i)
      out << ' ' << i << " [label=\"" << nodes[i].name << "\"];\n";

    for (const Pipe& pipe : pipes)
    {
      out << ' ' << indexOf(pipe.input) << " -> " << indexOf(pipe.output) << " [label=\"" << typeLabel(pipe.type)
          << "\"];\n";
    }
    out << "}\n";
  }
  else
  {
    throw std::runtime_error {std::string {"Unable to open "} + filename};
  }
}

void SkydelDefaultInstrumentationPlugin::pushQueueMeasures(const std::vector<QueueMeasure>& queues)
{
  auto filename = "queue_sizes.csv";
  QFile file(QDir(m_path).filePath(filename));

  if (file.open(QFile::WriteOnly | QFile::Append))
  {
    QTextStream out(&file);
    for (const QueueMeasure& measure : queues)
    {
      if (!m_queueSizeReference)
        m_queueSizeReference = measure.timestamp;
      out << (measure.timestamp - m_queueSizeReference.value()) << ',' << measure.pipeName << ',' << measure.size
          << '\n';
    }
  }
  else
  {
    throw std::runtime_error {std::string {"Unable to open "} + filename};
  }
}
