#ifndef SKYDEL_LICENSING_INTERFACE_H
#define SKYDEL_LICENSING_INTERFACE_H

#include "internal/skydel_licensing_base.h"

class SkydelLicensingInterface : public SkydelLicensingBase
{
public:
  virtual ~SkydelLicensingInterface() = default;

  void exchangeKey(unsigned char* ciphertext, unsigned char* nonce);
  virtual bool validateSerialNumber(const char* serialNumber) = 0;

  static constexpr auto ID = "SkydelLicensing";
  static constexpr auto VERSION = 1;
};

#endif // SKYDEL_LICENSING_INTERFACE_H
