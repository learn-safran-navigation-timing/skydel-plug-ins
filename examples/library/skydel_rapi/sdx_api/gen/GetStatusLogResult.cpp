#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetStatusLogResult
///
#include "gen/GetStatusLogResult.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetStatusLogResult::CmdName = "GetStatusLogResult";
    const char* const GetStatusLogResult::Documentation = "Result of GetStatusLog.";

    REGISTER_COMMAND_RESULT_FACTORY(GetStatusLogResult);


    GetStatusLogResult::GetStatusLogResult()
      : CommandResult(CmdName)
    {}

    GetStatusLogResult::GetStatusLogResult(CommandBasePtr relatedCommand, const std::vector<Sdx::LogRecord>& records)
      : CommandResult(CmdName, relatedCommand)
    {

      setRecords(records);
    }


    GetStatusLogResultPtr GetStatusLogResult::create(CommandBasePtr relatedCommand, const std::vector<Sdx::LogRecord>& records)
    {
      return GetStatusLogResultPtr(new GetStatusLogResult(relatedCommand, records));
    }

    GetStatusLogResultPtr GetStatusLogResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetStatusLogResult>(ptr);
    }

    bool GetStatusLogResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::vector<Sdx::LogRecord>>::is_valid(m_values["Records"])
        ;

    }

    std::string GetStatusLogResult::documentation() const { return Documentation; }


    std::vector<Sdx::LogRecord> GetStatusLogResult::records() const
    {
      return parse_json<std::vector<Sdx::LogRecord>>::parse(m_values["Records"]);
    }

    void GetStatusLogResult::setRecords(const std::vector<Sdx::LogRecord>& records)
    {
      m_values.AddMember("Records", parse_json<std::vector<Sdx::LogRecord>>::format(records, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
