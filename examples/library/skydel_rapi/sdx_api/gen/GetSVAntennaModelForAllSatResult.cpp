#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetSVAntennaModelForAllSatResult
///
#include "gen/GetSVAntennaModelForAllSatResult.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetSVAntennaModelForAllSatResult::CmdName = "GetSVAntennaModelForAllSatResult";
    const char* const GetSVAntennaModelForAllSatResult::Documentation = "Result of GetSVAntennaModelForAllSat.";

    REGISTER_COMMAND_RESULT_FACTORY(GetSVAntennaModelForAllSatResult);


    GetSVAntennaModelForAllSatResult::GetSVAntennaModelForAllSatResult()
      : CommandResult(CmdName)
    {}

    GetSVAntennaModelForAllSatResult::GetSVAntennaModelForAllSatResult(CommandBasePtr relatedCommand, const std::vector<std::string>& antennaModelNames, const std::string& system)
      : CommandResult(CmdName, relatedCommand)
    {

      setAntennaModelNames(antennaModelNames);
      setSystem(system);
    }


    GetSVAntennaModelForAllSatResultPtr GetSVAntennaModelForAllSatResult::create(CommandBasePtr relatedCommand, const std::vector<std::string>& antennaModelNames, const std::string& system)
    {
      return GetSVAntennaModelForAllSatResultPtr(new GetSVAntennaModelForAllSatResult(relatedCommand, antennaModelNames, system));
    }

    GetSVAntennaModelForAllSatResultPtr GetSVAntennaModelForAllSatResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetSVAntennaModelForAllSatResult>(ptr);
    }

    bool GetSVAntennaModelForAllSatResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::vector<std::string>>::is_valid(m_values["AntennaModelNames"])
          && parse_json<std::string>::is_valid(m_values["System"])
        ;

    }

    std::string GetSVAntennaModelForAllSatResult::documentation() const { return Documentation; }


    std::vector<std::string> GetSVAntennaModelForAllSatResult::antennaModelNames() const
    {
      return parse_json<std::vector<std::string>>::parse(m_values["AntennaModelNames"]);
    }

    void GetSVAntennaModelForAllSatResult::setAntennaModelNames(const std::vector<std::string>& antennaModelNames)
    {
      m_values.AddMember("AntennaModelNames", parse_json<std::vector<std::string>>::format(antennaModelNames, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string GetSVAntennaModelForAllSatResult::system() const
    {
      return parse_json<std::string>::parse(m_values["System"]);
    }

    void GetSVAntennaModelForAllSatResult::setSystem(const std::string& system)
    {
      m_values.AddMember("System", parse_json<std::string>::format(system, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
