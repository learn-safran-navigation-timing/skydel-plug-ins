#ifndef SKYDEL_NOTIFIER_INTERFACE_H
#define SKYDEL_NOTIFIER_INTERFACE_H

#include <string>

class SkydelNotifierInterface
{
public:
  virtual ~SkydelNotifierInterface() = default;

  enum Type
  {
    INFO,
    WARNING,
    ERROR
  };

  virtual void notify(const std::string& message, Type type = Type::INFO) = 0;
  virtual void setDirty() = 0;
};

#endif // SKYDEL_NOTIFIER_INTERFACE_H
