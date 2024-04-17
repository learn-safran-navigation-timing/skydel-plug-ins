
#include "gen/ReadNmeaResult.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of ReadNmeaResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const ReadNmeaResult::CmdName = "ReadNmeaResult";
    const char* const ReadNmeaResult::Documentation = "Result of ReadNmea.";

    REGISTER_COMMAND_TO_FACTORY_IMPL(ReadNmeaResult);


    ReadNmeaResult::ReadNmeaResult()
      : CommandResult(CmdName)
    {}

    ReadNmeaResult::ReadNmeaResult(const std::string& nmeaMessage)
      : CommandResult(CmdName)
    {

      setNmeaMessage(nmeaMessage);
    }

    ReadNmeaResult::ReadNmeaResult(CommandBasePtr relatedCommand, const std::string& nmeaMessage)
      : CommandResult(CmdName, relatedCommand)
    {

      setNmeaMessage(nmeaMessage);
    }


    ReadNmeaResultPtr ReadNmeaResult::create(const std::string& nmeaMessage)
    {
      return std::make_shared<ReadNmeaResult>(nmeaMessage);
    }

    ReadNmeaResultPtr ReadNmeaResult::create(CommandBasePtr relatedCommand, const std::string& nmeaMessage)
    {
      return std::make_shared<ReadNmeaResult>(relatedCommand, nmeaMessage);
    }

    ReadNmeaResultPtr ReadNmeaResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<ReadNmeaResult>(ptr);
    }

    bool ReadNmeaResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["NmeaMessage"])
        ;

    }

    std::string ReadNmeaResult::documentation() const { return Documentation; }


    std::string ReadNmeaResult::nmeaMessage() const
    {
      return parse_json<std::string>::parse(m_values["NmeaMessage"]);
    }

    void ReadNmeaResult::setNmeaMessage(const std::string& nmeaMessage)
    {
      m_values.AddMember("NmeaMessage", parse_json<std::string>::format(nmeaMessage, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
