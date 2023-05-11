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
    /// Please note the command SetQzssSatelliteL1cHealth is deprecated since 21.3. You may use SetQzssL1cHealthForSV.
    /// 
    /// Set QZSS L1C health (Health of L1C signal)
    ///
    /// Name        Type            Description
    /// ----------- --------------- -------------------------------------------------------------------------------------------
    /// SvId        int             Satellite SV ID 1..10, or use 0 to apply new value to all satellites.
    /// Health      bool            L1C health, false = signal OK, true = signal bad
    /// DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.
    ///

    class SetQzssSatelliteL1cHealth;
    typedef std::shared_ptr<SetQzssSatelliteL1cHealth> SetQzssSatelliteL1cHealthPtr;
    
    
    class SetQzssSatelliteL1cHealth : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      SetQzssSatelliteL1cHealth();

      SetQzssSatelliteL1cHealth(int svId, bool health, const Sdx::optional<std::string>& dataSetName = {});
  
      static SetQzssSatelliteL1cHealthPtr create(int svId, bool health, const Sdx::optional<std::string>& dataSetName = {});
      static SetQzssSatelliteL1cHealthPtr dynamicCast(CommandBasePtr ptr);
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

