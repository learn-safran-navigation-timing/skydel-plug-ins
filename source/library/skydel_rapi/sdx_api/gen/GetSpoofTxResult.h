#pragma once

#include <memory>
#include "command_result.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetSpoofTx.
    ///
    /// Name       Type   Description
    /// ---------- ------ ------------------------------------------------
    /// UsualName  string Usual name for the transmitter.
    /// Enabled    bool   Enable (true) or disable (false) the transmitter
    /// Address    string Remote instance IP address.
    /// InstanceId int    Remote instance ID.
    /// Id         string Transmitter unique identifier.
    ///

    class GetSpoofTxResult;
    typedef std::shared_ptr<GetSpoofTxResult> GetSpoofTxResultPtr;
    
    
    class GetSpoofTxResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetSpoofTxResult();

      GetSpoofTxResult(CommandBasePtr relatedCommand, const std::string& usualName, bool enabled, const std::string& address, int instanceId, const std::string& id);
  
      static GetSpoofTxResultPtr create(CommandBasePtr relatedCommand, const std::string& usualName, bool enabled, const std::string& address, int instanceId, const std::string& id);
      static GetSpoofTxResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;


      // **** usualName ****
      std::string usualName() const;
      void setUsualName(const std::string& usualName);


      // **** enabled ****
      bool enabled() const;
      void setEnabled(bool enabled);


      // **** address ****
      std::string address() const;
      void setAddress(const std::string& address);


      // **** instanceId ****
      int instanceId() const;
      void setInstanceId(int instanceId);


      // **** id ****
      std::string id() const;
      void setId(const std::string& id);
    };
  }
}

