#pragma once

#include <memory>
#include "command_result.h"
#include "sdx_optional.h"
#include <string>
#include <vector>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetQzssEphBoolParamForEachSV.
    ///
    /// Name        Type            Description
    /// ----------- --------------- --------------------------------------------------------------------------------------------------
    /// ParamName   string          Refer to SetQzssEphemerisBoolParam for accepted names
    /// Val         array bool      Parameter value for each satellite. Zero based index (index 0 => SV ID 1, index 1 => SV ID 2, etc)
    /// DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.
    ///

    class GetQzssEphBoolParamForEachSVResult;
    typedef std::shared_ptr<GetQzssEphBoolParamForEachSVResult> GetQzssEphBoolParamForEachSVResultPtr;
    typedef GetQzssEphBoolParamForEachSVResult GetQzssEphemerisBoolParamsResult;
    typedef std::shared_ptr<GetQzssEphemerisBoolParamsResult> GetQzssEphemerisBoolParamsResultPtr;
    
    class GetQzssEphBoolParamForEachSVResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetQzssEphBoolParamForEachSVResult();

      GetQzssEphBoolParamForEachSVResult(CommandBasePtr relatedCommand, const std::string& paramName, const std::vector<bool>& val, const Sdx::optional<std::string>& dataSetName = {});
  
      static GetQzssEphBoolParamForEachSVResultPtr create(CommandBasePtr relatedCommand, const std::string& paramName, const std::vector<bool>& val, const Sdx::optional<std::string>& dataSetName = {});
      static GetQzssEphBoolParamForEachSVResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;


      // **** paramName ****
      std::string paramName() const;
      void setParamName(const std::string& paramName);


      // **** val ****
      std::vector<bool> val() const;
      void setVal(const std::vector<bool>& val);


      // **** dataSetName ****
      Sdx::optional<std::string> dataSetName() const;
      void setDataSetName(const Sdx::optional<std::string>& dataSetName);
    };
  }
}

