#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of ResetHilWarning
///
#include "gen/ResetHilWarning.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const ResetHilWarning::CmdName = "ResetHilWarning";
    const char* const ResetHilWarning::Documentation = "Reset Hardware in the loop trajectory server warning message.";

    REGISTER_COMMAND_FACTORY(ResetHilWarning);


    ResetHilWarning::ResetHilWarning()
      : CommandBase(CmdName)
    {

    }


    ResetHilWarningPtr ResetHilWarning::create()
    {
      return ResetHilWarningPtr(new ResetHilWarning());
    }

    ResetHilWarningPtr ResetHilWarning::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<ResetHilWarning>(ptr);
    }

    bool ResetHilWarning::isValid() const
    {
      
        return m_values.IsObject()
        ;

    }

    std::string ResetHilWarning::documentation() const { return Documentation; }


    int ResetHilWarning::executePermission() const
    {
      return EXECUTE_IF_SIMULATING;
    }

  }
}
