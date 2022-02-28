#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetMessageModificationToQzssCNav
///
#include "gen/GetMessageModificationToQzssCNav.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetMessageModificationToQzssCNav::CmdName = "GetMessageModificationToQzssCNav";
    const char* const GetMessageModificationToQzssCNav::Documentation = "Get infos about the QZSS CNAV message modification with this ID.";

    REGISTER_COMMAND_FACTORY(GetMessageModificationToQzssCNav);


    GetMessageModificationToQzssCNav::GetMessageModificationToQzssCNav()
      : CommandBase(CmdName)
    {}

    GetMessageModificationToQzssCNav::GetMessageModificationToQzssCNav(const std::string& id)
      : CommandBase(CmdName)
    {

      setId(id);
    }


    GetMessageModificationToQzssCNavPtr GetMessageModificationToQzssCNav::create(const std::string& id)
    {
      return std::make_shared<GetMessageModificationToQzssCNav>(id);
    }

    GetMessageModificationToQzssCNavPtr GetMessageModificationToQzssCNav::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetMessageModificationToQzssCNav>(ptr);
    }

    bool GetMessageModificationToQzssCNav::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Id"])
        ;

    }

    std::string GetMessageModificationToQzssCNav::documentation() const { return Documentation; }


    int GetMessageModificationToQzssCNav::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string GetMessageModificationToQzssCNav::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void GetMessageModificationToQzssCNav::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
