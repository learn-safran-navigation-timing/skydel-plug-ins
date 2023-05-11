#pragma once

#include <memory>
#include "command_result.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetVehicleType.
    ///
    /// Name Type   Description
    /// ---- ------ ----------------------------------------------------------
    /// Type string Vehicle type ("Ground / Water" or "Airborne / Spaceborne")
    ///

    class GetVehicleTypeResult;
    typedef std::shared_ptr<GetVehicleTypeResult> GetVehicleTypeResultPtr;
    
    
    class GetVehicleTypeResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetVehicleTypeResult();

      GetVehicleTypeResult(CommandBasePtr relatedCommand, const std::string& type);
  
      static GetVehicleTypeResultPtr create(CommandBasePtr relatedCommand, const std::string& type);
      static GetVehicleTypeResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;


      // **** type ****
      std::string type() const;
      void setType(const std::string& type);
    };
  }
}

