#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetBeiDouCNav1MessageResult
///
#include "gen/GetBeiDouCNav1MessageResult.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetBeiDouCNav1MessageResult::CmdName = "GetBeiDouCNav1MessageResult";
    const char* const GetBeiDouCNav1MessageResult::Documentation = "Result of GetBeiDouCNav1Message.";

    REGISTER_COMMAND_RESULT_FACTORY(GetBeiDouCNav1MessageResult);


    GetBeiDouCNav1MessageResult::GetBeiDouCNav1MessageResult()
      : CommandResult(CmdName)
    {}

    GetBeiDouCNav1MessageResult::GetBeiDouCNav1MessageResult(CommandBasePtr relatedCommand, int prn, int startTime, int stopTime, int pageId, const std::string& condition, bool updateCRC, const std::string& bitsMods, const std::string& id)
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


    GetBeiDouCNav1MessageResultPtr GetBeiDouCNav1MessageResult::create(CommandBasePtr relatedCommand, int prn, int startTime, int stopTime, int pageId, const std::string& condition, bool updateCRC, const std::string& bitsMods, const std::string& id)
    {
      return GetBeiDouCNav1MessageResultPtr(new GetBeiDouCNav1MessageResult(relatedCommand, prn, startTime, stopTime, pageId, condition, updateCRC, bitsMods, id));
    }

    GetBeiDouCNav1MessageResultPtr GetBeiDouCNav1MessageResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetBeiDouCNav1MessageResult>(ptr);
    }

    bool GetBeiDouCNav1MessageResult::isValid() const
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

    std::string GetBeiDouCNav1MessageResult::documentation() const { return Documentation; }


    int GetBeiDouCNav1MessageResult::prn() const
    {
      return parse_json<int>::parse(m_values["Prn"]);
    }

    void GetBeiDouCNav1MessageResult::setPrn(int prn)
    {
      m_values.AddMember("Prn", parse_json<int>::format(prn, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetBeiDouCNav1MessageResult::startTime() const
    {
      return parse_json<int>::parse(m_values["StartTime"]);
    }

    void GetBeiDouCNav1MessageResult::setStartTime(int startTime)
    {
      m_values.AddMember("StartTime", parse_json<int>::format(startTime, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetBeiDouCNav1MessageResult::stopTime() const
    {
      return parse_json<int>::parse(m_values["StopTime"]);
    }

    void GetBeiDouCNav1MessageResult::setStopTime(int stopTime)
    {
      m_values.AddMember("StopTime", parse_json<int>::format(stopTime, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetBeiDouCNav1MessageResult::pageId() const
    {
      return parse_json<int>::parse(m_values["PageId"]);
    }

    void GetBeiDouCNav1MessageResult::setPageId(int pageId)
    {
      m_values.AddMember("PageId", parse_json<int>::format(pageId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string GetBeiDouCNav1MessageResult::condition() const
    {
      return parse_json<std::string>::parse(m_values["Condition"]);
    }

    void GetBeiDouCNav1MessageResult::setCondition(const std::string& condition)
    {
      m_values.AddMember("Condition", parse_json<std::string>::format(condition, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool GetBeiDouCNav1MessageResult::updateCRC() const
    {
      return parse_json<bool>::parse(m_values["UpdateCRC"]);
    }

    void GetBeiDouCNav1MessageResult::setUpdateCRC(bool updateCRC)
    {
      m_values.AddMember("UpdateCRC", parse_json<bool>::format(updateCRC, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string GetBeiDouCNav1MessageResult::bitsMods() const
    {
      return parse_json<std::string>::parse(m_values["BitsMods"]);
    }

    void GetBeiDouCNav1MessageResult::setBitsMods(const std::string& bitsMods)
    {
      m_values.AddMember("BitsMods", parse_json<std::string>::format(bitsMods, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string GetBeiDouCNav1MessageResult::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void GetBeiDouCNav1MessageResult::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
