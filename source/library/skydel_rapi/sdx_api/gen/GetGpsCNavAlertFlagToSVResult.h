#pragma once

#include <memory>
#include "command_result.h"
#include "command_factory.h"
#include <optional>
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetGpsCNavAlertFlagToSV.
    ///
    /// Name        Type            Description
    /// ----------- --------------- -------------------------------------------------------------------------------------------
    /// SvId        int             Satellite's SV ID 1..32, or use 0 to apply new value to all satellites.
    /// Alert       bool            GPS CNAV Alert Flag, false = No Alert, true = Alert
    /// DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.
    ///

    class GetGpsCNavAlertFlagToSVResult;
    typedef std::shared_ptr<GetGpsCNavAlertFlagToSVResult> GetGpsCNavAlertFlagToSVResultPtr;
    
    
    class GetGpsCNavAlertFlagToSVResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      GetGpsCNavAlertFlagToSVResult();

      GetGpsCNavAlertFlagToSVResult(int svId, bool alert, const std::optional<std::string>& dataSetName = {});

      GetGpsCNavAlertFlagToSVResult(CommandBasePtr relatedCommand, int svId, bool alert, const std::optional<std::string>& dataSetName = {});

      static GetGpsCNavAlertFlagToSVResultPtr create(int svId, bool alert, const std::optional<std::string>& dataSetName = {});

      static GetGpsCNavAlertFlagToSVResultPtr create(CommandBasePtr relatedCommand, int svId, bool alert, const std::optional<std::string>& dataSetName = {});
      static GetGpsCNavAlertFlagToSVResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;


      // **** svId ****
      int svId() const;
      void setSvId(int svId);


      // **** alert ****
      bool alert() const;
      void setAlert(bool alert);


      // **** dataSetName ****
      std::optional<std::string> dataSetName() const;
      void setDataSetName(const std::optional<std::string>& dataSetName);
    };
    REGISTER_COMMAND_TO_FACTORY_DECL(GetGpsCNavAlertFlagToSVResult);
  }
}

