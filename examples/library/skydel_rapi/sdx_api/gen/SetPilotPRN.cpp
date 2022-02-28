#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetPilotPRN
///
#include "gen/SetPilotPRN.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetPilotPRN::CmdName = "SetPilotPRN";
    const char* const SetPilotPRN::Documentation = "Set PRN pilot added to signal";

    REGISTER_COMMAND_FACTORY(SetPilotPRN);


    SetPilotPRN::SetPilotPRN()
      : CommandBase(CmdName)
    {}

    SetPilotPRN::SetPilotPRN(bool enabled, int outputIdx, double centralFreqOffset, double power, int prn, const std::string& type, const std::string& pilotId)
      : CommandBase(CmdName)
    {

      setEnabled(enabled);
      setOutputIdx(outputIdx);
      setCentralFreqOffset(centralFreqOffset);
      setPower(power);
      setPrn(prn);
      setType(type);
      setPilotId(pilotId);
    }


    SetPilotPRNPtr SetPilotPRN::create(bool enabled, int outputIdx, double centralFreqOffset, double power, int prn, const std::string& type, const std::string& pilotId)
    {
      return SetPilotPRNPtr(new SetPilotPRN(enabled, outputIdx, centralFreqOffset, power, prn, type, pilotId));
    }

    SetPilotPRNPtr SetPilotPRN::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetPilotPRN>(ptr);
    }

    bool SetPilotPRN::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<bool>::is_valid(m_values["Enabled"])
          && parse_json<int>::is_valid(m_values["OutputIdx"])
          && parse_json<double>::is_valid(m_values["CentralFreqOffset"])
          && parse_json<double>::is_valid(m_values["Power"])
          && parse_json<int>::is_valid(m_values["Prn"])
          && parse_json<std::string>::is_valid(m_values["Type"])
          && parse_json<std::string>::is_valid(m_values["PilotId"])
        ;

    }

    std::string SetPilotPRN::documentation() const { return Documentation; }


    int SetPilotPRN::executePermission() const
    {
      return EXECUTE_IF_SIMULATING | EXECUTE_IF_IDLE;
    }


    bool SetPilotPRN::enabled() const
    {
      return parse_json<bool>::parse(m_values["Enabled"]);
    }

    void SetPilotPRN::setEnabled(bool enabled)
    {
      m_values.AddMember("Enabled", parse_json<bool>::format(enabled, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int SetPilotPRN::outputIdx() const
    {
      return parse_json<int>::parse(m_values["OutputIdx"]);
    }

    void SetPilotPRN::setOutputIdx(int outputIdx)
    {
      m_values.AddMember("OutputIdx", parse_json<int>::format(outputIdx, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double SetPilotPRN::centralFreqOffset() const
    {
      return parse_json<double>::parse(m_values["CentralFreqOffset"]);
    }

    void SetPilotPRN::setCentralFreqOffset(double centralFreqOffset)
    {
      m_values.AddMember("CentralFreqOffset", parse_json<double>::format(centralFreqOffset, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double SetPilotPRN::power() const
    {
      return parse_json<double>::parse(m_values["Power"]);
    }

    void SetPilotPRN::setPower(double power)
    {
      m_values.AddMember("Power", parse_json<double>::format(power, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int SetPilotPRN::prn() const
    {
      return parse_json<int>::parse(m_values["Prn"]);
    }

    void SetPilotPRN::setPrn(int prn)
    {
      m_values.AddMember("Prn", parse_json<int>::format(prn, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string SetPilotPRN::type() const
    {
      return parse_json<std::string>::parse(m_values["Type"]);
    }

    void SetPilotPRN::setType(const std::string& type)
    {
      m_values.AddMember("Type", parse_json<std::string>::format(type, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string SetPilotPRN::pilotId() const
    {
      return parse_json<std::string>::parse(m_values["PilotId"]);
    }

    void SetPilotPRN::setPilotId(const std::string& pilotId)
    {
      m_values.AddMember("PilotId", parse_json<std::string>::format(pilotId, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
