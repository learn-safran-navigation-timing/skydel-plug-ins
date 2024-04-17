
#include "SetIntTxRefPower.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetIntTxRefPower
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetIntTxRefPower::CmdName = "SetIntTxRefPower";
    const char* const SetIntTxRefPower::Documentation = "Set the interference transmitter reference power.\n"
      "\n"
      "Name  Type   Description\n"
      "----- ------ ------------------------------\n"
      "Power double Reference Power (dBm)\n"
      "Id    string Transmitter unique identifier.";
    const char* const SetIntTxRefPower::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(SetIntTxRefPower);
    REGISTER_COMMAND_TO_FACTORY_IMPL(SetIntTxRefPower);


    SetIntTxRefPower::SetIntTxRefPower()
      : CommandBase(CmdName, TargetId)
    {}

    SetIntTxRefPower::SetIntTxRefPower(double power, const std::string& id)
      : CommandBase(CmdName, TargetId)
    {

      setPower(power);
      setId(id);
    }

    SetIntTxRefPowerPtr SetIntTxRefPower::create(double power, const std::string& id)
    {
      return std::make_shared<SetIntTxRefPower>(power, id);
    }

    SetIntTxRefPowerPtr SetIntTxRefPower::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetIntTxRefPower>(ptr);
    }

    bool SetIntTxRefPower::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<double>::is_valid(m_values["Power"])
          && parse_json<std::string>::is_valid(m_values["Id"])
        ;

    }

    std::string SetIntTxRefPower::documentation() const { return Documentation; }

    const std::vector<std::string>& SetIntTxRefPower::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Power", "Id"}; 
      return names; 
    }


    int SetIntTxRefPower::executePermission() const
    {
      return EXECUTE_IF_SIMULATING | EXECUTE_IF_IDLE;
    }


    double SetIntTxRefPower::power() const
    {
      return parse_json<double>::parse(m_values["Power"]);
    }

    void SetIntTxRefPower::setPower(double power)
    {
      m_values.AddMember("Power", parse_json<double>::format(power, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string SetIntTxRefPower::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void SetIntTxRefPower::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
