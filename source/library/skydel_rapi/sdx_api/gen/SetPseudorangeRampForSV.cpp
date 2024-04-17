
#include "SetPseudorangeRampForSV.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetPseudorangeRampForSV
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetPseudorangeRampForSV::CmdName = "SetPseudorangeRampForSV";
    const char* const SetPseudorangeRampForSV::Documentation = "Set PSR ramp event. This function lets user change the pseudorange of any satellite.\n"
      "If SV ID is set to 0, the change is applied to all satellites.\n"
      "\n"
      "          Hold Start Time\n"
      "          |         Hold Stop Time\n"
      "          |         |\n"
      "          ...........\n"
      "         ..         ...\n"
      "        ..            ...\n"
      "  .......               .........> Time\n"
      "        |               |\n"
      "        Start Time      Stop Time\n"
      "\n"
      "\n"
      "Name          Type   Description\n"
      "------------- ------ ----------------------------------------------------------------------------------\n"
      "System        string \"GPS\", \"GLONASS\", \"Galileo\", \"BeiDou\", \"SBAS\", \"QZSS\", \"NavIC\" or \"PULSAR\"\n"
      "SvId          int    The satellite's SV ID.\n"
      "Offset        double Change to satellite pseudorange in meter when ramp is at maximum. Range -1e7..+1e7\n"
      "StartTime     int    Elapsed time in seconds since start of simulation.\n"
      "HoldStartTime int    Elapsed time in seconds since start of simulation. HoldStartTime >= StartTime\n"
      "HoldStopTime  int    Elapsed time in seconds since start of simulation. HoldStopTime >= HoldStartTime\n"
      "StopTime      int    Elapsed time in seconds since start of simulation. StopTime >= HoldStopTime\n"
      "Id            string Unique identifier automatically set by simulator if empty string.\n"
      "                     The IDs pool is common between all system.";
    const char* const SetPseudorangeRampForSV::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(SetPseudorangeRampForSV);
    REGISTER_COMMAND_TO_FACTORY_IMPL(SetPseudorangeRampForSV);


    SetPseudorangeRampForSV::SetPseudorangeRampForSV()
      : CommandBase(CmdName, TargetId)
    {}

    SetPseudorangeRampForSV::SetPseudorangeRampForSV(const std::string& system, int svId, double offset, int startTime, int holdStartTime, int holdStopTime, int stopTime, const std::string& id)
      : CommandBase(CmdName, TargetId)
    {

      setSystem(system);
      setSvId(svId);
      setOffset(offset);
      setStartTime(startTime);
      setHoldStartTime(holdStartTime);
      setHoldStopTime(holdStopTime);
      setStopTime(stopTime);
      setId(id);
    }

    SetPseudorangeRampForSVPtr SetPseudorangeRampForSV::create(const std::string& system, int svId, double offset, int startTime, int holdStartTime, int holdStopTime, int stopTime, const std::string& id)
    {
      return std::make_shared<SetPseudorangeRampForSV>(system, svId, offset, startTime, holdStartTime, holdStopTime, stopTime, id);
    }

    SetPseudorangeRampForSVPtr SetPseudorangeRampForSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetPseudorangeRampForSV>(ptr);
    }

    bool SetPseudorangeRampForSV::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["System"])
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<double>::is_valid(m_values["Offset"])
          && parse_json<int>::is_valid(m_values["StartTime"])
          && parse_json<int>::is_valid(m_values["HoldStartTime"])
          && parse_json<int>::is_valid(m_values["HoldStopTime"])
          && parse_json<int>::is_valid(m_values["StopTime"])
          && parse_json<std::string>::is_valid(m_values["Id"])
        ;

    }

    std::string SetPseudorangeRampForSV::documentation() const { return Documentation; }

    const std::vector<std::string>& SetPseudorangeRampForSV::fieldNames() const 
    { 
      static const std::vector<std::string> names {"System", "SvId", "Offset", "StartTime", "HoldStartTime", "HoldStopTime", "StopTime", "Id"}; 
      return names; 
    }


    int SetPseudorangeRampForSV::executePermission() const
    {
      return EXECUTE_IF_SIMULATING | EXECUTE_IF_IDLE;
    }


    std::string SetPseudorangeRampForSV::system() const
    {
      return parse_json<std::string>::parse(m_values["System"]);
    }

    void SetPseudorangeRampForSV::setSystem(const std::string& system)
    {
      m_values.AddMember("System", parse_json<std::string>::format(system, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int SetPseudorangeRampForSV::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void SetPseudorangeRampForSV::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double SetPseudorangeRampForSV::offset() const
    {
      return parse_json<double>::parse(m_values["Offset"]);
    }

    void SetPseudorangeRampForSV::setOffset(double offset)
    {
      m_values.AddMember("Offset", parse_json<double>::format(offset, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int SetPseudorangeRampForSV::startTime() const
    {
      return parse_json<int>::parse(m_values["StartTime"]);
    }

    void SetPseudorangeRampForSV::setStartTime(int startTime)
    {
      m_values.AddMember("StartTime", parse_json<int>::format(startTime, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int SetPseudorangeRampForSV::holdStartTime() const
    {
      return parse_json<int>::parse(m_values["HoldStartTime"]);
    }

    void SetPseudorangeRampForSV::setHoldStartTime(int holdStartTime)
    {
      m_values.AddMember("HoldStartTime", parse_json<int>::format(holdStartTime, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int SetPseudorangeRampForSV::holdStopTime() const
    {
      return parse_json<int>::parse(m_values["HoldStopTime"]);
    }

    void SetPseudorangeRampForSV::setHoldStopTime(int holdStopTime)
    {
      m_values.AddMember("HoldStopTime", parse_json<int>::format(holdStopTime, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int SetPseudorangeRampForSV::stopTime() const
    {
      return parse_json<int>::parse(m_values["StopTime"]);
    }

    void SetPseudorangeRampForSV::setStopTime(int stopTime)
    {
      m_values.AddMember("StopTime", parse_json<int>::format(stopTime, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string SetPseudorangeRampForSV::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void SetPseudorangeRampForSV::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
