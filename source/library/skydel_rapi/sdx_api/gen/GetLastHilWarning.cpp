#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetLastHilWarning
///
#include "gen/GetLastHilWarning.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetLastHilWarning::CmdName = "GetLastHilWarning";
    const char* const GetLastHilWarning::Documentation = "Get last Hardware in the loop trajectory server warning message. Returns HilWarningResult.";

    REGISTER_COMMAND_FACTORY(GetLastHilWarning);


    GetLastHilWarning::GetLastHilWarning()
      : CommandBase(CmdName)
    {

    }


    GetLastHilWarningPtr GetLastHilWarning::create()
    {
      return GetLastHilWarningPtr(new GetLastHilWarning());
    }

    GetLastHilWarningPtr GetLastHilWarning::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetLastHilWarning>(ptr);
    }

    bool GetLastHilWarning::isValid() const
    {
      
        return m_values.IsObject()
        ;

    }

    std::string GetLastHilWarning::documentation() const { return Documentation; }


    int GetLastHilWarning::executePermission() const
    {
      return EXECUTE_IF_SIMULATING;
    }

  }
}
