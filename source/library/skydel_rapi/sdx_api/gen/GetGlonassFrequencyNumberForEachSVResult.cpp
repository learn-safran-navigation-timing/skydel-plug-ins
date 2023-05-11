#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetGlonassFrequencyNumberForEachSVResult
///
#include "gen/GetGlonassFrequencyNumberForEachSVResult.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetGlonassFrequencyNumberForEachSVResult::CmdName = "GetGlonassFrequencyNumberForEachSVResult";
    const char* const GetGlonassFrequencyNumberForEachSVResult::Documentation = "Result of GetGlonassFrequencyNumberForEachSV";

    REGISTER_COMMAND_RESULT_FACTORY(GetGlonassFrequencyNumberForEachSVResult);


    GetGlonassFrequencyNumberForEachSVResult::GetGlonassFrequencyNumberForEachSVResult()
      : CommandResult(CmdName)
    {}

    GetGlonassFrequencyNumberForEachSVResult::GetGlonassFrequencyNumberForEachSVResult(CommandBasePtr relatedCommand, const std::vector<int>& frequencyNumber)
      : CommandResult(CmdName, relatedCommand)
    {

      setFrequencyNumber(frequencyNumber);
    }


    GetGlonassFrequencyNumberForEachSVResultPtr GetGlonassFrequencyNumberForEachSVResult::create(CommandBasePtr relatedCommand, const std::vector<int>& frequencyNumber)
    {
      return std::make_shared<GetGlonassFrequencyNumberForEachSVResult>(relatedCommand, frequencyNumber);
    }

    GetGlonassFrequencyNumberForEachSVResultPtr GetGlonassFrequencyNumberForEachSVResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetGlonassFrequencyNumberForEachSVResult>(ptr);
    }

    bool GetGlonassFrequencyNumberForEachSVResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::vector<int>>::is_valid(m_values["FrequencyNumber"])
        ;

    }

    std::string GetGlonassFrequencyNumberForEachSVResult::documentation() const { return Documentation; }


    std::vector<int> GetGlonassFrequencyNumberForEachSVResult::frequencyNumber() const
    {
      return parse_json<std::vector<int>>::parse(m_values["FrequencyNumber"]);
    }

    void GetGlonassFrequencyNumberForEachSVResult::setFrequencyNumber(const std::vector<int>& frequencyNumber)
    {
      m_values.AddMember("FrequencyNumber", parse_json<std::vector<int>>::format(frequencyNumber, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
