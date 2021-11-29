#ifndef HIL_LOGGER_H
#define HIL_LOGGER_H

#include <QFile>

#include "skydel_plug_ins/skydel_plugin.h"

// Runtime hil observer implementation
class HilLogger : public SkydelRuntimeHilObserver
{
  Q_OBJECT
public:
  explicit HilLogger(const QString& logPath,
                     bool enableFileLogging,
                     SkydelNotifierInterface* skydelNotifier); // Called at simulation initialization phase
  ~HilLogger();                                                // Called at simluation ending phase
  void pushHilInput(const TimedPosition& p) override;
  void connectToView(QWidget* view) override;

signals:
  void updatePosition(const SkydelRuntimeHilObserver::TimedPosition& p);
  void lockConfiguration(bool lock);

private:
  QString toString(const SkydelRuntimeHilObserver::TimedPosition& p);

  SkydelNotifierInterface* m_skydelNotifier;
  bool m_enableFileLogging;
  QFile m_file;
  int64_t m_displayedPosTimestamp; // ms
};

#endif // HIL_LOGGER_H
