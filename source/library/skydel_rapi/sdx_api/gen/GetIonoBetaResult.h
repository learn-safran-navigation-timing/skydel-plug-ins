#pragma once

#include <memory>
#include "command_result.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetIonoBeta.
    ///
    /// Name  Type   Description
    /// ----- ------ ------------------------
    /// Index int    Coefficient index [0..3]
    /// Val   double Coefficient value
    ///

    class GetIonoBetaResult;
    typedef std::shared_ptr<GetIonoBetaResult> GetIonoBetaResultPtr;
    
    
    class GetIonoBetaResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetIonoBetaResult();

      GetIonoBetaResult(CommandBasePtr relatedCommand, int index, double val);
  
      static GetIonoBetaResultPtr create(CommandBasePtr relatedCommand, int index, double val);
      static GetIonoBetaResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;


      // **** index ****
      int index() const;
      void setIndex(int index);


      // **** val ****
      double val() const;
      void setVal(double val);
    };
  }
}

