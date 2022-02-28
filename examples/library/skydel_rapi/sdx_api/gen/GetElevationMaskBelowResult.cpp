#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetElevationMaskBelowResult
///
#include "gen/GetElevationMaskBelowResult.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetElevationMaskBelowResult::CmdName = "GetElevationMaskBelowResult";
    const char* const GetElevationMaskBelowResult::Documentation = "Result of GetElevationMaskBelow.";

    REGISTER_COMMAND_RESULT_FACTORY(GetElevationMaskBelowResult);


    GetElevationMaskBelowResult::GetElevationMaskBelowResult()
      : CommandResult(CmdName)
    {}

    GetElevationMaskBelowResult::GetElevationMaskBelowResult(CommandBasePtr relatedCommand, double angle)
      : CommandResult(CmdName, relatedCommand)
    {

      setAngle(angle);
    }


    GetElevationMaskBelowResultPtr GetElevationMaskBelowResult::create(CommandBasePtr relatedCommand, double angle)
    {
      return GetElevationMaskBelowResultPtr(new GetElevationMaskBelowResult(relatedCommand, angle));
    }

    GetElevationMaskBelowResultPtr GetElevationMaskBelowResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetElevationMaskBelowResult>(ptr);
    }

    bool GetElevationMaskBelowResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<double>::is_valid(m_values["Angle"])
        ;

    }

    std::string GetElevationMaskBelowResult::documentation() const { return Documentation; }


    double GetElevationMaskBelowResult::angle() const
    {
      return parse_json<double>::parse(m_values["Angle"]);
    }

    void GetElevationMaskBelowResult::setAngle(double angle)
    {
      m_values.AddMember("Angle", parse_json<double>::format(angle, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
