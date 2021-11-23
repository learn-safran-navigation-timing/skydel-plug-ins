#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of IsBeiDouSatMotionFixedResult
///
#include "gen/IsBeiDouSatMotionFixedResult.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const IsBeiDouSatMotionFixedResult::CmdName = "IsBeiDouSatMotionFixedResult";
    const char* const IsBeiDouSatMotionFixedResult::Documentation = "Result of IsBeiDouSatMotionFixed.";

    REGISTER_COMMAND_RESULT_FACTORY(IsBeiDouSatMotionFixedResult);


    IsBeiDouSatMotionFixedResult::IsBeiDouSatMotionFixedResult()
      : CommandResult(CmdName)
    {}

    IsBeiDouSatMotionFixedResult::IsBeiDouSatMotionFixedResult(CommandBasePtr relatedCommand, int prn, bool isFixed)
      : CommandResult(CmdName, relatedCommand)
    {

      setPrn(prn);
      setIsFixed(isFixed);
    }


    IsBeiDouSatMotionFixedResultPtr IsBeiDouSatMotionFixedResult::create(CommandBasePtr relatedCommand, int prn, bool isFixed)
    {
      return IsBeiDouSatMotionFixedResultPtr(new IsBeiDouSatMotionFixedResult(relatedCommand, prn, isFixed));
    }

    IsBeiDouSatMotionFixedResultPtr IsBeiDouSatMotionFixedResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<IsBeiDouSatMotionFixedResult>(ptr);
    }

    bool IsBeiDouSatMotionFixedResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["Prn"])
          && parse_json<bool>::is_valid(m_values["IsFixed"])
        ;

    }

    std::string IsBeiDouSatMotionFixedResult::documentation() const { return Documentation; }


    int IsBeiDouSatMotionFixedResult::prn() const
    {
      return parse_json<int>::parse(m_values["Prn"]);
    }

    void IsBeiDouSatMotionFixedResult::setPrn(int prn)
    {
      m_values.AddMember("Prn", parse_json<int>::format(prn, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool IsBeiDouSatMotionFixedResult::isFixed() const
    {
      return parse_json<bool>::parse(m_values["IsFixed"]);
    }

    void IsBeiDouSatMotionFixedResult::setIsFixed(bool isFixed)
    {
      m_values.AddMember("IsFixed", parse_json<bool>::format(isFixed, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
