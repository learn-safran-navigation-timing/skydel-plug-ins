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
    /// Please note the command GetQzssEphBoolParamForEachSV is deprecated since 23.11. You may use GetConstellationParameterForSV.
    /// 
    /// Get QZSS ephemeris boolean parameter value for all satellites
    ///
    /// Name        Type            Description
    /// ----------- --------------- -------------------------------------------------------------------------------------------
    /// ParamName   string          Refer to SetQzssEphemerisBoolParam for accepted names
    /// DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.
    ///

    class GetQzssEphBoolParamForEachSV;
    typedef std::shared_ptr<GetQzssEphBoolParamForEachSV> GetQzssEphBoolParamForEachSVPtr;
    
    
    class GetQzssEphBoolParamForEachSV : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;

      static const char* const Deprecated;


      GetQzssEphBoolParamForEachSV();

      GetQzssEphBoolParamForEachSV(const std::string& paramName, const Sdx::optional<std::string>& dataSetName = {});

      static GetQzssEphBoolParamForEachSVPtr create(const std::string& paramName, const Sdx::optional<std::string>& dataSetName = {});
      static GetQzssEphBoolParamForEachSVPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual Sdx::optional<std::string> deprecated() const override;

      virtual int executePermission() const override;


      // **** paramName ****
      std::string paramName() const;
      void setParamName(const std::string& paramName);


      // **** dataSetName ****
      Sdx::optional<std::string> dataSetName() const;
      void setDataSetName(const Sdx::optional<std::string>& dataSetName);
    };
    
  }
}

