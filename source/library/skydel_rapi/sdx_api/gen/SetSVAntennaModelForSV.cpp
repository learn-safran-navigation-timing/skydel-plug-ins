
#include "gen/SetSVAntennaModelForSV.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetSVAntennaModelForSV
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetSVAntennaModelForSV::CmdName = "SetSVAntennaModelForSV";
    const char* const SetSVAntennaModelForSV::Documentation = "Set the antenna model used by the SV.";

    REGISTER_COMMAND_FACTORY(SetSVAntennaModelForSV);


    SetSVAntennaModelForSV::SetSVAntennaModelForSV()
      : CommandBase(CmdName)
    {}

    SetSVAntennaModelForSV::SetSVAntennaModelForSV(const std::string& system, int svId, const std::string& antennaModelName)
      : CommandBase(CmdName)
    {

      setSystem(system);
      setSvId(svId);
      setAntennaModelName(antennaModelName);
    }

    SetSVAntennaModelForSVPtr SetSVAntennaModelForSV::create(const std::string& system, int svId, const std::string& antennaModelName)
    {
      return std::make_shared<SetSVAntennaModelForSV>(system, svId, antennaModelName);
    }

    SetSVAntennaModelForSVPtr SetSVAntennaModelForSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetSVAntennaModelForSV>(ptr);
    }

    bool SetSVAntennaModelForSV::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["System"])
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<std::string>::is_valid(m_values["AntennaModelName"])
        ;

    }

    std::string SetSVAntennaModelForSV::documentation() const { return Documentation; }


    int SetSVAntennaModelForSV::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string SetSVAntennaModelForSV::system() const
    {
      return parse_json<std::string>::parse(m_values["System"]);
    }

    void SetSVAntennaModelForSV::setSystem(const std::string& system)
    {
      m_values.AddMember("System", parse_json<std::string>::format(system, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int SetSVAntennaModelForSV::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void SetSVAntennaModelForSV::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string SetSVAntennaModelForSV::antennaModelName() const
    {
      return parse_json<std::string>::parse(m_values["AntennaModelName"]);
    }

    void SetSVAntennaModelForSV::setAntennaModelName(const std::string& antennaModelName)
    {
      m_values.AddMember("AntennaModelName", parse_json<std::string>::format(antennaModelName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
