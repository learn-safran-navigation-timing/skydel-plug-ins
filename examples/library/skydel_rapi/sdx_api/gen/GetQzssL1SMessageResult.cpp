#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetQzssL1SMessageResult
///
#include "gen/GetQzssL1SMessageResult.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetQzssL1SMessageResult::CmdName = "GetQzssL1SMessageResult";
    const char* const GetQzssL1SMessageResult::Documentation = "Result of GetQzssL1SMessage.";

    REGISTER_COMMAND_RESULT_FACTORY(GetQzssL1SMessageResult);


    GetQzssL1SMessageResult::GetQzssL1SMessageResult()
      : CommandResult(CmdName)
    {}

    GetQzssL1SMessageResult::GetQzssL1SMessageResult(CommandBasePtr relatedCommand, int svId, int startTime, int stopTime, int messageType, const std::string& condition, bool updateCRC, const std::string& bitsMods, const std::string& id)
      : CommandResult(CmdName, relatedCommand)
    {

      setSvId(svId);
      setStartTime(startTime);
      setStopTime(stopTime);
      setMessageType(messageType);
      setCondition(condition);
      setUpdateCRC(updateCRC);
      setBitsMods(bitsMods);
      setId(id);
    }


    GetQzssL1SMessageResultPtr GetQzssL1SMessageResult::create(CommandBasePtr relatedCommand, int svId, int startTime, int stopTime, int messageType, const std::string& condition, bool updateCRC, const std::string& bitsMods, const std::string& id)
    {
      return GetQzssL1SMessageResultPtr(new GetQzssL1SMessageResult(relatedCommand, svId, startTime, stopTime, messageType, condition, updateCRC, bitsMods, id));
    }

    GetQzssL1SMessageResultPtr GetQzssL1SMessageResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetQzssL1SMessageResult>(ptr);
    }

    bool GetQzssL1SMessageResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<int>::is_valid(m_values["StartTime"])
          && parse_json<int>::is_valid(m_values["StopTime"])
          && parse_json<int>::is_valid(m_values["MessageType"])
          && parse_json<std::string>::is_valid(m_values["Condition"])
          && parse_json<bool>::is_valid(m_values["UpdateCRC"])
          && parse_json<std::string>::is_valid(m_values["BitsMods"])
          && parse_json<std::string>::is_valid(m_values["Id"])
        ;

    }

    std::string GetQzssL1SMessageResult::documentation() const { return Documentation; }


    int GetQzssL1SMessageResult::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void GetQzssL1SMessageResult::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetQzssL1SMessageResult::startTime() const
    {
      return parse_json<int>::parse(m_values["StartTime"]);
    }

    void GetQzssL1SMessageResult::setStartTime(int startTime)
    {
      m_values.AddMember("StartTime", parse_json<int>::format(startTime, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetQzssL1SMessageResult::stopTime() const
    {
      return parse_json<int>::parse(m_values["StopTime"]);
    }

    void GetQzssL1SMessageResult::setStopTime(int stopTime)
    {
      m_values.AddMember("StopTime", parse_json<int>::format(stopTime, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetQzssL1SMessageResult::messageType() const
    {
      return parse_json<int>::parse(m_values["MessageType"]);
    }

    void GetQzssL1SMessageResult::setMessageType(int messageType)
    {
      m_values.AddMember("MessageType", parse_json<int>::format(messageType, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string GetQzssL1SMessageResult::condition() const
    {
      return parse_json<std::string>::parse(m_values["Condition"]);
    }

    void GetQzssL1SMessageResult::setCondition(const std::string& condition)
    {
      m_values.AddMember("Condition", parse_json<std::string>::format(condition, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool GetQzssL1SMessageResult::updateCRC() const
    {
      return parse_json<bool>::parse(m_values["UpdateCRC"]);
    }

    void GetQzssL1SMessageResult::setUpdateCRC(bool updateCRC)
    {
      m_values.AddMember("UpdateCRC", parse_json<bool>::format(updateCRC, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string GetQzssL1SMessageResult::bitsMods() const
    {
      return parse_json<std::string>::parse(m_values["BitsMods"]);
    }

    void GetQzssL1SMessageResult::setBitsMods(const std::string& bitsMods)
    {
      m_values.AddMember("BitsMods", parse_json<std::string>::format(bitsMods, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string GetQzssL1SMessageResult::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void GetQzssL1SMessageResult::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
