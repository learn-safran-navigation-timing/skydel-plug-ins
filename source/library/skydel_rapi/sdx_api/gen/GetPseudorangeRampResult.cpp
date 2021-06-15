#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetPseudorangeRampResult
///
#include "gen/GetPseudorangeRampResult.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetPseudorangeRampResult::CmdName = "GetPseudorangeRampResult";
    const char* const GetPseudorangeRampResult::Documentation = "Result of GetPseudorangeRamp.";

    REGISTER_COMMAND_RESULT_FACTORY(GetPseudorangeRampResult);


    GetPseudorangeRampResult::GetPseudorangeRampResult()
      : CommandResult(CmdName)
    {}

    GetPseudorangeRampResult::GetPseudorangeRampResult(CommandBasePtr relatedCommand, const std::string& system, int prn, double offset, int startTime, int holdStartTime, int holdStopTime, int stopTime, const std::string& id)
      : CommandResult(CmdName, relatedCommand)
    {

      setSystem(system);
      setPrn(prn);
      setOffset(offset);
      setStartTime(startTime);
      setHoldStartTime(holdStartTime);
      setHoldStopTime(holdStopTime);
      setStopTime(stopTime);
      setId(id);
    }


    GetPseudorangeRampResultPtr GetPseudorangeRampResult::create(CommandBasePtr relatedCommand, const std::string& system, int prn, double offset, int startTime, int holdStartTime, int holdStopTime, int stopTime, const std::string& id)
    {
      return GetPseudorangeRampResultPtr(new GetPseudorangeRampResult(relatedCommand, system, prn, offset, startTime, holdStartTime, holdStopTime, stopTime, id));
    }

    GetPseudorangeRampResultPtr GetPseudorangeRampResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetPseudorangeRampResult>(ptr);
    }

    bool GetPseudorangeRampResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["System"])
          && parse_json<int>::is_valid(m_values["Prn"])
          && parse_json<double>::is_valid(m_values["Offset"])
          && parse_json<int>::is_valid(m_values["StartTime"])
          && parse_json<int>::is_valid(m_values["HoldStartTime"])
          && parse_json<int>::is_valid(m_values["HoldStopTime"])
          && parse_json<int>::is_valid(m_values["StopTime"])
          && parse_json<std::string>::is_valid(m_values["Id"])
        ;

    }

    std::string GetPseudorangeRampResult::documentation() const { return Documentation; }


    std::string GetPseudorangeRampResult::system() const
    {
      return parse_json<std::string>::parse(m_values["System"]);
    }

    void GetPseudorangeRampResult::setSystem(const std::string& system)
    {
      m_values.AddMember("System", parse_json<std::string>::format(system, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetPseudorangeRampResult::prn() const
    {
      return parse_json<int>::parse(m_values["Prn"]);
    }

    void GetPseudorangeRampResult::setPrn(int prn)
    {
      m_values.AddMember("Prn", parse_json<int>::format(prn, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double GetPseudorangeRampResult::offset() const
    {
      return parse_json<double>::parse(m_values["Offset"]);
    }

    void GetPseudorangeRampResult::setOffset(double offset)
    {
      m_values.AddMember("Offset", parse_json<double>::format(offset, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetPseudorangeRampResult::startTime() const
    {
      return parse_json<int>::parse(m_values["StartTime"]);
    }

    void GetPseudorangeRampResult::setStartTime(int startTime)
    {
      m_values.AddMember("StartTime", parse_json<int>::format(startTime, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetPseudorangeRampResult::holdStartTime() const
    {
      return parse_json<int>::parse(m_values["HoldStartTime"]);
    }

    void GetPseudorangeRampResult::setHoldStartTime(int holdStartTime)
    {
      m_values.AddMember("HoldStartTime", parse_json<int>::format(holdStartTime, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetPseudorangeRampResult::holdStopTime() const
    {
      return parse_json<int>::parse(m_values["HoldStopTime"]);
    }

    void GetPseudorangeRampResult::setHoldStopTime(int holdStopTime)
    {
      m_values.AddMember("HoldStopTime", parse_json<int>::format(holdStopTime, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetPseudorangeRampResult::stopTime() const
    {
      return parse_json<int>::parse(m_values["StopTime"]);
    }

    void GetPseudorangeRampResult::setStopTime(int stopTime)
    {
      m_values.AddMember("StopTime", parse_json<int>::format(stopTime, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string GetPseudorangeRampResult::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void GetPseudorangeRampResult::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
