#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetPlugInInstanceResult
///
#include "gen/GetPlugInInstanceResult.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetPlugInInstanceResult::CmdName = "GetPlugInInstanceResult";
    const char* const GetPlugInInstanceResult::Documentation = "Result of GetPlugInInstance.";

    REGISTER_COMMAND_RESULT_FACTORY(GetPlugInInstanceResult);


    GetPlugInInstanceResult::GetPlugInInstanceResult()
      : CommandResult(CmdName)
    {}

    GetPlugInInstanceResult::GetPlugInInstanceResult(CommandBasePtr relatedCommand, const std::string& name, const std::string& type)
      : CommandResult(CmdName, relatedCommand)
    {

      setName(name);
      setType(type);
    }


    GetPlugInInstanceResultPtr GetPlugInInstanceResult::create(CommandBasePtr relatedCommand, const std::string& name, const std::string& type)
    {
      return std::make_shared<GetPlugInInstanceResult>(relatedCommand, name, type);
    }

    GetPlugInInstanceResultPtr GetPlugInInstanceResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetPlugInInstanceResult>(ptr);
    }

    bool GetPlugInInstanceResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Name"])
          && parse_json<std::string>::is_valid(m_values["Type"])
        ;

    }

    std::string GetPlugInInstanceResult::documentation() const { return Documentation; }


    std::string GetPlugInInstanceResult::name() const
    {
      return parse_json<std::string>::parse(m_values["Name"]);
    }

    void GetPlugInInstanceResult::setName(const std::string& name)
    {
      m_values.AddMember("Name", parse_json<std::string>::format(name, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string GetPlugInInstanceResult::type() const
    {
      return parse_json<std::string>::parse(m_values["Type"]);
    }

    void GetPlugInInstanceResult::setType(const std::string& type)
    {
      m_values.AddMember("Type", parse_json<std::string>::format(type, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
