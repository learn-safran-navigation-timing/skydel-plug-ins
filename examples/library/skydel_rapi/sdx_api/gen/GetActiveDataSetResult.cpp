#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetActiveDataSetResult
///
#include "gen/GetActiveDataSetResult.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetActiveDataSetResult::CmdName = "GetActiveDataSetResult";
    const char* const GetActiveDataSetResult::Documentation = "Result of GetActiveDataSet.";

    REGISTER_COMMAND_RESULT_FACTORY(GetActiveDataSetResult);


    GetActiveDataSetResult::GetActiveDataSetResult()
      : CommandResult(CmdName)
    {}

    GetActiveDataSetResult::GetActiveDataSetResult(CommandBasePtr relatedCommand, const std::string& system, const std::string& dataSetName)
      : CommandResult(CmdName, relatedCommand)
    {

      setSystem(system);
      setDataSetName(dataSetName);
    }


    GetActiveDataSetResultPtr GetActiveDataSetResult::create(CommandBasePtr relatedCommand, const std::string& system, const std::string& dataSetName)
    {
      return GetActiveDataSetResultPtr(new GetActiveDataSetResult(relatedCommand, system, dataSetName));
    }

    GetActiveDataSetResultPtr GetActiveDataSetResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetActiveDataSetResult>(ptr);
    }

    bool GetActiveDataSetResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["System"])
          && parse_json<std::string>::is_valid(m_values["DataSetName"])
        ;

    }

    std::string GetActiveDataSetResult::documentation() const { return Documentation; }


    std::string GetActiveDataSetResult::system() const
    {
      return parse_json<std::string>::parse(m_values["System"]);
    }

    void GetActiveDataSetResult::setSystem(const std::string& system)
    {
      m_values.AddMember("System", parse_json<std::string>::format(system, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string GetActiveDataSetResult::dataSetName() const
    {
      return parse_json<std::string>::parse(m_values["DataSetName"]);
    }

    void GetActiveDataSetResult::setDataSetName(const std::string& dataSetName)
    {
      m_values.AddMember("DataSetName", parse_json<std::string>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
