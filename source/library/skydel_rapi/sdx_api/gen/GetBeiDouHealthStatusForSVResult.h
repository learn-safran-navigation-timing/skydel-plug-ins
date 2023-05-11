#pragma once

#include <memory>
#include "command_result.h"
#include "sdx_optional.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetBeiDouHealthStatusForSV.
    ///
    /// Name        Type            Description
    /// ----------- --------------- -------------------------------------------------------------------------------------------
    /// SvId        int             Satellite SV ID 1..35, or use 0 to apply new value to all satellites.
    /// Health      int             Health Info, 2-bit integer : 0, 1, 2 or 3
    /// DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.
    ///

    class GetBeiDouHealthStatusForSVResult;
    typedef std::shared_ptr<GetBeiDouHealthStatusForSVResult> GetBeiDouHealthStatusForSVResultPtr;
    
    
    class GetBeiDouHealthStatusForSVResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetBeiDouHealthStatusForSVResult();

      GetBeiDouHealthStatusForSVResult(CommandBasePtr relatedCommand, int svId, int health, const Sdx::optional<std::string>& dataSetName = {});
  
      static GetBeiDouHealthStatusForSVResultPtr create(CommandBasePtr relatedCommand, int svId, int health, const Sdx::optional<std::string>& dataSetName = {});
      static GetBeiDouHealthStatusForSVResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;


      // **** svId ****
      int svId() const;
      void setSvId(int svId);


      // **** health ****
      int health() const;
      void setHealth(int health);


      // **** dataSetName ****
      Sdx::optional<std::string> dataSetName() const;
      void setDataSetName(const Sdx::optional<std::string>& dataSetName);
    };
  }
}

