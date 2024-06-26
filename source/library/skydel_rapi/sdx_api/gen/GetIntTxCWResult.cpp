
#include "GetIntTxCWResult.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetIntTxCWResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetIntTxCWResult::CmdName = "GetIntTxCWResult";
    const char* const GetIntTxCWResult::Documentation = "Result of GetIntTxCW.\n"
      "\n"
      "Name               Type            Description\n"
      "------------------ --------------- ---------------------------------------------------\n"
      "Enabled            bool            Enable (true) or disable (false) the signal\n"
      "CentralFreq        double          Central frequency (Hz)\n"
      "Power              double          Power (dB), relative to transmitter reference power\n"
      "TransmitterId      string          Transmitter unique identifier.\n"
      "SignalId           string          CW unique identifier.\n"
      "InitialPhaseOffset optional double Initial phase offset, in radians. Defaults to 0.\n"
      "Group              optional int    Group, if not using default group.";
    const char* const GetIntTxCWResult::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_IMPL(GetIntTxCWResult);


    GetIntTxCWResult::GetIntTxCWResult()
      : CommandResult(CmdName, TargetId)
    {}

    GetIntTxCWResult::GetIntTxCWResult(bool enabled, double centralFreq, double power, const std::string& transmitterId, const std::string& signalId, const std::optional<double>& initialPhaseOffset, const std::optional<int>& group)
      : CommandResult(CmdName, TargetId)
    {

      setEnabled(enabled);
      setCentralFreq(centralFreq);
      setPower(power);
      setTransmitterId(transmitterId);
      setSignalId(signalId);
      setInitialPhaseOffset(initialPhaseOffset);
      setGroup(group);
    }

    GetIntTxCWResult::GetIntTxCWResult(CommandBasePtr relatedCommand, bool enabled, double centralFreq, double power, const std::string& transmitterId, const std::string& signalId, const std::optional<double>& initialPhaseOffset, const std::optional<int>& group)
      : CommandResult(CmdName, TargetId, relatedCommand)
    {

      setEnabled(enabled);
      setCentralFreq(centralFreq);
      setPower(power);
      setTransmitterId(transmitterId);
      setSignalId(signalId);
      setInitialPhaseOffset(initialPhaseOffset);
      setGroup(group);
    }


    GetIntTxCWResultPtr GetIntTxCWResult::create(bool enabled, double centralFreq, double power, const std::string& transmitterId, const std::string& signalId, const std::optional<double>& initialPhaseOffset, const std::optional<int>& group)
    {
      return std::make_shared<GetIntTxCWResult>(enabled, centralFreq, power, transmitterId, signalId, initialPhaseOffset, group);
    }

    GetIntTxCWResultPtr GetIntTxCWResult::create(CommandBasePtr relatedCommand, bool enabled, double centralFreq, double power, const std::string& transmitterId, const std::string& signalId, const std::optional<double>& initialPhaseOffset, const std::optional<int>& group)
    {
      return std::make_shared<GetIntTxCWResult>(relatedCommand, enabled, centralFreq, power, transmitterId, signalId, initialPhaseOffset, group);
    }

    GetIntTxCWResultPtr GetIntTxCWResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetIntTxCWResult>(ptr);
    }

    bool GetIntTxCWResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<bool>::is_valid(m_values["Enabled"])
          && parse_json<double>::is_valid(m_values["CentralFreq"])
          && parse_json<double>::is_valid(m_values["Power"])
          && parse_json<std::string>::is_valid(m_values["TransmitterId"])
          && parse_json<std::string>::is_valid(m_values["SignalId"])
          && parse_json<std::optional<double>>::is_valid(m_values["InitialPhaseOffset"])
          && parse_json<std::optional<int>>::is_valid(m_values["Group"])
        ;

    }

    std::string GetIntTxCWResult::documentation() const { return Documentation; }

    const std::vector<std::string>& GetIntTxCWResult::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Enabled", "CentralFreq", "Power", "TransmitterId", "SignalId", "InitialPhaseOffset", "Group"}; 
      return names; 
    }


    bool GetIntTxCWResult::enabled() const
    {
      return parse_json<bool>::parse(m_values["Enabled"]);
    }

    void GetIntTxCWResult::setEnabled(bool enabled)
    {
      m_values.AddMember("Enabled", parse_json<bool>::format(enabled, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double GetIntTxCWResult::centralFreq() const
    {
      return parse_json<double>::parse(m_values["CentralFreq"]);
    }

    void GetIntTxCWResult::setCentralFreq(double centralFreq)
    {
      m_values.AddMember("CentralFreq", parse_json<double>::format(centralFreq, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double GetIntTxCWResult::power() const
    {
      return parse_json<double>::parse(m_values["Power"]);
    }

    void GetIntTxCWResult::setPower(double power)
    {
      m_values.AddMember("Power", parse_json<double>::format(power, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string GetIntTxCWResult::transmitterId() const
    {
      return parse_json<std::string>::parse(m_values["TransmitterId"]);
    }

    void GetIntTxCWResult::setTransmitterId(const std::string& transmitterId)
    {
      m_values.AddMember("TransmitterId", parse_json<std::string>::format(transmitterId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string GetIntTxCWResult::signalId() const
    {
      return parse_json<std::string>::parse(m_values["SignalId"]);
    }

    void GetIntTxCWResult::setSignalId(const std::string& signalId)
    {
      m_values.AddMember("SignalId", parse_json<std::string>::format(signalId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::optional<double> GetIntTxCWResult::initialPhaseOffset() const
    {
      return parse_json<std::optional<double>>::parse(m_values["InitialPhaseOffset"]);
    }

    void GetIntTxCWResult::setInitialPhaseOffset(const std::optional<double>& initialPhaseOffset)
    {
      m_values.AddMember("InitialPhaseOffset", parse_json<std::optional<double>>::format(initialPhaseOffset, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::optional<int> GetIntTxCWResult::group() const
    {
      return parse_json<std::optional<int>>::parse(m_values["Group"]);
    }

    void GetIntTxCWResult::setGroup(const std::optional<int>& group)
    {
      m_values.AddMember("Group", parse_json<std::optional<int>>::format(group, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
