#ifndef COMMANDRESULT_H
#define COMMANDRESULT_H

#include "command_base.h"

namespace Sdx
{
//
// Sdx::msg::CommandResult
//
// Command Result if succeed or not with optional data.
//
// Name         Type    Description
// -----------  ------  ---------------------------
// command      string  Attached command json
// succeed      bool    If command succeeded or not
// result       string  Message or json
//
class CommandResult;
typedef std::shared_ptr<CommandResult> CommandResultPtr;

class CommandResult : public CommandBase
{
public:
  static const std::string RelatedCommand;

  CommandResult(const std::string& cmdName, const std::string& targetId);
  CommandResult(const std::string& cmdName, const std::string& targetId, CommandBasePtr relatedCommand);
  virtual bool isValid() const;
  static CommandResultPtr dynamicCast(CommandBasePtr ptr);

  virtual double timestamp() const;
  virtual Sdx::DateTime gpsTimestamp() const;
  virtual void setTimestamp(double);
  virtual void setGpsTimestamp(const Sdx::DateTime& gpsTimestamp);

  inline CommandBasePtr relatedCommand() const { return m_relatedCommand; }

  virtual std::string toReadableCommand(bool includeName = true) const;

  inline virtual std::string errorMsg() const { return ""; }
  inline virtual bool isSuccess() const { return true; }
  std::string message() const;

  void setRelatedCommand(CommandBasePtr relatedCommand);

private:
  CommandBasePtr m_relatedCommand;
  friend class CommandFactory;
};
} // namespace Sdx

#endif // COMMANDRESULT_H
