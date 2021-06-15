#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetGalileoFNavMessageResult
///
#include "gen/GetGalileoFNavMessageResult.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetGalileoFNavMessageResult::CmdName = "GetGalileoFNavMessageResult";
    const char* const GetGalileoFNavMessageResult::Documentation = "Result of GetGalileoFNavMessage.";

    REGISTER_COMMAND_RESULT_FACTORY(GetGalileoFNavMessageResult);


    GetGalileoFNavMessageResult::GetGalileoFNavMessageResult()
      : CommandResult(CmdName)
    {}

    GetGalileoFNavMessageResult::GetGalileoFNavMessageResult(CommandBasePtr relatedCommand, int prn, int startTime, int stopTime, int subFrame, int page, bool updateCRC, const std::string& bitsMods, const std::string& id)
      : CommandResult(CmdName, relatedCommand)
    {

      setPrn(prn);
      setStartTime(startTime);
      setStopTime(stopTime);
      setSubFrame(subFrame);
      setPage(page);
      setUpdateCRC(updateCRC);
      setBitsMods(bitsMods);
      setId(id);
    }


    GetGalileoFNavMessageResultPtr GetGalileoFNavMessageResult::create(CommandBasePtr relatedCommand, int prn, int startTime, int stopTime, int subFrame, int page, bool updateCRC, const std::string& bitsMods, const std::string& id)
    {
      return GetGalileoFNavMessageResultPtr(new GetGalileoFNavMessageResult(relatedCommand, prn, startTime, stopTime, subFrame, page, updateCRC, bitsMods, id));
    }

    GetGalileoFNavMessageResultPtr GetGalileoFNavMessageResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetGalileoFNavMessageResult>(ptr);
    }

    bool GetGalileoFNavMessageResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["Prn"])
          && parse_json<int>::is_valid(m_values["StartTime"])
          && parse_json<int>::is_valid(m_values["StopTime"])
          && parse_json<int>::is_valid(m_values["SubFrame"])
          && parse_json<int>::is_valid(m_values["Page"])
          && parse_json<bool>::is_valid(m_values["UpdateCRC"])
          && parse_json<std::string>::is_valid(m_values["BitsMods"])
          && parse_json<std::string>::is_valid(m_values["Id"])
        ;

    }

    std::string GetGalileoFNavMessageResult::documentation() const { return Documentation; }


    int GetGalileoFNavMessageResult::prn() const
    {
      return parse_json<int>::parse(m_values["Prn"]);
    }

    void GetGalileoFNavMessageResult::setPrn(int prn)
    {
      m_values.AddMember("Prn", parse_json<int>::format(prn, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetGalileoFNavMessageResult::startTime() const
    {
      return parse_json<int>::parse(m_values["StartTime"]);
    }

    void GetGalileoFNavMessageResult::setStartTime(int startTime)
    {
      m_values.AddMember("StartTime", parse_json<int>::format(startTime, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetGalileoFNavMessageResult::stopTime() const
    {
      return parse_json<int>::parse(m_values["StopTime"]);
    }

    void GetGalileoFNavMessageResult::setStopTime(int stopTime)
    {
      m_values.AddMember("StopTime", parse_json<int>::format(stopTime, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetGalileoFNavMessageResult::subFrame() const
    {
      return parse_json<int>::parse(m_values["SubFrame"]);
    }

    void GetGalileoFNavMessageResult::setSubFrame(int subFrame)
    {
      m_values.AddMember("SubFrame", parse_json<int>::format(subFrame, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetGalileoFNavMessageResult::page() const
    {
      return parse_json<int>::parse(m_values["Page"]);
    }

    void GetGalileoFNavMessageResult::setPage(int page)
    {
      m_values.AddMember("Page", parse_json<int>::format(page, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool GetGalileoFNavMessageResult::updateCRC() const
    {
      return parse_json<bool>::parse(m_values["UpdateCRC"]);
    }

    void GetGalileoFNavMessageResult::setUpdateCRC(bool updateCRC)
    {
      m_values.AddMember("UpdateCRC", parse_json<bool>::format(updateCRC, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string GetGalileoFNavMessageResult::bitsMods() const
    {
      return parse_json<std::string>::parse(m_values["BitsMods"]);
    }

    void GetGalileoFNavMessageResult::setBitsMods(const std::string& bitsMods)
    {
      m_values.AddMember("BitsMods", parse_json<std::string>::format(bitsMods, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string GetGalileoFNavMessageResult::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void GetGalileoFNavMessageResult::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
