#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetGpsCodePrn
///
#include "gen/SetGpsCodePrn.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetGpsCodePrn::CmdName = "SetGpsCodePrn";
    const char* const SetGpsCodePrn::Documentation = "Please note the command SetGpsCodePrn is deprecated since 21.3. You may use SetPrnOfSVID.\n\nSet the transmitted PRN code for the specified satellite";

    REGISTER_COMMAND_FACTORY(SetGpsCodePrn);


    SetGpsCodePrn::SetGpsCodePrn()
      : CommandBase(CmdName)
    {}

    SetGpsCodePrn::SetGpsCodePrn(int satPrn, int transmittedPrn)
      : CommandBase(CmdName)
    {

      setSatPrn(satPrn);
      setTransmittedPrn(transmittedPrn);
    }


    SetGpsCodePrnPtr SetGpsCodePrn::create(int satPrn, int transmittedPrn)
    {
      return SetGpsCodePrnPtr(new SetGpsCodePrn(satPrn, transmittedPrn));
    }

    SetGpsCodePrnPtr SetGpsCodePrn::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetGpsCodePrn>(ptr);
    }

    bool SetGpsCodePrn::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["SatPrn"])
          && parse_json<int>::is_valid(m_values["TransmittedPrn"])
        ;

    }

    std::string SetGpsCodePrn::documentation() const { return Documentation; }


    int SetGpsCodePrn::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    int SetGpsCodePrn::satPrn() const
    {
      return parse_json<int>::parse(m_values["SatPrn"]);
    }

    void SetGpsCodePrn::setSatPrn(int satPrn)
    {
      m_values.AddMember("SatPrn", parse_json<int>::format(satPrn, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int SetGpsCodePrn::transmittedPrn() const
    {
      return parse_json<int>::parse(m_values["TransmittedPrn"]);
    }

    void SetGpsCodePrn::setTransmittedPrn(int transmittedPrn)
    {
      m_values.AddMember("TransmittedPrn", parse_json<int>::format(transmittedPrn, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
