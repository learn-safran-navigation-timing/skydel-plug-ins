#pragma once

#include <memory>
#include "command_base.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Please note the command ClearAllMessageModifications is deprecated since 21.3. You may use ClearAllMessageModificationsForSignal.
    /// 
    /// Clear the signal for all message modifications.
    ///
    /// Name   Type   Description
    /// ------ ------ -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    /// Signal string Signal key, accepted values : "L1CA", "L1C", "L1P", "L1M", "L2C", "L2P", "L2M", "L5", "G1", "G2", "E1", "E5a", "E5b", "B1", "B2", "B2a", "B1C", "QZSSL1CA", "QZSSL1CB", "QZSSL1S", "NAVICL5", "SBASL1" and "SBASL5"
    ///

    class ClearAllMessageModifications;
    typedef std::shared_ptr<ClearAllMessageModifications> ClearAllMessageModificationsPtr;
    
    
    class ClearAllMessageModifications : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      ClearAllMessageModifications();

      ClearAllMessageModifications(const std::string& signal);
  
      static ClearAllMessageModificationsPtr create(const std::string& signal);
      static ClearAllMessageModificationsPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** signal ****
      std::string signal() const;
      void setSignal(const std::string& signal);
    };
  }
}

