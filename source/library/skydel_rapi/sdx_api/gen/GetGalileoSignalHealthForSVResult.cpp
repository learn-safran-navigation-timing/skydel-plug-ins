
#include "GetGalileoSignalHealthForSVResult.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetGalileoSignalHealthForSVResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetGalileoSignalHealthForSVResult::CmdName = "GetGalileoSignalHealthForSVResult";
    const char* const GetGalileoSignalHealthForSVResult::Documentation = "Result of GetGalileoSignalHealthForSV.\n"
      "\n"
      "Name        Type            Description\n"
      "----------- --------------- -------------------------------------------------------------------------------------------\n"
      "SvId        int             The satellite's SV ID 1..36\n"
      "Component   string          Component is either \"E5a\", \"E5b\", or \"E1B\"\n"
      "Health      int             Signal health 0..3\n"
      "DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.";
    const char* const GetGalileoSignalHealthForSVResult::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_IMPL(GetGalileoSignalHealthForSVResult);


    GetGalileoSignalHealthForSVResult::GetGalileoSignalHealthForSVResult()
      : CommandResult(CmdName, TargetId)
    {}

    GetGalileoSignalHealthForSVResult::GetGalileoSignalHealthForSVResult(int svId, const std::string& component, int health, const Sdx::optional<std::string>& dataSetName)
      : CommandResult(CmdName, TargetId)
    {

      setSvId(svId);
      setComponent(component);
      setHealth(health);
      setDataSetName(dataSetName);
    }

    GetGalileoSignalHealthForSVResult::GetGalileoSignalHealthForSVResult(CommandBasePtr relatedCommand, int svId, const std::string& component, int health, const Sdx::optional<std::string>& dataSetName)
      : CommandResult(CmdName, TargetId, relatedCommand)
    {

      setSvId(svId);
      setComponent(component);
      setHealth(health);
      setDataSetName(dataSetName);
    }


    GetGalileoSignalHealthForSVResultPtr GetGalileoSignalHealthForSVResult::create(int svId, const std::string& component, int health, const Sdx::optional<std::string>& dataSetName)
    {
      return std::make_shared<GetGalileoSignalHealthForSVResult>(svId, component, health, dataSetName);
    }

    GetGalileoSignalHealthForSVResultPtr GetGalileoSignalHealthForSVResult::create(CommandBasePtr relatedCommand, int svId, const std::string& component, int health, const Sdx::optional<std::string>& dataSetName)
    {
      return std::make_shared<GetGalileoSignalHealthForSVResult>(relatedCommand, svId, component, health, dataSetName);
    }

    GetGalileoSignalHealthForSVResultPtr GetGalileoSignalHealthForSVResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetGalileoSignalHealthForSVResult>(ptr);
    }

    bool GetGalileoSignalHealthForSVResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<std::string>::is_valid(m_values["Component"])
          && parse_json<int>::is_valid(m_values["Health"])
          && parse_json<Sdx::optional<std::string>>::is_valid(m_values["DataSetName"])
        ;

    }

    std::string GetGalileoSignalHealthForSVResult::documentation() const { return Documentation; }

    const std::vector<std::string>& GetGalileoSignalHealthForSVResult::fieldNames() const 
    { 
      static const std::vector<std::string> names {"SvId", "Component", "Health", "DataSetName"}; 
      return names; 
    }


    int GetGalileoSignalHealthForSVResult::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void GetGalileoSignalHealthForSVResult::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string GetGalileoSignalHealthForSVResult::component() const
    {
      return parse_json<std::string>::parse(m_values["Component"]);
    }

    void GetGalileoSignalHealthForSVResult::setComponent(const std::string& component)
    {
      m_values.AddMember("Component", parse_json<std::string>::format(component, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetGalileoSignalHealthForSVResult::health() const
    {
      return parse_json<int>::parse(m_values["Health"]);
    }

    void GetGalileoSignalHealthForSVResult::setHealth(int health)
    {
      m_values.AddMember("Health", parse_json<int>::format(health, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::optional<std::string> GetGalileoSignalHealthForSVResult::dataSetName() const
    {
      return parse_json<Sdx::optional<std::string>>::parse(m_values["DataSetName"]);
    }

    void GetGalileoSignalHealthForSVResult::setDataSetName(const Sdx::optional<std::string>& dataSetName)
    {
      m_values.AddMember("DataSetName", parse_json<Sdx::optional<std::string>>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
