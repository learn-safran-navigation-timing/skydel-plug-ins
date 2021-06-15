#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetPrnsEnabled
///
#include "gen/GetPrnsEnabled.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetPrnsEnabled::CmdName = "GetPrnsEnabled";
    const char* const GetPrnsEnabled::Documentation = "Please note the command GetPrnsEnabled is deprecated since 21.3. You may use IsEachSVEnabled.\n\nGet  enabled or disabled satellites for this constellation.";

    REGISTER_COMMAND_FACTORY(GetPrnsEnabled);


    GetPrnsEnabled::GetPrnsEnabled()
      : CommandBase(CmdName)
    {}

    GetPrnsEnabled::GetPrnsEnabled(const std::string& system)
      : CommandBase(CmdName)
    {

      setSystem(system);
    }


    GetPrnsEnabledPtr GetPrnsEnabled::create(const std::string& system)
    {
      return GetPrnsEnabledPtr(new GetPrnsEnabled(system));
    }

    GetPrnsEnabledPtr GetPrnsEnabled::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetPrnsEnabled>(ptr);
    }

    bool GetPrnsEnabled::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["System"])
        ;

    }

    std::string GetPrnsEnabled::documentation() const { return Documentation; }


    int GetPrnsEnabled::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string GetPrnsEnabled::system() const
    {
      return parse_json<std::string>::parse(m_values["System"]);
    }

    void GetPrnsEnabled::setSystem(const std::string& system)
    {
      m_values.AddMember("System", parse_json<std::string>::format(system, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
