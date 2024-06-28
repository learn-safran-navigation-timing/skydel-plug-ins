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
    /// Please note the command GetQzssEphDoubleParamForSV is deprecated since 23.11. You may use GetConstellationParameterForSV.
    /// 
    /// Get various parameters in the QZSS ephemeris.
    ///
    /// Name        Type            Description
    /// ----------- --------------- -------------------------------------------------------------------------------------------
    /// SvId        int             The satellite's SV ID 1..10 (use 0 to apply to all satellites)
    /// ParamName   string          In meters:  "Crs", "Crc"
    ///                             In radians: "Cis", "Cic", "Cus", "Cuc"
    ///                             In seconds: "Tgd", "IscL1Ca", "IscL2C", "IscL5I5", "IscL5Q5", "IscL1CP", "IscL1CD"
    /// DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.
    ///

    class GetQzssEphDoubleParamForSV;
    typedef std::shared_ptr<GetQzssEphDoubleParamForSV> GetQzssEphDoubleParamForSVPtr;
    
    
    class GetQzssEphDoubleParamForSV : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;

      static const char* const Deprecated;


      GetQzssEphDoubleParamForSV();

      GetQzssEphDoubleParamForSV(int svId, const std::string& paramName, const std::optional<std::string>& dataSetName = {});

      static GetQzssEphDoubleParamForSVPtr create(int svId, const std::string& paramName, const std::optional<std::string>& dataSetName = {});
      static GetQzssEphDoubleParamForSVPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual std::optional<std::string> deprecated() const override;

      virtual int executePermission() const override;


      // **** svId ****
      int svId() const;
      void setSvId(int svId);


      // **** paramName ****
      std::string paramName() const;
      void setParamName(const std::string& paramName);


      // **** dataSetName ****
      std::optional<std::string> dataSetName() const;
      void setDataSetName(const std::optional<std::string>& dataSetName);
    };
    
  }
}

