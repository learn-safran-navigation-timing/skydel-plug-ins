#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of IsGalileoSatMotionFixed
///
#include "gen/IsGalileoSatMotionFixed.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const IsGalileoSatMotionFixed::CmdName = "IsGalileoSatMotionFixed";
    const char* const IsGalileoSatMotionFixed::Documentation = "Please note the command IsGalileoSatMotionFixed is deprecated since 21.3. You may use IsSatMotionFixed.\n\nTells if the satellite is fixed (True) or not fixed (false).";

    REGISTER_COMMAND_FACTORY(IsGalileoSatMotionFixed);


    IsGalileoSatMotionFixed::IsGalileoSatMotionFixed()
      : CommandBase(CmdName)
    {}

    IsGalileoSatMotionFixed::IsGalileoSatMotionFixed(int prn)
      : CommandBase(CmdName)
    {

      setPrn(prn);
    }


    IsGalileoSatMotionFixedPtr IsGalileoSatMotionFixed::create(int prn)
    {
      return IsGalileoSatMotionFixedPtr(new IsGalileoSatMotionFixed(prn));
    }

    IsGalileoSatMotionFixedPtr IsGalileoSatMotionFixed::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<IsGalileoSatMotionFixed>(ptr);
    }

    bool IsGalileoSatMotionFixed::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["Prn"])
        ;

    }

    std::string IsGalileoSatMotionFixed::documentation() const { return Documentation; }


    int IsGalileoSatMotionFixed::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    int IsGalileoSatMotionFixed::prn() const
    {
      return parse_json<int>::parse(m_values["Prn"]);
    }

    void IsGalileoSatMotionFixed::setPrn(int prn)
    {
      m_values.AddMember("Prn", parse_json<int>::format(prn, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
