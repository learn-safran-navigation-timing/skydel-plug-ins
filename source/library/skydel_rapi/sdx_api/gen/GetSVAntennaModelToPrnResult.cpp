#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetSVAntennaModelToPrnResult
///
#include "gen/GetSVAntennaModelToPrnResult.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetSVAntennaModelToPrnResult::CmdName = "GetSVAntennaModelToPrnResult";
    const char* const GetSVAntennaModelToPrnResult::Documentation = "Result of GetSVAntennaModelToPrn.";

    REGISTER_COMMAND_RESULT_FACTORY(GetSVAntennaModelToPrnResult);


    GetSVAntennaModelToPrnResult::GetSVAntennaModelToPrnResult()
      : CommandResult(CmdName)
    {}

    GetSVAntennaModelToPrnResult::GetSVAntennaModelToPrnResult(CommandBasePtr relatedCommand, int prn, const std::string& system, const std::string& antennaModelName)
      : CommandResult(CmdName, relatedCommand)
    {

      setPrn(prn);
      setSystem(system);
      setAntennaModelName(antennaModelName);
    }


    GetSVAntennaModelToPrnResultPtr GetSVAntennaModelToPrnResult::create(CommandBasePtr relatedCommand, int prn, const std::string& system, const std::string& antennaModelName)
    {
      return GetSVAntennaModelToPrnResultPtr(new GetSVAntennaModelToPrnResult(relatedCommand, prn, system, antennaModelName));
    }

    GetSVAntennaModelToPrnResultPtr GetSVAntennaModelToPrnResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetSVAntennaModelToPrnResult>(ptr);
    }

    bool GetSVAntennaModelToPrnResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["Prn"])
          && parse_json<std::string>::is_valid(m_values["System"])
          && parse_json<std::string>::is_valid(m_values["AntennaModelName"])
        ;

    }

    std::string GetSVAntennaModelToPrnResult::documentation() const { return Documentation; }


    int GetSVAntennaModelToPrnResult::prn() const
    {
      return parse_json<int>::parse(m_values["Prn"]);
    }

    void GetSVAntennaModelToPrnResult::setPrn(int prn)
    {
      m_values.AddMember("Prn", parse_json<int>::format(prn, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string GetSVAntennaModelToPrnResult::system() const
    {
      return parse_json<std::string>::parse(m_values["System"]);
    }

    void GetSVAntennaModelToPrnResult::setSystem(const std::string& system)
    {
      m_values.AddMember("System", parse_json<std::string>::format(system, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string GetSVAntennaModelToPrnResult::antennaModelName() const
    {
      return parse_json<std::string>::parse(m_values["AntennaModelName"]);
    }

    void GetSVAntennaModelToPrnResult::setAntennaModelName(const std::string& antennaModelName)
    {
      m_values.AddMember("AntennaModelName", parse_json<std::string>::format(antennaModelName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
