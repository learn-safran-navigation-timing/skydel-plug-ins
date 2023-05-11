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
    /// Result of GetQzssNavAlertFlagForSV.
    ///
    /// Name        Type            Description
    /// ----------- --------------- -------------------------------------------------------------------------------------------
    /// SvId        int             Satellite SV ID 1..10, or use 0 to apply new value to all satellites.
    /// Alert       bool            QZSS NAV Alert Flag, false = No Alert, true = Alert
    /// DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.
    ///

    class GetQzssNavAlertFlagForSVResult;
    typedef std::shared_ptr<GetQzssNavAlertFlagForSVResult> GetQzssNavAlertFlagForSVResultPtr;
    typedef GetQzssNavAlertFlagForSVResult GetQzssSatelliteNavAlertFlagResult;
    typedef std::shared_ptr<GetQzssSatelliteNavAlertFlagResult> GetQzssSatelliteNavAlertFlagResultPtr;
    
    class GetQzssNavAlertFlagForSVResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetQzssNavAlertFlagForSVResult();

      GetQzssNavAlertFlagForSVResult(CommandBasePtr relatedCommand, int svId, bool alert, const Sdx::optional<std::string>& dataSetName = {});
  
      static GetQzssNavAlertFlagForSVResultPtr create(CommandBasePtr relatedCommand, int svId, bool alert, const Sdx::optional<std::string>& dataSetName = {});
      static GetQzssNavAlertFlagForSVResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;


      // **** svId ****
      int svId() const;
      void setSvId(int svId);


      // **** alert ****
      bool alert() const;
      void setAlert(bool alert);


      // **** dataSetName ****
      Sdx::optional<std::string> dataSetName() const;
      void setDataSetName(const Sdx::optional<std::string>& dataSetName);
    };
  }
}

