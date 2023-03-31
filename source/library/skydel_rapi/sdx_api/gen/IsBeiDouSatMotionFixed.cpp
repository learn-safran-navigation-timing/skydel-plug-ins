#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of IsBeiDouSatMotionFixed
///
#include "gen/IsBeiDouSatMotionFixed.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const IsBeiDouSatMotionFixed::CmdName = "IsBeiDouSatMotionFixed";
    const char* const IsBeiDouSatMotionFixed::Documentation = "Please note the command IsBeiDouSatMotionFixed is deprecated since 21.3. You may use IsSatMotionFixed.\n\nTells if the satellite is fixed (True) or not fixed (false).";

    REGISTER_COMMAND_FACTORY(IsBeiDouSatMotionFixed);


    IsBeiDouSatMotionFixed::IsBeiDouSatMotionFixed()
      : CommandBase(CmdName)
    {}

    IsBeiDouSatMotionFixed::IsBeiDouSatMotionFixed(int prn)
      : CommandBase(CmdName)
    {

      setPrn(prn);
    }


    IsBeiDouSatMotionFixedPtr IsBeiDouSatMotionFixed::create(int prn)
    {
      return IsBeiDouSatMotionFixedPtr(new IsBeiDouSatMotionFixed(prn));
    }

    IsBeiDouSatMotionFixedPtr IsBeiDouSatMotionFixed::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<IsBeiDouSatMotionFixed>(ptr);
    }

    bool IsBeiDouSatMotionFixed::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["Prn"])
        ;

    }

    std::string IsBeiDouSatMotionFixed::documentation() const { return Documentation; }


    int IsBeiDouSatMotionFixed::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    int IsBeiDouSatMotionFixed::prn() const
    {
      return parse_json<int>::parse(m_values["Prn"]);
    }

    void IsBeiDouSatMotionFixed::setPrn(int prn)
    {
      m_values.AddMember("Prn", parse_json<int>::format(prn, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
