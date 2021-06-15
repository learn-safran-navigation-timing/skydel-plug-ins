#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetPseudorangeRamp
///
#include "gen/SetPseudorangeRamp.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetPseudorangeRamp::CmdName = "SetPseudorangeRamp";
    const char* const SetPseudorangeRamp::Documentation = "Please note the command SetPseudorangeRamp is deprecated since 21.3. You may use SetPseudorangeRampForSV.\n\nSet PSR ramp event. This function lets user change the pseudorange of any satellite.\nIf PRN is set to 0, the change is applied to all satellites.\n\n         Hold Start Time\n         |     Hold Stop Time\n         |     |\n         ...........\n       ..       ...\n       ..        ...\n  .......           .........> Time\n      |           |\n      Start Time      Stop Time\n";

    REGISTER_COMMAND_FACTORY(SetPseudorangeRamp);


    SetPseudorangeRamp::SetPseudorangeRamp()
      : CommandBase(CmdName)
    {}

    SetPseudorangeRamp::SetPseudorangeRamp(const std::string& system, int prn, double offset, int startTime, int holdStartTime, int holdStopTime, int stopTime, const std::string& id)
      : CommandBase(CmdName)
    {

      setSystem(system);
      setPrn(prn);
      setOffset(offset);
      setStartTime(startTime);
      setHoldStartTime(holdStartTime);
      setHoldStopTime(holdStopTime);
      setStopTime(stopTime);
      setId(id);
    }


    SetPseudorangeRampPtr SetPseudorangeRamp::create(const std::string& system, int prn, double offset, int startTime, int holdStartTime, int holdStopTime, int stopTime, const std::string& id)
    {
      return SetPseudorangeRampPtr(new SetPseudorangeRamp(system, prn, offset, startTime, holdStartTime, holdStopTime, stopTime, id));
    }

    SetPseudorangeRampPtr SetPseudorangeRamp::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetPseudorangeRamp>(ptr);
    }

    bool SetPseudorangeRamp::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["System"])
          && parse_json<int>::is_valid(m_values["Prn"])
          && parse_json<double>::is_valid(m_values["Offset"])
          && parse_json<int>::is_valid(m_values["StartTime"])
          && parse_json<int>::is_valid(m_values["HoldStartTime"])
          && parse_json<int>::is_valid(m_values["HoldStopTime"])
          && parse_json<int>::is_valid(m_values["StopTime"])
          && parse_json<std::string>::is_valid(m_values["Id"])
        ;

    }

    std::string SetPseudorangeRamp::documentation() const { return Documentation; }


    int SetPseudorangeRamp::executePermission() const
    {
      return EXECUTE_IF_SIMULATING | EXECUTE_IF_IDLE;
    }


    std::string SetPseudorangeRamp::system() const
    {
      return parse_json<std::string>::parse(m_values["System"]);
    }

    void SetPseudorangeRamp::setSystem(const std::string& system)
    {
      m_values.AddMember("System", parse_json<std::string>::format(system, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int SetPseudorangeRamp::prn() const
    {
      return parse_json<int>::parse(m_values["Prn"]);
    }

    void SetPseudorangeRamp::setPrn(int prn)
    {
      m_values.AddMember("Prn", parse_json<int>::format(prn, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double SetPseudorangeRamp::offset() const
    {
      return parse_json<double>::parse(m_values["Offset"]);
    }

    void SetPseudorangeRamp::setOffset(double offset)
    {
      m_values.AddMember("Offset", parse_json<double>::format(offset, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int SetPseudorangeRamp::startTime() const
    {
      return parse_json<int>::parse(m_values["StartTime"]);
    }

    void SetPseudorangeRamp::setStartTime(int startTime)
    {
      m_values.AddMember("StartTime", parse_json<int>::format(startTime, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int SetPseudorangeRamp::holdStartTime() const
    {
      return parse_json<int>::parse(m_values["HoldStartTime"]);
    }

    void SetPseudorangeRamp::setHoldStartTime(int holdStartTime)
    {
      m_values.AddMember("HoldStartTime", parse_json<int>::format(holdStartTime, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int SetPseudorangeRamp::holdStopTime() const
    {
      return parse_json<int>::parse(m_values["HoldStopTime"]);
    }

    void SetPseudorangeRamp::setHoldStopTime(int holdStopTime)
    {
      m_values.AddMember("HoldStopTime", parse_json<int>::format(holdStopTime, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int SetPseudorangeRamp::stopTime() const
    {
      return parse_json<int>::parse(m_values["StopTime"]);
    }

    void SetPseudorangeRamp::setStopTime(int stopTime)
    {
      m_values.AddMember("StopTime", parse_json<int>::format(stopTime, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string SetPseudorangeRamp::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void SetPseudorangeRamp::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
