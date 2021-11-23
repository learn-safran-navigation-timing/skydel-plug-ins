#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetBeiDouD2NavigationMessageResult
///
#include "gen/GetBeiDouD2NavigationMessageResult.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetBeiDouD2NavigationMessageResult::CmdName = "GetBeiDouD2NavigationMessageResult";
    const char* const GetBeiDouD2NavigationMessageResult::Documentation = "Result of GetBeiDouD2NavigationMessage.";

    REGISTER_COMMAND_RESULT_FACTORY(GetBeiDouD2NavigationMessageResult);


    GetBeiDouD2NavigationMessageResult::GetBeiDouD2NavigationMessageResult()
      : CommandResult(CmdName)
    {}

    GetBeiDouD2NavigationMessageResult::GetBeiDouD2NavigationMessageResult(CommandBasePtr relatedCommand, int prn, int startTime, int stopTime, int subFrame, int page, int word, bool updateParity, const std::string& modification, const std::string& id)
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


    GetBeiDouD2NavigationMessageResultPtr GetBeiDouD2NavigationMessageResult::create(CommandBasePtr relatedCommand, int prn, int startTime, int stopTime, int subFrame, int page, int word, bool updateParity, const std::string& modification, const std::string& id)
    {
      return GetBeiDouD2NavigationMessageResultPtr(new GetBeiDouD2NavigationMessageResult(relatedCommand, prn, startTime, stopTime, subFrame, page, word, updateParity, modification, id));
    }

    GetBeiDouD2NavigationMessageResultPtr GetBeiDouD2NavigationMessageResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetBeiDouD2NavigationMessageResult>(ptr);
    }

    bool GetBeiDouD2NavigationMessageResult::isValid() const
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

    std::string GetBeiDouD2NavigationMessageResult::documentation() const { return Documentation; }


    int GetBeiDouD2NavigationMessageResult::prn() const
    {
      return parse_json<int>::parse(m_values["Prn"]);
    }

    void GetBeiDouD2NavigationMessageResult::setPrn(int prn)
    {
      m_values.AddMember("Prn", parse_json<int>::format(prn, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetBeiDouD2NavigationMessageResult::startTime() const
    {
      return parse_json<int>::parse(m_values["StartTime"]);
    }

    void GetBeiDouD2NavigationMessageResult::setStartTime(int startTime)
    {
      m_values.AddMember("StartTime", parse_json<int>::format(startTime, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetBeiDouD2NavigationMessageResult::stopTime() const
    {
      return parse_json<int>::parse(m_values["StopTime"]);
    }

    void GetBeiDouD2NavigationMessageResult::setStopTime(int stopTime)
    {
      m_values.AddMember("StopTime", parse_json<int>::format(stopTime, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetBeiDouD2NavigationMessageResult::subFrame() const
    {
      return parse_json<int>::parse(m_values["SubFrame"]);
    }

    void GetBeiDouD2NavigationMessageResult::setSubFrame(int subFrame)
    {
      m_values.AddMember("SubFrame", parse_json<int>::format(subFrame, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetBeiDouD2NavigationMessageResult::page() const
    {
      return parse_json<int>::parse(m_values["Page"]);
    }

    void GetBeiDouD2NavigationMessageResult::setPage(int page)
    {
      m_values.AddMember("Page", parse_json<int>::format(page, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetBeiDouD2NavigationMessageResult::word() const
    {
      return parse_json<int>::parse(m_values["Word"]);
    }

    void GetBeiDouD2NavigationMessageResult::setWord(int word)
    {
      m_values.AddMember("Word", parse_json<int>::format(word, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool GetBeiDouD2NavigationMessageResult::updateParity() const
    {
      return parse_json<bool>::parse(m_values["UpdateParity"]);
    }

    void GetBeiDouD2NavigationMessageResult::setUpdateParity(bool updateParity)
    {
      m_values.AddMember("UpdateParity", parse_json<bool>::format(updateParity, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string GetBeiDouD2NavigationMessageResult::modification() const
    {
      return parse_json<std::string>::parse(m_values["Modification"]);
    }

    void GetBeiDouD2NavigationMessageResult::setModification(const std::string& modification)
    {
      m_values.AddMember("Modification", parse_json<std::string>::format(modification, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string GetBeiDouD2NavigationMessageResult::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void GetBeiDouD2NavigationMessageResult::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
