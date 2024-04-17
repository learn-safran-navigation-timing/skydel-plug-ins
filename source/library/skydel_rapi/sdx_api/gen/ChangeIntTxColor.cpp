
#include "ChangeIntTxColor.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of ChangeIntTxColor
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const ChangeIntTxColor::CmdName = "ChangeIntTxColor";
    const char* const ChangeIntTxColor::Documentation = "Set a transmitter color in spectrums\n"
      "\n"
      "Name  Type   Description\n"
      "----- ------ -------------------------------------------------------------------------------\n"
      "Color string Color 'name'. Either a common color (red, white, ...) or an hex code (#FFFFFF).\n"
      "Id    string Transmitter unique identifier.";
    const char* const ChangeIntTxColor::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(ChangeIntTxColor);
    REGISTER_COMMAND_TO_FACTORY_IMPL(ChangeIntTxColor);


    ChangeIntTxColor::ChangeIntTxColor()
      : CommandBase(CmdName, TargetId)
    {}

    ChangeIntTxColor::ChangeIntTxColor(const std::string& color, const std::string& id)
      : CommandBase(CmdName, TargetId)
    {

      setColor(color);
      setId(id);
    }

    ChangeIntTxColorPtr ChangeIntTxColor::create(const std::string& color, const std::string& id)
    {
      return std::make_shared<ChangeIntTxColor>(color, id);
    }

    ChangeIntTxColorPtr ChangeIntTxColor::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<ChangeIntTxColor>(ptr);
    }

    bool ChangeIntTxColor::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Color"])
          && parse_json<std::string>::is_valid(m_values["Id"])
        ;

    }

    std::string ChangeIntTxColor::documentation() const { return Documentation; }

    const std::vector<std::string>& ChangeIntTxColor::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Color", "Id"}; 
      return names; 
    }


    int ChangeIntTxColor::executePermission() const
    {
      return EXECUTE_IF_SIMULATING | EXECUTE_IF_IDLE;
    }


    std::string ChangeIntTxColor::color() const
    {
      return parse_json<std::string>::parse(m_values["Color"]);
    }

    void ChangeIntTxColor::setColor(const std::string& color)
    {
      m_values.AddMember("Color", parse_json<std::string>::format(color, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string ChangeIntTxColor::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void ChangeIntTxColor::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
