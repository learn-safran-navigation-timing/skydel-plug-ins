#pragma once

#include <stdexcept>
#include <unordered_map>

#include "skydel_command_execution.h"

using namespace CommandExecution;

class SkydelCommandExecutor
{
public:
  template<typename HandlerObject, typename CommandType, typename ResultType>
  void registerCommand(HandlerObject* object,
                       ExecuteMethod<HandlerObject, CommandType, ResultType> execute,
                       UndoFactoryMethod<HandlerObject, CommandType> undoFactory = nullptr)
  {
    insertHandler<CommandType>(Handler {createExecuteFunction<CommandType>(object, execute),
                                        createUndoFunction<CommandType>(object, undoFactory)});
  }

  template<typename HandlerObject, typename CommandType, typename ResultType>
  void registerNonMutableCommand(HandlerObject* object,
                                 NonMutableExecuteMethod<HandlerObject, CommandType, ResultType> execute)
  {
    insertHandler<CommandType>(Handler {createExecuteFunction<CommandType>(object, execute), nullptr});
  }

  const Handler* findHandlerFor(const Sdx::CommandBase& cmd) const
  {
    auto it = m_commandHandlers.find(cmd.name());
    return (it == m_commandHandlers.end()) ? nullptr : &it->second;
  }

private:
  template<typename CommandType>
  void insertHandler(Handler handler)
  {
    const std::string commandName = CommandType::CmdName;
    const auto [it, inserted] = m_commandHandlers.insert(std::make_pair(commandName, handler));
    if (!inserted)
      throw std::runtime_error {"Duplicate handler for command " + commandName + "."};
  }

  std::unordered_map<std::string, Handler> m_commandHandlers;
};
