#pragma once

#include <memory>
#include "command_base.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Import all the CCIR data files from the specified directory.
    ///
    /// Name Type   Description
    /// ---- ------ ---------------
    /// Path string Directory path.
    ///

    class ImportCCIRFilesFromDirectory;
    typedef std::shared_ptr<ImportCCIRFilesFromDirectory> ImportCCIRFilesFromDirectoryPtr;
    
    
    class ImportCCIRFilesFromDirectory : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      ImportCCIRFilesFromDirectory();

      ImportCCIRFilesFromDirectory(const std::string& path);
  
      static ImportCCIRFilesFromDirectoryPtr create(const std::string& path);
      static ImportCCIRFilesFromDirectoryPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** path ****
      std::string path() const;
      void setPath(const std::string& path);
    };
  }
}

