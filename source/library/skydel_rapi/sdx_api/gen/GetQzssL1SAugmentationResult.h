#pragma once

#include <memory>
#include "command_result.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetQzssL1SAugmentation.
    ///
    /// Name       Type   Description
    /// ---------- ------ ----------------------------------------------------------------------------------
    /// System     string "GPS", "GLONASS", "Galileo", "BeiDou" or "QZSS"
    /// Prn        int    Satellite PRN number.
    /// AugmentIOD bool   Include the satellite Issue Of Data in L1S message.
    /// AugmentPRC bool   Include the satellite Pseudorange Correction in L1S message.
    /// Prc        double Pseudorange Correction to include in L1S message. Only used if AugmentPSR is True.
    /// Id         string Unique identifier of the augmentation.
    ///

    class GetQzssL1SAugmentationResult;
    typedef std::shared_ptr<GetQzssL1SAugmentationResult> GetQzssL1SAugmentationResultPtr;
    
    
    class GetQzssL1SAugmentationResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetQzssL1SAugmentationResult();

      GetQzssL1SAugmentationResult(CommandBasePtr relatedCommand, const std::string& system, int prn, bool augmentIOD, bool augmentPRC, double prc, const std::string& id);
  
      static GetQzssL1SAugmentationResultPtr create(CommandBasePtr relatedCommand, const std::string& system, int prn, bool augmentIOD, bool augmentPRC, double prc, const std::string& id);
      static GetQzssL1SAugmentationResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;


      // **** system ****
      std::string system() const;
      void setSystem(const std::string& system);


      // **** prn ****
      int prn() const;
      void setPrn(int prn);


      // **** augmentIOD ****
      bool augmentIOD() const;
      void setAugmentIOD(bool augmentIOD);


      // **** augmentPRC ****
      bool augmentPRC() const;
      void setAugmentPRC(bool augmentPRC);


      // **** prc ****
      double prc() const;
      void setPrc(double prc);


      // **** id ****
      std::string id() const;
      void setId(const std::string& id);
    };
  }
}

