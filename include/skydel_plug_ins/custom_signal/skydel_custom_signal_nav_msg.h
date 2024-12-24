#pragma once

#include "skydel_custom_signal_types.h"

class SkydelCustomSignalNavMsg
{
public:
  virtual ~SkydelCustomSignalNavMsg() = default;

  // Return the navigation message duration, in millisecond
  virtual uint32_t getNavMsgDurationMs() = 0;

  // Return the offset between the message beginning and the time of week 0, in seconds
  virtual int32_t getTOWOffset() = 0;

  // Called every navMsgDuration
  // elapsedTime is an offset to the start time in millisecond
  // prn is the PRN transmitted by legacy signals on the same space vehicle
  virtual void buildNavMsg(int64_t elapsedTime, uint32_t prn, const Sdx::CS::Constellation& data) = 0;
};
