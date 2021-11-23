#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetPseudorangeRampsResult
///
#include "gen/GetPseudorangeRampsResult.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetPseudorangeRampsResult::CmdName = "GetPseudorangeRampsResult";
    const char* const GetPseudorangeRampsResult::Documentation = "result of GetPseudorangeRamps";

    REGISTER_COMMAND_RESULT_FACTORY(GetPseudorangeRampsResult);


    GetPseudorangeRampsResult::GetPseudorangeRampsResult()
      : CommandResult(CmdName)
    {}

    GetPseudorangeRampsResult::GetPseudorangeRampsResult(CommandBasePtr relatedCommand, const std::string& system, int prn, const std::vector<std::string>& ids)
      : CommandResult(CmdName, relatedCommand)
    {

      setSystem(system);
      setPrn(prn);
      setIds(ids);
    }


    GetPseudorangeRampsResultPtr GetPseudorangeRampsResult::create(CommandBasePtr relatedCommand, const std::string& system, int prn, const std::vector<std::string>& ids)
    {
      return GetPseudorangeRampsResultPtr(new GetPseudorangeRampsResult(relatedCommand, system, prn, ids));
    }

    GetPseudorangeRampsResultPtr GetPseudorangeRampsResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetPseudorangeRampsResult>(ptr);
    }

    bool GetPseudorangeRampsResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["System"])
          && parse_json<int>::is_valid(m_values["Prn"])
          && parse_json<std::vector<std::string>>::is_valid(m_values["Ids"])
        ;

    }

    std::string GetPseudorangeRampsResult::documentation() const { return Documentation; }


    std::string GetPseudorangeRampsResult::system() const
    {
      return parse_json<std::string>::parse(m_values["System"]);
    }

    void GetPseudorangeRampsResult::setSystem(const std::string& system)
    {
      m_values.AddMember("System", parse_json<std::string>::format(system, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetPseudorangeRampsResult::prn() const
    {
      return parse_json<int>::parse(m_values["Prn"]);
    }

    void GetPseudorangeRampsResult::setPrn(int prn)
    {
      m_values.AddMember("Prn", parse_json<int>::format(prn, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::vector<std::string> GetPseudorangeRampsResult::ids() const
    {
      return parse_json<std::vector<std::string>>::parse(m_values["Ids"]);
    }

    void GetPseudorangeRampsResult::setIds(const std::vector<std::string>& ids)
    {
      m_values.AddMember("Ids", parse_json<std::vector<std::string>>::format(ids, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
