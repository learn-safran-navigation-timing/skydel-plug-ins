#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetBeiDouCNavHealthInfoForSV
///
#include "gen/GetBeiDouCNavHealthInfoForSV.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetBeiDouCNavHealthInfoForSV::CmdName = "GetBeiDouCNavHealthInfoForSV";
    const char* const GetBeiDouCNavHealthInfoForSV::Documentation = "Get BeiDou CNav satellite health info";

    REGISTER_COMMAND_FACTORY(GetBeiDouCNavHealthInfoForSV);


    GetBeiDouCNavHealthInfoForSV::GetBeiDouCNavHealthInfoForSV()
      : CommandBase(CmdName)
    {}

    GetBeiDouCNavHealthInfoForSV::GetBeiDouCNavHealthInfoForSV(int svId)
      : CommandBase(CmdName)
    {

      setSvId(svId);
    }


    GetBeiDouCNavHealthInfoForSVPtr GetBeiDouCNavHealthInfoForSV::create(int svId)
    {
      return GetBeiDouCNavHealthInfoForSVPtr(new GetBeiDouCNavHealthInfoForSV(svId));
    }

    GetBeiDouCNavHealthInfoForSVPtr GetBeiDouCNavHealthInfoForSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetBeiDouCNavHealthInfoForSV>(ptr);
    }

    bool GetBeiDouCNavHealthInfoForSV::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["SvId"])
        ;

    }

    std::string GetBeiDouCNavHealthInfoForSV::documentation() const { return Documentation; }


    int GetBeiDouCNavHealthInfoForSV::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    int GetBeiDouCNavHealthInfoForSV::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void GetBeiDouCNavHealthInfoForSV::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
