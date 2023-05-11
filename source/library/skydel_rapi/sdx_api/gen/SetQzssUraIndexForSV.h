#pragma once

#include <memory>
#include "command_base.h"
#include "sdx_optional.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Set the URA index of a QZSS satellite
    ///
    /// Name        Type            Description
    /// ----------- --------------- -------------------------------------------------------------------------------------------
    /// SvId        int             The satellite SV ID, or use 0 to apply new value to all satellites.
    /// Urai        int             URA index.
    /// DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.
    ///

    class SetQzssUraIndexForSV;
    typedef std::shared_ptr<SetQzssUraIndexForSV> SetQzssUraIndexForSVPtr;
    
    
    class SetQzssUraIndexForSV : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      SetQzssUraIndexForSV();

      SetQzssUraIndexForSV(int svId, int urai, const Sdx::optional<std::string>& dataSetName = {});
  
      static SetQzssUraIndexForSVPtr create(int svId, int urai, const Sdx::optional<std::string>& dataSetName = {});
      static SetQzssUraIndexForSVPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** svId ****
      int svId() const;
      void setSvId(int svId);


      // **** urai ****
      int urai() const;
      void setUrai(int urai);


      // **** dataSetName ****
      Sdx::optional<std::string> dataSetName() const;
      void setDataSetName(const Sdx::optional<std::string>& dataSetName);
    };
  }
}

