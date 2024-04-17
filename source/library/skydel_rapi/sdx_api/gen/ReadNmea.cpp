
#include "gen/ReadNmea.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of ReadNmea
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const ReadNmea::CmdName = "ReadNmea";
    const char* const ReadNmea::Documentation = "Get the next NMEA sentence.";

    REGISTER_COMMAND_TO_FACTORY_DECL(ReadNmea);
    REGISTER_COMMAND_TO_FACTORY_IMPL(ReadNmea);


    ReadNmea::ReadNmea()
      : CommandBase(CmdName)
    {

    }

    ReadNmeaPtr ReadNmea::create()
    {
      return std::make_shared<ReadNmea>();
    }

    ReadNmeaPtr ReadNmea::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<ReadNmea>(ptr);
    }

    bool ReadNmea::isValid() const
    {
      
        return m_values.IsObject()
        ;

    }

    std::string ReadNmea::documentation() const { return Documentation; }


    int ReadNmea::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }

  }
}
