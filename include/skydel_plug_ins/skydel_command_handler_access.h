#ifndef SKYDEL_COMMAND_HANDLER_ACCESS_H
#define SKYDEL_COMMAND_HANDLER_ACCESS_H

#include "command_factory.h"
#include "internal/skydel_command_executor.h"
#include "internal/skydel_command_handler_interface.h"

class SkydelCommandHandlerAccess : public SkydelCommandHandlerInterface
{
public:
  // Use this function to facilitate the handling of plugin commands.
  // See the RapiPlugin example and how it's used in the RapiPluginCommandHandler class.
  inline auto& commandExecutor() { return m_commandExecutor; }

  // Do not use this function, it's used by Skydel and not by the plugin user.
  std::optional<SkydelCommandHandlerInterface::CommandHandler> getCommandHandler(
    const std::string& serializedCommand) override;

private:
  std::optional<std::function<void()>> createUndo(const Handler& handler, Sdx::CommandBasePtr command);

  SkydelCommandExecutor m_commandExecutor;
};

inline std::optional<SkydelCommandHandlerInterface::CommandHandler> SkydelCommandHandlerAccess::getCommandHandler(
  const std::string& serializedCommand)
{
  if (auto command = Sdx::CommandFactory::instance()->createCommand(serializedCommand))
  {
    if (auto handler = m_commandExecutor.findHandlerFor(*command))
    {
      auto execute = [command, execute = handler->handler]() { return execute(std::move(command))->toString(); };
      return SkydelCommandHandlerInterface::CommandHandler {std::move(execute),
                                                            createUndo(*handler, std::move(command))};
    }
  }

  return {};
}

inline std::optional<std::function<void()>> SkydelCommandHandlerAccess::createUndo(const Handler& handler,
                                                                                   Sdx::CommandBasePtr command)
{
  if (handler.undoFactory)
  {
    return handler.undoFactory(std::move(command));
  }
  else
  {
    return std::nullopt;
  }
}

#endif // SKYDEL_COMMAND_HANDLER_ACCESS_H
