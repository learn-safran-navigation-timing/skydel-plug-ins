
#include "GetWFAntennaElementModelResult.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetWFAntennaElementModelResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetWFAntennaElementModelResult::CmdName = "GetWFAntennaElementModelResult";
    const char* const GetWFAntennaElementModelResult::Documentation = "Result of GetWFAntennaElementModel.\n"
      "\n"
      "Name             Type   Description\n"
      "---------------- ------ ----------------------------------------------------------------------------------------------------\n"
      "AntennaModelName string Antenna Model name to set for this element. Antenna models must be defined in vehicle antenna model.\n"
      "Element          int    One-based index for element in antenna.";
    const char* const GetWFAntennaElementModelResult::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_IMPL(GetWFAntennaElementModelResult);


    GetWFAntennaElementModelResult::GetWFAntennaElementModelResult()
      : CommandResult(CmdName, TargetId)
    {}

    GetWFAntennaElementModelResult::GetWFAntennaElementModelResult(const std::string& antennaModelName, int element)
      : CommandResult(CmdName, TargetId)
    {

      setAntennaModelName(antennaModelName);
      setElement(element);
    }

    GetWFAntennaElementModelResult::GetWFAntennaElementModelResult(CommandBasePtr relatedCommand, const std::string& antennaModelName, int element)
      : CommandResult(CmdName, TargetId, relatedCommand)
    {

      setAntennaModelName(antennaModelName);
      setElement(element);
    }


    GetWFAntennaElementModelResultPtr GetWFAntennaElementModelResult::create(const std::string& antennaModelName, int element)
    {
      return std::make_shared<GetWFAntennaElementModelResult>(antennaModelName, element);
    }

    GetWFAntennaElementModelResultPtr GetWFAntennaElementModelResult::create(CommandBasePtr relatedCommand, const std::string& antennaModelName, int element)
    {
      return std::make_shared<GetWFAntennaElementModelResult>(relatedCommand, antennaModelName, element);
    }

    GetWFAntennaElementModelResultPtr GetWFAntennaElementModelResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetWFAntennaElementModelResult>(ptr);
    }

    bool GetWFAntennaElementModelResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["AntennaModelName"])
          && parse_json<int>::is_valid(m_values["Element"])
        ;

    }

    std::string GetWFAntennaElementModelResult::documentation() const { return Documentation; }

    const std::vector<std::string>& GetWFAntennaElementModelResult::fieldNames() const 
    { 
      static const std::vector<std::string> names {"AntennaModelName", "Element"}; 
      return names; 
    }


    std::string GetWFAntennaElementModelResult::antennaModelName() const
    {
      return parse_json<std::string>::parse(m_values["AntennaModelName"]);
    }

    void GetWFAntennaElementModelResult::setAntennaModelName(const std::string& antennaModelName)
    {
      m_values.AddMember("AntennaModelName", parse_json<std::string>::format(antennaModelName, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetWFAntennaElementModelResult::element() const
    {
      return parse_json<int>::parse(m_values["Element"]);
    }

    void GetWFAntennaElementModelResult::setElement(int element)
    {
      m_values.AddMember("Element", parse_json<int>::format(element, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
