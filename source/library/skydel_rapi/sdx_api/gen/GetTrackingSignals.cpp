
#include "gen/GetTrackingSignals.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetTrackingSignals
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetTrackingSignals::CmdName = "GetTrackingSignals";
    const char* const GetTrackingSignals::Documentation = "Returns all the signals tracked.";

    REGISTER_COMMAND_TO_FACTORY_DECL(GetTrackingSignals);
    REGISTER_COMMAND_TO_FACTORY_IMPL(GetTrackingSignals);


    GetTrackingSignals::GetTrackingSignals()
      : CommandBase(CmdName)
    {

    }

    GetTrackingSignalsPtr GetTrackingSignals::create()
    {
      return std::make_shared<GetTrackingSignals>();
    }

    GetTrackingSignalsPtr GetTrackingSignals::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetTrackingSignals>(ptr);
    }

    bool GetTrackingSignals::isValid() const
    {
      
        return m_values.IsObject()
        ;

    }

    std::string GetTrackingSignals::documentation() const { return Documentation; }


    int GetTrackingSignals::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }

  }
}
