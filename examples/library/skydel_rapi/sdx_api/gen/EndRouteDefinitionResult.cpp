#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of EndRouteDefinitionResult
///
#include "gen/EndRouteDefinitionResult.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const EndRouteDefinitionResult::CmdName = "EndRouteDefinitionResult";
    const char* const EndRouteDefinitionResult::Documentation = "EndRouteDefinition Result with created route informations.";

    REGISTER_COMMAND_RESULT_FACTORY(EndRouteDefinitionResult);


    EndRouteDefinitionResult::EndRouteDefinitionResult()
      : CommandResult(CmdName)
    {}

    EndRouteDefinitionResult::EndRouteDefinitionResult(CommandBasePtr relatedCommand, int count)
      : CommandResult(CmdName, relatedCommand)
    {

      setCount(count);
    }


    EndRouteDefinitionResultPtr EndRouteDefinitionResult::create(CommandBasePtr relatedCommand, int count)
    {
      return EndRouteDefinitionResultPtr(new EndRouteDefinitionResult(relatedCommand, count));
    }

    EndRouteDefinitionResultPtr EndRouteDefinitionResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<EndRouteDefinitionResult>(ptr);
    }

    bool EndRouteDefinitionResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["Count"])
        ;

    }

    std::string EndRouteDefinitionResult::documentation() const { return Documentation; }


    int EndRouteDefinitionResult::count() const
    {
      return parse_json<int>::parse(m_values["Count"]);
    }

    void EndRouteDefinitionResult::setCount(int count)
    {
      m_values.AddMember("Count", parse_json<int>::format(count, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
