#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetMultipath
///
#include "gen/GetMultipath.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetMultipath::CmdName = "GetMultipath";
    const char* const GetMultipath::Documentation = "Please note the command GetMultipath is deprecated since 21.3. You may use GetMultipathForID.\n\nGet multipath infos for the specified multipath ID.";

    REGISTER_COMMAND_FACTORY(GetMultipath);


    GetMultipath::GetMultipath()
      : CommandBase(CmdName)
    {}

    GetMultipath::GetMultipath(const std::string& id)
      : CommandBase(CmdName)
    {

      setId(id);
    }


    GetMultipathPtr GetMultipath::create(const std::string& id)
    {
      return GetMultipathPtr(new GetMultipath(id));
    }

    GetMultipathPtr GetMultipath::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetMultipath>(ptr);
    }

    bool GetMultipath::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Id"])
        ;

    }

    std::string GetMultipath::documentation() const { return Documentation; }


    int GetMultipath::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string GetMultipath::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void GetMultipath::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
