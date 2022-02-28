#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetPowerOffsetResult
///
#include "gen/GetPowerOffsetResult.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetPowerOffsetResult::CmdName = "GetPowerOffsetResult";
    const char* const GetPowerOffsetResult::Documentation = "Result of GetPowerOffset.";

    REGISTER_COMMAND_RESULT_FACTORY(GetPowerOffsetResult);


    GetPowerOffsetResult::GetPowerOffsetResult()
      : CommandResult(CmdName)
    {}

    GetPowerOffsetResult::GetPowerOffsetResult(CommandBasePtr relatedCommand, const std::string& signal, double offset)
      : CommandResult(CmdName, relatedCommand)
    {

      setSignal(signal);
      setOffset(offset);
    }


    GetPowerOffsetResultPtr GetPowerOffsetResult::create(CommandBasePtr relatedCommand, const std::string& signal, double offset)
    {
      return std::make_shared<GetPowerOffsetResult>(relatedCommand, signal, offset);
    }

    GetPowerOffsetResultPtr GetPowerOffsetResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetPowerOffsetResult>(ptr);
    }

    bool GetPowerOffsetResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Signal"])
          && parse_json<double>::is_valid(m_values["Offset"])
        ;

    }

    std::string GetPowerOffsetResult::documentation() const { return Documentation; }


    std::string GetPowerOffsetResult::signal() const
    {
      return parse_json<std::string>::parse(m_values["Signal"]);
    }

    void GetPowerOffsetResult::setSignal(const std::string& signal)
    {
      m_values.AddMember("Signal", parse_json<std::string>::format(signal, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double GetPowerOffsetResult::offset() const
    {
      return parse_json<double>::parse(m_values["Offset"]);
    }

    void GetPowerOffsetResult::setOffset(double offset)
    {
      m_values.AddMember("Offset", parse_json<double>::format(offset, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
