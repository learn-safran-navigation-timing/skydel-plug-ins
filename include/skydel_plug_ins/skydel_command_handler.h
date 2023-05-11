#ifndef SKYDEL_COMMAND_HANDLER_H
#define SKYDEL_COMMAND_HANDLER_H

#include "internal/skydel_command_executor.h"

template<typename TDerived>
struct SkydelCommandHandler
{
  SkydelCommandHandler(SkydelCommandExecutor& commandExecutor) : m_commandExecutor(commandExecutor) {}

  template<typename TCommand>
  void registerCommand()
  {
    m_commandExecutor.registerCommand<TDerived, TCommand>(static_cast<TDerived*>(this), &TDerived::execute);
  }

  template<typename TCommand>
  void registerCommandWithUndo()
  {
    m_commandExecutor.registerCommand<TDerived, TCommand>(static_cast<TDerived*>(this),
                                                          &TDerived::execute,
                                                          &TDerived::getUndo);
  }

  template<typename TCommand>
  void registerNonMutableCommand()
  {
    m_commandExecutor.registerNonMutableCommand<TDerived, TCommand>(static_cast<TDerived*>(this), &TDerived::execute);
  }

private:
  SkydelCommandExecutor& m_commandExecutor;
};

#endif // SKYDEL_COMMAND_HANDLER_H
