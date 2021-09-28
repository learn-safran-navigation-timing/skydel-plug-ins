#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetGpsCNavMessageResult
///
#include "gen/GetGpsCNavMessageResult.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetGpsCNavMessageResult::CmdName = "GetGpsCNavMessageResult";
    const char* const GetGpsCNavMessageResult::Documentation = "Result of GetGpsCNavMessage.";

    REGISTER_COMMAND_RESULT_FACTORY(GetGpsCNavMessageResult);


    GetGpsCNavMessageResult::GetGpsCNavMessageResult()
      : CommandResult(CmdName)
    {}

    GetGpsCNavMessageResult::GetGpsCNavMessageResult(CommandBasePtr relatedCommand, int prn, int startTime, int stopTime, int msgTypeId, const std::string& condition, bool updateCRC, const std::string& bitsMods, const std::string& id)
      : CommandResult(CmdName, relatedCommand)
    {

      setPrn(prn);
      setStartTime(startTime);
      setStopTime(stopTime);
      setMsgTypeId(msgTypeId);
      setCondition(condition);
      setUpdateCRC(updateCRC);
      setBitsMods(bitsMods);
      setId(id);
    }


    GetGpsCNavMessageResultPtr GetGpsCNavMessageResult::create(CommandBasePtr relatedCommand, int prn, int startTime, int stopTime, int msgTypeId, const std::string& condition, bool updateCRC, const std::string& bitsMods, const std::string& id)
    {
      return GetGpsCNavMessageResultPtr(new GetGpsCNavMessageResult(relatedCommand, prn, startTime, stopTime, msgTypeId, condition, updateCRC, bitsMods, id));
    }

    GetGpsCNavMessageResultPtr GetGpsCNavMessageResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetGpsCNavMessageResult>(ptr);
    }

    bool GetGpsCNavMessageResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["Prn"])
          && parse_json<int>::is_valid(m_values["StartTime"])
          && parse_json<int>::is_valid(m_values["StopTime"])
          && parse_json<int>::is_valid(m_values["MsgTypeId"])
          && parse_json<std::string>::is_valid(m_values["Condition"])
          && parse_json<bool>::is_valid(m_values["UpdateCRC"])
          && parse_json<std::string>::is_valid(m_values["BitsMods"])
          && parse_json<std::string>::is_valid(m_values["Id"])
        ;

    }

    std::string GetGpsCNavMessageResult::documentation() const { return Documentation; }


    int GetGpsCNavMessageResult::prn() const
    {
      return parse_json<int>::parse(m_values["Prn"]);
    }

    void GetGpsCNavMessageResult::setPrn(int prn)
    {
      m_values.AddMember("Prn", parse_json<int>::format(prn, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetGpsCNavMessageResult::startTime() const
    {
      return parse_json<int>::parse(m_values["StartTime"]);
    }

    void GetGpsCNavMessageResult::setStartTime(int startTime)
    {
      m_values.AddMember("StartTime", parse_json<int>::format(startTime, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetGpsCNavMessageResult::stopTime() const
    {
      return parse_json<int>::parse(m_values["StopTime"]);
    }

    void GetGpsCNavMessageResult::setStopTime(int stopTime)
    {
      m_values.AddMember("StopTime", parse_json<int>::format(stopTime, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetGpsCNavMessageResult::msgTypeId() const
    {
      return parse_json<int>::parse(m_values["MsgTypeId"]);
    }

    void GetGpsCNavMessageResult::setMsgTypeId(int msgTypeId)
    {
      m_values.AddMember("MsgTypeId", parse_json<int>::format(msgTypeId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string GetGpsCNavMessageResult::condition() const
    {
      return parse_json<std::string>::parse(m_values["Condition"]);
    }

    void GetGpsCNavMessageResult::setCondition(const std::string& condition)
    {
      m_values.AddMember("Condition", parse_json<std::string>::format(condition, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool GetGpsCNavMessageResult::updateCRC() const
    {
      return parse_json<bool>::parse(m_values["UpdateCRC"]);
    }

    void GetGpsCNavMessageResult::setUpdateCRC(bool updateCRC)
    {
      m_values.AddMember("UpdateCRC", parse_json<bool>::format(updateCRC, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string GetGpsCNavMessageResult::bitsMods() const
    {
      return parse_json<std::string>::parse(m_values["BitsMods"]);
    }

    void GetGpsCNavMessageResult::setBitsMods(const std::string& bitsMods)
    {
      m_values.AddMember("BitsMods", parse_json<std::string>::format(bitsMods, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string GetGpsCNavMessageResult::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void GetGpsCNavMessageResult::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
