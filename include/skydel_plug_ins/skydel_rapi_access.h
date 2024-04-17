#ifndef SKYDEL_RAPI_ACCESS_H
#define SKYDEL_RAPI_ACCESS_H

#include <QString>

#include <stdexcept>

#include "command_base.h"
#include "command_factory.h"
#include "internal/skydel_rapi_interface.h"

class SkydelRapiAccess : public SkydelRapiInterface
{
public:
  SkydelRapiAccess(const QString& name) : m_name(name.toStdString()) {}
  inline void setRapi(SkydelRapi* rapi) override { m_rapi = rapi; }

  inline void post(Sdx::CommandBasePtr cmd,
                   double timestamp,
                   std::function<void(Sdx::CommandResultPtr)> callback = {},
                   bool hideFromAutomationTab = false)
  {
    if (m_rapi)
    {
      if (hideFromAutomationTab)
      {
        cmd->setHidden(true);
      }

      if (callback)
      {
        m_rapi->post(cmd->toString(), timestamp, [callback = std::move(callback)](const std::string& result) {
          std::string errorMsg;
          auto commandResult = Sdx::CommandFactory::instance()->createCommandResult(result, &errorMsg);

          if (!commandResult)
            throw std::runtime_error(errorMsg.c_str());

          callback(commandResult);
        });
      }
      else
      {
        m_rapi->post(cmd->toString(), timestamp);
      }
    }
  }

  inline void post(Sdx::CommandBasePtr cmd, bool hideFromAutomationTab = false)
  {
    post(cmd, 0.0, {}, hideFromAutomationTab);
  }

  inline void post(Sdx::CommandBasePtr cmd,
                   std::function<void(Sdx::CommandResultPtr)> callback,
                   bool hideFromAutomationTab = false)
  {
    post(cmd, 0.0, callback, hideFromAutomationTab);
  }

  Sdx::CommandResultPtr call(Sdx::CommandBasePtr cmd, bool hideFromAutomationTab = false)
  {
    if (m_rapi)
    {
      cmd->setHidden(hideFromAutomationTab);

      auto result = m_rapi->call(cmd->toString());

      std::string errorMsg;
      auto commandResult = Sdx::CommandFactory::instance()->createCommandResult(result, &errorMsg);

      if (!commandResult)
        throw std::runtime_error(errorMsg.c_str());

      return commandResult;
    }

    return nullptr;
  }

private:
  SkydelRapi* m_rapi;
  std::string m_name;
};

#endif // SKYDEL_RAPI_ACCESS_H
