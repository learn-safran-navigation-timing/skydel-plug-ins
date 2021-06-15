#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of IsGpsSatMotionFixedResult
///
#include "gen/IsGpsSatMotionFixedResult.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const IsGpsSatMotionFixedResult::CmdName = "IsGpsSatMotionFixedResult";
    const char* const IsGpsSatMotionFixedResult::Documentation = "Result of IsGpsSatMotionFixed.";

    REGISTER_COMMAND_RESULT_FACTORY(IsGpsSatMotionFixedResult);


    IsGpsSatMotionFixedResult::IsGpsSatMotionFixedResult()
      : CommandResult(CmdName)
    {}

    IsGpsSatMotionFixedResult::IsGpsSatMotionFixedResult(CommandBasePtr relatedCommand, int prn, bool isFixed)
      : CommandResult(CmdName, relatedCommand)
    {

      setPrn(prn);
      setIsFixed(isFixed);
    }


    IsGpsSatMotionFixedResultPtr IsGpsSatMotionFixedResult::create(CommandBasePtr relatedCommand, int prn, bool isFixed)
    {
      return IsGpsSatMotionFixedResultPtr(new IsGpsSatMotionFixedResult(relatedCommand, prn, isFixed));
    }

    IsGpsSatMotionFixedResultPtr IsGpsSatMotionFixedResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<IsGpsSatMotionFixedResult>(ptr);
    }

    bool IsGpsSatMotionFixedResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["Prn"])
          && parse_json<bool>::is_valid(m_values["IsFixed"])
        ;

    }

    std::string IsGpsSatMotionFixedResult::documentation() const { return Documentation; }


    int IsGpsSatMotionFixedResult::prn() const
    {
      return parse_json<int>::parse(m_values["Prn"]);
    }

    void IsGpsSatMotionFixedResult::setPrn(int prn)
    {
      m_values.AddMember("Prn", parse_json<int>::format(prn, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool IsGpsSatMotionFixedResult::isFixed() const
    {
      return parse_json<bool>::parse(m_values["IsFixed"]);
    }

    void IsGpsSatMotionFixedResult::setIsFixed(bool isFixed)
    {
      m_values.AddMember("IsFixed", parse_json<bool>::format(isFixed, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
