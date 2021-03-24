#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetBeiDouHealthInfoForSV
///
#include "gen/GetBeiDouHealthInfoForSV.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetBeiDouHealthInfoForSV::CmdName = "GetBeiDouHealthInfoForSV";
    const char* const GetBeiDouHealthInfoForSV::Documentation = "Get BeiDou satellite health info";

    REGISTER_COMMAND_FACTORY(GetBeiDouHealthInfoForSV);


    GetBeiDouHealthInfoForSV::GetBeiDouHealthInfoForSV()
      : CommandBase(CmdName)
    {}

    GetBeiDouHealthInfoForSV::GetBeiDouHealthInfoForSV(int svId)
      : CommandBase(CmdName)
    {

      setSvId(svId);
    }


    GetBeiDouHealthInfoForSVPtr GetBeiDouHealthInfoForSV::create(int svId)
    {
      return GetBeiDouHealthInfoForSVPtr(new GetBeiDouHealthInfoForSV(svId));
    }

    GetBeiDouHealthInfoForSVPtr GetBeiDouHealthInfoForSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetBeiDouHealthInfoForSV>(ptr);
    }

    bool GetBeiDouHealthInfoForSV::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["SvId"])
        ;

    }

    std::string GetBeiDouHealthInfoForSV::documentation() const { return Documentation; }


    int GetBeiDouHealthInfoForSV::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    int GetBeiDouHealthInfoForSV::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void GetBeiDouHealthInfoForSV::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
