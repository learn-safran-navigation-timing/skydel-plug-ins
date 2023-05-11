#pragma once

#include <memory>
#include "command_base.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get infos about the Galileo I/NAV message modification with this ID.
    ///
    /// Name Type   Description
    /// ---- ------ ------------------------------
    /// Id   string Unique identifier of the event
    ///

    class GetMessageModificationToGalileoINav;
    typedef std::shared_ptr<GetMessageModificationToGalileoINav> GetMessageModificationToGalileoINavPtr;
    
    
    class GetMessageModificationToGalileoINav : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetMessageModificationToGalileoINav();

      GetMessageModificationToGalileoINav(const std::string& id);
  
      static GetMessageModificationToGalileoINavPtr create(const std::string& id);
      static GetMessageModificationToGalileoINavPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** id ****
      std::string id() const;
      void setId(const std::string& id);
    };
  }
}

