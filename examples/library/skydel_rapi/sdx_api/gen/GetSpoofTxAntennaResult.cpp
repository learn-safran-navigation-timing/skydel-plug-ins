#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetSpoofTxAntennaResult
///
#include "gen/GetSpoofTxAntennaResult.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetSpoofTxAntennaResult::CmdName = "GetSpoofTxAntennaResult";
    const char* const GetSpoofTxAntennaResult::Documentation = "Result of GetSpoofTxAntenna.";

    REGISTER_COMMAND_RESULT_FACTORY(GetSpoofTxAntennaResult);


    GetSpoofTxAntennaResult::GetSpoofTxAntennaResult()
      : CommandResult(CmdName)
    {}

    GetSpoofTxAntennaResult::GetSpoofTxAntennaResult(CommandBasePtr relatedCommand, const std::vector<std::vector<double>>& gain, const Sdx::AntennaPatternType& type, const std::string& id)
      : CommandResult(CmdName, relatedCommand)
    {

      setGain(gain);
      setType(type);
      setId(id);
    }


    GetSpoofTxAntennaResultPtr GetSpoofTxAntennaResult::create(CommandBasePtr relatedCommand, const std::vector<std::vector<double>>& gain, const Sdx::AntennaPatternType& type, const std::string& id)
    {
      return GetSpoofTxAntennaResultPtr(new GetSpoofTxAntennaResult(relatedCommand, gain, type, id));
    }

    GetSpoofTxAntennaResultPtr GetSpoofTxAntennaResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetSpoofTxAntennaResult>(ptr);
    }

    bool GetSpoofTxAntennaResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::vector<std::vector<double>>>::is_valid(m_values["Gain"])
          && parse_json<Sdx::AntennaPatternType>::is_valid(m_values["Type"])
          && parse_json<std::string>::is_valid(m_values["Id"])
        ;

    }

    std::string GetSpoofTxAntennaResult::documentation() const { return Documentation; }


    std::vector<std::vector<double>> GetSpoofTxAntennaResult::gain() const
    {
      return parse_json<std::vector<std::vector<double>>>::parse(m_values["Gain"]);
    }

    void GetSpoofTxAntennaResult::setGain(const std::vector<std::vector<double>>& gain)
    {
      m_values.AddMember("Gain", parse_json<std::vector<std::vector<double>>>::format(gain, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::AntennaPatternType GetSpoofTxAntennaResult::type() const
    {
      return parse_json<Sdx::AntennaPatternType>::parse(m_values["Type"]);
    }

    void GetSpoofTxAntennaResult::setType(const Sdx::AntennaPatternType& type)
    {
      m_values.AddMember("Type", parse_json<Sdx::AntennaPatternType>::format(type, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string GetSpoofTxAntennaResult::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void GetSpoofTxAntennaResult::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
