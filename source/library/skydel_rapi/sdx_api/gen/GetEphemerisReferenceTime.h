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
    /// Please note the command GetEphemerisReferenceTime is deprecated since 21.3. You may use GetEphemerisReferenceTimeForSV.
    /// 
    /// Get the ephemeris reference time for the specified constellation.
    ///
    /// Name        Type            Description
    /// ----------- --------------- -------------------------------------------------------------------------------------------
    /// System      string          "GPS", "Galileo", "BeiDou", "QZSS" or "NavIC"
    /// SvId        int             The satellite's SV ID.
    /// DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.
    ///

    class GetEphemerisReferenceTime;
    typedef std::shared_ptr<GetEphemerisReferenceTime> GetEphemerisReferenceTimePtr;
    
    
    class GetEphemerisReferenceTime : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetEphemerisReferenceTime();

      GetEphemerisReferenceTime(const std::string& system, int svId, const Sdx::optional<std::string>& dataSetName = {});
  
      static GetEphemerisReferenceTimePtr create(const std::string& system, int svId, const Sdx::optional<std::string>& dataSetName = {});
      static GetEphemerisReferenceTimePtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** system ****
      std::string system() const;
      void setSystem(const std::string& system);


      // **** svId ****
      int svId() const;
      void setSvId(int svId);


      // **** dataSetName ****
      Sdx::optional<std::string> dataSetName() const;
      void setDataSetName(const Sdx::optional<std::string>& dataSetName);
    };
  }
}

