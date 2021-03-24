#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetEphemerisReferenceTimeForSV
///
#include "gen/GetEphemerisReferenceTimeForSV.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetEphemerisReferenceTimeForSV::CmdName = "GetEphemerisReferenceTimeForSV";
    const char* const GetEphemerisReferenceTimeForSV::Documentation = "Please note the command GetEphemerisReferenceTime is deprecated since 21.3. You may use GetEphemerisReferenceTimeForSV.\n\nGet the ephemeris reference time for the specified constellation.";

    REGISTER_COMMAND_FACTORY(GetEphemerisReferenceTimeForSV);


    GetEphemerisReferenceTimeForSV::GetEphemerisReferenceTimeForSV()
      : CommandBase(CmdName)
    {}

    GetEphemerisReferenceTimeForSV::GetEphemerisReferenceTimeForSV(const std::string& system, int svId)
      : CommandBase(CmdName)
    {

      setSystem(system);
      setSvId(svId);
    }


    GetEphemerisReferenceTimeForSVPtr GetEphemerisReferenceTimeForSV::create(const std::string& system, int svId)
    {
      return GetEphemerisReferenceTimeForSVPtr(new GetEphemerisReferenceTimeForSV(system, svId));
    }

    GetEphemerisReferenceTimeForSVPtr GetEphemerisReferenceTimeForSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetEphemerisReferenceTimeForSV>(ptr);
    }

    bool GetEphemerisReferenceTimeForSV::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["System"])
          && parse_json<int>::is_valid(m_values["SvId"])
        ;

    }

    std::string GetEphemerisReferenceTimeForSV::documentation() const { return Documentation; }


    int GetEphemerisReferenceTimeForSV::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string GetEphemerisReferenceTimeForSV::system() const
    {
      return parse_json<std::string>::parse(m_values["System"]);
    }

    void GetEphemerisReferenceTimeForSV::setSystem(const std::string& system)
    {
      m_values.AddMember("System", parse_json<std::string>::format(system, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetEphemerisReferenceTimeForSV::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void GetEphemerisReferenceTimeForSV::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
