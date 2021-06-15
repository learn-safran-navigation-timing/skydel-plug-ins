#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetBeiDouCNavSatelliteHealthInfo
///
#include "gen/GetBeiDouCNavSatelliteHealthInfo.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetBeiDouCNavSatelliteHealthInfo::CmdName = "GetBeiDouCNavSatelliteHealthInfo";
    const char* const GetBeiDouCNavSatelliteHealthInfo::Documentation = "Please note the command GetBeiDouCNavSatelliteHealthInfo is deprecated since 21.3. You may use GetBeiDouCNavHealthInfoForSV.\n\nGet BeiDou CNav satellite health info";

    REGISTER_COMMAND_FACTORY(GetBeiDouCNavSatelliteHealthInfo);


    GetBeiDouCNavSatelliteHealthInfo::GetBeiDouCNavSatelliteHealthInfo()
      : CommandBase(CmdName)
    {}

    GetBeiDouCNavSatelliteHealthInfo::GetBeiDouCNavSatelliteHealthInfo(int prn)
      : CommandBase(CmdName)
    {

      setPrn(prn);
    }


    GetBeiDouCNavSatelliteHealthInfoPtr GetBeiDouCNavSatelliteHealthInfo::create(int prn)
    {
      return GetBeiDouCNavSatelliteHealthInfoPtr(new GetBeiDouCNavSatelliteHealthInfo(prn));
    }

    GetBeiDouCNavSatelliteHealthInfoPtr GetBeiDouCNavSatelliteHealthInfo::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetBeiDouCNavSatelliteHealthInfo>(ptr);
    }

    bool GetBeiDouCNavSatelliteHealthInfo::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["Prn"])
        ;

    }

    std::string GetBeiDouCNavSatelliteHealthInfo::documentation() const { return Documentation; }


    int GetBeiDouCNavSatelliteHealthInfo::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    int GetBeiDouCNavSatelliteHealthInfo::prn() const
    {
      return parse_json<int>::parse(m_values["Prn"]);
    }

    void GetBeiDouCNavSatelliteHealthInfo::setPrn(int prn)
    {
      m_values.AddMember("Prn", parse_json<int>::format(prn, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
