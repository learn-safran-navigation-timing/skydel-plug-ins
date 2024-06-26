
#include "SetSVType.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetSVType
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetSVType::CmdName = "SetSVType";
    const char* const SetSVType::Documentation = "Set the type of a SV.\n"
      "Satellite SV ID accepted values (0 for all SVs):\n"
      "QZSS 1..10\n"
      "\n"
      "Name   Type   Description\n"
      "------ ------ -------------------------------------------------------------\n"
      "System string Only \"QZSS\" supported.\n"
      "SvId   int    Satellite SV ID, see command description for accepted values.\n"
      "SvType string Type of the SV. QZSS: \"BlockI\", \"BlockII\".";
    const char* const SetSVType::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(SetSVType);
    REGISTER_COMMAND_TO_FACTORY_IMPL(SetSVType);


    SetSVType::SetSVType()
      : CommandBase(CmdName, TargetId)
    {}

    SetSVType::SetSVType(const std::string& system, int svId, const std::string& svType)
      : CommandBase(CmdName, TargetId)
    {

      setSystem(system);
      setSvId(svId);
      setSvType(svType);
    }

    SetSVTypePtr SetSVType::create(const std::string& system, int svId, const std::string& svType)
    {
      return std::make_shared<SetSVType>(system, svId, svType);
    }

    SetSVTypePtr SetSVType::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetSVType>(ptr);
    }

    bool SetSVType::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["System"])
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<std::string>::is_valid(m_values["SvType"])
        ;

    }

    std::string SetSVType::documentation() const { return Documentation; }

    const std::vector<std::string>& SetSVType::fieldNames() const 
    { 
      static const std::vector<std::string> names {"System", "SvId", "SvType"}; 
      return names; 
    }


    int SetSVType::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string SetSVType::system() const
    {
      return parse_json<std::string>::parse(m_values["System"]);
    }

    void SetSVType::setSystem(const std::string& system)
    {
      m_values.AddMember("System", parse_json<std::string>::format(system, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int SetSVType::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void SetSVType::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string SetSVType::svType() const
    {
      return parse_json<std::string>::parse(m_values["SvType"]);
    }

    void SetSVType::setSvType(const std::string& svType)
    {
      m_values.AddMember("SvType", parse_json<std::string>::format(svType, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
