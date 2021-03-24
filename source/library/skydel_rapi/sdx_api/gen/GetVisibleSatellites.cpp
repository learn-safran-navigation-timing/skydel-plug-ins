#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetVisibleSatellites
///
#include "gen/GetVisibleSatellites.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetVisibleSatellites::CmdName = "GetVisibleSatellites";
    const char* const GetVisibleSatellites::Documentation = "Please note the command GetVisibleSatellites is deprecated since 21.3. You may use GetVisibleSV.\n\nGet a list of visible satellites within a system, returns a GetVisibleSatellitesResult";

    REGISTER_COMMAND_FACTORY(GetVisibleSatellites);


    GetVisibleSatellites::GetVisibleSatellites()
      : CommandBase(CmdName)
    {}

    GetVisibleSatellites::GetVisibleSatellites(const std::string& system)
      : CommandBase(CmdName)
    {

      setSystem(system);
    }


    GetVisibleSatellitesPtr GetVisibleSatellites::create(const std::string& system)
    {
      return GetVisibleSatellitesPtr(new GetVisibleSatellites(system));
    }

    GetVisibleSatellitesPtr GetVisibleSatellites::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetVisibleSatellites>(ptr);
    }

    bool GetVisibleSatellites::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["System"])
        ;

    }

    std::string GetVisibleSatellites::documentation() const { return Documentation; }


    int GetVisibleSatellites::executePermission() const
    {
      return EXECUTE_IF_SIMULATING;
    }


    std::string GetVisibleSatellites::system() const
    {
      return parse_json<std::string>::parse(m_values["System"]);
    }

    void GetVisibleSatellites::setSystem(const std::string& system)
    {
      m_values.AddMember("System", parse_json<std::string>::format(system, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
