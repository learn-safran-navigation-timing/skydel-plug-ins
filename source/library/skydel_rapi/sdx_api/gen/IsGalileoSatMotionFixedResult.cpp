#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of IsGalileoSatMotionFixedResult
///
#include "gen/IsGalileoSatMotionFixedResult.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const IsGalileoSatMotionFixedResult::CmdName = "IsGalileoSatMotionFixedResult";
    const char* const IsGalileoSatMotionFixedResult::Documentation = "Result of IsGalileoSatMotionFixed.";

    REGISTER_COMMAND_RESULT_FACTORY(IsGalileoSatMotionFixedResult);


    IsGalileoSatMotionFixedResult::IsGalileoSatMotionFixedResult()
      : CommandResult(CmdName)
    {}

    IsGalileoSatMotionFixedResult::IsGalileoSatMotionFixedResult(CommandBasePtr relatedCommand, int prn, bool isFixed)
      : CommandResult(CmdName, relatedCommand)
    {

      setPrn(prn);
      setIsFixed(isFixed);
    }


    IsGalileoSatMotionFixedResultPtr IsGalileoSatMotionFixedResult::create(CommandBasePtr relatedCommand, int prn, bool isFixed)
    {
      return IsGalileoSatMotionFixedResultPtr(new IsGalileoSatMotionFixedResult(relatedCommand, prn, isFixed));
    }

    IsGalileoSatMotionFixedResultPtr IsGalileoSatMotionFixedResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<IsGalileoSatMotionFixedResult>(ptr);
    }

    bool IsGalileoSatMotionFixedResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["Prn"])
          && parse_json<bool>::is_valid(m_values["IsFixed"])
        ;

    }

    std::string IsGalileoSatMotionFixedResult::documentation() const { return Documentation; }


    int IsGalileoSatMotionFixedResult::prn() const
    {
      return parse_json<int>::parse(m_values["Prn"]);
    }

    void IsGalileoSatMotionFixedResult::setPrn(int prn)
    {
      m_values.AddMember("Prn", parse_json<int>::format(prn, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool IsGalileoSatMotionFixedResult::isFixed() const
    {
      return parse_json<bool>::parse(m_values["IsFixed"]);
    }

    void IsGalileoSatMotionFixedResult::setIsFixed(bool isFixed)
    {
      m_values.AddMember("IsFixed", parse_json<bool>::format(isFixed, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
