
#include "SetGpsConfigurationForEachSV.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetGpsConfigurationForEachSV
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetGpsConfigurationForEachSV::CmdName = "SetGpsConfigurationForEachSV";
    const char* const SetGpsConfigurationForEachSV::Documentation = "Set GPS SV configuration flag for each SVs\n"
      "\n"
      "Name        Type            Description\n"
      "----------- --------------- -------------------------------------------------------------------------------------------\n"
      "SvConfigs   array int       SV Config of all satellite\n"
      "DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.";
    const char* const SetGpsConfigurationForEachSV::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(SetGpsConfigurationForEachSV);
    REGISTER_COMMAND_TO_FACTORY_IMPL(SetGpsConfigurationForEachSV);


    SetGpsConfigurationForEachSV::SetGpsConfigurationForEachSV()
      : CommandBase(CmdName, TargetId)
    {}

    SetGpsConfigurationForEachSV::SetGpsConfigurationForEachSV(const std::vector<int>& svConfigs, const Sdx::optional<std::string>& dataSetName)
      : CommandBase(CmdName, TargetId)
    {

      setSvConfigs(svConfigs);
      setDataSetName(dataSetName);
    }

    SetGpsConfigurationForEachSVPtr SetGpsConfigurationForEachSV::create(const std::vector<int>& svConfigs, const Sdx::optional<std::string>& dataSetName)
    {
      return std::make_shared<SetGpsConfigurationForEachSV>(svConfigs, dataSetName);
    }

    SetGpsConfigurationForEachSVPtr SetGpsConfigurationForEachSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetGpsConfigurationForEachSV>(ptr);
    }

    bool SetGpsConfigurationForEachSV::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::vector<int>>::is_valid(m_values["SvConfigs"])
          && parse_json<Sdx::optional<std::string>>::is_valid(m_values["DataSetName"])
        ;

    }

    std::string SetGpsConfigurationForEachSV::documentation() const { return Documentation; }

    const std::vector<std::string>& SetGpsConfigurationForEachSV::fieldNames() const 
    { 
      static const std::vector<std::string> names {"SvConfigs", "DataSetName"}; 
      return names; 
    }


    int SetGpsConfigurationForEachSV::executePermission() const
    {
      return EXECUTE_IF_IDLE | EXECUTE_IF_SIMULATING;
    }


    std::vector<int> SetGpsConfigurationForEachSV::svConfigs() const
    {
      return parse_json<std::vector<int>>::parse(m_values["SvConfigs"]);
    }

    void SetGpsConfigurationForEachSV::setSvConfigs(const std::vector<int>& svConfigs)
    {
      m_values.AddMember("SvConfigs", parse_json<std::vector<int>>::format(svConfigs, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::optional<std::string> SetGpsConfigurationForEachSV::dataSetName() const
    {
      return parse_json<Sdx::optional<std::string>>::parse(m_values["DataSetName"]);
    }

    void SetGpsConfigurationForEachSV::setDataSetName(const Sdx::optional<std::string>& dataSetName)
    {
      m_values.AddMember("DataSetName", parse_json<Sdx::optional<std::string>>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
