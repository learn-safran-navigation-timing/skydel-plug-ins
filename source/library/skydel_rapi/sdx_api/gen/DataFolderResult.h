#pragma once

#include <memory>
#include "command_result.h"
#include "command_factory.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetDataFolder.
    ///
    /// Name   Type   Description
    /// ------ ------ ------------------
    /// Folder string Skydel Data Folder
    ///

    class DataFolderResult;
    typedef std::shared_ptr<DataFolderResult> DataFolderResultPtr;
    
    
    class DataFolderResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      DataFolderResult();

      DataFolderResult(const std::string& folder);

      DataFolderResult(CommandBasePtr relatedCommand, const std::string& folder);

      static DataFolderResultPtr create(const std::string& folder);

      static DataFolderResultPtr create(CommandBasePtr relatedCommand, const std::string& folder);
      static DataFolderResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;


      // **** folder ****
      std::string folder() const;
      void setFolder(const std::string& folder);
    };
    REGISTER_COMMAND_TO_FACTORY_DECL(DataFolderResult);
  }
}

