#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetNavICEphDoubleParamForSVResult
///
#include "gen/GetNavICEphDoubleParamForSVResult.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetNavICEphDoubleParamForSVResult::CmdName = "GetNavICEphDoubleParamForSVResult";
    const char* const GetNavICEphDoubleParamForSVResult::Documentation = "Result of GetNavICEphDoubleParamForSV.";

    REGISTER_COMMAND_RESULT_FACTORY(GetNavICEphDoubleParamForSVResult);


    GetNavICEphDoubleParamForSVResult::GetNavICEphDoubleParamForSVResult()
      : CommandResult(CmdName)
    {}

    GetNavICEphDoubleParamForSVResult::GetNavICEphDoubleParamForSVResult(CommandBasePtr relatedCommand, int svId, const std::string& paramName, double val)
      : CommandResult(CmdName, relatedCommand)
    {

      setSvId(svId);
      setParamName(paramName);
      setVal(val);
    }


    GetNavICEphDoubleParamForSVResultPtr GetNavICEphDoubleParamForSVResult::create(CommandBasePtr relatedCommand, int svId, const std::string& paramName, double val)
    {
      return GetNavICEphDoubleParamForSVResultPtr(new GetNavICEphDoubleParamForSVResult(relatedCommand, svId, paramName, val));
    }

    GetNavICEphDoubleParamForSVResultPtr GetNavICEphDoubleParamForSVResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetNavICEphDoubleParamForSVResult>(ptr);
    }

    bool GetNavICEphDoubleParamForSVResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<std::string>::is_valid(m_values["ParamName"])
          && parse_json<double>::is_valid(m_values["Val"])
        ;

    }

    std::string GetNavICEphDoubleParamForSVResult::documentation() const { return Documentation; }


    int GetNavICEphDoubleParamForSVResult::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void GetNavICEphDoubleParamForSVResult::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string GetNavICEphDoubleParamForSVResult::paramName() const
    {
      return parse_json<std::string>::parse(m_values["ParamName"]);
    }

    void GetNavICEphDoubleParamForSVResult::setParamName(const std::string& paramName)
    {
      m_values.AddMember("ParamName", parse_json<std::string>::format(paramName, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double GetNavICEphDoubleParamForSVResult::val() const
    {
      return parse_json<double>::parse(m_values["Val"]);
    }

    void GetNavICEphDoubleParamForSVResult::setVal(double val)
    {
      m_values.AddMember("Val", parse_json<double>::format(val, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
