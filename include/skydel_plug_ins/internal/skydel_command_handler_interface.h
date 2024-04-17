#ifndef SKYDEL_COMMAND_HANDLER_INTERFACE_H
#define SKYDEL_COMMAND_HANDLER_INTERFACE_H

#include <functional>
#include <optional>
#include <string>

class SkydelCommandHandlerInterface
{
public:
  virtual ~SkydelCommandHandlerInterface() = default;

  struct CommandHandler
  {
    using Execute = std::function<std::string()>;
    using Undo = std::optional<std::function<void()>>;
    using Documentation = std::function<std::string()>;
    using FieldNames = std::function<std::vector<std::string>()>;

    Execute execute;
    Undo undo;
    Documentation documentation;
    FieldNames fieldNames;
  };

  virtual std::optional<CommandHandler> getCommandHandler(const std::string& serializedCommand) = 0;

  static constexpr auto ID = "SkydelCommandHandler";
  static constexpr auto VERSION = 1;
};

#endif // SKYDEL_COMMAND_HANDLER_INTERFACE_H
