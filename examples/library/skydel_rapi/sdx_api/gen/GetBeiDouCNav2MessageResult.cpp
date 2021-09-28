#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetBeiDouCNav2MessageResult
///
#include "gen/GetBeiDouCNav2MessageResult.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetBeiDouCNav2MessageResult::CmdName = "GetBeiDouCNav2MessageResult";
    const char* const GetBeiDouCNav2MessageResult::Documentation = "Result of GetBeiDouCNav2Message.";

    REGISTER_COMMAND_RESULT_FACTORY(GetBeiDouCNav2MessageResult);


    GetBeiDouCNav2MessageResult::GetBeiDouCNav2MessageResult()
      : CommandResult(CmdName)
    {}

    GetBeiDouCNav2MessageResult::GetBeiDouCNav2MessageResult(CommandBasePtr relatedCommand, int prn, int startTime, int stopTime, int messageType, const std::string& condition, bool updateCRC, const std::string& bitsMods, const std::string& id)
      : CommandResult(CmdName, relatedCommand)
    {

      setPrn(prn);
      setStartTime(startTime);
      setStopTime(stopTime);
      setMessageType(messageType);
      setCondition(condition);
      setUpdateCRC(updateCRC);
      setBitsMods(bitsMods);
      setId(id);
    }


    GetBeiDouCNav2MessageResultPtr GetBeiDouCNav2MessageResult::create(CommandBasePtr relatedCommand, int prn, int startTime, int stopTime, int messageType, const std::string& condition, bool updateCRC, const std::string& bitsMods, const std::string& id)
    {
      return GetBeiDouCNav2MessageResultPtr(new GetBeiDouCNav2MessageResult(relatedCommand, prn, startTime, stopTime, messageType, condition, updateCRC, bitsMods, id));
    }

    GetBeiDouCNav2MessageResultPtr GetBeiDouCNav2MessageResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetBeiDouCNav2MessageResult>(ptr);
    }

    bool GetBeiDouCNav2MessageResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["Prn"])
          && parse_json<int>::is_valid(m_values["StartTime"])
          && parse_json<int>::is_valid(m_values["StopTime"])
          && parse_json<int>::is_valid(m_values["MessageType"])
          && parse_json<std::string>::is_valid(m_values["Condition"])
          && parse_json<bool>::is_valid(m_values["UpdateCRC"])
          && parse_json<std::string>::is_valid(m_values["BitsMods"])
          && parse_json<std::string>::is_valid(m_values["Id"])
        ;

    }

    std::string GetBeiDouCNav2MessageResult::documentation() const { return Documentation; }


    int GetBeiDouCNav2MessageResult::prn() const
    {
      return parse_json<int>::parse(m_values["Prn"]);
    }

    void GetBeiDouCNav2MessageResult::setPrn(int prn)
    {
      m_values.AddMember("Prn", parse_json<int>::format(prn, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetBeiDouCNav2MessageResult::startTime() const
    {
      return parse_json<int>::parse(m_values["StartTime"]);
    }

    void GetBeiDouCNav2MessageResult::setStartTime(int startTime)
    {
      m_values.AddMember("StartTime", parse_json<int>::format(startTime, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetBeiDouCNav2MessageResult::stopTime() const
    {
      return parse_json<int>::parse(m_values["StopTime"]);
    }

    void GetBeiDouCNav2MessageResult::setStopTime(int stopTime)
    {
      m_values.AddMember("StopTime", parse_json<int>::format(stopTime, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetBeiDouCNav2MessageResult::messageType() const
    {
      return parse_json<int>::parse(m_values["MessageType"]);
    }

    void GetBeiDouCNav2MessageResult::setMessageType(int messageType)
    {
      m_values.AddMember("MessageType", parse_json<int>::format(messageType, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string GetBeiDouCNav2MessageResult::condition() const
    {
      return parse_json<std::string>::parse(m_values["Condition"]);
    }

    void GetBeiDouCNav2MessageResult::setCondition(const std::string& condition)
    {
      m_values.AddMember("Condition", parse_json<std::string>::format(condition, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool GetBeiDouCNav2MessageResult::updateCRC() const
    {
      return parse_json<bool>::parse(m_values["UpdateCRC"]);
    }

    void GetBeiDouCNav2MessageResult::setUpdateCRC(bool updateCRC)
    {
      m_values.AddMember("UpdateCRC", parse_json<bool>::format(updateCRC, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string GetBeiDouCNav2MessageResult::bitsMods() const
    {
      return parse_json<std::string>::parse(m_values["BitsMods"]);
    }

    void GetBeiDouCNav2MessageResult::setBitsMods(const std::string& bitsMods)
    {
      m_values.AddMember("BitsMods", parse_json<std::string>::format(bitsMods, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string GetBeiDouCNav2MessageResult::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void GetBeiDouCNav2MessageResult::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
