#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetAlmanacInitialUploadTimeOffset
///
#include "gen/GetAlmanacInitialUploadTimeOffset.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetAlmanacInitialUploadTimeOffset::CmdName = "GetAlmanacInitialUploadTimeOffset";
    const char* const GetAlmanacInitialUploadTimeOffset::Documentation = "Get next almanac upload time relative to simulation start time.";

    REGISTER_COMMAND_FACTORY(GetAlmanacInitialUploadTimeOffset);


    GetAlmanacInitialUploadTimeOffset::GetAlmanacInitialUploadTimeOffset()
      : CommandBase(CmdName)
    {

    }


    GetAlmanacInitialUploadTimeOffsetPtr GetAlmanacInitialUploadTimeOffset::create()
    {
      return GetAlmanacInitialUploadTimeOffsetPtr(new GetAlmanacInitialUploadTimeOffset());
    }

    GetAlmanacInitialUploadTimeOffsetPtr GetAlmanacInitialUploadTimeOffset::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetAlmanacInitialUploadTimeOffset>(ptr);
    }

    bool GetAlmanacInitialUploadTimeOffset::isValid() const
    {
      
        return m_values.IsObject()
        ;

    }

    std::string GetAlmanacInitialUploadTimeOffset::documentation() const { return Documentation; }


    int GetAlmanacInitialUploadTimeOffset::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }

  }
}
