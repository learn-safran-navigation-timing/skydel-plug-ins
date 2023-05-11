#pragma once

#include <memory>
#include "command_base.h"
#include "sdx_optional.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Set GPS L1 health (used with CNAV and CNAV2)
    ///
    /// Name        Type            Description
    /// ----------- --------------- -------------------------------------------------------------------------------------------
    /// SvId        int             Satellite's SV ID 1..32
    /// Health      bool            L1 health, false = signal OK, true = signal bad or unavailable
    /// DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.
    ///

    class SetGpsL1HealthForSV;
    typedef std::shared_ptr<SetGpsL1HealthForSV> SetGpsL1HealthForSVPtr;
    
    
    class SetGpsL1HealthForSV : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      SetGpsL1HealthForSV();

      SetGpsL1HealthForSV(int svId, bool health, const Sdx::optional<std::string>& dataSetName = {});
  
      static SetGpsL1HealthForSVPtr create(int svId, bool health, const Sdx::optional<std::string>& dataSetName = {});
      static SetGpsL1HealthForSVPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** svId ****
      int svId() const;
      void setSvId(int svId);


      // **** health ****
      bool health() const;
      void setHealth(bool health);


      // **** dataSetName ****
      Sdx::optional<std::string> dataSetName() const;
      void setDataSetName(const Sdx::optional<std::string>& dataSetName);
    };
  }
}

