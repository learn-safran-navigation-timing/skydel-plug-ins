#pragma once

#include <memory>
#include "command_result.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetIonoAlpha.
    ///
    /// Name  Type   Description
    /// ----- ------ ------------------------
    /// Index int    Coefficient index [0..3]
    /// Val   double Coefficient value
    ///

    class GetIonoAlphaResult;
    typedef std::shared_ptr<GetIonoAlphaResult> GetIonoAlphaResultPtr;
    
    
    class GetIonoAlphaResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetIonoAlphaResult();

      GetIonoAlphaResult(CommandBasePtr relatedCommand, int index, double val);
  
      static GetIonoAlphaResultPtr create(CommandBasePtr relatedCommand, int index, double val);
      static GetIonoAlphaResultPtr dynamicCast(CommandBasePtr ptr);
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

