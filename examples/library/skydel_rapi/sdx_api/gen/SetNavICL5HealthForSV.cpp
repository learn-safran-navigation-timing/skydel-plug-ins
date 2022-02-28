#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetNavICL5HealthForSV
///
#include "gen/SetNavICL5HealthForSV.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetNavICL5HealthForSV::CmdName = "SetNavICL5HealthForSV";
    const char* const SetNavICL5HealthForSV::Documentation = "Please note the command SetNavICSatelliteL5Health is deprecated since 21.3. You may use SetNavICL5HealthForSV.\n\nSet NavIC L5 health (Health of L5 signal)";

    REGISTER_COMMAND_FACTORY(SetNavICL5HealthForSV);


    SetNavICL5HealthForSV::SetNavICL5HealthForSV()
      : CommandBase(CmdName)
    {}

    SetNavICL5HealthForSV::SetNavICL5HealthForSV(int svId, bool health, const Sdx::optional<std::string>& dataSetName)
      : CommandBase(CmdName)
    {

      setSvId(svId);
      setHealth(health);
      setDataSetName(dataSetName);
    }


    SetNavICL5HealthForSVPtr SetNavICL5HealthForSV::create(int svId, bool health, const Sdx::optional<std::string>& dataSetName)
    {
      return SetNavICL5HealthForSVPtr(new SetNavICL5HealthForSV(svId, health, dataSetName));
    }

    SetNavICL5HealthForSVPtr SetNavICL5HealthForSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetNavICL5HealthForSV>(ptr);
    }

    bool SetNavICL5HealthForSV::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<bool>::is_valid(m_values["Health"])
          && parse_json<Sdx::optional<std::string>>::is_valid(m_values["DataSetName"])
        ;

    }

    std::string SetNavICL5HealthForSV::documentation() const { return Documentation; }


    int SetNavICL5HealthForSV::executePermission() const
    {
      return EXECUTE_IF_SIMULATING | EXECUTE_IF_IDLE;
    }


    int SetNavICL5HealthForSV::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void SetNavICL5HealthForSV::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool SetNavICL5HealthForSV::health() const
    {
      return parse_json<bool>::parse(m_values["Health"]);
    }

    void SetNavICL5HealthForSV::setHealth(bool health)
    {
      m_values.AddMember("Health", parse_json<bool>::format(health, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::optional<std::string> SetNavICL5HealthForSV::dataSetName() const
    {
      return parse_json<Sdx::optional<std::string>>::parse(m_values["DataSetName"]);
    }

    void SetNavICL5HealthForSV::setDataSetName(const Sdx::optional<std::string>& dataSetName)
    {
      m_values.AddMember("DataSetName", parse_json<Sdx::optional<std::string>>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
