#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetIonoGridErrorAllResult
///
#include "gen/GetIonoGridErrorAllResult.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetIonoGridErrorAllResult::CmdName = "GetIonoGridErrorAllResult";
    const char* const GetIonoGridErrorAllResult::Documentation = "Result of GetIonoGridErrorAll.";

    REGISTER_COMMAND_RESULT_FACTORY(GetIonoGridErrorAllResult);


    GetIonoGridErrorAllResult::GetIonoGridErrorAllResult()
      : CommandResult(CmdName)
    {}

    GetIonoGridErrorAllResult::GetIonoGridErrorAllResult(CommandBasePtr relatedCommand, const std::vector<std::vector<double>>& grid)
      : CommandResult(CmdName, relatedCommand)
    {

      setGrid(grid);
    }


    GetIonoGridErrorAllResultPtr GetIonoGridErrorAllResult::create(CommandBasePtr relatedCommand, const std::vector<std::vector<double>>& grid)
    {
      return GetIonoGridErrorAllResultPtr(new GetIonoGridErrorAllResult(relatedCommand, grid));
    }

    GetIonoGridErrorAllResultPtr GetIonoGridErrorAllResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetIonoGridErrorAllResult>(ptr);
    }

    bool GetIonoGridErrorAllResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::vector<std::vector<double>>>::is_valid(m_values["Grid"])
        ;

    }

    std::string GetIonoGridErrorAllResult::documentation() const { return Documentation; }


    std::vector<std::vector<double>> GetIonoGridErrorAllResult::grid() const
    {
      return parse_json<std::vector<std::vector<double>>>::parse(m_values["Grid"]);
    }

    void GetIonoGridErrorAllResult::setGrid(const std::vector<std::vector<double>>& grid)
    {
      m_values.AddMember("Grid", parse_json<std::vector<std::vector<double>>>::format(grid, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
