#pragma once

#include <memory>
#include "command_result.h"
#include <string>
#include <vector>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetPseudorangeNoiseOffsetForEachSV.
    ///
    /// Name    Type         Description
    /// ------- ------------ ----------------------------------------------------------------
    /// System  string       "GPS", "GLONASS", "Galileo", "BeiDou", "SBAS", "QZSS" or "NavIC"
    /// Enabled array bool   If true, the offset is enabled (applied)
    /// Offset  array double The constant offset in metters
    ///

    class GetPseudorangeNoiseOffsetForEachSVResult;
    typedef std::shared_ptr<GetPseudorangeNoiseOffsetForEachSVResult> GetPseudorangeNoiseOffsetForEachSVResultPtr;
    typedef GetPseudorangeNoiseOffsetForEachSVResult GetAllSatellitesPseudorangeNoiseOffsetResult;
    typedef std::shared_ptr<GetAllSatellitesPseudorangeNoiseOffsetResult> GetAllSatellitesPseudorangeNoiseOffsetResultPtr;
    
    class GetPseudorangeNoiseOffsetForEachSVResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetPseudorangeNoiseOffsetForEachSVResult();

      GetPseudorangeNoiseOffsetForEachSVResult(CommandBasePtr relatedCommand, const std::string& system, const std::vector<bool>& enabled, const std::vector<double>& offset);
  
      static GetPseudorangeNoiseOffsetForEachSVResultPtr create(CommandBasePtr relatedCommand, const std::string& system, const std::vector<bool>& enabled, const std::vector<double>& offset);
      static GetPseudorangeNoiseOffsetForEachSVResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;


      // **** system ****
      std::string system() const;
      void setSystem(const std::string& system);


      // **** enabled ****
      std::vector<bool> enabled() const;
      void setEnabled(const std::vector<bool>& enabled);


      // **** offset ****
      std::vector<double> offset() const;
      void setOffset(const std::vector<double>& offset);
    };
  }
}

