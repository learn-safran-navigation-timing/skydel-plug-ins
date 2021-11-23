#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetSatellitePseudorangeNoiseOffset
///
#include "gen/SetSatellitePseudorangeNoiseOffset.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetSatellitePseudorangeNoiseOffset::CmdName = "SetSatellitePseudorangeNoiseOffset";
    const char* const SetSatellitePseudorangeNoiseOffset::Documentation = "Please note the command SetSatellitePseudorangeNoiseOffset is deprecated since 21.3. You may use SetPseudorangeNoiseOffsetForSV.\n\nSet the satellite pseudorange noise constant offset.";

    REGISTER_COMMAND_FACTORY(SetSatellitePseudorangeNoiseOffset);


    SetSatellitePseudorangeNoiseOffset::SetSatellitePseudorangeNoiseOffset()
      : CommandBase(CmdName)
    {}

    SetSatellitePseudorangeNoiseOffset::SetSatellitePseudorangeNoiseOffset(const std::string& system, int prn, bool enabled, double offset)
      : CommandBase(CmdName)
    {

      setSystem(system);
      setPrn(prn);
      setEnabled(enabled);
      setOffset(offset);
    }


    SetSatellitePseudorangeNoiseOffsetPtr SetSatellitePseudorangeNoiseOffset::create(const std::string& system, int prn, bool enabled, double offset)
    {
      return SetSatellitePseudorangeNoiseOffsetPtr(new SetSatellitePseudorangeNoiseOffset(system, prn, enabled, offset));
    }

    SetSatellitePseudorangeNoiseOffsetPtr SetSatellitePseudorangeNoiseOffset::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetSatellitePseudorangeNoiseOffset>(ptr);
    }

    bool SetSatellitePseudorangeNoiseOffset::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["System"])
          && parse_json<int>::is_valid(m_values["Prn"])
          && parse_json<bool>::is_valid(m_values["Enabled"])
          && parse_json<double>::is_valid(m_values["Offset"])
        ;

    }

    std::string SetSatellitePseudorangeNoiseOffset::documentation() const { return Documentation; }


    int SetSatellitePseudorangeNoiseOffset::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string SetSatellitePseudorangeNoiseOffset::system() const
    {
      return parse_json<std::string>::parse(m_values["System"]);
    }

    void SetSatellitePseudorangeNoiseOffset::setSystem(const std::string& system)
    {
      m_values.AddMember("System", parse_json<std::string>::format(system, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int SetSatellitePseudorangeNoiseOffset::prn() const
    {
      return parse_json<int>::parse(m_values["Prn"]);
    }

    void SetSatellitePseudorangeNoiseOffset::setPrn(int prn)
    {
      m_values.AddMember("Prn", parse_json<int>::format(prn, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool SetSatellitePseudorangeNoiseOffset::enabled() const
    {
      return parse_json<bool>::parse(m_values["Enabled"]);
    }

    void SetSatellitePseudorangeNoiseOffset::setEnabled(bool enabled)
    {
      m_values.AddMember("Enabled", parse_json<bool>::format(enabled, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double SetSatellitePseudorangeNoiseOffset::offset() const
    {
      return parse_json<double>::parse(m_values["Offset"]);
    }

    void SetSatellitePseudorangeNoiseOffset::setOffset(double offset)
    {
      m_values.AddMember("Offset", parse_json<double>::format(offset, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
