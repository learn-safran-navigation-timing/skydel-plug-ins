#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetAllSVAntennaNamesResult
///
#include "gen/GetAllSVAntennaNamesResult.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetAllSVAntennaNamesResult::CmdName = "GetAllSVAntennaNamesResult";
    const char* const GetAllSVAntennaNamesResult::Documentation = "Result of GetAllSVAntennaNames.";

    REGISTER_COMMAND_RESULT_FACTORY(GetAllSVAntennaNamesResult);


    GetAllSVAntennaNamesResult::GetAllSVAntennaNamesResult()
      : CommandResult(CmdName)
    {}

    GetAllSVAntennaNamesResult::GetAllSVAntennaNamesResult(CommandBasePtr relatedCommand, const std::string& system, const std::vector<std::string>& antennaNames)
      : CommandResult(CmdName, relatedCommand)
    {

      setSystem(system);
      setAntennaNames(antennaNames);
    }


    GetAllSVAntennaNamesResultPtr GetAllSVAntennaNamesResult::create(CommandBasePtr relatedCommand, const std::string& system, const std::vector<std::string>& antennaNames)
    {
      return std::make_shared<GetAllSVAntennaNamesResult>(relatedCommand, system, antennaNames);
    }

    GetAllSVAntennaNamesResultPtr GetAllSVAntennaNamesResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetAllSVAntennaNamesResult>(ptr);
    }

    bool GetAllSVAntennaNamesResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["System"])
          && parse_json<std::vector<std::string>>::is_valid(m_values["AntennaNames"])
        ;

    }

    std::string GetAllSVAntennaNamesResult::documentation() const { return Documentation; }


    std::string GetAllSVAntennaNamesResult::system() const
    {
      return parse_json<std::string>::parse(m_values["System"]);
    }

    void GetAllSVAntennaNamesResult::setSystem(const std::string& system)
    {
      m_values.AddMember("System", parse_json<std::string>::format(system, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::vector<std::string> GetAllSVAntennaNamesResult::antennaNames() const
    {
      return parse_json<std::vector<std::string>>::parse(m_values["AntennaNames"]);
    }

    void GetAllSVAntennaNamesResult::setAntennaNames(const std::vector<std::string>& antennaNames)
    {
      m_values.AddMember("AntennaNames", parse_json<std::vector<std::string>>::format(antennaNames, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
