#ifndef SKYDEL_RAPI_ACCESS_H
#define SKYDEL_RAPI_ACCESS_H

#include <QString>

#include <stdexcept>
#include <utility>

#include "command_base.h"
#include "command_result_factory.h"
#include "gen/PlugInCommand.h"
#include "internal/skydel_rapi_interface.h"

class SkydelRapiAccess : public SkydelRapiInterface
{
public:
  inline void setRapi(SkydelRapi* rapi) override { m_rapi = rapi; }

  inline void post(Sdx::CommandBasePtr cmd,
                   double timestamp = 0.0,
                   std::function<void(Sdx::CommandResultPtr)> callback = {},
                   bool hideFromAutomationTab = false)
  {
    if (m_rapi)
    {
      cmd->setHidden(hideFromAutomationTab);

      if (callback)
      {
        m_rapi->post(cmd->toString(), timestamp, [callback = std::move(callback)](const std::string& result) {
          std::string errorMsg;
          Sdx::CommandResultPtr commandResult = Sdx::CommandResultFactory::instance()->createCommandResult(result,
                                                                                                           &errorMsg);

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
      Sdx::CommandResultPtr commandResult = Sdx::CommandResultFactory::instance()->createCommandResult(result,
                                                                                                       &errorMsg);
      if (!commandResult)
        throw std::runtime_error(errorMsg.c_str());

      return commandResult;
    }

    return nullptr;
  }

  inline void setPluginInstanceName(const QString& name) { m_instanceName = name.toStdString(); }

  inline Sdx::CommandBasePtr createPluginCommand(Sdx::CommandBasePtr cmd) const
  {
    return Sdx::Cmd::PlugInCommand::create(m_instanceName, cmd->toString());
  }

  inline void thisPost(Sdx::CommandBasePtr cmd) { post(createPluginCommand(cmd), 0.0, {}, false); }

private:
  SkydelRapi* m_rapi;
  std::string m_instanceName;
};

#endif // SKYDEL_RAPI_ACCESS_H
