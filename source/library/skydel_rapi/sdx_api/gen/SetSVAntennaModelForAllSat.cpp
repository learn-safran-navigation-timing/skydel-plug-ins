#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetSVAntennaModelForAllSat
///
#include "gen/SetSVAntennaModelForAllSat.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetSVAntennaModelForAllSat::CmdName = "SetSVAntennaModelForAllSat";
    const char* const SetSVAntennaModelForAllSat::Documentation = "Please note the command SetSVAntennaModelForAllSat is deprecated since 21.3. You may use SetSVAntennaModelForEachSV.\n\nSet the antenna model for all satellites.";

    REGISTER_COMMAND_FACTORY(SetSVAntennaModelForAllSat);


    SetSVAntennaModelForAllSat::SetSVAntennaModelForAllSat()
      : CommandBase(CmdName)
    {}

    SetSVAntennaModelForAllSat::SetSVAntennaModelForAllSat(const std::vector<std::string>& antennaModelNames, const std::string& system)
      : CommandBase(CmdName)
    {

      setAntennaModelNames(antennaModelNames);
      setSystem(system);
    }


    SetSVAntennaModelForAllSatPtr SetSVAntennaModelForAllSat::create(const std::vector<std::string>& antennaModelNames, const std::string& system)
    {
      return SetSVAntennaModelForAllSatPtr(new SetSVAntennaModelForAllSat(antennaModelNames, system));
    }

    SetSVAntennaModelForAllSatPtr SetSVAntennaModelForAllSat::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetSVAntennaModelForAllSat>(ptr);
    }

    bool SetSVAntennaModelForAllSat::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::vector<std::string>>::is_valid(m_values["AntennaModelNames"])
          && parse_json<std::string>::is_valid(m_values["System"])
        ;

    }

    std::string SetSVAntennaModelForAllSat::documentation() const { return Documentation; }


    int SetSVAntennaModelForAllSat::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::vector<std::string> SetSVAntennaModelForAllSat::antennaModelNames() const
    {
      return parse_json<std::vector<std::string>>::parse(m_values["AntennaModelNames"]);
    }

    void SetSVAntennaModelForAllSat::setAntennaModelNames(const std::vector<std::string>& antennaModelNames)
    {
      m_values.AddMember("AntennaModelNames", parse_json<std::vector<std::string>>::format(antennaModelNames, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string SetSVAntennaModelForAllSat::system() const
    {
      return parse_json<std::string>::parse(m_values["System"]);
    }

    void SetSVAntennaModelForAllSat::setSystem(const std::string& system)
    {
      m_values.AddMember("System", parse_json<std::string>::format(system, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
