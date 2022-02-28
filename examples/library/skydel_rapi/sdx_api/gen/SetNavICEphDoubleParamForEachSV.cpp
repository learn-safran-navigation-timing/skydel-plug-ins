#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetNavICEphDoubleParamForEachSV
///
#include "gen/SetNavICEphDoubleParamForEachSV.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetNavICEphDoubleParamForEachSV::CmdName = "SetNavICEphDoubleParamForEachSV";
    const char* const SetNavICEphDoubleParamForEachSV::Documentation = "Please note the command SetNavICEphemerisDoubleParams is deprecated since 21.3. You may use SetNavICEphDoubleParamForEachSV.\n\nSet NavIC ephemeris parameter value for all satellites";

    REGISTER_COMMAND_FACTORY(SetNavICEphDoubleParamForEachSV);


    SetNavICEphDoubleParamForEachSV::SetNavICEphDoubleParamForEachSV()
      : CommandBase(CmdName)
    {}

    SetNavICEphDoubleParamForEachSV::SetNavICEphDoubleParamForEachSV(const std::string& paramName, const std::vector<double>& val, const Sdx::optional<std::string>& dataSetName)
      : CommandBase(CmdName)
    {

      setParamName(paramName);
      setVal(val);
      setDataSetName(dataSetName);
    }


    SetNavICEphDoubleParamForEachSVPtr SetNavICEphDoubleParamForEachSV::create(const std::string& paramName, const std::vector<double>& val, const Sdx::optional<std::string>& dataSetName)
    {
      return SetNavICEphDoubleParamForEachSVPtr(new SetNavICEphDoubleParamForEachSV(paramName, val, dataSetName));
    }

    SetNavICEphDoubleParamForEachSVPtr SetNavICEphDoubleParamForEachSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetNavICEphDoubleParamForEachSV>(ptr);
    }

    bool SetNavICEphDoubleParamForEachSV::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["ParamName"])
          && parse_json<std::vector<double>>::is_valid(m_values["Val"])
          && parse_json<Sdx::optional<std::string>>::is_valid(m_values["DataSetName"])
        ;

    }

    std::string SetNavICEphDoubleParamForEachSV::documentation() const { return Documentation; }


    int SetNavICEphDoubleParamForEachSV::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string SetNavICEphDoubleParamForEachSV::paramName() const
    {
      return parse_json<std::string>::parse(m_values["ParamName"]);
    }

    void SetNavICEphDoubleParamForEachSV::setParamName(const std::string& paramName)
    {
      m_values.AddMember("ParamName", parse_json<std::string>::format(paramName, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::vector<double> SetNavICEphDoubleParamForEachSV::val() const
    {
      return parse_json<std::vector<double>>::parse(m_values["Val"]);
    }

    void SetNavICEphDoubleParamForEachSV::setVal(const std::vector<double>& val)
    {
      m_values.AddMember("Val", parse_json<std::vector<double>>::format(val, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::optional<std::string> SetNavICEphDoubleParamForEachSV::dataSetName() const
    {
      return parse_json<Sdx::optional<std::string>>::parse(m_values["DataSetName"]);
    }

    void SetNavICEphDoubleParamForEachSV::setDataSetName(const Sdx::optional<std::string>& dataSetName)
    {
      m_values.AddMember("DataSetName", parse_json<Sdx::optional<std::string>>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
