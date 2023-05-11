#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetNavICEphDoubleParamForEachSV
///
#include "gen/GetNavICEphDoubleParamForEachSV.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetNavICEphDoubleParamForEachSV::CmdName = "GetNavICEphDoubleParamForEachSV";
    const char* const GetNavICEphDoubleParamForEachSV::Documentation = "Please note the command GetNavICEphemerisDoubleParams is deprecated since 21.3. You may use GetNavICEphDoubleParamForEachSV.\n\nGet NavIC ephemeris parameter value for all satellites";

    REGISTER_COMMAND_FACTORY(GetNavICEphDoubleParamForEachSV);


    GetNavICEphDoubleParamForEachSV::GetNavICEphDoubleParamForEachSV()
      : CommandBase(CmdName)
    {}

    GetNavICEphDoubleParamForEachSV::GetNavICEphDoubleParamForEachSV(const std::string& paramName, const Sdx::optional<std::string>& dataSetName)
      : CommandBase(CmdName)
    {

      setParamName(paramName);
      setDataSetName(dataSetName);
    }


    GetNavICEphDoubleParamForEachSVPtr GetNavICEphDoubleParamForEachSV::create(const std::string& paramName, const Sdx::optional<std::string>& dataSetName)
    {
      return std::make_shared<GetNavICEphDoubleParamForEachSV>(paramName, dataSetName);
    }

    GetNavICEphDoubleParamForEachSVPtr GetNavICEphDoubleParamForEachSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetNavICEphDoubleParamForEachSV>(ptr);
    }

    bool GetNavICEphDoubleParamForEachSV::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["ParamName"])
          && parse_json<Sdx::optional<std::string>>::is_valid(m_values["DataSetName"])
        ;

    }

    std::string GetNavICEphDoubleParamForEachSV::documentation() const { return Documentation; }


    int GetNavICEphDoubleParamForEachSV::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string GetNavICEphDoubleParamForEachSV::paramName() const
    {
      return parse_json<std::string>::parse(m_values["ParamName"]);
    }

    void GetNavICEphDoubleParamForEachSV::setParamName(const std::string& paramName)
    {
      m_values.AddMember("ParamName", parse_json<std::string>::format(paramName, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::optional<std::string> GetNavICEphDoubleParamForEachSV::dataSetName() const
    {
      return parse_json<Sdx::optional<std::string>>::parse(m_values["DataSetName"]);
    }

    void GetNavICEphDoubleParamForEachSV::setDataSetName(const Sdx::optional<std::string>& dataSetName)
    {
      m_values.AddMember("DataSetName", parse_json<Sdx::optional<std::string>>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
