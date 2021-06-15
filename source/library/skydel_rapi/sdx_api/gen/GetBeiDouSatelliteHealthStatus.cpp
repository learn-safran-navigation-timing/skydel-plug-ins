#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetBeiDouSatelliteHealthStatus
///
#include "gen/GetBeiDouSatelliteHealthStatus.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetBeiDouSatelliteHealthStatus::CmdName = "GetBeiDouSatelliteHealthStatus";
    const char* const GetBeiDouSatelliteHealthStatus::Documentation = "Please note the command GetBeiDouSatelliteHealthStatus is deprecated since 21.3. You may use GetBeiDouHealthStatusForSV.\n\nGet BeiDou satellite health status";

    REGISTER_COMMAND_FACTORY(GetBeiDouSatelliteHealthStatus);


    GetBeiDouSatelliteHealthStatus::GetBeiDouSatelliteHealthStatus()
      : CommandBase(CmdName)
    {}

    GetBeiDouSatelliteHealthStatus::GetBeiDouSatelliteHealthStatus(int prn)
      : CommandBase(CmdName)
    {

      setPrn(prn);
    }


    GetBeiDouSatelliteHealthStatusPtr GetBeiDouSatelliteHealthStatus::create(int prn)
    {
      return GetBeiDouSatelliteHealthStatusPtr(new GetBeiDouSatelliteHealthStatus(prn));
    }

    GetBeiDouSatelliteHealthStatusPtr GetBeiDouSatelliteHealthStatus::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetBeiDouSatelliteHealthStatus>(ptr);
    }

    bool GetBeiDouSatelliteHealthStatus::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["Prn"])
        ;

    }

    std::string GetBeiDouSatelliteHealthStatus::documentation() const { return Documentation; }


    int GetBeiDouSatelliteHealthStatus::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    int GetBeiDouSatelliteHealthStatus::prn() const
    {
      return parse_json<int>::parse(m_values["Prn"]);
    }

    void GetBeiDouSatelliteHealthStatus::setPrn(int prn)
    {
      m_values.AddMember("Prn", parse_json<int>::format(prn, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
