#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetGlonassNavigationMessageResult
///
#include "gen/GetGlonassNavigationMessageResult.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetGlonassNavigationMessageResult::CmdName = "GetGlonassNavigationMessageResult";
    const char* const GetGlonassNavigationMessageResult::Documentation = "Result of GetGlonassNavigationMessage.";

    REGISTER_COMMAND_RESULT_FACTORY(GetGlonassNavigationMessageResult);


    GetGlonassNavigationMessageResult::GetGlonassNavigationMessageResult()
      : CommandResult(CmdName)
    {}

    GetGlonassNavigationMessageResult::GetGlonassNavigationMessageResult(CommandBasePtr relatedCommand, int prn, int startTime, int stopTime, int frame, int stringNumber, bool updateHammingCode, const std::string& modification, const std::string& id)
      : CommandResult(CmdName, relatedCommand)
    {

      setPrn(prn);
      setStartTime(startTime);
      setStopTime(stopTime);
      setFrame(frame);
      setStringNumber(stringNumber);
      setUpdateHammingCode(updateHammingCode);
      setModification(modification);
      setId(id);
    }


    GetGlonassNavigationMessageResultPtr GetGlonassNavigationMessageResult::create(CommandBasePtr relatedCommand, int prn, int startTime, int stopTime, int frame, int stringNumber, bool updateHammingCode, const std::string& modification, const std::string& id)
    {
      return GetGlonassNavigationMessageResultPtr(new GetGlonassNavigationMessageResult(relatedCommand, prn, startTime, stopTime, frame, stringNumber, updateHammingCode, modification, id));
    }

    GetGlonassNavigationMessageResultPtr GetGlonassNavigationMessageResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetGlonassNavigationMessageResult>(ptr);
    }

    bool GetGlonassNavigationMessageResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["Prn"])
          && parse_json<int>::is_valid(m_values["StartTime"])
          && parse_json<int>::is_valid(m_values["StopTime"])
          && parse_json<int>::is_valid(m_values["Frame"])
          && parse_json<int>::is_valid(m_values["StringNumber"])
          && parse_json<bool>::is_valid(m_values["UpdateHammingCode"])
          && parse_json<std::string>::is_valid(m_values["Modification"])
          && parse_json<std::string>::is_valid(m_values["Id"])
        ;

    }

    std::string GetGlonassNavigationMessageResult::documentation() const { return Documentation; }


    int GetGlonassNavigationMessageResult::prn() const
    {
      return parse_json<int>::parse(m_values["Prn"]);
    }

    void GetGlonassNavigationMessageResult::setPrn(int prn)
    {
      m_values.AddMember("Prn", parse_json<int>::format(prn, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetGlonassNavigationMessageResult::startTime() const
    {
      return parse_json<int>::parse(m_values["StartTime"]);
    }

    void GetGlonassNavigationMessageResult::setStartTime(int startTime)
    {
      m_values.AddMember("StartTime", parse_json<int>::format(startTime, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetGlonassNavigationMessageResult::stopTime() const
    {
      return parse_json<int>::parse(m_values["StopTime"]);
    }

    void GetGlonassNavigationMessageResult::setStopTime(int stopTime)
    {
      m_values.AddMember("StopTime", parse_json<int>::format(stopTime, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetGlonassNavigationMessageResult::frame() const
    {
      return parse_json<int>::parse(m_values["Frame"]);
    }

    void GetGlonassNavigationMessageResult::setFrame(int frame)
    {
      m_values.AddMember("Frame", parse_json<int>::format(frame, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetGlonassNavigationMessageResult::stringNumber() const
    {
      return parse_json<int>::parse(m_values["StringNumber"]);
    }

    void GetGlonassNavigationMessageResult::setStringNumber(int stringNumber)
    {
      m_values.AddMember("StringNumber", parse_json<int>::format(stringNumber, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool GetGlonassNavigationMessageResult::updateHammingCode() const
    {
      return parse_json<bool>::parse(m_values["UpdateHammingCode"]);
    }

    void GetGlonassNavigationMessageResult::setUpdateHammingCode(bool updateHammingCode)
    {
      m_values.AddMember("UpdateHammingCode", parse_json<bool>::format(updateHammingCode, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string GetGlonassNavigationMessageResult::modification() const
    {
      return parse_json<std::string>::parse(m_values["Modification"]);
    }

    void GetGlonassNavigationMessageResult::setModification(const std::string& modification)
    {
      m_values.AddMember("Modification", parse_json<std::string>::format(modification, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string GetGlonassNavigationMessageResult::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void GetGlonassNavigationMessageResult::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
