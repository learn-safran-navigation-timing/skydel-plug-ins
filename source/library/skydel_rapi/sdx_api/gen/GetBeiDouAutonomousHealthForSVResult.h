#pragma once

#include <memory>
#include "command_result.h"
#include "command_factory.h"
#include <optional>
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetBeiDouAutonomousHealthForSV.
    ///
    /// Name        Type            Description
    /// ----------- --------------- -------------------------------------------------------------------------------------------
    /// SvId        int             Satellite SV ID 1..35, or use 0 to apply new value to all satellites.
    /// Health      bool            Status, false = Good, true = Not Good
    /// DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.
    ///

    class GetBeiDouAutonomousHealthForSVResult;
    typedef std::shared_ptr<GetBeiDouAutonomousHealthForSVResult> GetBeiDouAutonomousHealthForSVResultPtr;
    
    
    class GetBeiDouAutonomousHealthForSVResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      GetBeiDouAutonomousHealthForSVResult();

      GetBeiDouAutonomousHealthForSVResult(int svId, bool health, const std::optional<std::string>& dataSetName = {});

      GetBeiDouAutonomousHealthForSVResult(CommandBasePtr relatedCommand, int svId, bool health, const std::optional<std::string>& dataSetName = {});

      static GetBeiDouAutonomousHealthForSVResultPtr create(int svId, bool health, const std::optional<std::string>& dataSetName = {});

      static GetBeiDouAutonomousHealthForSVResultPtr create(CommandBasePtr relatedCommand, int svId, bool health, const std::optional<std::string>& dataSetName = {});
      static GetBeiDouAutonomousHealthForSVResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;


      // **** svId ****
      int svId() const;
      void setSvId(int svId);


      // **** health ****
      bool health() const;
      void setHealth(bool health);


      // **** dataSetName ****
      std::optional<std::string> dataSetName() const;
      void setDataSetName(const std::optional<std::string>& dataSetName);
    };
    REGISTER_COMMAND_TO_FACTORY_DECL(GetBeiDouAutonomousHealthForSVResult);
  }
}

