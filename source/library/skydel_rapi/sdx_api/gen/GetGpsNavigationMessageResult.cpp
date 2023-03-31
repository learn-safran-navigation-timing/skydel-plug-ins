#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetGpsNavigationMessageResult
///
#include "gen/GetGpsNavigationMessageResult.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetGpsNavigationMessageResult::CmdName = "GetGpsNavigationMessageResult";
    const char* const GetGpsNavigationMessageResult::Documentation = "Result of GetGpsNavigationMessage.";

    REGISTER_COMMAND_RESULT_FACTORY(GetGpsNavigationMessageResult);


    GetGpsNavigationMessageResult::GetGpsNavigationMessageResult()
      : CommandResult(CmdName)
    {}

    GetGpsNavigationMessageResult::GetGpsNavigationMessageResult(CommandBasePtr relatedCommand, int prn, int startTime, int stopTime, int subFrame, int page, int word, bool updateParity, const std::string& modification, const std::string& id)
      : CommandResult(CmdName, relatedCommand)
    {

      setPrn(prn);
      setStartTime(startTime);
      setStopTime(stopTime);
      setSubFrame(subFrame);
      setPage(page);
      setWord(word);
      setUpdateParity(updateParity);
      setModification(modification);
      setId(id);
    }


    GetGpsNavigationMessageResultPtr GetGpsNavigationMessageResult::create(CommandBasePtr relatedCommand, int prn, int startTime, int stopTime, int subFrame, int page, int word, bool updateParity, const std::string& modification, const std::string& id)
    {
      return GetGpsNavigationMessageResultPtr(new GetGpsNavigationMessageResult(relatedCommand, prn, startTime, stopTime, subFrame, page, word, updateParity, modification, id));
    }

    GetGpsNavigationMessageResultPtr GetGpsNavigationMessageResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetGpsNavigationMessageResult>(ptr);
    }

    bool GetGpsNavigationMessageResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["Prn"])
          && parse_json<int>::is_valid(m_values["StartTime"])
          && parse_json<int>::is_valid(m_values["StopTime"])
          && parse_json<int>::is_valid(m_values["SubFrame"])
          && parse_json<int>::is_valid(m_values["Page"])
          && parse_json<int>::is_valid(m_values["Word"])
          && parse_json<bool>::is_valid(m_values["UpdateParity"])
          && parse_json<std::string>::is_valid(m_values["Modification"])
          && parse_json<std::string>::is_valid(m_values["Id"])
        ;

    }

    std::string GetGpsNavigationMessageResult::documentation() const { return Documentation; }


    int GetGpsNavigationMessageResult::prn() const
    {
      return parse_json<int>::parse(m_values["Prn"]);
    }

    void GetGpsNavigationMessageResult::setPrn(int prn)
    {
      m_values.AddMember("Prn", parse_json<int>::format(prn, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetGpsNavigationMessageResult::startTime() const
    {
      return parse_json<int>::parse(m_values["StartTime"]);
    }

    void GetGpsNavigationMessageResult::setStartTime(int startTime)
    {
      m_values.AddMember("StartTime", parse_json<int>::format(startTime, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetGpsNavigationMessageResult::stopTime() const
    {
      return parse_json<int>::parse(m_values["StopTime"]);
    }

    void GetGpsNavigationMessageResult::setStopTime(int stopTime)
    {
      m_values.AddMember("StopTime", parse_json<int>::format(stopTime, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetGpsNavigationMessageResult::subFrame() const
    {
      return parse_json<int>::parse(m_values["SubFrame"]);
    }

    void GetGpsNavigationMessageResult::setSubFrame(int subFrame)
    {
      m_values.AddMember("SubFrame", parse_json<int>::format(subFrame, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetGpsNavigationMessageResult::page() const
    {
      return parse_json<int>::parse(m_values["Page"]);
    }

    void GetGpsNavigationMessageResult::setPage(int page)
    {
      m_values.AddMember("Page", parse_json<int>::format(page, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetGpsNavigationMessageResult::word() const
    {
      return parse_json<int>::parse(m_values["Word"]);
    }

    void GetGpsNavigationMessageResult::setWord(int word)
    {
      m_values.AddMember("Word", parse_json<int>::format(word, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool GetGpsNavigationMessageResult::updateParity() const
    {
      return parse_json<bool>::parse(m_values["UpdateParity"]);
    }

    void GetGpsNavigationMessageResult::setUpdateParity(bool updateParity)
    {
      m_values.AddMember("UpdateParity", parse_json<bool>::format(updateParity, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string GetGpsNavigationMessageResult::modification() const
    {
      return parse_json<std::string>::parse(m_values["Modification"]);
    }

    void GetGpsNavigationMessageResult::setModification(const std::string& modification)
    {
      m_values.AddMember("Modification", parse_json<std::string>::format(modification, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string GetGpsNavigationMessageResult::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void GetGpsNavigationMessageResult::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
