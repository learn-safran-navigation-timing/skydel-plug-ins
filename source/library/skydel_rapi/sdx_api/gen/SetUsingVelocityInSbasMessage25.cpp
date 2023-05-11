#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetUsingVelocityInSbasMessage25
///
#include "gen/SetUsingVelocityInSbasMessage25.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetUsingVelocityInSbasMessage25::CmdName = "SetUsingVelocityInSbasMessage25";
    const char* const SetUsingVelocityInSbasMessage25::Documentation = "Set whether SBAS message 25 should send velocity corrections";

    REGISTER_COMMAND_FACTORY(SetUsingVelocityInSbasMessage25);


    SetUsingVelocityInSbasMessage25::SetUsingVelocityInSbasMessage25()
      : CommandBase(CmdName)
    {}

    SetUsingVelocityInSbasMessage25::SetUsingVelocityInSbasMessage25(bool useVelocity)
      : CommandBase(CmdName)
    {

      setUseVelocity(useVelocity);
    }


    SetUsingVelocityInSbasMessage25Ptr SetUsingVelocityInSbasMessage25::create(bool useVelocity)
    {
      return std::make_shared<SetUsingVelocityInSbasMessage25>(useVelocity);
    }

    SetUsingVelocityInSbasMessage25Ptr SetUsingVelocityInSbasMessage25::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetUsingVelocityInSbasMessage25>(ptr);
    }

    bool SetUsingVelocityInSbasMessage25::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<bool>::is_valid(m_values["UseVelocity"])
        ;

    }

    std::string SetUsingVelocityInSbasMessage25::documentation() const { return Documentation; }


    int SetUsingVelocityInSbasMessage25::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    bool SetUsingVelocityInSbasMessage25::useVelocity() const
    {
      return parse_json<bool>::parse(m_values["UseVelocity"]);
    }

    void SetUsingVelocityInSbasMessage25::setUseVelocity(bool useVelocity)
    {
      m_values.AddMember("UseVelocity", parse_json<bool>::format(useVelocity, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
