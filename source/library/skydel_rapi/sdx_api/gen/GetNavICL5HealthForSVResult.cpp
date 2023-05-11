#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetNavICL5HealthForSVResult
///
#include "gen/GetNavICL5HealthForSVResult.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetNavICL5HealthForSVResult::CmdName = "GetNavICL5HealthForSVResult";
    const char* const GetNavICL5HealthForSVResult::Documentation = "Result of GetNavICL5HealthForSV.";

    REGISTER_COMMAND_RESULT_FACTORY(GetNavICL5HealthForSVResult);


    GetNavICL5HealthForSVResult::GetNavICL5HealthForSVResult()
      : CommandResult(CmdName)
    {}

    GetNavICL5HealthForSVResult::GetNavICL5HealthForSVResult(CommandBasePtr relatedCommand, int svId, bool health, const Sdx::optional<std::string>& dataSetName)
      : CommandResult(CmdName, relatedCommand)
    {

      setSvId(svId);
      setHealth(health);
      setDataSetName(dataSetName);
    }


    GetNavICL5HealthForSVResultPtr GetNavICL5HealthForSVResult::create(CommandBasePtr relatedCommand, int svId, bool health, const Sdx::optional<std::string>& dataSetName)
    {
      return std::make_shared<GetNavICL5HealthForSVResult>(relatedCommand, svId, health, dataSetName);
    }

    GetNavICL5HealthForSVResultPtr GetNavICL5HealthForSVResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetNavICL5HealthForSVResult>(ptr);
    }

    bool GetNavICL5HealthForSVResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<bool>::is_valid(m_values["Health"])
          && parse_json<Sdx::optional<std::string>>::is_valid(m_values["DataSetName"])
        ;

    }

    std::string GetNavICL5HealthForSVResult::documentation() const { return Documentation; }


    int GetNavICL5HealthForSVResult::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void GetNavICL5HealthForSVResult::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool GetNavICL5HealthForSVResult::health() const
    {
      return parse_json<bool>::parse(m_values["Health"]);
    }

    void GetNavICL5HealthForSVResult::setHealth(bool health)
    {
      m_values.AddMember("Health", parse_json<bool>::format(health, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::optional<std::string> GetNavICL5HealthForSVResult::dataSetName() const
    {
      return parse_json<Sdx::optional<std::string>>::parse(m_values["DataSetName"]);
    }

    void GetNavICL5HealthForSVResult::setDataSetName(const Sdx::optional<std::string>& dataSetName)
    {
      m_values.AddMember("DataSetName", parse_json<Sdx::optional<std::string>>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
