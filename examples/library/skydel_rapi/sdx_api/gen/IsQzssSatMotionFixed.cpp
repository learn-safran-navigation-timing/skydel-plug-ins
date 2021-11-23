#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of IsQzssSatMotionFixed
///
#include "gen/IsQzssSatMotionFixed.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const IsQzssSatMotionFixed::CmdName = "IsQzssSatMotionFixed";
    const char* const IsQzssSatMotionFixed::Documentation = "Please note the command IsQzssSatMotionFixed is deprecated since 20.9. You may use IsSatMotionFixed.\n\nTells if the satellite is fixed (True) or not fixed (false).";

    REGISTER_COMMAND_FACTORY(IsQzssSatMotionFixed);


    IsQzssSatMotionFixed::IsQzssSatMotionFixed()
      : CommandBase(CmdName)
    {}

    IsQzssSatMotionFixed::IsQzssSatMotionFixed(int svId)
      : CommandBase(CmdName)
    {

      setSvId(svId);
    }


    IsQzssSatMotionFixedPtr IsQzssSatMotionFixed::create(int svId)
    {
      return IsQzssSatMotionFixedPtr(new IsQzssSatMotionFixed(svId));
    }

    IsQzssSatMotionFixedPtr IsQzssSatMotionFixed::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<IsQzssSatMotionFixed>(ptr);
    }

    bool IsQzssSatMotionFixed::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["SvId"])
        ;

    }

    std::string IsQzssSatMotionFixed::documentation() const { return Documentation; }


    int IsQzssSatMotionFixed::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    int IsQzssSatMotionFixed::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void IsQzssSatMotionFixed::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
