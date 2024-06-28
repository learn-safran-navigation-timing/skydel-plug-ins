#pragma once

#include <functional>

#include "command_base.h"
#include "command_result.h"
#include "gen/SuccessResult.h"

namespace CommandExecution
{

using CommandHandler = std::function<Sdx::CommandResultPtr(Sdx::CommandBasePtr)>;
using UndoHandler = std::function<void()>;
using UndoFactory = std::function<UndoHandler(Sdx::CommandBasePtr)>;

template<typename HandlerObject, typename CommandType, typename ResultType>
using ExecuteMethod = ResultType (HandlerObject::*)(const CommandType&);
template<typename HandlerObject, typename CommandType, typename ResultType>
using NonMutableExecuteMethod = ResultType (HandlerObject::*)(const CommandType&) const;
template<typename HandlerObject, typename CommandType>
using UndoFactoryMethod = UndoHandler (HandlerObject::*)(const CommandType&);

struct Handler
{
  CommandHandler handler;
  UndoFactory undoFactory;
};

template<typename CommandType>
inline Sdx::CommandBasePtr commandFactory()
{
  return std::make_shared<CommandType>();
}

template<typename CommandType, typename HandlerObject, typename Method>
inline auto createUndoFunction(HandlerObject* object, Method method)
{
  auto sent = std::function {[object, method](std::shared_ptr<Sdx::CommandBase> cmd) {
    return std::invoke(method, object, static_cast<const CommandType&>(*cmd));
  }};
  if (!method)
    sent = nullptr;
  return sent;
}

template<typename CommandType, typename HandlerObject, typename Method>
inline Sdx::CommandResultPtr executeCommand(HandlerObject* object, Method method, std::shared_ptr<CommandType> cmd)
{
  Sdx::CommandResultPtr result;

  if constexpr (std::is_same_v<decltype(std::invoke(method, object, *cmd)), void>)
  {
    std::invoke(method, object, *cmd);
    result = std::make_shared<Sdx::Cmd::SuccessResult>();
  }
  else
  {
    result = std::invoke(method, object, *cmd);
  }

  if (!result->relatedCommand())
  {
    result->setRelatedCommand(std::move(cmd));
  }

  return result;
}

template<typename CommandType, typename HandlerObject, typename Method>
inline auto createExecuteFunction(HandlerObject* object, Method method)
{
  auto sent = std::function {[object, method](Sdx::CommandBasePtr cmd) {
    return executeCommand(object, method, std::dynamic_pointer_cast<CommandType>(std::move(cmd)));
  }};

  if (!method)
    sent = nullptr;

  return sent;
}

} // namespace CommandExecution
