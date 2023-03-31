#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetSbasEphemerisParams
///
#include "gen/SetSbasEphemerisParams.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetSbasEphemerisParams::CmdName = "SetSbasEphemerisParams";
    const char* const SetSbasEphemerisParams::Documentation = "Please note the command SetSbasEphemerisParams is deprecated since 21.3. You may use SetSbasEphParamForSV.\n\nSet parameters for a SBAS satellite ephemeris (runtime modification only available for health parameter)";

    REGISTER_COMMAND_FACTORY(SetSbasEphemerisParams);


    SetSbasEphemerisParams::SetSbasEphemerisParams()
      : CommandBase(CmdName)
    {}

    SetSbasEphemerisParams::SetSbasEphemerisParams(int prn, const std::vector<Sdx::StringPair>& parameters)
      : CommandBase(CmdName)
    {

      setPrn(prn);
      setParameters(parameters);
    }


    SetSbasEphemerisParamsPtr SetSbasEphemerisParams::create(int prn, const std::vector<Sdx::StringPair>& parameters)
    {
      return SetSbasEphemerisParamsPtr(new SetSbasEphemerisParams(prn, parameters));
    }

    SetSbasEphemerisParamsPtr SetSbasEphemerisParams::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetSbasEphemerisParams>(ptr);
    }

    bool SetSbasEphemerisParams::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["Prn"])
          && parse_json<std::vector<Sdx::StringPair>>::is_valid(m_values["Parameters"])
        ;

    }

    std::string SetSbasEphemerisParams::documentation() const { return Documentation; }


    int SetSbasEphemerisParams::executePermission() const
    {
      return EXECUTE_IF_IDLE | EXECUTE_IF_SIMULATING;
    }


    int SetSbasEphemerisParams::prn() const
    {
      return parse_json<int>::parse(m_values["Prn"]);
    }

    void SetSbasEphemerisParams::setPrn(int prn)
    {
      m_values.AddMember("Prn", parse_json<int>::format(prn, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::vector<Sdx::StringPair> SetSbasEphemerisParams::parameters() const
    {
      return parse_json<std::vector<Sdx::StringPair>>::parse(m_values["Parameters"]);
    }

    void SetSbasEphemerisParams::setParameters(const std::vector<Sdx::StringPair>& parameters)
    {
      m_values.AddMember("Parameters", parse_json<std::vector<Sdx::StringPair>>::format(parameters, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
