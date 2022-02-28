#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetQzssL1DataHealthForSVResult
///
#include "gen/GetQzssL1DataHealthForSVResult.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetQzssL1DataHealthForSVResult::CmdName = "GetQzssL1DataHealthForSVResult";
    const char* const GetQzssL1DataHealthForSVResult::Documentation = "Result of GetQzssL1DataHealthForSV.";

    REGISTER_COMMAND_RESULT_FACTORY(GetQzssL1DataHealthForSVResult);


    GetQzssL1DataHealthForSVResult::GetQzssL1DataHealthForSVResult()
      : CommandResult(CmdName)
    {}

    GetQzssL1DataHealthForSVResult::GetQzssL1DataHealthForSVResult(CommandBasePtr relatedCommand, int svId, int health, const Sdx::optional<std::string>& dataSetName)
      : CommandResult(CmdName, relatedCommand)
    {

      setSvId(svId);
      setHealth(health);
      setDataSetName(dataSetName);
    }


    GetQzssL1DataHealthForSVResultPtr GetQzssL1DataHealthForSVResult::create(CommandBasePtr relatedCommand, int svId, int health, const Sdx::optional<std::string>& dataSetName)
    {
      return GetQzssL1DataHealthForSVResultPtr(new GetQzssL1DataHealthForSVResult(relatedCommand, svId, health, dataSetName));
    }

    GetQzssL1DataHealthForSVResultPtr GetQzssL1DataHealthForSVResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetQzssL1DataHealthForSVResult>(ptr);
    }

    bool GetQzssL1DataHealthForSVResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<int>::is_valid(m_values["Health"])
          && parse_json<Sdx::optional<std::string>>::is_valid(m_values["DataSetName"])
        ;

    }

    std::string GetQzssL1DataHealthForSVResult::documentation() const { return Documentation; }


    int GetQzssL1DataHealthForSVResult::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void GetQzssL1DataHealthForSVResult::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetQzssL1DataHealthForSVResult::health() const
    {
      return parse_json<int>::parse(m_values["Health"]);
    }

    void GetQzssL1DataHealthForSVResult::setHealth(int health)
    {
      m_values.AddMember("Health", parse_json<int>::format(health, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::optional<std::string> GetQzssL1DataHealthForSVResult::dataSetName() const
    {
      return parse_json<Sdx::optional<std::string>>::parse(m_values["DataSetName"]);
    }

    void GetQzssL1DataHealthForSVResult::setDataSetName(const Sdx::optional<std::string>& dataSetName)
    {
      m_values.AddMember("DataSetName", parse_json<Sdx::optional<std::string>>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
