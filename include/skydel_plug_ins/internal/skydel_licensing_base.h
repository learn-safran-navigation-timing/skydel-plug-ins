#ifndef SKYDEL_LICENSING_BASE_H
#define SKYDEL_LICENSING_BASE_H

class QByteArray;

class SkydelLicensingBase
{
public:
  virtual ~SkydelLicensingBase() = default;

  virtual void exchangeKey(QByteArray& ciphertext, QByteArray& nonce) = 0;
};

#endif // SKYDEL_LICENSING_BASE_H
