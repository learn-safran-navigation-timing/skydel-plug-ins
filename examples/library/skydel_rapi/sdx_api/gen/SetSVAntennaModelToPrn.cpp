#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetSVAntennaModelToPrn
///
#include "gen/SetSVAntennaModelToPrn.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetSVAntennaModelToPrn::CmdName = "SetSVAntennaModelToPrn";
    const char* const SetSVAntennaModelToPrn::Documentation = "Please note the command SetSVAntennaModelToPrn is deprecated since 21.3. You may use SetSVAntennaModelForSV.\n\nSet the antenna model used by the PRN.";

    REGISTER_COMMAND_FACTORY(SetSVAntennaModelToPrn);


    SetSVAntennaModelToPrn::SetSVAntennaModelToPrn()
      : CommandBase(CmdName)
    {}

    SetSVAntennaModelToPrn::SetSVAntennaModelToPrn(int prn, const std::string& system, const std::string& antennaModelName)
      : CommandBase(CmdName)
    {

      setPrn(prn);
      setSystem(system);
      setAntennaModelName(antennaModelName);
    }


    SetSVAntennaModelToPrnPtr SetSVAntennaModelToPrn::create(int prn, const std::string& system, const std::string& antennaModelName)
    {
      return SetSVAntennaModelToPrnPtr(new SetSVAntennaModelToPrn(prn, system, antennaModelName));
    }

    SetSVAntennaModelToPrnPtr SetSVAntennaModelToPrn::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetSVAntennaModelToPrn>(ptr);
    }

    bool SetSVAntennaModelToPrn::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["Prn"])
          && parse_json<std::string>::is_valid(m_values["System"])
          && parse_json<std::string>::is_valid(m_values["AntennaModelName"])
        ;

    }

    std::string SetSVAntennaModelToPrn::documentation() const { return Documentation; }


    int SetSVAntennaModelToPrn::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    int SetSVAntennaModelToPrn::prn() const
    {
      return parse_json<int>::parse(m_values["Prn"]);
    }

    void SetSVAntennaModelToPrn::setPrn(int prn)
    {
      m_values.AddMember("Prn", parse_json<int>::format(prn, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string SetSVAntennaModelToPrn::system() const
    {
      return parse_json<std::string>::parse(m_values["System"]);
    }

    void SetSVAntennaModelToPrn::setSystem(const std::string& system)
    {
      m_values.AddMember("System", parse_json<std::string>::format(system, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string SetSVAntennaModelToPrn::antennaModelName() const
    {
      return parse_json<std::string>::parse(m_values["AntennaModelName"]);
    }

    void SetSVAntennaModelToPrn::setAntennaModelName(const std::string& antennaModelName)
    {
      m_values.AddMember("AntennaModelName", parse_json<std::string>::format(antennaModelName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
