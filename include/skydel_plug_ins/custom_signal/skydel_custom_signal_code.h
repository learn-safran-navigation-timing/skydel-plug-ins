#pragma once

#include <cstdint>

class SkydelCustomSignalCode
{
public:
  virtual ~SkydelCustomSignalCode() = default;

  // Return the number of chips per ms
  virtual uint32_t getNumberOfChipsPerMSec() = 0;

  // Return the extra chips to allocate for the chips buffer
  virtual uint32_t getExtraAllocSize() = 0;

  // Called every millisecond
  // elapsedTime is an offset to the start time in millisecond
  // prn is the PRN transmitted by legacy signals on the same space vehicle
  // chips is a chip buffer allocated for <codeRate> / 1000 + extraAllocSize chips
  virtual void getChips(int64_t elapsedTime, uint32_t prn, int8_t* chips) = 0;
};
