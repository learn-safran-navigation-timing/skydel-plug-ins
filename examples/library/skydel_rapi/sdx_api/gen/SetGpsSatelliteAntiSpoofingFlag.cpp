#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetGpsSatelliteAntiSpoofingFlag
///
#include "gen/SetGpsSatelliteAntiSpoofingFlag.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetGpsSatelliteAntiSpoofingFlag::CmdName = "SetGpsSatelliteAntiSpoofingFlag";
    const char* const SetGpsSatelliteAntiSpoofingFlag::Documentation = "Please note the command SetGpsSatelliteAntiSpoofingFlag is deprecated since 21.3. You may use SetGpsAntiSpoofingFlagForSV.\n\nSet GPS Anti-Spoofing Flag";

    REGISTER_COMMAND_FACTORY(SetGpsSatelliteAntiSpoofingFlag);


    SetGpsSatelliteAntiSpoofingFlag::SetGpsSatelliteAntiSpoofingFlag()
      : CommandBase(CmdName)
    {}

    SetGpsSatelliteAntiSpoofingFlag::SetGpsSatelliteAntiSpoofingFlag(int prn, const Sdx::GpsASFlag& antiSpoofing)
      : CommandBase(CmdName)
    {

      setPrn(prn);
      setAntiSpoofing(antiSpoofing);
    }


    SetGpsSatelliteAntiSpoofingFlagPtr SetGpsSatelliteAntiSpoofingFlag::create(int prn, const Sdx::GpsASFlag& antiSpoofing)
    {
      return SetGpsSatelliteAntiSpoofingFlagPtr(new SetGpsSatelliteAntiSpoofingFlag(prn, antiSpoofing));
    }

    SetGpsSatelliteAntiSpoofingFlagPtr SetGpsSatelliteAntiSpoofingFlag::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetGpsSatelliteAntiSpoofingFlag>(ptr);
    }

    bool SetGpsSatelliteAntiSpoofingFlag::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["Prn"])
          && parse_json<Sdx::GpsASFlag>::is_valid(m_values["AntiSpoofing"])
        ;

    }

    std::string SetGpsSatelliteAntiSpoofingFlag::documentation() const { return Documentation; }


    int SetGpsSatelliteAntiSpoofingFlag::executePermission() const
    {
      return EXECUTE_IF_SIMULATING | EXECUTE_IF_IDLE;
    }


    int SetGpsSatelliteAntiSpoofingFlag::prn() const
    {
      return parse_json<int>::parse(m_values["Prn"]);
    }

    void SetGpsSatelliteAntiSpoofingFlag::setPrn(int prn)
    {
      m_values.AddMember("Prn", parse_json<int>::format(prn, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::GpsASFlag SetGpsSatelliteAntiSpoofingFlag::antiSpoofing() const
    {
      return parse_json<Sdx::GpsASFlag>::parse(m_values["AntiSpoofing"]);
    }

    void SetGpsSatelliteAntiSpoofingFlag::setAntiSpoofing(const Sdx::GpsASFlag& antiSpoofing)
    {
      m_values.AddMember("AntiSpoofing", parse_json<Sdx::GpsASFlag>::format(antiSpoofing, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
