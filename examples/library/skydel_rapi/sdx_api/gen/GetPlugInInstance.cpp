#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetPlugInInstance
///
#include "gen/GetPlugInInstance.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetPlugInInstance::CmdName = "GetPlugInInstance";
    const char* const GetPlugInInstance::Documentation = "Get Add a plug-in instance of specified type.";

    REGISTER_COMMAND_FACTORY(GetPlugInInstance);


    GetPlugInInstance::GetPlugInInstance()
      : CommandBase(CmdName)
    {

    }


    GetPlugInInstancePtr GetPlugInInstance::create()
    {
      return GetPlugInInstancePtr(new GetPlugInInstance());
    }

    GetPlugInInstancePtr GetPlugInInstance::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetPlugInInstance>(ptr);
    }

    bool GetPlugInInstance::isValid() const
    {
      
        return m_values.IsObject()
        ;

    }

    std::string GetPlugInInstance::documentation() const { return Documentation; }


    int GetPlugInInstance::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }

  }
}
