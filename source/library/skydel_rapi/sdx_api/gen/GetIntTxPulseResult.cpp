#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetIntTxPulseResult
///
#include "gen/GetIntTxPulseResult.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetIntTxPulseResult::CmdName = "GetIntTxPulseResult";
    const char* const GetIntTxPulseResult::Documentation = "Result of GetIntTxPulse.";

    REGISTER_COMMAND_RESULT_FACTORY(GetIntTxPulseResult);


    GetIntTxPulseResult::GetIntTxPulseResult()
      : CommandResult(CmdName)
    {}

    GetIntTxPulseResult::GetIntTxPulseResult(CommandBasePtr relatedCommand, bool enabled, double centralFreq, double power, double dutyCycle, int pulseRate, const std::string& transmitterId, const std::string& signalId, const Sdx::optional<int>& group)
      : CommandResult(CmdName, relatedCommand)
    {

      setEnabled(enabled);
      setCentralFreq(centralFreq);
      setPower(power);
      setDutyCycle(dutyCycle);
      setPulseRate(pulseRate);
      setTransmitterId(transmitterId);
      setSignalId(signalId);
      setGroup(group);
    }


    GetIntTxPulseResultPtr GetIntTxPulseResult::create(CommandBasePtr relatedCommand, bool enabled, double centralFreq, double power, double dutyCycle, int pulseRate, const std::string& transmitterId, const std::string& signalId, const Sdx::optional<int>& group)
    {
      return std::make_shared<GetIntTxPulseResult>(relatedCommand, enabled, centralFreq, power, dutyCycle, pulseRate, transmitterId, signalId, group);
    }

    GetIntTxPulseResultPtr GetIntTxPulseResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetIntTxPulseResult>(ptr);
    }

    bool GetIntTxPulseResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<bool>::is_valid(m_values["Enabled"])
          && parse_json<double>::is_valid(m_values["CentralFreq"])
          && parse_json<double>::is_valid(m_values["Power"])
          && parse_json<double>::is_valid(m_values["DutyCycle"])
          && parse_json<int>::is_valid(m_values["PulseRate"])
          && parse_json<std::string>::is_valid(m_values["TransmitterId"])
          && parse_json<std::string>::is_valid(m_values["SignalId"])
          && parse_json<Sdx::optional<int>>::is_valid(m_values["Group"])
        ;

    }

    std::string GetIntTxPulseResult::documentation() const { return Documentation; }


    bool GetIntTxPulseResult::enabled() const
    {
      return parse_json<bool>::parse(m_values["Enabled"]);
    }

    void GetIntTxPulseResult::setEnabled(bool enabled)
    {
      m_values.AddMember("Enabled", parse_json<bool>::format(enabled, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double GetIntTxPulseResult::centralFreq() const
    {
      return parse_json<double>::parse(m_values["CentralFreq"]);
    }

    void GetIntTxPulseResult::setCentralFreq(double centralFreq)
    {
      m_values.AddMember("CentralFreq", parse_json<double>::format(centralFreq, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double GetIntTxPulseResult::power() const
    {
      return parse_json<double>::parse(m_values["Power"]);
    }

    void GetIntTxPulseResult::setPower(double power)
    {
      m_values.AddMember("Power", parse_json<double>::format(power, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double GetIntTxPulseResult::dutyCycle() const
    {
      return parse_json<double>::parse(m_values["DutyCycle"]);
    }

    void GetIntTxPulseResult::setDutyCycle(double dutyCycle)
    {
      m_values.AddMember("DutyCycle", parse_json<double>::format(dutyCycle, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetIntTxPulseResult::pulseRate() const
    {
      return parse_json<int>::parse(m_values["PulseRate"]);
    }

    void GetIntTxPulseResult::setPulseRate(int pulseRate)
    {
      m_values.AddMember("PulseRate", parse_json<int>::format(pulseRate, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string GetIntTxPulseResult::transmitterId() const
    {
      return parse_json<std::string>::parse(m_values["TransmitterId"]);
    }

    void GetIntTxPulseResult::setTransmitterId(const std::string& transmitterId)
    {
      m_values.AddMember("TransmitterId", parse_json<std::string>::format(transmitterId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string GetIntTxPulseResult::signalId() const
    {
      return parse_json<std::string>::parse(m_values["SignalId"]);
    }

    void GetIntTxPulseResult::setSignalId(const std::string& signalId)
    {
      m_values.AddMember("SignalId", parse_json<std::string>::format(signalId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::optional<int> GetIntTxPulseResult::group() const
    {
      return parse_json<Sdx::optional<int>>::parse(m_values["Group"]);
    }

    void GetIntTxPulseResult::setGroup(const Sdx::optional<int>& group)
    {
      m_values.AddMember("Group", parse_json<Sdx::optional<int>>::format(group, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
