
#include "SetSpoofTxIgnorePropagationLoss.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetSpoofTxIgnorePropagationLoss
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetSpoofTxIgnorePropagationLoss::CmdName = "SetSpoofTxIgnorePropagationLoss";
    const char* const SetSpoofTxIgnorePropagationLoss::Documentation = "Set whether a spoofer should ignore propagation loss or not.\n"
      "\n"
      "Name   Type   Description\n"
      "------ ------ ------------------------------------------\n"
      "Ignore bool   If true, propagation loss will be ignored.\n"
      "Id     string Transmitter unique identifier.";
    const char* const SetSpoofTxIgnorePropagationLoss::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(SetSpoofTxIgnorePropagationLoss);
    REGISTER_COMMAND_TO_FACTORY_IMPL(SetSpoofTxIgnorePropagationLoss);


    SetSpoofTxIgnorePropagationLoss::SetSpoofTxIgnorePropagationLoss()
      : CommandBase(CmdName, TargetId)
    {}

    SetSpoofTxIgnorePropagationLoss::SetSpoofTxIgnorePropagationLoss(bool ignore, const std::string& id)
      : CommandBase(CmdName, TargetId)
    {

      setIgnore(ignore);
      setId(id);
    }

    SetSpoofTxIgnorePropagationLossPtr SetSpoofTxIgnorePropagationLoss::create(bool ignore, const std::string& id)
    {
      return std::make_shared<SetSpoofTxIgnorePropagationLoss>(ignore, id);
    }

    SetSpoofTxIgnorePropagationLossPtr SetSpoofTxIgnorePropagationLoss::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetSpoofTxIgnorePropagationLoss>(ptr);
    }

    bool SetSpoofTxIgnorePropagationLoss::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<bool>::is_valid(m_values["Ignore"])
          && parse_json<std::string>::is_valid(m_values["Id"])
        ;

    }

    std::string SetSpoofTxIgnorePropagationLoss::documentation() const { return Documentation; }

    const std::vector<std::string>& SetSpoofTxIgnorePropagationLoss::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Ignore", "Id"}; 
      return names; 
    }


    int SetSpoofTxIgnorePropagationLoss::executePermission() const
    {
      return EXECUTE_IF_IDLE | EXECUTE_IF_SIMULATING;
    }


    bool SetSpoofTxIgnorePropagationLoss::ignore() const
    {
      return parse_json<bool>::parse(m_values["Ignore"]);
    }

    void SetSpoofTxIgnorePropagationLoss::setIgnore(bool ignore)
    {
      m_values.AddMember("Ignore", parse_json<bool>::format(ignore, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string SetSpoofTxIgnorePropagationLoss::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void SetSpoofTxIgnorePropagationLoss::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
