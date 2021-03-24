#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetNavICL5HealthForSV
///
#include "gen/GetNavICL5HealthForSV.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetNavICL5HealthForSV::CmdName = "GetNavICL5HealthForSV";
    const char* const GetNavICL5HealthForSV::Documentation = "Please note the command GetNavICSatelliteL5Health is deprecated since 21.3. You may use GetNavICL5HealthForSV.\n\nGet NavIC L5 health (Health of L5 signal)";

    REGISTER_COMMAND_FACTORY(GetNavICL5HealthForSV);


    GetNavICL5HealthForSV::GetNavICL5HealthForSV()
      : CommandBase(CmdName)
    {}

    GetNavICL5HealthForSV::GetNavICL5HealthForSV(int svId)
      : CommandBase(CmdName)
    {

      setSvId(svId);
    }


    GetNavICL5HealthForSVPtr GetNavICL5HealthForSV::create(int svId)
    {
      return GetNavICL5HealthForSVPtr(new GetNavICL5HealthForSV(svId));
    }

    GetNavICL5HealthForSVPtr GetNavICL5HealthForSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetNavICL5HealthForSV>(ptr);
    }

    bool GetNavICL5HealthForSV::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["SvId"])
        ;

    }

    std::string GetNavICL5HealthForSV::documentation() const { return Documentation; }


    int GetNavICL5HealthForSV::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    int GetNavICL5HealthForSV::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void GetNavICL5HealthForSV::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
