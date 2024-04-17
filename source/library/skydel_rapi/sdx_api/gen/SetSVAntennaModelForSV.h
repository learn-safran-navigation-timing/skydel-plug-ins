#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Set the antenna model used by the SV.
    ///
    /// Name             Type   Description
    /// ---------------- ------ ---------------------------------------------------------------------------
    /// System           string "GPS", "GLONASS", "Galileo", "BeiDou", "SBAS", "QZSS", "NavIC" or "PULSAR".
    /// SvId             int    The satellite's SV ID.
    /// AntennaModelName string SV antenna model name.
    ///

    class SetSVAntennaModelForSV;
    typedef std::shared_ptr<SetSVAntennaModelForSV> SetSVAntennaModelForSVPtr;
    
    
    class SetSVAntennaModelForSV : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      SetSVAntennaModelForSV();

      SetSVAntennaModelForSV(const std::string& system, int svId, const std::string& antennaModelName);

      static SetSVAntennaModelForSVPtr create(const std::string& system, int svId, const std::string& antennaModelName);
      static SetSVAntennaModelForSVPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;


      // **** system ****
      std::string system() const;
      void setSystem(const std::string& system);


      // **** svId ****
      int svId() const;
      void setSvId(int svId);


      // **** antennaModelName ****
      std::string antennaModelName() const;
      void setAntennaModelName(const std::string& antennaModelName);
    };
    
  }
}

