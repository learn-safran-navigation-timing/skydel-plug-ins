#pragma once

#include <memory>
#include "command_result.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetEffectiveIonisationLevelCoefficient.
    ///
    /// Name  Type   Description
    /// ----- ------ ---------------------------------------------------------------
    /// Index int    Coefficient index, 0, 1 or 2 for ai0, ai1 and ai2 respectively.
    /// Val   double Coefficient value.
    ///

    class GetEffectiveIonisationLevelCoefficientResult;
    typedef std::shared_ptr<GetEffectiveIonisationLevelCoefficientResult> GetEffectiveIonisationLevelCoefficientResultPtr;
    
    
    class GetEffectiveIonisationLevelCoefficientResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetEffectiveIonisationLevelCoefficientResult();

      GetEffectiveIonisationLevelCoefficientResult(CommandBasePtr relatedCommand, int index, double val);
  
      static GetEffectiveIonisationLevelCoefficientResultPtr create(CommandBasePtr relatedCommand, int index, double val);
      static GetEffectiveIonisationLevelCoefficientResultPtr dynamicCast(CommandBasePtr ptr);
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

