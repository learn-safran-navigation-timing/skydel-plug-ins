#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetGpsSignalHealthForSVResult
///
#include "gen/GetGpsSignalHealthForSVResult.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetGpsSignalHealthForSVResult::CmdName = "GetGpsSignalHealthForSVResult";
    const char* const GetGpsSignalHealthForSVResult::Documentation = "Result of GetGpsSignalHealthForSV";

    REGISTER_COMMAND_RESULT_FACTORY(GetGpsSignalHealthForSVResult);


    GetGpsSignalHealthForSVResult::GetGpsSignalHealthForSVResult()
      : CommandResult(CmdName)
    {}

    GetGpsSignalHealthForSVResult::GetGpsSignalHealthForSVResult(CommandBasePtr relatedCommand, int svId, int health)
      : CommandResult(CmdName, relatedCommand)
    {

      setSvId(svId);
      setHealth(health);
    }


    GetGpsSignalHealthForSVResultPtr GetGpsSignalHealthForSVResult::create(CommandBasePtr relatedCommand, int svId, int health)
    {
      return GetGpsSignalHealthForSVResultPtr(new GetGpsSignalHealthForSVResult(relatedCommand, svId, health));
    }

    GetGpsSignalHealthForSVResultPtr GetGpsSignalHealthForSVResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetGpsSignalHealthForSVResult>(ptr);
    }

    bool GetGpsSignalHealthForSVResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<int>::is_valid(m_values["Health"])
        ;

    }

    std::string GetGpsSignalHealthForSVResult::documentation() const { return Documentation; }


    int GetGpsSignalHealthForSVResult::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void GetGpsSignalHealthForSVResult::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetGpsSignalHealthForSVResult::health() const
    {
      return parse_json<int>::parse(m_values["Health"]);
    }

    void GetGpsSignalHealthForSVResult::setHealth(int health)
    {
      m_values.AddMember("Health", parse_json<int>::format(health, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}