#ifndef SKYDEL_LICENSING_BASE_H
#define SKYDEL_LICENSING_BASE_H

class SkydelLicensingBase
{
public:
  virtual ~SkydelLicensingBase() = default;

  virtual void exchangeKey(unsigned char* ciphertext, unsigned char* nonce) = 0;
};

#endif // SKYDEL_LICENSING_BASE_H
