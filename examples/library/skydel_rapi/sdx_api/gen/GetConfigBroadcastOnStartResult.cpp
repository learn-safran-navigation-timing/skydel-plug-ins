#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetConfigBroadcastOnStartResult
///
#include "gen/GetConfigBroadcastOnStartResult.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetConfigBroadcastOnStartResult::CmdName = "GetConfigBroadcastOnStartResult";
    const char* const GetConfigBroadcastOnStartResult::Documentation = "Result of GetConfigBroadcastOnStart.";

    REGISTER_COMMAND_RESULT_FACTORY(GetConfigBroadcastOnStartResult);


    GetConfigBroadcastOnStartResult::GetConfigBroadcastOnStartResult()
      : CommandResult(CmdName)
    {}

    GetConfigBroadcastOnStartResult::GetConfigBroadcastOnStartResult(CommandBasePtr relatedCommand, bool broadcastOnStart)
      : CommandResult(CmdName, relatedCommand)
    {

      setBroadcastOnStart(broadcastOnStart);
    }


    GetConfigBroadcastOnStartResultPtr GetConfigBroadcastOnStartResult::create(CommandBasePtr relatedCommand, bool broadcastOnStart)
    {
      return GetConfigBroadcastOnStartResultPtr(new GetConfigBroadcastOnStartResult(relatedCommand, broadcastOnStart));
    }

    GetConfigBroadcastOnStartResultPtr GetConfigBroadcastOnStartResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetConfigBroadcastOnStartResult>(ptr);
    }

    bool GetConfigBroadcastOnStartResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<bool>::is_valid(m_values["BroadcastOnStart"])
        ;

    }

    std::string GetConfigBroadcastOnStartResult::documentation() const { return Documentation; }


    bool GetConfigBroadcastOnStartResult::broadcastOnStart() const
    {
      return parse_json<bool>::parse(m_values["BroadcastOnStart"]);
    }

    void GetConfigBroadcastOnStartResult::setBroadcastOnStart(bool broadcastOnStart)
    {
      m_values.AddMember("BroadcastOnStart", parse_json<bool>::format(broadcastOnStart, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
