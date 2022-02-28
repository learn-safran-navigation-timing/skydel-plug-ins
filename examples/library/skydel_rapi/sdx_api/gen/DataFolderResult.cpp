#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of DataFolderResult
///
#include "gen/DataFolderResult.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const DataFolderResult::CmdName = "DataFolderResult";
    const char* const DataFolderResult::Documentation = "Result of GetDataFolder.";

    REGISTER_COMMAND_RESULT_FACTORY(DataFolderResult);


    DataFolderResult::DataFolderResult()
      : CommandResult(CmdName)
    {}

    DataFolderResult::DataFolderResult(CommandBasePtr relatedCommand, const std::string& folder)
      : CommandResult(CmdName, relatedCommand)
    {

      setFolder(folder);
    }


    DataFolderResultPtr DataFolderResult::create(CommandBasePtr relatedCommand, const std::string& folder)
    {
      return DataFolderResultPtr(new DataFolderResult(relatedCommand, folder));
    }

    DataFolderResultPtr DataFolderResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<DataFolderResult>(ptr);
    }

    bool DataFolderResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Folder"])
        ;

    }

    std::string DataFolderResult::documentation() const { return Documentation; }


    std::string DataFolderResult::folder() const
    {
      return parse_json<std::string>::parse(m_values["Folder"]);
    }

    void DataFolderResult::setFolder(const std::string& folder)
    {
      m_values.AddMember("Folder", parse_json<std::string>::format(folder, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
