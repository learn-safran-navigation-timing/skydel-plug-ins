#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetPseudorangeRamps
///
#include "gen/GetPseudorangeRamps.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetPseudorangeRamps::CmdName = "GetPseudorangeRamps";
    const char* const GetPseudorangeRamps::Documentation = "Please note the command GetPseudorangeRamps is deprecated since 21.3. You may use GetAllPseudorangeRampForSV.\n\nGet a list of all the pseudorange ramps IDs for one satellite of a system";

    REGISTER_COMMAND_FACTORY(GetPseudorangeRamps);


    GetPseudorangeRamps::GetPseudorangeRamps()
      : CommandBase(CmdName)
    {}

    GetPseudorangeRamps::GetPseudorangeRamps(const std::string& system, int prn)
      : CommandBase(CmdName)
    {

      setSystem(system);
      setPrn(prn);
    }


    GetPseudorangeRampsPtr GetPseudorangeRamps::create(const std::string& system, int prn)
    {
      return GetPseudorangeRampsPtr(new GetPseudorangeRamps(system, prn));
    }

    GetPseudorangeRampsPtr GetPseudorangeRamps::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetPseudorangeRamps>(ptr);
    }

    bool GetPseudorangeRamps::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["System"])
          && parse_json<int>::is_valid(m_values["Prn"])
        ;

    }

    std::string GetPseudorangeRamps::documentation() const { return Documentation; }


    int GetPseudorangeRamps::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string GetPseudorangeRamps::system() const
    {
      return parse_json<std::string>::parse(m_values["System"]);
    }

    void GetPseudorangeRamps::setSystem(const std::string& system)
    {
      m_values.AddMember("System", parse_json<std::string>::format(system, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetPseudorangeRamps::prn() const
    {
      return parse_json<int>::parse(m_values["Prn"]);
    }

    void GetPseudorangeRamps::setPrn(int prn)
    {
      m_values.AddMember("Prn", parse_json<int>::format(prn, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
