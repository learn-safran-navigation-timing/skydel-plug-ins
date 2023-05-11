#pragma once

#include <memory>
#include "command_result.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetIntTx.
    ///
    /// Name      Type   Description
    /// --------- ------ ----------------------------------------------------------------------------------------
    /// UsualName string Usual name for the transmitter.
    /// Enabled   bool   Enable (true) or disable (false) the transmitter
    /// Group     int    Interference group number [1..16]
    /// Dynamic   bool   Set to true for a dynamic transmitter (propagation loss and doppler shift are simulated)
    /// Power     double Set the transmitter reference power
    /// Id        string Transmitter unique identifier.
    ///

    class GetIntTxResult;
    typedef std::shared_ptr<GetIntTxResult> GetIntTxResultPtr;
    
    
    class GetIntTxResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetIntTxResult();

      GetIntTxResult(CommandBasePtr relatedCommand, const std::string& usualName, bool enabled, int group, bool dynamic, double power, const std::string& id);
  
      static GetIntTxResultPtr create(CommandBasePtr relatedCommand, const std::string& usualName, bool enabled, int group, bool dynamic, double power, const std::string& id);
      static GetIntTxResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;


      // **** usualName ****
      std::string usualName() const;
      void setUsualName(const std::string& usualName);


      // **** enabled ****
      bool enabled() const;
      void setEnabled(bool enabled);


      // **** group ****
      int group() const;
      void setGroup(int group);


      // **** dynamic ****
      bool dynamic() const;
      void setDynamic(bool dynamic);


      // **** power ****
      double power() const;
      void setPower(double power);


      // **** id ****
      std::string id() const;
      void setId(const std::string& id);
    };
  }
}

