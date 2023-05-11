#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get infos about the SBAS NAV message modification with this ID.
    ///
    /// Name Type   Description
    /// ---- ------ ------------------------------
    /// Id   string Unique identifier of the event
    ///

    class GetMessageModificationToSbasNav;
    typedef std::shared_ptr<GetMessageModificationToSbasNav> GetMessageModificationToSbasNavPtr;
    
    
    class GetMessageModificationToSbasNav : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetMessageModificationToSbasNav();

      GetMessageModificationToSbasNav(const std::string& id);

      static GetMessageModificationToSbasNavPtr create(const std::string& id);
      static GetMessageModificationToSbasNavPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** id ****
      std::string id() const;
      void setId(const std::string& id);
    };
    
  }
}

