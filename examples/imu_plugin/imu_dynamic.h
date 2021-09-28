#ifndef IMU_DYNAMIC_H
#define IMU_DYNAMIC_H

#include <QString>

#include <vector>

#include "dynamic.h"
#include "imu_configuration.h"
#include "imu_logger.h"
#include "skydel_plug_ins/skydel_position_observer_interface.h"

class ImuDynamic : public SkydelRuntimePositionObserver
{
public:
  explicit ImuDynamic(const ImuConfiguration& configuration, const QString& logPath);
  void pushPosition(const TimedPosition& p) override;
  void connectToView(QWidget*) override {}

private:
  Iml::BodyInertialDynamic m_bodyDynamic;
  std::vector<ImuLoggerPtr> m_loggers;
};

#endif // IMU_DYNAMIC_H
