#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetBeiDouAutonomousHealthForSV
///
#include "gen/SetBeiDouAutonomousHealthForSV.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetBeiDouAutonomousHealthForSV::CmdName = "SetBeiDouAutonomousHealthForSV";
    const char* const SetBeiDouAutonomousHealthForSV::Documentation = "Set BeiDou satellite autonomous health";

    REGISTER_COMMAND_FACTORY(SetBeiDouAutonomousHealthForSV);


    SetBeiDouAutonomousHealthForSV::SetBeiDouAutonomousHealthForSV()
      : CommandBase(CmdName)
    {}

    SetBeiDouAutonomousHealthForSV::SetBeiDouAutonomousHealthForSV(int svId, bool health, const Sdx::optional<std::string>& dataSetName)
      : CommandBase(CmdName)
    {

      setSvId(svId);
      setHealth(health);
      setDataSetName(dataSetName);
    }


    SetBeiDouAutonomousHealthForSVPtr SetBeiDouAutonomousHealthForSV::create(int svId, bool health, const Sdx::optional<std::string>& dataSetName)
    {
      return SetBeiDouAutonomousHealthForSVPtr(new SetBeiDouAutonomousHealthForSV(svId, health, dataSetName));
    }

    SetBeiDouAutonomousHealthForSVPtr SetBeiDouAutonomousHealthForSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetBeiDouAutonomousHealthForSV>(ptr);
    }

    bool SetBeiDouAutonomousHealthForSV::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<bool>::is_valid(m_values["Health"])
          && parse_json<Sdx::optional<std::string>>::is_valid(m_values["DataSetName"])
        ;

    }

    std::string SetBeiDouAutonomousHealthForSV::documentation() const { return Documentation; }


    int SetBeiDouAutonomousHealthForSV::executePermission() const
    {
      return EXECUTE_IF_SIMULATING | EXECUTE_IF_IDLE;
    }


    int SetBeiDouAutonomousHealthForSV::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void SetBeiDouAutonomousHealthForSV::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool SetBeiDouAutonomousHealthForSV::health() const
    {
      return parse_json<bool>::parse(m_values["Health"]);
    }

    void SetBeiDouAutonomousHealthForSV::setHealth(bool health)
    {
      m_values.AddMember("Health", parse_json<bool>::format(health, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::optional<std::string> SetBeiDouAutonomousHealthForSV::dataSetName() const
    {
      return parse_json<Sdx::optional<std::string>>::parse(m_values["DataSetName"]);
    }

    void SetBeiDouAutonomousHealthForSV::setDataSetName(const Sdx::optional<std::string>& dataSetName)
    {
      m_values.AddMember("DataSetName", parse_json<Sdx::optional<std::string>>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
