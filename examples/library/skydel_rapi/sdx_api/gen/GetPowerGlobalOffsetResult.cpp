#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetPowerGlobalOffsetResult
///
#include "gen/GetPowerGlobalOffsetResult.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetPowerGlobalOffsetResult::CmdName = "GetPowerGlobalOffsetResult";
    const char* const GetPowerGlobalOffsetResult::Documentation = "Result of GetPowerGlobalOffset.";

    REGISTER_COMMAND_RESULT_FACTORY(GetPowerGlobalOffsetResult);


    GetPowerGlobalOffsetResult::GetPowerGlobalOffsetResult()
      : CommandResult(CmdName)
    {}

    GetPowerGlobalOffsetResult::GetPowerGlobalOffsetResult(CommandBasePtr relatedCommand, double offset)
      : CommandResult(CmdName, relatedCommand)
    {

      setOffset(offset);
    }


    GetPowerGlobalOffsetResultPtr GetPowerGlobalOffsetResult::create(CommandBasePtr relatedCommand, double offset)
    {
      return GetPowerGlobalOffsetResultPtr(new GetPowerGlobalOffsetResult(relatedCommand, offset));
    }

    GetPowerGlobalOffsetResultPtr GetPowerGlobalOffsetResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetPowerGlobalOffsetResult>(ptr);
    }

    bool GetPowerGlobalOffsetResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<double>::is_valid(m_values["Offset"])
        ;

    }

    std::string GetPowerGlobalOffsetResult::documentation() const { return Documentation; }


    double GetPowerGlobalOffsetResult::offset() const
    {
      return parse_json<double>::parse(m_values["Offset"]);
    }

    void GetPowerGlobalOffsetResult::setOffset(double offset)
    {
      m_values.AddMember("Offset", parse_json<double>::format(offset, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
