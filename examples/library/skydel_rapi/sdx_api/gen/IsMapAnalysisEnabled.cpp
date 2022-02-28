#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of IsMapAnalysisEnabled
///
#include "gen/IsMapAnalysisEnabled.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const IsMapAnalysisEnabled::CmdName = "IsMapAnalysisEnabled";
    const char* const IsMapAnalysisEnabled::Documentation = "Get if map is show/hide in Analysis tab.";

    REGISTER_COMMAND_FACTORY(IsMapAnalysisEnabled);


    IsMapAnalysisEnabled::IsMapAnalysisEnabled()
      : CommandBase(CmdName)
    {

    }


    IsMapAnalysisEnabledPtr IsMapAnalysisEnabled::create()
    {
      return IsMapAnalysisEnabledPtr(new IsMapAnalysisEnabled());
    }

    IsMapAnalysisEnabledPtr IsMapAnalysisEnabled::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<IsMapAnalysisEnabled>(ptr);
    }

    bool IsMapAnalysisEnabled::isValid() const
    {
      
        return m_values.IsObject()
        ;

    }

    std::string IsMapAnalysisEnabled::documentation() const { return Documentation; }


    int IsMapAnalysisEnabled::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }

  }
}
