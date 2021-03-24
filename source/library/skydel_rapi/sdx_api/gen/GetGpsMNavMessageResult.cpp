#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetGpsMNavMessageResult
///
#include "gen/GetGpsMNavMessageResult.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetGpsMNavMessageResult::CmdName = "GetGpsMNavMessageResult";
    const char* const GetGpsMNavMessageResult::Documentation = "Result of GetGpsMNavMessage";

    REGISTER_COMMAND_RESULT_FACTORY(GetGpsMNavMessageResult);


    GetGpsMNavMessageResult::GetGpsMNavMessageResult()
      : CommandResult(CmdName)
    {}

    GetGpsMNavMessageResult::GetGpsMNavMessageResult(CommandBasePtr relatedCommand, int prn, int startTime, int stopTime, int msgTypeId, int occurrence, const std::string& condition, const std::string& bitsMods, const std::string& id)
      : CommandResult(CmdName, relatedCommand)
    {

      setPrn(prn);
      setStartTime(startTime);
      setStopTime(stopTime);
      setMsgTypeId(msgTypeId);
      setOccurrence(occurrence);
      setCondition(condition);
      setBitsMods(bitsMods);
      setId(id);
    }


    GetGpsMNavMessageResultPtr GetGpsMNavMessageResult::create(CommandBasePtr relatedCommand, int prn, int startTime, int stopTime, int msgTypeId, int occurrence, const std::string& condition, const std::string& bitsMods, const std::string& id)
    {
      return GetGpsMNavMessageResultPtr(new GetGpsMNavMessageResult(relatedCommand, prn, startTime, stopTime, msgTypeId, occurrence, condition, bitsMods, id));
    }

    GetGpsMNavMessageResultPtr GetGpsMNavMessageResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetGpsMNavMessageResult>(ptr);
    }

    bool GetGpsMNavMessageResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["Prn"])
          && parse_json<int>::is_valid(m_values["StartTime"])
          && parse_json<int>::is_valid(m_values["StopTime"])
          && parse_json<int>::is_valid(m_values["MsgTypeId"])
          && parse_json<int>::is_valid(m_values["Occurrence"])
          && parse_json<std::string>::is_valid(m_values["Condition"])
          && parse_json<std::string>::is_valid(m_values["BitsMods"])
          && parse_json<std::string>::is_valid(m_values["Id"])
        ;

    }

    std::string GetGpsMNavMessageResult::documentation() const { return Documentation; }


    int GetGpsMNavMessageResult::prn() const
    {
      return parse_json<int>::parse(m_values["Prn"]);
    }

    void GetGpsMNavMessageResult::setPrn(int prn)
    {
      m_values.AddMember("Prn", parse_json<int>::format(prn, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetGpsMNavMessageResult::startTime() const
    {
      return parse_json<int>::parse(m_values["StartTime"]);
    }

    void GetGpsMNavMessageResult::setStartTime(int startTime)
    {
      m_values.AddMember("StartTime", parse_json<int>::format(startTime, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetGpsMNavMessageResult::stopTime() const
    {
      return parse_json<int>::parse(m_values["StopTime"]);
    }

    void GetGpsMNavMessageResult::setStopTime(int stopTime)
    {
      m_values.AddMember("StopTime", parse_json<int>::format(stopTime, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetGpsMNavMessageResult::msgTypeId() const
    {
      return parse_json<int>::parse(m_values["MsgTypeId"]);
    }

    void GetGpsMNavMessageResult::setMsgTypeId(int msgTypeId)
    {
      m_values.AddMember("MsgTypeId", parse_json<int>::format(msgTypeId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetGpsMNavMessageResult::occurrence() const
    {
      return parse_json<int>::parse(m_values["Occurrence"]);
    }

    void GetGpsMNavMessageResult::setOccurrence(int occurrence)
    {
      m_values.AddMember("Occurrence", parse_json<int>::format(occurrence, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string GetGpsMNavMessageResult::condition() const
    {
      return parse_json<std::string>::parse(m_values["Condition"]);
    }

    void GetGpsMNavMessageResult::setCondition(const std::string& condition)
    {
      m_values.AddMember("Condition", parse_json<std::string>::format(condition, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string GetGpsMNavMessageResult::bitsMods() const
    {
      return parse_json<std::string>::parse(m_values["BitsMods"]);
    }

    void GetGpsMNavMessageResult::setBitsMods(const std::string& bitsMods)
    {
      m_values.AddMember("BitsMods", parse_json<std::string>::format(bitsMods, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string GetGpsMNavMessageResult::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void GetGpsMNavMessageResult::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
