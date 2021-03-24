#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetBeiDouHealthStatusForSV
///
#include "gen/GetBeiDouHealthStatusForSV.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetBeiDouHealthStatusForSV::CmdName = "GetBeiDouHealthStatusForSV";
    const char* const GetBeiDouHealthStatusForSV::Documentation = "Get BeiDou satellite health status";

    REGISTER_COMMAND_FACTORY(GetBeiDouHealthStatusForSV);


    GetBeiDouHealthStatusForSV::GetBeiDouHealthStatusForSV()
      : CommandBase(CmdName)
    {}

    GetBeiDouHealthStatusForSV::GetBeiDouHealthStatusForSV(int svId)
      : CommandBase(CmdName)
    {

      setSvId(svId);
    }


    GetBeiDouHealthStatusForSVPtr GetBeiDouHealthStatusForSV::create(int svId)
    {
      return GetBeiDouHealthStatusForSVPtr(new GetBeiDouHealthStatusForSV(svId));
    }

    GetBeiDouHealthStatusForSVPtr GetBeiDouHealthStatusForSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetBeiDouHealthStatusForSV>(ptr);
    }

    bool GetBeiDouHealthStatusForSV::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["SvId"])
        ;

    }

    std::string GetBeiDouHealthStatusForSV::documentation() const { return Documentation; }


    int GetBeiDouHealthStatusForSV::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    int GetBeiDouHealthStatusForSV::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void GetBeiDouHealthStatusForSV::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
