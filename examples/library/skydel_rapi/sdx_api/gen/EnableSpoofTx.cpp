#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of EnableSpoofTx
///
#include "gen/EnableSpoofTx.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const EnableSpoofTx::CmdName = "EnableSpoofTx";
    const char* const EnableSpoofTx::Documentation = "Enable/Disable the spoofer.";

    REGISTER_COMMAND_FACTORY(EnableSpoofTx);


    EnableSpoofTx::EnableSpoofTx()
      : CommandBase(CmdName)
    {}

    EnableSpoofTx::EnableSpoofTx(bool enabled, const std::string& id)
      : CommandBase(CmdName)
    {

      setEnabled(enabled);
      setId(id);
    }


    EnableSpoofTxPtr EnableSpoofTx::create(bool enabled, const std::string& id)
    {
      return EnableSpoofTxPtr(new EnableSpoofTx(enabled, id));
    }

    EnableSpoofTxPtr EnableSpoofTx::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<EnableSpoofTx>(ptr);
    }

    bool EnableSpoofTx::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<bool>::is_valid(m_values["Enabled"])
          && parse_json<std::string>::is_valid(m_values["Id"])
        ;

    }

    std::string EnableSpoofTx::documentation() const { return Documentation; }


    int EnableSpoofTx::executePermission() const
    {
      return EXECUTE_IF_IDLE | EXECUTE_IF_SIMULATING;
    }


    bool EnableSpoofTx::enabled() const
    {
      return parse_json<bool>::parse(m_values["Enabled"]);
    }

    void EnableSpoofTx::setEnabled(bool enabled)
    {
      m_values.AddMember("Enabled", parse_json<bool>::format(enabled, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string EnableSpoofTx::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void EnableSpoofTx::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
