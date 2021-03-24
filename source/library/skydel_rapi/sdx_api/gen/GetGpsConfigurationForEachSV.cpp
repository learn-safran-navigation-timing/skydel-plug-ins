#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetGpsConfigurationForEachSV
///
#include "gen/GetGpsConfigurationForEachSV.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetGpsConfigurationForEachSV::CmdName = "GetGpsConfigurationForEachSV";
    const char* const GetGpsConfigurationForEachSV::Documentation = "Please note the command GetGpsSVConfigurationForAllSat is deprecated since 21.3. You may use GetGpsConfigurationForEachSV.\n\nGet GPS SV configuration flag for each SVs";

    REGISTER_COMMAND_FACTORY(GetGpsConfigurationForEachSV);


    GetGpsConfigurationForEachSV::GetGpsConfigurationForEachSV()
      : CommandBase(CmdName)
    {

    }


    GetGpsConfigurationForEachSVPtr GetGpsConfigurationForEachSV::create()
    {
      return GetGpsConfigurationForEachSVPtr(new GetGpsConfigurationForEachSV());
    }

    GetGpsConfigurationForEachSVPtr GetGpsConfigurationForEachSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetGpsConfigurationForEachSV>(ptr);
    }

    bool GetGpsConfigurationForEachSV::isValid() const
    {
      
        return m_values.IsObject()
        ;

    }

    std::string GetGpsConfigurationForEachSV::documentation() const { return Documentation; }


    int GetGpsConfigurationForEachSV::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }

  }
}
