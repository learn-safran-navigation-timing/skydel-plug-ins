#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of VersionResult
///
#include "gen/VersionResult.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const VersionResult::CmdName = "VersionResult";
    const char* const VersionResult::Documentation = "Result of GetVersion.";

    REGISTER_COMMAND_RESULT_FACTORY(VersionResult);


    VersionResult::VersionResult()
      : CommandResult(CmdName)
    {}

    VersionResult::VersionResult(CommandBasePtr relatedCommand, const std::string& version)
      : CommandResult(CmdName, relatedCommand)
    {

      setVersion(version);
    }


    VersionResultPtr VersionResult::create(CommandBasePtr relatedCommand, const std::string& version)
    {
      return std::make_shared<VersionResult>(relatedCommand, version);
    }

    VersionResultPtr VersionResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<VersionResult>(ptr);
    }

    bool VersionResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Version"])
        ;

    }

    std::string VersionResult::documentation() const { return Documentation; }


    std::string VersionResult::version() const
    {
      return parse_json<std::string>::parse(m_values["Version"]);
    }

    void VersionResult::setVersion(const std::string& version)
    {
      m_values.AddMember("Version", parse_json<std::string>::format(version, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
