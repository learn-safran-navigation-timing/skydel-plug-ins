#ifndef IML_DYNAMIC_H
#define IML_DYNAMIC_H

#include <cstdint>
#include <vector>

#include "gravity.h"
#include "triplet.h"

namespace Iml
{
struct RawPositionData
{
  int64_t time;          // millisecond
  double position[3];    // meter
  double orientation[3]; // radian
};

struct InertialData
{
  int64_t time;            // millisecond
  Triplet position;        // meter
  Triplet velocity;        // meter/second
  Triplet acceleration;    // meter/second^2
  Triplet attitude;        // radian
  Triplet angularVelocity; // radian/second
};

class BodyDynamic
{
public:
  virtual inline InertialData getPosition() const { return m_datas[1]; }
  inline bool isReady() const { return m_datas.size() == m_bufferCapacity; }
  void pushPosition(const RawPositionData& rawPosition);

private:
  Triplet m_phaseCorrection;
  std::vector<InertialData> m_datas;
  static constexpr size_t m_bufferCapacity = 4;
};

class BodyInertialDynamic : public BodyDynamic
{
public:
  BodyInertialDynamic(GravityModel gravityModel);
  InertialData getPosition() const override;

private:
  GravityModel m_gravityModel;
};

} // namespace Iml

#endif // IML_DYNAMIC_H
