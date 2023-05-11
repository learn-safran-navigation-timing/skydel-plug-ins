#pragma once

#include <memory>
#include "command_result.h"
#include "sdx_optional.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetQzssL1cHealthForSV.
    ///
    /// Name        Type            Description
    /// ----------- --------------- -------------------------------------------------------------------------------------------
    /// SvId        int             Satellite SV ID 1..10, or use 0 to apply new value to all satellites.
    /// Health      bool            L1C health, false = signal OK, true = signal bad
    /// DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.
    ///

    class GetQzssL1cHealthForSVResult;
    typedef std::shared_ptr<GetQzssL1cHealthForSVResult> GetQzssL1cHealthForSVResultPtr;
    typedef GetQzssL1cHealthForSVResult GetQzssSatelliteL1cHealthResult;
    typedef std::shared_ptr<GetQzssSatelliteL1cHealthResult> GetQzssSatelliteL1cHealthResultPtr;
    
    class GetQzssL1cHealthForSVResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetQzssL1cHealthForSVResult();

      GetQzssL1cHealthForSVResult(CommandBasePtr relatedCommand, int svId, bool health, const Sdx::optional<std::string>& dataSetName = {});
  
      static GetQzssL1cHealthForSVResultPtr create(CommandBasePtr relatedCommand, int svId, bool health, const Sdx::optional<std::string>& dataSetName = {});
      static GetQzssL1cHealthForSVResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;


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

