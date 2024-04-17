
#include "SetPseudorangeNoiseOffsetForSV.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetPseudorangeNoiseOffsetForSV
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetPseudorangeNoiseOffsetForSV::CmdName = "SetPseudorangeNoiseOffsetForSV";
    const char* const SetPseudorangeNoiseOffsetForSV::Documentation = "Set the satellite pseudorange noise constant offset.\n"
      "\n"
      "Name    Type   Description\n"
      "------- ------ --------------------------------------------------------------------------\n"
      "System  string \"GPS\", \"GLONASS\", \"Galileo\", \"BeiDou\", \"SBAS\", \"QZSS\", \"NavIC\" or \"PULSAR\"\n"
      "SvId    int    Satellite SV ID.\n"
      "Enabled bool   If true, the offset is enabled (applied)\n"
      "Offset  double The constant offset in metters";
    const char* const SetPseudorangeNoiseOffsetForSV::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(SetPseudorangeNoiseOffsetForSV);
    REGISTER_COMMAND_TO_FACTORY_IMPL(SetPseudorangeNoiseOffsetForSV);


    SetPseudorangeNoiseOffsetForSV::SetPseudorangeNoiseOffsetForSV()
      : CommandBase(CmdName, TargetId)
    {}

    SetPseudorangeNoiseOffsetForSV::SetPseudorangeNoiseOffsetForSV(const std::string& system, int svId, bool enabled, double offset)
      : CommandBase(CmdName, TargetId)
    {

      setSystem(system);
      setSvId(svId);
      setEnabled(enabled);
      setOffset(offset);
    }

    SetPseudorangeNoiseOffsetForSVPtr SetPseudorangeNoiseOffsetForSV::create(const std::string& system, int svId, bool enabled, double offset)
    {
      return std::make_shared<SetPseudorangeNoiseOffsetForSV>(system, svId, enabled, offset);
    }

    SetPseudorangeNoiseOffsetForSVPtr SetPseudorangeNoiseOffsetForSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetPseudorangeNoiseOffsetForSV>(ptr);
    }

    bool SetPseudorangeNoiseOffsetForSV::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["System"])
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<bool>::is_valid(m_values["Enabled"])
          && parse_json<double>::is_valid(m_values["Offset"])
        ;

    }

    std::string SetPseudorangeNoiseOffsetForSV::documentation() const { return Documentation; }

    const std::vector<std::string>& SetPseudorangeNoiseOffsetForSV::fieldNames() const 
    { 
      static const std::vector<std::string> names {"System", "SvId", "Enabled", "Offset"}; 
      return names; 
    }


    int SetPseudorangeNoiseOffsetForSV::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string SetPseudorangeNoiseOffsetForSV::system() const
    {
      return parse_json<std::string>::parse(m_values["System"]);
    }

    void SetPseudorangeNoiseOffsetForSV::setSystem(const std::string& system)
    {
      m_values.AddMember("System", parse_json<std::string>::format(system, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int SetPseudorangeNoiseOffsetForSV::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void SetPseudorangeNoiseOffsetForSV::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool SetPseudorangeNoiseOffsetForSV::enabled() const
    {
      return parse_json<bool>::parse(m_values["Enabled"]);
    }

    void SetPseudorangeNoiseOffsetForSV::setEnabled(bool enabled)
    {
      m_values.AddMember("Enabled", parse_json<bool>::format(enabled, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double SetPseudorangeNoiseOffsetForSV::offset() const
    {
      return parse_json<double>::parse(m_values["Offset"]);
    }

    void SetPseudorangeNoiseOffsetForSV::setOffset(double offset)
    {
      m_values.AddMember("Offset", parse_json<double>::format(offset, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
