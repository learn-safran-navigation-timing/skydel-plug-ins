
#include "GetMessageModificationToGpsLNav.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetMessageModificationToGpsLNav
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetMessageModificationToGpsLNav::CmdName = "GetMessageModificationToGpsLNav";
    const char* const GetMessageModificationToGpsLNav::Documentation = "Get infos about the GPS LNAV message modification with this ID.\n"
      "\n"
      "Name Type   Description\n"
      "---- ------ ------------------------------\n"
      "Id   string Unique identifier of the event";
    const char* const GetMessageModificationToGpsLNav::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(GetMessageModificationToGpsLNav);
    REGISTER_COMMAND_TO_FACTORY_IMPL(GetMessageModificationToGpsLNav);


    GetMessageModificationToGpsLNav::GetMessageModificationToGpsLNav()
      : CommandBase(CmdName, TargetId)
    {}

    GetMessageModificationToGpsLNav::GetMessageModificationToGpsLNav(const std::string& id)
      : CommandBase(CmdName, TargetId)
    {

      setId(id);
    }

    GetMessageModificationToGpsLNavPtr GetMessageModificationToGpsLNav::create(const std::string& id)
    {
      return std::make_shared<GetMessageModificationToGpsLNav>(id);
    }

    GetMessageModificationToGpsLNavPtr GetMessageModificationToGpsLNav::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetMessageModificationToGpsLNav>(ptr);
    }

    bool GetMessageModificationToGpsLNav::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Id"])
        ;

    }

    std::string GetMessageModificationToGpsLNav::documentation() const { return Documentation; }

    const std::vector<std::string>& GetMessageModificationToGpsLNav::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Id"}; 
      return names; 
    }


    int GetMessageModificationToGpsLNav::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string GetMessageModificationToGpsLNav::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void GetMessageModificationToGpsLNav::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
