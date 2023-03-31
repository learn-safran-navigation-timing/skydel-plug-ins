#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetGpsSatelliteAntiSpoofingFlag
///
#include "gen/GetGpsSatelliteAntiSpoofingFlag.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetGpsSatelliteAntiSpoofingFlag::CmdName = "GetGpsSatelliteAntiSpoofingFlag";
    const char* const GetGpsSatelliteAntiSpoofingFlag::Documentation = "Please note the command GetGpsSatelliteAntiSpoofingFlag is deprecated since 21.3. You may use GetGpsAntiSpoofingFlagForSV.\n\nGet GPS Anti-Spoofing Flag";

    REGISTER_COMMAND_FACTORY(GetGpsSatelliteAntiSpoofingFlag);


    GetGpsSatelliteAntiSpoofingFlag::GetGpsSatelliteAntiSpoofingFlag()
      : CommandBase(CmdName)
    {}

    GetGpsSatelliteAntiSpoofingFlag::GetGpsSatelliteAntiSpoofingFlag(int prn)
      : CommandBase(CmdName)
    {

      setPrn(prn);
    }


    GetGpsSatelliteAntiSpoofingFlagPtr GetGpsSatelliteAntiSpoofingFlag::create(int prn)
    {
      return GetGpsSatelliteAntiSpoofingFlagPtr(new GetGpsSatelliteAntiSpoofingFlag(prn));
    }

    GetGpsSatelliteAntiSpoofingFlagPtr GetGpsSatelliteAntiSpoofingFlag::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetGpsSatelliteAntiSpoofingFlag>(ptr);
    }

    bool GetGpsSatelliteAntiSpoofingFlag::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["Prn"])
        ;

    }

    std::string GetGpsSatelliteAntiSpoofingFlag::documentation() const { return Documentation; }


    int GetGpsSatelliteAntiSpoofingFlag::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    int GetGpsSatelliteAntiSpoofingFlag::prn() const
    {
      return parse_json<int>::parse(m_values["Prn"]);
    }

    void GetGpsSatelliteAntiSpoofingFlag::setPrn(int prn)
    {
      m_values.AddMember("Prn", parse_json<int>::format(prn, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
