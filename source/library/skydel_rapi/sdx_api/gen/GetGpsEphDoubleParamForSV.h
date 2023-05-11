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
    /// Get various parameters in the GPS ephemeris
    /// 
    ///   ParamName         Unit
    ///   "ClockBias"       sec
    ///   "ClockDrift"      sec/sec
    ///   "ClockDriftRate"  sec/sec^2
    ///   "Crs"             meter
    ///   "Crc"             meter
    ///   "Cis"             rad
    ///   "Cic"             rad
    ///   "Cus"             rad
    ///   "Cuc"             rad
    ///   "DeltaN"          rad/sec
    ///   "M0"              rad
    ///   "Eccentricity"    -
    ///   "SqrtA"           sqrt(meter)
    ///   "BigOmega"        rad
    ///   "I0"              rad
    ///   "LittleOmega"     rad
    ///   "BigOmegaDot"     rad/sec
    ///   "Idot"            rad/sec
    ///   "Accuracy"        meter
    ///   "Adot"            meters/sec
    ///   "DeltaN0dot"      rad/sec^2
    ///   "Tgd"             sec
    ///   "IscL1Ca"         sec
    ///   "IscL2C"          sec
    ///   "IscL5I5"         sec
    ///   "IscL5Q5"         sec
    ///   "IscL1CP"         sec
    ///   "IscL1CD"         sec
    ///
    /// Name        Type            Description
    /// ----------- --------------- -------------------------------------------------------------------------------------------
    /// SvId        int             Satellite SV ID 1..32, or use 0 to apply new value to all satellites.
    /// ParamName   string          Parameter name (see table above for accepted names)
    /// DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.
    ///

    class GetGpsEphDoubleParamForSV;
    typedef std::shared_ptr<GetGpsEphDoubleParamForSV> GetGpsEphDoubleParamForSVPtr;
    
    
    class GetGpsEphDoubleParamForSV : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetGpsEphDoubleParamForSV();

      GetGpsEphDoubleParamForSV(int svId, const std::string& paramName, const Sdx::optional<std::string>& dataSetName = {});
  
      static GetGpsEphDoubleParamForSVPtr create(int svId, const std::string& paramName, const Sdx::optional<std::string>& dataSetName = {});
      static GetGpsEphDoubleParamForSVPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** svId ****
      int svId() const;
      void setSvId(int svId);


      // **** paramName ****
      std::string paramName() const;
      void setParamName(const std::string& paramName);


      // **** dataSetName ****
      Sdx::optional<std::string> dataSetName() const;
      void setDataSetName(const Sdx::optional<std::string>& dataSetName);
    };
  }
}

