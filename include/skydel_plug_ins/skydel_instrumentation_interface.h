#ifndef SKYDEL_INSTRUMENTATION_INTERFACE
#define SKYDEL_INSTRUMENTATION_INTERFACE

#include <vector>

class SkydelInstrumentationInterface
{
public:
  virtual ~SkydelInstrumentationInterface() = default;

  enum PipeType
  {
    ModulationOrder,
    IQBlock,
    Other
  };

  struct Node
  {
    const char* name;
  };

  struct Pipe
  {
    PipeType type;
    const Node* input;
    const Node* output;
  };

  // Lifetime of Node, Pipe and their content is not guaranteed after returning from this function
  virtual void setEngineGraph(const std::vector<Node>& nodes, const std::vector<Pipe>& pipes) = 0;

  struct QueueMeasure
  {
    const char* pipeName;
    uint64_t timestamp; // In ms. Only use to compare to other measures, absolute value is irrelevant.
    int size;
  };
  virtual void pushQueueMeasures(const std::vector<QueueMeasure>& queues) = 0;

  static constexpr auto ID = "SkydelInstrumentation";
  static constexpr auto VERSION = 1;
};

#endif // SKYDEL_INSTRUMENTATION_INTERFACE
