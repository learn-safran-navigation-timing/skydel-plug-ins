#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetNavICEphDoubleParamForEachSVResult
///
#include "gen/GetNavICEphDoubleParamForEachSVResult.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetNavICEphDoubleParamForEachSVResult::CmdName = "GetNavICEphDoubleParamForEachSVResult";
    const char* const GetNavICEphDoubleParamForEachSVResult::Documentation = "Result of GetNavICEphDoubleParamForEachSV.";

    REGISTER_COMMAND_RESULT_FACTORY(GetNavICEphDoubleParamForEachSVResult);


    GetNavICEphDoubleParamForEachSVResult::GetNavICEphDoubleParamForEachSVResult()
      : CommandResult(CmdName)
    {}

    GetNavICEphDoubleParamForEachSVResult::GetNavICEphDoubleParamForEachSVResult(CommandBasePtr relatedCommand, const std::string& paramName, const std::vector<double>& val)
      : CommandResult(CmdName, relatedCommand)
    {

      setParamName(paramName);
      setVal(val);
    }


    GetNavICEphDoubleParamForEachSVResultPtr GetNavICEphDoubleParamForEachSVResult::create(CommandBasePtr relatedCommand, const std::string& paramName, const std::vector<double>& val)
    {
      return GetNavICEphDoubleParamForEachSVResultPtr(new GetNavICEphDoubleParamForEachSVResult(relatedCommand, paramName, val));
    }

    GetNavICEphDoubleParamForEachSVResultPtr GetNavICEphDoubleParamForEachSVResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetNavICEphDoubleParamForEachSVResult>(ptr);
    }

    bool GetNavICEphDoubleParamForEachSVResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["ParamName"])
          && parse_json<std::vector<double>>::is_valid(m_values["Val"])
        ;

    }

    std::string GetNavICEphDoubleParamForEachSVResult::documentation() const { return Documentation; }


    std::string GetNavICEphDoubleParamForEachSVResult::paramName() const
    {
      return parse_json<std::string>::parse(m_values["ParamName"]);
    }

    void GetNavICEphDoubleParamForEachSVResult::setParamName(const std::string& paramName)
    {
      m_values.AddMember("ParamName", parse_json<std::string>::format(paramName, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::vector<double> GetNavICEphDoubleParamForEachSVResult::val() const
    {
      return parse_json<std::vector<double>>::parse(m_values["Val"]);
    }

    void GetNavICEphDoubleParamForEachSVResult::setVal(const std::vector<double>& val)
    {
      m_values.AddMember("Val", parse_json<std::vector<double>>::format(val, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
