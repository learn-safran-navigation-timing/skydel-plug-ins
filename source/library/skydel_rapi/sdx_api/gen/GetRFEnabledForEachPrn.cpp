#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetRFEnabledForEachPrn
///
#include "gen/GetRFEnabledForEachPrn.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetRFEnabledForEachPrn::CmdName = "GetRFEnabledForEachPrn";
    const char* const GetRFEnabledForEachPrn::Documentation = "Please note the command GetRFEnabledForEachPrn is deprecated since 21.3. You may use IsRFOutputEnabledForEachSV.\n\nTells if the RF is enabled or disabled for each satellite.";

    REGISTER_COMMAND_FACTORY(GetRFEnabledForEachPrn);


    GetRFEnabledForEachPrn::GetRFEnabledForEachPrn()
      : CommandBase(CmdName)
    {}

    GetRFEnabledForEachPrn::GetRFEnabledForEachPrn(const std::string& system)
      : CommandBase(CmdName)
    {

      setSystem(system);
    }


    GetRFEnabledForEachPrnPtr GetRFEnabledForEachPrn::create(const std::string& system)
    {
      return GetRFEnabledForEachPrnPtr(new GetRFEnabledForEachPrn(system));
    }

    GetRFEnabledForEachPrnPtr GetRFEnabledForEachPrn::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetRFEnabledForEachPrn>(ptr);
    }

    bool GetRFEnabledForEachPrn::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["System"])
        ;

    }

    std::string GetRFEnabledForEachPrn::documentation() const { return Documentation; }


    int GetRFEnabledForEachPrn::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string GetRFEnabledForEachPrn::system() const
    {
      return parse_json<std::string>::parse(m_values["System"]);
    }

    void GetRFEnabledForEachPrn::setSystem(const std::string& system)
    {
      m_values.AddMember("System", parse_json<std::string>::format(system, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
