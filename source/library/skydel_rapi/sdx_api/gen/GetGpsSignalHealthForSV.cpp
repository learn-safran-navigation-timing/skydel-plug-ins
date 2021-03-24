#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetGpsSignalHealthForSV
///
#include "gen/GetGpsSignalHealthForSV.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetGpsSignalHealthForSV::CmdName = "GetGpsSignalHealthForSV";
    const char* const GetGpsSignalHealthForSV::Documentation = "Get GPS signal health";

    REGISTER_COMMAND_FACTORY(GetGpsSignalHealthForSV);


    GetGpsSignalHealthForSV::GetGpsSignalHealthForSV()
      : CommandBase(CmdName)
    {}

    GetGpsSignalHealthForSV::GetGpsSignalHealthForSV(int svId)
      : CommandBase(CmdName)
    {

      setSvId(svId);
    }


    GetGpsSignalHealthForSVPtr GetGpsSignalHealthForSV::create(int svId)
    {
      return GetGpsSignalHealthForSVPtr(new GetGpsSignalHealthForSV(svId));
    }

    GetGpsSignalHealthForSVPtr GetGpsSignalHealthForSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetGpsSignalHealthForSV>(ptr);
    }

    bool GetGpsSignalHealthForSV::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["SvId"])
        ;

    }

    std::string GetGpsSignalHealthForSV::documentation() const { return Documentation; }


    int GetGpsSignalHealthForSV::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    int GetGpsSignalHealthForSV::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void GetGpsSignalHealthForSV::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
