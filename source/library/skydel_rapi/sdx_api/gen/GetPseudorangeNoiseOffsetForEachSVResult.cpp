
#include "GetPseudorangeNoiseOffsetForEachSVResult.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetPseudorangeNoiseOffsetForEachSVResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetPseudorangeNoiseOffsetForEachSVResult::CmdName = "GetPseudorangeNoiseOffsetForEachSVResult";
    const char* const GetPseudorangeNoiseOffsetForEachSVResult::Documentation = "Result of GetPseudorangeNoiseOffsetForEachSV.\n"
      "\n"
      "Name    Type         Description\n"
      "------- ------------ --------------------------------------------------------------------------\n"
      "System  string       \"GPS\", \"GLONASS\", \"Galileo\", \"BeiDou\", \"SBAS\", \"QZSS\", \"NavIC\" or \"PULSAR\"\n"
      "Enabled array bool   If true, the offset is enabled (applied)\n"
      "Offset  array double The constant offset in metters";
    const char* const GetPseudorangeNoiseOffsetForEachSVResult::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_IMPL(GetPseudorangeNoiseOffsetForEachSVResult);


    GetPseudorangeNoiseOffsetForEachSVResult::GetPseudorangeNoiseOffsetForEachSVResult()
      : CommandResult(CmdName, TargetId)
    {}

    GetPseudorangeNoiseOffsetForEachSVResult::GetPseudorangeNoiseOffsetForEachSVResult(const std::string& system, const std::vector<bool>& enabled, const std::vector<double>& offset)
      : CommandResult(CmdName, TargetId)
    {

      setSystem(system);
      setEnabled(enabled);
      setOffset(offset);
    }

    GetPseudorangeNoiseOffsetForEachSVResult::GetPseudorangeNoiseOffsetForEachSVResult(CommandBasePtr relatedCommand, const std::string& system, const std::vector<bool>& enabled, const std::vector<double>& offset)
      : CommandResult(CmdName, TargetId, relatedCommand)
    {

      setSystem(system);
      setEnabled(enabled);
      setOffset(offset);
    }


    GetPseudorangeNoiseOffsetForEachSVResultPtr GetPseudorangeNoiseOffsetForEachSVResult::create(const std::string& system, const std::vector<bool>& enabled, const std::vector<double>& offset)
    {
      return std::make_shared<GetPseudorangeNoiseOffsetForEachSVResult>(system, enabled, offset);
    }

    GetPseudorangeNoiseOffsetForEachSVResultPtr GetPseudorangeNoiseOffsetForEachSVResult::create(CommandBasePtr relatedCommand, const std::string& system, const std::vector<bool>& enabled, const std::vector<double>& offset)
    {
      return std::make_shared<GetPseudorangeNoiseOffsetForEachSVResult>(relatedCommand, system, enabled, offset);
    }

    GetPseudorangeNoiseOffsetForEachSVResultPtr GetPseudorangeNoiseOffsetForEachSVResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetPseudorangeNoiseOffsetForEachSVResult>(ptr);
    }

    bool GetPseudorangeNoiseOffsetForEachSVResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["System"])
          && parse_json<std::vector<bool>>::is_valid(m_values["Enabled"])
          && parse_json<std::vector<double>>::is_valid(m_values["Offset"])
        ;

    }

    std::string GetPseudorangeNoiseOffsetForEachSVResult::documentation() const { return Documentation; }

    const std::vector<std::string>& GetPseudorangeNoiseOffsetForEachSVResult::fieldNames() const 
    { 
      static const std::vector<std::string> names {"System", "Enabled", "Offset"}; 
      return names; 
    }


    std::string GetPseudorangeNoiseOffsetForEachSVResult::system() const
    {
      return parse_json<std::string>::parse(m_values["System"]);
    }

    void GetPseudorangeNoiseOffsetForEachSVResult::setSystem(const std::string& system)
    {
      m_values.AddMember("System", parse_json<std::string>::format(system, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::vector<bool> GetPseudorangeNoiseOffsetForEachSVResult::enabled() const
    {
      return parse_json<std::vector<bool>>::parse(m_values["Enabled"]);
    }

    void GetPseudorangeNoiseOffsetForEachSVResult::setEnabled(const std::vector<bool>& enabled)
    {
      m_values.AddMember("Enabled", parse_json<std::vector<bool>>::format(enabled, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::vector<double> GetPseudorangeNoiseOffsetForEachSVResult::offset() const
    {
      return parse_json<std::vector<double>>::parse(m_values["Offset"]);
    }

    void GetPseudorangeNoiseOffsetForEachSVResult::setOffset(const std::vector<double>& offset)
    {
      m_values.AddMember("Offset", parse_json<std::vector<double>>::format(offset, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
