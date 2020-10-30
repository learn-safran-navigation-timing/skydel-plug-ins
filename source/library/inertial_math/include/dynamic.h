#ifndef IML_DYNAMIC_H
#define IML_DYNAMIC_H

#include <cstdint>
#include <vector>

#include "triplet.h"

namespace Iml {

struct RawPositionData
{
  int64_t time;           // ms
  double  position[3];    // m
  double  orientation[3]; // deg
};

struct InertialData
{
  int64_t time;             // ms
  Xyz position;             // m
  Xyz velocity;             // m/s
  Xyz acceleration;         // m/s^2
  Attitude attitude;        // rad
  Attitude angularVelocity; // rad/s
};

class BodyDynamic
{
public:
  inline InertialData getPosition() const { return m_datas[1]; }
  inline bool isReady() const { return m_datas.size() == m_bufferCapacity; }
  void pushPosition(const RawPositionData &rawPosition);

private:
  Attitude m_phaseCorrection;
  std::vector<InertialData> m_datas;
  static const size_t m_bufferCapacity = 4;
};

class BodyInertialDynamic : public BodyDynamic
{
public:
  InertialData getPosition() const;
};

} // namespace Iml

#endif // IML_DYNAMIC_H
