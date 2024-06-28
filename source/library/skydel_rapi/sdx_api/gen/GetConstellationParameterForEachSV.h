#pragma once

#include <memory>
#include "command_base.h"

#include <optional>
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get "GPS", "Galileo", "BeiDou", "QZSS", "NavIC" or "PULSAR" constellation parameter value for all satellites.
    ///
    /// Name        Type            Description
    /// ----------- --------------- -------------------------------------------------------------------------------------------
    /// System      string          "GPS", "Galileo", "BeiDou", "QZSS", "NavIC" or "PULSAR".
    /// ParamName   string          Refer to SetConstellationParameterForSV for accepted names.
    /// DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.
    ///

    class GetConstellationParameterForEachSV;
    typedef std::shared_ptr<GetConstellationParameterForEachSV> GetConstellationParameterForEachSVPtr;
    
    
    class GetConstellationParameterForEachSV : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      GetConstellationParameterForEachSV();

      GetConstellationParameterForEachSV(const std::string& system, const std::string& paramName, const std::optional<std::string>& dataSetName = {});

      static GetConstellationParameterForEachSVPtr create(const std::string& system, const std::string& paramName, const std::optional<std::string>& dataSetName = {});
      static GetConstellationParameterForEachSVPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;


      // **** system ****
      std::string system() const;
      void setSystem(const std::string& system);


      // **** paramName ****
      std::string paramName() const;
      void setParamName(const std::string& paramName);


      // **** dataSetName ****
      std::optional<std::string> dataSetName() const;
      void setDataSetName(const std::optional<std::string>& dataSetName);
    };
    
  }
}

