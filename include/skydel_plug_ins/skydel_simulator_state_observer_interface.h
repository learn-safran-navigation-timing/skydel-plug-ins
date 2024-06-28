#pragma once

#include <QString>

class SkydelSimulatorStateObserverInterface
{
public:
  virtual ~SkydelSimulatorStateObserverInterface() = default;

  virtual void pushSimulatorState(const QString& simulatorState, const QString& simulatorSubState) = 0;

  static constexpr auto ID = "SkydelSimulatorStateObserver";
  static constexpr auto VERSION = 1;
};
