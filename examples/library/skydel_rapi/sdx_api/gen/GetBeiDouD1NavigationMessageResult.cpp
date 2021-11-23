#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetBeiDouD1NavigationMessageResult
///
#include "gen/GetBeiDouD1NavigationMessageResult.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetBeiDouD1NavigationMessageResult::CmdName = "GetBeiDouD1NavigationMessageResult";
    const char* const GetBeiDouD1NavigationMessageResult::Documentation = "Result of GetBeiDouD1NavigationMessage.";

    REGISTER_COMMAND_RESULT_FACTORY(GetBeiDouD1NavigationMessageResult);


    GetBeiDouD1NavigationMessageResult::GetBeiDouD1NavigationMessageResult()
      : CommandResult(CmdName)
    {}

    GetBeiDouD1NavigationMessageResult::GetBeiDouD1NavigationMessageResult(CommandBasePtr relatedCommand, int prn, int startTime, int stopTime, int subFrame, int page, int word, bool updateParity, const std::string& modification, const std::string& id)
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


    GetBeiDouD1NavigationMessageResultPtr GetBeiDouD1NavigationMessageResult::create(CommandBasePtr relatedCommand, int prn, int startTime, int stopTime, int subFrame, int page, int word, bool updateParity, const std::string& modification, const std::string& id)
    {
      return GetBeiDouD1NavigationMessageResultPtr(new GetBeiDouD1NavigationMessageResult(relatedCommand, prn, startTime, stopTime, subFrame, page, word, updateParity, modification, id));
    }

    GetBeiDouD1NavigationMessageResultPtr GetBeiDouD1NavigationMessageResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetBeiDouD1NavigationMessageResult>(ptr);
    }

    bool GetBeiDouD1NavigationMessageResult::isValid() const
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

    std::string GetBeiDouD1NavigationMessageResult::documentation() const { return Documentation; }


    int GetBeiDouD1NavigationMessageResult::prn() const
    {
      return parse_json<int>::parse(m_values["Prn"]);
    }

    void GetBeiDouD1NavigationMessageResult::setPrn(int prn)
    {
      m_values.AddMember("Prn", parse_json<int>::format(prn, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetBeiDouD1NavigationMessageResult::startTime() const
    {
      return parse_json<int>::parse(m_values["StartTime"]);
    }

    void GetBeiDouD1NavigationMessageResult::setStartTime(int startTime)
    {
      m_values.AddMember("StartTime", parse_json<int>::format(startTime, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetBeiDouD1NavigationMessageResult::stopTime() const
    {
      return parse_json<int>::parse(m_values["StopTime"]);
    }

    void GetBeiDouD1NavigationMessageResult::setStopTime(int stopTime)
    {
      m_values.AddMember("StopTime", parse_json<int>::format(stopTime, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetBeiDouD1NavigationMessageResult::subFrame() const
    {
      return parse_json<int>::parse(m_values["SubFrame"]);
    }

    void GetBeiDouD1NavigationMessageResult::setSubFrame(int subFrame)
    {
      m_values.AddMember("SubFrame", parse_json<int>::format(subFrame, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetBeiDouD1NavigationMessageResult::page() const
    {
      return parse_json<int>::parse(m_values["Page"]);
    }

    void GetBeiDouD1NavigationMessageResult::setPage(int page)
    {
      m_values.AddMember("Page", parse_json<int>::format(page, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetBeiDouD1NavigationMessageResult::word() const
    {
      return parse_json<int>::parse(m_values["Word"]);
    }

    void GetBeiDouD1NavigationMessageResult::setWord(int word)
    {
      m_values.AddMember("Word", parse_json<int>::format(word, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool GetBeiDouD1NavigationMessageResult::updateParity() const
    {
      return parse_json<bool>::parse(m_values["UpdateParity"]);
    }

    void GetBeiDouD1NavigationMessageResult::setUpdateParity(bool updateParity)
    {
      m_values.AddMember("UpdateParity", parse_json<bool>::format(updateParity, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string GetBeiDouD1NavigationMessageResult::modification() const
    {
      return parse_json<std::string>::parse(m_values["Modification"]);
    }

    void GetBeiDouD1NavigationMessageResult::setModification(const std::string& modification)
    {
      m_values.AddMember("Modification", parse_json<std::string>::format(modification, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string GetBeiDouD1NavigationMessageResult::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void GetBeiDouD1NavigationMessageResult::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
