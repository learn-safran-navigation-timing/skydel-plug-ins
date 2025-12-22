#pragma once

#include "skydel_custom_signal_interface.h"
#include "skydel_custom_signal_types.h"

class SkydelCustomSignalFactoryInterface
{
public:
  virtual ~SkydelCustomSignalFactoryInterface() = default;

  virtual SkydelCustomSignalInterface* createCustomSignal(const Sdx::CS::InitializationDatas& datas) = 0;

  static constexpr auto ID = "SkydelCustomSignalFactory";
  static constexpr auto VERSION = 3;
};
