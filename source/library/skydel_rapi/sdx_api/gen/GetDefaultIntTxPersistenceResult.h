#pragma once

#include <memory>
#include "command_result.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetDefaultIntTxPersistence.
    ///
    /// Name         Type Description
    /// ------------ ---- --------------------------------------------------------------------------------
    /// DefaultValue bool True if jammers should keep the modifications done during simulation by default.
    ///

    class GetDefaultIntTxPersistenceResult;
    typedef std::shared_ptr<GetDefaultIntTxPersistenceResult> GetDefaultIntTxPersistenceResultPtr;
    
    
    class GetDefaultIntTxPersistenceResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetDefaultIntTxPersistenceResult();

      GetDefaultIntTxPersistenceResult(CommandBasePtr relatedCommand, bool defaultValue);
  
      static GetDefaultIntTxPersistenceResultPtr create(CommandBasePtr relatedCommand, bool defaultValue);
      static GetDefaultIntTxPersistenceResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;


      // **** defaultValue ****
      bool defaultValue() const;
      void setDefaultValue(bool defaultValue);
    };
  }
}

