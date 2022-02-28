#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetInterferenceCW
///
#include "gen/SetInterferenceCW.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetInterferenceCW::CmdName = "SetInterferenceCW";
    const char* const SetInterferenceCW::Documentation = "Add or update continuous wave interference.";

    REGISTER_COMMAND_FACTORY(SetInterferenceCW);


    SetInterferenceCW::SetInterferenceCW()
      : CommandBase(CmdName)
    {}

    SetInterferenceCW::SetInterferenceCW(int startTime, int stopTime, double centralFreq, double power, bool enabled, const std::string& id)
      : CommandBase(CmdName)
    {

      setStartTime(startTime);
      setStopTime(stopTime);
      setCentralFreq(centralFreq);
      setPower(power);
      setEnabled(enabled);
      setId(id);
    }


    SetInterferenceCWPtr SetInterferenceCW::create(int startTime, int stopTime, double centralFreq, double power, bool enabled, const std::string& id)
    {
      return SetInterferenceCWPtr(new SetInterferenceCW(startTime, stopTime, centralFreq, power, enabled, id));
    }

    SetInterferenceCWPtr SetInterferenceCW::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetInterferenceCW>(ptr);
    }

    bool SetInterferenceCW::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["StartTime"])
          && parse_json<int>::is_valid(m_values["StopTime"])
          && parse_json<double>::is_valid(m_values["CentralFreq"])
          && parse_json<double>::is_valid(m_values["Power"])
          && parse_json<bool>::is_valid(m_values["Enabled"])
          && parse_json<std::string>::is_valid(m_values["Id"])
        ;

    }

    std::string SetInterferenceCW::documentation() const { return Documentation; }


    int SetInterferenceCW::executePermission() const
    {
      return EXECUTE_IF_SIMULATING | EXECUTE_IF_IDLE;
    }


    int SetInterferenceCW::startTime() const
    {
      return parse_json<int>::parse(m_values["StartTime"]);
    }

    void SetInterferenceCW::setStartTime(int startTime)
    {
      m_values.AddMember("StartTime", parse_json<int>::format(startTime, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int SetInterferenceCW::stopTime() const
    {
      return parse_json<int>::parse(m_values["StopTime"]);
    }

    void SetInterferenceCW::setStopTime(int stopTime)
    {
      m_values.AddMember("StopTime", parse_json<int>::format(stopTime, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double SetInterferenceCW::centralFreq() const
    {
      return parse_json<double>::parse(m_values["CentralFreq"]);
    }

    void SetInterferenceCW::setCentralFreq(double centralFreq)
    {
      m_values.AddMember("CentralFreq", parse_json<double>::format(centralFreq, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double SetInterferenceCW::power() const
    {
      return parse_json<double>::parse(m_values["Power"]);
    }

    void SetInterferenceCW::setPower(double power)
    {
      m_values.AddMember("Power", parse_json<double>::format(power, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool SetInterferenceCW::enabled() const
    {
      return parse_json<bool>::parse(m_values["Enabled"]);
    }

    void SetInterferenceCW::setEnabled(bool enabled)
    {
      m_values.AddMember("Enabled", parse_json<bool>::format(enabled, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string SetInterferenceCW::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void SetInterferenceCW::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
