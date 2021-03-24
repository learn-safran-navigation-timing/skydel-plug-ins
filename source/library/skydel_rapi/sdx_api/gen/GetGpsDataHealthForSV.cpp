#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetGpsDataHealthForSV
///
#include "gen/GetGpsDataHealthForSV.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetGpsDataHealthForSV::CmdName = "GetGpsDataHealthForSV";
    const char* const GetGpsDataHealthForSV::Documentation = "Get GPS nav data health";

    REGISTER_COMMAND_FACTORY(GetGpsDataHealthForSV);


    GetGpsDataHealthForSV::GetGpsDataHealthForSV()
      : CommandBase(CmdName)
    {}

    GetGpsDataHealthForSV::GetGpsDataHealthForSV(int svId)
      : CommandBase(CmdName)
    {

      setSvId(svId);
    }


    GetGpsDataHealthForSVPtr GetGpsDataHealthForSV::create(int svId)
    {
      return GetGpsDataHealthForSVPtr(new GetGpsDataHealthForSV(svId));
    }

    GetGpsDataHealthForSVPtr GetGpsDataHealthForSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetGpsDataHealthForSV>(ptr);
    }

    bool GetGpsDataHealthForSV::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["SvId"])
        ;

    }

    std::string GetGpsDataHealthForSV::documentation() const { return Documentation; }


    int GetGpsDataHealthForSV::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    int GetGpsDataHealthForSV::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void GetGpsDataHealthForSV::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
