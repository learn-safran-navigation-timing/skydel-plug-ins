#pragma once

#include <memory>
#include "command_result.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetIonoBdgimAlpha.
    ///
    /// Name  Type   Description
    /// ----- ------ ------------------------
    /// Index int    Coefficient index [1..9]
    /// Val   double Coefficient value
    ///

    class GetIonoBdgimAlphaResult;
    typedef std::shared_ptr<GetIonoBdgimAlphaResult> GetIonoBdgimAlphaResultPtr;
    
    
    class GetIonoBdgimAlphaResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetIonoBdgimAlphaResult();

      GetIonoBdgimAlphaResult(CommandBasePtr relatedCommand, int index, double val);
  
      static GetIonoBdgimAlphaResultPtr create(CommandBasePtr relatedCommand, int index, double val);
      static GetIonoBdgimAlphaResultPtr dynamicCast(CommandBasePtr ptr);
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

