#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetPseudorangeRamp
///
#include "gen/GetPseudorangeRamp.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetPseudorangeRamp::CmdName = "GetPseudorangeRamp";
    const char* const GetPseudorangeRamp::Documentation = "Please note the command GetPseudorangeRamp is deprecated since 21.3. You may use GetPseudorangeRampForSV.\n\nGet PSR ramp event. This function lets user change the pseudorange of any satellite.\nIf PRN is set to 0, the change is applied to all satellites.\n\n         Hold Start Time\n         |     Hold Stop Time\n         |     |\n         ...........\n       ..       ...\n       ..        ...\n  .......           .........> Time\n      |           |\n      Start Time      Stop Time\n";

    REGISTER_COMMAND_FACTORY(GetPseudorangeRamp);


    GetPseudorangeRamp::GetPseudorangeRamp()
      : CommandBase(CmdName)
    {}

    GetPseudorangeRamp::GetPseudorangeRamp(const std::string& id)
      : CommandBase(CmdName)
    {

      setId(id);
    }


    GetPseudorangeRampPtr GetPseudorangeRamp::create(const std::string& id)
    {
      return GetPseudorangeRampPtr(new GetPseudorangeRamp(id));
    }

    GetPseudorangeRampPtr GetPseudorangeRamp::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetPseudorangeRamp>(ptr);
    }

    bool GetPseudorangeRamp::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Id"])
        ;

    }

    std::string GetPseudorangeRamp::documentation() const { return Documentation; }


    int GetPseudorangeRamp::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string GetPseudorangeRamp::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void GetPseudorangeRamp::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
