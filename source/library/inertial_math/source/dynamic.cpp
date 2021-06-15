#include "dynamic.h"

#include "angle_unwrap.h"
#include "sensor.h"
#include "transformation.h"

namespace Iml
{
void BodyDynamic::pushPosition(const RawPositionData& rawPosition)
{
  InertialData data = {static_cast<int64_t>(rawPosition.time),
                       rawPosition.position,
                       {0.0, 0.0, 0.0},
                       {0.0, 0.0, 0.0},
                       {rawPosition.orientation},
                       {0.0, 0.0, 0.0}};

  if (!m_datas.empty())
  {
    data.attitude = unwrap(m_datas.back().attitude + m_phaseCorrection, data.attitude, m_phaseCorrection);
  }

  if (isReady())
  {
    m_datas.erase(m_datas.begin());
  }

  m_datas.push_back(data);

  if (isReady())
  {
    auto dt_1_0 = (m_datas[1].time - m_datas[0].time) / 1000.0;
    auto dt_2_0 = (m_datas[2].time - m_datas[0].time) / 1000.0;
    auto dt_3_1 = (m_datas[3].time - m_datas[1].time) / 1000.0;

    m_datas[1].velocity = (m_datas[2].position - m_datas[0].position) / dt_2_0;
    m_datas[2].velocity = (m_datas[3].position - m_datas[1].position) / dt_3_1;

    m_datas[1].acceleration = (m_datas[2].velocity - m_datas[0].velocity) / dt_2_0;

    m_datas[1].angularVelocity = (m_datas[1].attitude - m_datas[0].attitude) / dt_1_0;
  }
}

BodyInertialDynamic::BodyInertialDynamic(GravityModel gravityModel) : m_gravityModel(gravityModel)
{
}

InertialData BodyInertialDynamic::getPosition() const
{
  InertialData position;

  if (isReady())
  {
    position = BodyDynamic::getPosition();
    auto llaPosition = ecefToLla(position.position);
    position.acceleration =
      idealAccelerometer(llaPosition, position.velocity, position.acceleration, position.attitude, m_gravityModel);
    position.angularVelocity = idealGyroscope(llaPosition,
                                              position.velocity,
                                              position.attitude,
                                              position.angularVelocity);
  }

  return position;
}

} // namespace Iml
