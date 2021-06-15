#ifndef SKYDEL_LICENSING_INTERFACE_H
#define SKYDEL_LICENSING_INTERFACE_H

#include <QString>

#include "internal/skydel_licensing_base.h"

class SkydelLicensingInterface : public SkydelLicensingBase
{
public:
  virtual ~SkydelLicensingInterface() = default;

  void exchangeKey(QByteArray& ciphertext, QByteArray& nonce);
  virtual QString getPluginIID() const = 0;

  static constexpr auto ID = "SkydelLicensing";
  static constexpr auto VERSION = 1;
};

#endif // SKYDEL_LICENSING_INTERFACE_H
