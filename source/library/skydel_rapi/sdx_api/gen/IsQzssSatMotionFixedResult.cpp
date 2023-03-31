#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of IsQzssSatMotionFixedResult
///
#include "gen/IsQzssSatMotionFixedResult.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const IsQzssSatMotionFixedResult::CmdName = "IsQzssSatMotionFixedResult";
    const char* const IsQzssSatMotionFixedResult::Documentation = "Result of IsQzssSatMotionFixed.";

    REGISTER_COMMAND_RESULT_FACTORY(IsQzssSatMotionFixedResult);


    IsQzssSatMotionFixedResult::IsQzssSatMotionFixedResult()
      : CommandResult(CmdName)
    {}

    IsQzssSatMotionFixedResult::IsQzssSatMotionFixedResult(CommandBasePtr relatedCommand, int svId, bool isFixed)
      : CommandResult(CmdName, relatedCommand)
    {

      setSvId(svId);
      setIsFixed(isFixed);
    }


    IsQzssSatMotionFixedResultPtr IsQzssSatMotionFixedResult::create(CommandBasePtr relatedCommand, int svId, bool isFixed)
    {
      return IsQzssSatMotionFixedResultPtr(new IsQzssSatMotionFixedResult(relatedCommand, svId, isFixed));
    }

    IsQzssSatMotionFixedResultPtr IsQzssSatMotionFixedResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<IsQzssSatMotionFixedResult>(ptr);
    }

    bool IsQzssSatMotionFixedResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<bool>::is_valid(m_values["IsFixed"])
        ;

    }

    std::string IsQzssSatMotionFixedResult::documentation() const { return Documentation; }


    int IsQzssSatMotionFixedResult::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void IsQzssSatMotionFixedResult::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool IsQzssSatMotionFixedResult::isFixed() const
    {
      return parse_json<bool>::parse(m_values["IsFixed"]);
    }

    void IsQzssSatMotionFixedResult::setIsFixed(bool isFixed)
    {
      m_values.AddMember("IsFixed", parse_json<bool>::format(isFixed, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
