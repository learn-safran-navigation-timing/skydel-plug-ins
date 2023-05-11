#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetHilExtrapolationStateResult
///
#include "gen/GetHilExtrapolationStateResult.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetHilExtrapolationStateResult::CmdName = "GetHilExtrapolationStateResult";
    const char* const GetHilExtrapolationStateResult::Documentation = "Result of GetHilExtrapolationState.";

    REGISTER_COMMAND_RESULT_FACTORY(GetHilExtrapolationStateResult);


    GetHilExtrapolationStateResult::GetHilExtrapolationStateResult()
      : CommandResult(CmdName)
    {}

    GetHilExtrapolationStateResult::GetHilExtrapolationStateResult(CommandBasePtr relatedCommand, const Sdx::HilExtrapolationState& state, int elapsedTime)
      : CommandResult(CmdName, relatedCommand)
    {

      setState(state);
      setElapsedTime(elapsedTime);
    }


    GetHilExtrapolationStateResultPtr GetHilExtrapolationStateResult::create(CommandBasePtr relatedCommand, const Sdx::HilExtrapolationState& state, int elapsedTime)
    {
      return std::make_shared<GetHilExtrapolationStateResult>(relatedCommand, state, elapsedTime);
    }

    GetHilExtrapolationStateResultPtr GetHilExtrapolationStateResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetHilExtrapolationStateResult>(ptr);
    }

    bool GetHilExtrapolationStateResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<Sdx::HilExtrapolationState>::is_valid(m_values["State"])
          && parse_json<int>::is_valid(m_values["ElapsedTime"])
        ;

    }

    std::string GetHilExtrapolationStateResult::documentation() const { return Documentation; }


    Sdx::HilExtrapolationState GetHilExtrapolationStateResult::state() const
    {
      return parse_json<Sdx::HilExtrapolationState>::parse(m_values["State"]);
    }

    void GetHilExtrapolationStateResult::setState(const Sdx::HilExtrapolationState& state)
    {
      m_values.AddMember("State", parse_json<Sdx::HilExtrapolationState>::format(state, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetHilExtrapolationStateResult::elapsedTime() const
    {
      return parse_json<int>::parse(m_values["ElapsedTime"]);
    }

    void GetHilExtrapolationStateResult::setElapsedTime(int elapsedTime)
    {
      m_values.AddMember("ElapsedTime", parse_json<int>::format(elapsedTime, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
