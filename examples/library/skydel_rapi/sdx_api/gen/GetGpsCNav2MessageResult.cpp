#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetGpsCNav2MessageResult
///
#include "gen/GetGpsCNav2MessageResult.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetGpsCNav2MessageResult::CmdName = "GetGpsCNav2MessageResult";
    const char* const GetGpsCNav2MessageResult::Documentation = "Result of GetGpsCNav2Message.";

    REGISTER_COMMAND_RESULT_FACTORY(GetGpsCNav2MessageResult);


    GetGpsCNav2MessageResult::GetGpsCNav2MessageResult()
      : CommandResult(CmdName)
    {}

    GetGpsCNav2MessageResult::GetGpsCNav2MessageResult(CommandBasePtr relatedCommand, int prn, int startTime, int stopTime, int pageId, const std::string& condition, bool updateCRC, const std::string& bitsMods, const std::string& id)
      : CommandResult(CmdName, relatedCommand)
    {

      setPrn(prn);
      setStartTime(startTime);
      setStopTime(stopTime);
      setPageId(pageId);
      setCondition(condition);
      setUpdateCRC(updateCRC);
      setBitsMods(bitsMods);
      setId(id);
    }


    GetGpsCNav2MessageResultPtr GetGpsCNav2MessageResult::create(CommandBasePtr relatedCommand, int prn, int startTime, int stopTime, int pageId, const std::string& condition, bool updateCRC, const std::string& bitsMods, const std::string& id)
    {
      return GetGpsCNav2MessageResultPtr(new GetGpsCNav2MessageResult(relatedCommand, prn, startTime, stopTime, pageId, condition, updateCRC, bitsMods, id));
    }

    GetGpsCNav2MessageResultPtr GetGpsCNav2MessageResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetGpsCNav2MessageResult>(ptr);
    }

    bool GetGpsCNav2MessageResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["Prn"])
          && parse_json<int>::is_valid(m_values["StartTime"])
          && parse_json<int>::is_valid(m_values["StopTime"])
          && parse_json<int>::is_valid(m_values["PageId"])
          && parse_json<std::string>::is_valid(m_values["Condition"])
          && parse_json<bool>::is_valid(m_values["UpdateCRC"])
          && parse_json<std::string>::is_valid(m_values["BitsMods"])
          && parse_json<std::string>::is_valid(m_values["Id"])
        ;

    }

    std::string GetGpsCNav2MessageResult::documentation() const { return Documentation; }


    int GetGpsCNav2MessageResult::prn() const
    {
      return parse_json<int>::parse(m_values["Prn"]);
    }

    void GetGpsCNav2MessageResult::setPrn(int prn)
    {
      m_values.AddMember("Prn", parse_json<int>::format(prn, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetGpsCNav2MessageResult::startTime() const
    {
      return parse_json<int>::parse(m_values["StartTime"]);
    }

    void GetGpsCNav2MessageResult::setStartTime(int startTime)
    {
      m_values.AddMember("StartTime", parse_json<int>::format(startTime, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetGpsCNav2MessageResult::stopTime() const
    {
      return parse_json<int>::parse(m_values["StopTime"]);
    }

    void GetGpsCNav2MessageResult::setStopTime(int stopTime)
    {
      m_values.AddMember("StopTime", parse_json<int>::format(stopTime, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetGpsCNav2MessageResult::pageId() const
    {
      return parse_json<int>::parse(m_values["PageId"]);
    }

    void GetGpsCNav2MessageResult::setPageId(int pageId)
    {
      m_values.AddMember("PageId", parse_json<int>::format(pageId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string GetGpsCNav2MessageResult::condition() const
    {
      return parse_json<std::string>::parse(m_values["Condition"]);
    }

    void GetGpsCNav2MessageResult::setCondition(const std::string& condition)
    {
      m_values.AddMember("Condition", parse_json<std::string>::format(condition, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool GetGpsCNav2MessageResult::updateCRC() const
    {
      return parse_json<bool>::parse(m_values["UpdateCRC"]);
    }

    void GetGpsCNav2MessageResult::setUpdateCRC(bool updateCRC)
    {
      m_values.AddMember("UpdateCRC", parse_json<bool>::format(updateCRC, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string GetGpsCNav2MessageResult::bitsMods() const
    {
      return parse_json<std::string>::parse(m_values["BitsMods"]);
    }

    void GetGpsCNav2MessageResult::setBitsMods(const std::string& bitsMods)
    {
      m_values.AddMember("BitsMods", parse_json<std::string>::format(bitsMods, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string GetGpsCNav2MessageResult::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void GetGpsCNav2MessageResult::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
