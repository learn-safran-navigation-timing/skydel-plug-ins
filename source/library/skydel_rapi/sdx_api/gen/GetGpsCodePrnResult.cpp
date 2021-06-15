#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetGpsCodePrnResult
///
#include "gen/GetGpsCodePrnResult.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetGpsCodePrnResult::CmdName = "GetGpsCodePrnResult";
    const char* const GetGpsCodePrnResult::Documentation = "Result of GetGpsCodePrn.";

    REGISTER_COMMAND_RESULT_FACTORY(GetGpsCodePrnResult);


    GetGpsCodePrnResult::GetGpsCodePrnResult()
      : CommandResult(CmdName)
    {}

    GetGpsCodePrnResult::GetGpsCodePrnResult(CommandBasePtr relatedCommand, int satPrn, int transmittedPrn)
      : CommandResult(CmdName, relatedCommand)
    {

      setSatPrn(satPrn);
      setTransmittedPrn(transmittedPrn);
    }


    GetGpsCodePrnResultPtr GetGpsCodePrnResult::create(CommandBasePtr relatedCommand, int satPrn, int transmittedPrn)
    {
      return GetGpsCodePrnResultPtr(new GetGpsCodePrnResult(relatedCommand, satPrn, transmittedPrn));
    }

    GetGpsCodePrnResultPtr GetGpsCodePrnResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetGpsCodePrnResult>(ptr);
    }

    bool GetGpsCodePrnResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["SatPrn"])
          && parse_json<int>::is_valid(m_values["TransmittedPrn"])
        ;

    }

    std::string GetGpsCodePrnResult::documentation() const { return Documentation; }


    int GetGpsCodePrnResult::satPrn() const
    {
      return parse_json<int>::parse(m_values["SatPrn"]);
    }

    void GetGpsCodePrnResult::setSatPrn(int satPrn)
    {
      m_values.AddMember("SatPrn", parse_json<int>::format(satPrn, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetGpsCodePrnResult::transmittedPrn() const
    {
      return parse_json<int>::parse(m_values["TransmittedPrn"]);
    }

    void GetGpsCodePrnResult::setTransmittedPrn(int transmittedPrn)
    {
      m_values.AddMember("TransmittedPrn", parse_json<int>::format(transmittedPrn, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
