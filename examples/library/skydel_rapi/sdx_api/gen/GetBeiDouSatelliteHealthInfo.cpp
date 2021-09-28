#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetBeiDouSatelliteHealthInfo
///
#include "gen/GetBeiDouSatelliteHealthInfo.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetBeiDouSatelliteHealthInfo::CmdName = "GetBeiDouSatelliteHealthInfo";
    const char* const GetBeiDouSatelliteHealthInfo::Documentation = "Please note the command GetBeiDouSatelliteHealthInfo is deprecated since 21.3. You may use GetBeiDouHealthInfoForSV.\n\nGet BeiDou satellite health info";

    REGISTER_COMMAND_FACTORY(GetBeiDouSatelliteHealthInfo);


    GetBeiDouSatelliteHealthInfo::GetBeiDouSatelliteHealthInfo()
      : CommandBase(CmdName)
    {}

    GetBeiDouSatelliteHealthInfo::GetBeiDouSatelliteHealthInfo(int prn)
      : CommandBase(CmdName)
    {

      setPrn(prn);
    }


    GetBeiDouSatelliteHealthInfoPtr GetBeiDouSatelliteHealthInfo::create(int prn)
    {
      return GetBeiDouSatelliteHealthInfoPtr(new GetBeiDouSatelliteHealthInfo(prn));
    }

    GetBeiDouSatelliteHealthInfoPtr GetBeiDouSatelliteHealthInfo::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetBeiDouSatelliteHealthInfo>(ptr);
    }

    bool GetBeiDouSatelliteHealthInfo::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["Prn"])
        ;

    }

    std::string GetBeiDouSatelliteHealthInfo::documentation() const { return Documentation; }


    int GetBeiDouSatelliteHealthInfo::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    int GetBeiDouSatelliteHealthInfo::prn() const
    {
      return parse_json<int>::parse(m_values["Prn"]);
    }

    void GetBeiDouSatelliteHealthInfo::setPrn(int prn)
    {
      m_values.AddMember("Prn", parse_json<int>::format(prn, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
