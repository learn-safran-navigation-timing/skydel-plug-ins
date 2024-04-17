
#include "gen/GetTimingSystemResult.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetTimingSystemResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetTimingSystemResult::CmdName = "GetTimingSystemResult";
    const char* const GetTimingSystemResult::Documentation = "Result of GetTimingSystem.";

    REGISTER_COMMAND_TO_FACTORY_IMPL(GetTimingSystemResult);


    GetTimingSystemResult::GetTimingSystemResult()
      : CommandResult(CmdName)
    {}

    GetTimingSystemResult::GetTimingSystemResult(const std::string& system)
      : CommandResult(CmdName)
    {

      setSystem(system);
    }

    GetTimingSystemResult::GetTimingSystemResult(CommandBasePtr relatedCommand, const std::string& system)
      : CommandResult(CmdName, relatedCommand)
    {

      setSystem(system);
    }


    GetTimingSystemResultPtr GetTimingSystemResult::create(const std::string& system)
    {
      return std::make_shared<GetTimingSystemResult>(system);
    }

    GetTimingSystemResultPtr GetTimingSystemResult::create(CommandBasePtr relatedCommand, const std::string& system)
    {
      return std::make_shared<GetTimingSystemResult>(relatedCommand, system);
    }

    GetTimingSystemResultPtr GetTimingSystemResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetTimingSystemResult>(ptr);
    }

    bool GetTimingSystemResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["System"])
        ;

    }

    std::string GetTimingSystemResult::documentation() const { return Documentation; }


    std::string GetTimingSystemResult::system() const
    {
      return parse_json<std::string>::parse(m_values["System"]);
    }

    void GetTimingSystemResult::setSystem(const std::string& system)
    {
      m_values.AddMember("System", parse_json<std::string>::format(system, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
