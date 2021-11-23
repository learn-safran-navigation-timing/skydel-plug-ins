#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of IsGpsSatMotionFixed
///
#include "gen/IsGpsSatMotionFixed.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const IsGpsSatMotionFixed::CmdName = "IsGpsSatMotionFixed";
    const char* const IsGpsSatMotionFixed::Documentation = "Please note the command IsGpsSatMotionFixed is deprecated since 21.3. You may use IsSatMotionFixed.\n\nTells if the satellite is fixed (True) or not fixed (false).";

    REGISTER_COMMAND_FACTORY(IsGpsSatMotionFixed);


    IsGpsSatMotionFixed::IsGpsSatMotionFixed()
      : CommandBase(CmdName)
    {}

    IsGpsSatMotionFixed::IsGpsSatMotionFixed(int prn)
      : CommandBase(CmdName)
    {

      setPrn(prn);
    }


    IsGpsSatMotionFixedPtr IsGpsSatMotionFixed::create(int prn)
    {
      return IsGpsSatMotionFixedPtr(new IsGpsSatMotionFixed(prn));
    }

    IsGpsSatMotionFixedPtr IsGpsSatMotionFixed::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<IsGpsSatMotionFixed>(ptr);
    }

    bool IsGpsSatMotionFixed::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["Prn"])
        ;

    }

    std::string IsGpsSatMotionFixed::documentation() const { return Documentation; }


    int IsGpsSatMotionFixed::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    int IsGpsSatMotionFixed::prn() const
    {
      return parse_json<int>::parse(m_values["Prn"]);
    }

    void IsGpsSatMotionFixed::setPrn(int prn)
    {
      m_values.AddMember("Prn", parse_json<int>::format(prn, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
