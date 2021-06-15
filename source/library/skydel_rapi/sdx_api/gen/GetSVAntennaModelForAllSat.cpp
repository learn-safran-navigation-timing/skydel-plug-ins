#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetSVAntennaModelForAllSat
///
#include "gen/GetSVAntennaModelForAllSat.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetSVAntennaModelForAllSat::CmdName = "GetSVAntennaModelForAllSat";
    const char* const GetSVAntennaModelForAllSat::Documentation = "Please note the command GetSVAntennaModelForAllSat is deprecated since 21.3. You may use GetSVAntennaModelForEachSV.\n\nGet the antenna model for all satellites.";

    REGISTER_COMMAND_FACTORY(GetSVAntennaModelForAllSat);


    GetSVAntennaModelForAllSat::GetSVAntennaModelForAllSat()
      : CommandBase(CmdName)
    {}

    GetSVAntennaModelForAllSat::GetSVAntennaModelForAllSat(const std::string& system)
      : CommandBase(CmdName)
    {

      setSystem(system);
    }


    GetSVAntennaModelForAllSatPtr GetSVAntennaModelForAllSat::create(const std::string& system)
    {
      return GetSVAntennaModelForAllSatPtr(new GetSVAntennaModelForAllSat(system));
    }

    GetSVAntennaModelForAllSatPtr GetSVAntennaModelForAllSat::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetSVAntennaModelForAllSat>(ptr);
    }

    bool GetSVAntennaModelForAllSat::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["System"])
        ;

    }

    std::string GetSVAntennaModelForAllSat::documentation() const { return Documentation; }


    int GetSVAntennaModelForAllSat::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string GetSVAntennaModelForAllSat::system() const
    {
      return parse_json<std::string>::parse(m_values["System"]);
    }

    void GetSVAntennaModelForAllSat::setSystem(const std::string& system)
    {
      m_values.AddMember("System", parse_json<std::string>::format(system, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
