#pragma once

#include "skydel_custom_signal_code.h"
#include "skydel_custom_signal_nav_msg.h"

class SkydelCustomSignalInterface
{
public:
  virtual ~SkydelCustomSignalInterface() = default;

  // Can be null in the case of a signal without navigation message
  virtual SkydelCustomSignalNavMsg* getNavMsg() = 0;

  // Name is a null terminated string identifying the code
  virtual SkydelCustomSignalCode* getCode(const char* name) = 0;
};
