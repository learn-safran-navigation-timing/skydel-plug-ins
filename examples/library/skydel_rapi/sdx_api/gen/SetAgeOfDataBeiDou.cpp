#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetAgeOfDataBeiDou
///
#include "gen/SetAgeOfDataBeiDou.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetAgeOfDataBeiDou::CmdName = "SetAgeOfDataBeiDou";
    const char* const SetAgeOfDataBeiDou::Documentation = "Set BeiDou Age of data, Ephemeris (AODE) and Age of data, Clock (AODC)";

    REGISTER_COMMAND_FACTORY(SetAgeOfDataBeiDou);


    SetAgeOfDataBeiDou::SetAgeOfDataBeiDou()
      : CommandBase(CmdName)
    {}

    SetAgeOfDataBeiDou::SetAgeOfDataBeiDou(int clock, int ephemeris, const Sdx::optional<bool>& overrideRinex)
      : CommandBase(CmdName)
    {

      setClock(clock);
      setEphemeris(ephemeris);
      setOverrideRinex(overrideRinex);
    }


    SetAgeOfDataBeiDouPtr SetAgeOfDataBeiDou::create(int clock, int ephemeris, const Sdx::optional<bool>& overrideRinex)
    {
      return std::make_shared<SetAgeOfDataBeiDou>(clock, ephemeris, overrideRinex);
    }

    SetAgeOfDataBeiDouPtr SetAgeOfDataBeiDou::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetAgeOfDataBeiDou>(ptr);
    }

    bool SetAgeOfDataBeiDou::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["Clock"])
          && parse_json<int>::is_valid(m_values["Ephemeris"])
          && parse_json<Sdx::optional<bool>>::is_valid(m_values["OverrideRinex"])
        ;

    }

    std::string SetAgeOfDataBeiDou::documentation() const { return Documentation; }


    int SetAgeOfDataBeiDou::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    int SetAgeOfDataBeiDou::clock() const
    {
      return parse_json<int>::parse(m_values["Clock"]);
    }

    void SetAgeOfDataBeiDou::setClock(int clock)
    {
      m_values.AddMember("Clock", parse_json<int>::format(clock, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int SetAgeOfDataBeiDou::ephemeris() const
    {
      return parse_json<int>::parse(m_values["Ephemeris"]);
    }

    void SetAgeOfDataBeiDou::setEphemeris(int ephemeris)
    {
      m_values.AddMember("Ephemeris", parse_json<int>::format(ephemeris, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::optional<bool> SetAgeOfDataBeiDou::overrideRinex() const
    {
      return parse_json<Sdx::optional<bool>>::parse(m_values["OverrideRinex"]);
    }

    void SetAgeOfDataBeiDou::setOverrideRinex(const Sdx::optional<bool>& overrideRinex)
    {
      m_values.AddMember("OverrideRinex", parse_json<Sdx::optional<bool>>::format(overrideRinex, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
