#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetSatellitePower
///
#include "gen/SetSatellitePower.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetSatellitePower::CmdName = "SetSatellitePower";
    const char* const SetSatellitePower::Documentation = "Please note the command SetSatellitePower is deprecated since 21.3. You may use SetPowerForSV.\n\nSet power offset for specified satellite PRN. Use PRN 0 to set power for all satellites.";

    REGISTER_COMMAND_FACTORY(SetSatellitePower);


    SetSatellitePower::SetSatellitePower()
      : CommandBase(CmdName)
    {}

    SetSatellitePower::SetSatellitePower(const std::string& system, int prn, double powerOffset, bool otherSatsFollow)
      : CommandBase(CmdName)
    {

      setSystem(system);
      setPrn(prn);
      setPowerOffset(powerOffset);
      setOtherSatsFollow(otherSatsFollow);
    }


    SetSatellitePowerPtr SetSatellitePower::create(const std::string& system, int prn, double powerOffset, bool otherSatsFollow)
    {
      return SetSatellitePowerPtr(new SetSatellitePower(system, prn, powerOffset, otherSatsFollow));
    }

    SetSatellitePowerPtr SetSatellitePower::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetSatellitePower>(ptr);
    }

    bool SetSatellitePower::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["System"])
          && parse_json<int>::is_valid(m_values["Prn"])
          && parse_json<double>::is_valid(m_values["PowerOffset"])
          && parse_json<bool>::is_valid(m_values["OtherSatsFollow"])
        ;

    }

    std::string SetSatellitePower::documentation() const { return Documentation; }


    int SetSatellitePower::executePermission() const
    {
      return EXECUTE_IF_SIMULATING;
    }


    std::string SetSatellitePower::system() const
    {
      return parse_json<std::string>::parse(m_values["System"]);
    }

    void SetSatellitePower::setSystem(const std::string& system)
    {
      m_values.AddMember("System", parse_json<std::string>::format(system, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int SetSatellitePower::prn() const
    {
      return parse_json<int>::parse(m_values["Prn"]);
    }

    void SetSatellitePower::setPrn(int prn)
    {
      m_values.AddMember("Prn", parse_json<int>::format(prn, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double SetSatellitePower::powerOffset() const
    {
      return parse_json<double>::parse(m_values["PowerOffset"]);
    }

    void SetSatellitePower::setPowerOffset(double powerOffset)
    {
      m_values.AddMember("PowerOffset", parse_json<double>::format(powerOffset, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool SetSatellitePower::otherSatsFollow() const
    {
      return parse_json<bool>::parse(m_values["OtherSatsFollow"]);
    }

    void SetSatellitePower::setOtherSatsFollow(bool otherSatsFollow)
    {
      m_values.AddMember("OtherSatsFollow", parse_json<bool>::format(otherSatsFollow, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
