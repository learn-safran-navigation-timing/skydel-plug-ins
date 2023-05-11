#pragma once

#include <memory>
#include "command_result.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetWFAntennaElementModel.
    ///
    /// Name             Type   Description
    /// ---------------- ------ ----------------------------------------------------------------------------------------------------
    /// AntennaModelName string Antenna Model name to set for this element. Antenna models must be defined in vehicle antenna model.
    /// Element          int    One-based index for element in antenna.
    ///

    class GetWFAntennaElementModelResult;
    typedef std::shared_ptr<GetWFAntennaElementModelResult> GetWFAntennaElementModelResultPtr;
    
    
    class GetWFAntennaElementModelResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetWFAntennaElementModelResult();

      GetWFAntennaElementModelResult(CommandBasePtr relatedCommand, const std::string& antennaModelName, int element);
  
      static GetWFAntennaElementModelResultPtr create(CommandBasePtr relatedCommand, const std::string& antennaModelName, int element);
      static GetWFAntennaElementModelResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;


      // **** antennaModelName ****
      std::string antennaModelName() const;
      void setAntennaModelName(const std::string& antennaModelName);


      // **** element ****
      int element() const;
      void setElement(int element);
    };
  }
}

