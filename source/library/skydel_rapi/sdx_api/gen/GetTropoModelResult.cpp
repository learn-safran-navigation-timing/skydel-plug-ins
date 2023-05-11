#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetTropoModelResult
///
#include "gen/GetTropoModelResult.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetTropoModelResult::CmdName = "GetTropoModelResult";
    const char* const GetTropoModelResult::Documentation = "Result of GetTropoModel.";

    REGISTER_COMMAND_RESULT_FACTORY(GetTropoModelResult);


    GetTropoModelResult::GetTropoModelResult()
      : CommandResult(CmdName)
    {}

    GetTropoModelResult::GetTropoModelResult(CommandBasePtr relatedCommand, const std::string& model)
      : CommandResult(CmdName, relatedCommand)
    {

      setModel(model);
    }


    GetTropoModelResultPtr GetTropoModelResult::create(CommandBasePtr relatedCommand, const std::string& model)
    {
      return std::make_shared<GetTropoModelResult>(relatedCommand, model);
    }

    GetTropoModelResultPtr GetTropoModelResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetTropoModelResult>(ptr);
    }

    bool GetTropoModelResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Model"])
        ;

    }

    std::string GetTropoModelResult::documentation() const { return Documentation; }


    std::string GetTropoModelResult::model() const
    {
      return parse_json<std::string>::parse(m_values["Model"]);
    }

    void GetTropoModelResult::setModel(const std::string& model)
    {
      m_values.AddMember("Model", parse_json<std::string>::format(model, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
