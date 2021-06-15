#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetGpsCodePrn
///
#include "gen/GetGpsCodePrn.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetGpsCodePrn::CmdName = "GetGpsCodePrn";
    const char* const GetGpsCodePrn::Documentation = "Please note the command GetGpsCodePrn is deprecated since 21.3. You may use GetPrnOfSVID.\n\nGet the transmitted PRN code for the specified satellite";

    REGISTER_COMMAND_FACTORY(GetGpsCodePrn);


    GetGpsCodePrn::GetGpsCodePrn()
      : CommandBase(CmdName)
    {}

    GetGpsCodePrn::GetGpsCodePrn(int satPrn)
      : CommandBase(CmdName)
    {

      setSatPrn(satPrn);
    }


    GetGpsCodePrnPtr GetGpsCodePrn::create(int satPrn)
    {
      return GetGpsCodePrnPtr(new GetGpsCodePrn(satPrn));
    }

    GetGpsCodePrnPtr GetGpsCodePrn::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetGpsCodePrn>(ptr);
    }

    bool GetGpsCodePrn::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["SatPrn"])
        ;

    }

    std::string GetGpsCodePrn::documentation() const { return Documentation; }


    int GetGpsCodePrn::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    int GetGpsCodePrn::satPrn() const
    {
      return parse_json<int>::parse(m_values["SatPrn"]);
    }

    void GetGpsCodePrn::setSatPrn(int satPrn)
    {
      m_values.AddMember("SatPrn", parse_json<int>::format(satPrn, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
