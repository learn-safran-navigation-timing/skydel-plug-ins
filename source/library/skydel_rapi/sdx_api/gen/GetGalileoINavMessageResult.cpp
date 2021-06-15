#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetGalileoINavMessageResult
///
#include "gen/GetGalileoINavMessageResult.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetGalileoINavMessageResult::CmdName = "GetGalileoINavMessageResult";
    const char* const GetGalileoINavMessageResult::Documentation = "Result of GetGalileoINavMessage.";

    REGISTER_COMMAND_RESULT_FACTORY(GetGalileoINavMessageResult);


    GetGalileoINavMessageResult::GetGalileoINavMessageResult()
      : CommandResult(CmdName)
    {}

    GetGalileoINavMessageResult::GetGalileoINavMessageResult(CommandBasePtr relatedCommand, int prn, int startTime, int stopTime, int subFrame, int page, bool updateCRC, const std::string& bitsMods, bool e1, bool e5b, const std::string& id)
      : CommandResult(CmdName, relatedCommand)
    {

      setPrn(prn);
      setStartTime(startTime);
      setStopTime(stopTime);
      setSubFrame(subFrame);
      setPage(page);
      setUpdateCRC(updateCRC);
      setBitsMods(bitsMods);
      setE1(e1);
      setE5b(e5b);
      setId(id);
    }


    GetGalileoINavMessageResultPtr GetGalileoINavMessageResult::create(CommandBasePtr relatedCommand, int prn, int startTime, int stopTime, int subFrame, int page, bool updateCRC, const std::string& bitsMods, bool e1, bool e5b, const std::string& id)
    {
      return GetGalileoINavMessageResultPtr(new GetGalileoINavMessageResult(relatedCommand, prn, startTime, stopTime, subFrame, page, updateCRC, bitsMods, e1, e5b, id));
    }

    GetGalileoINavMessageResultPtr GetGalileoINavMessageResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetGalileoINavMessageResult>(ptr);
    }

    bool GetGalileoINavMessageResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["Prn"])
          && parse_json<int>::is_valid(m_values["StartTime"])
          && parse_json<int>::is_valid(m_values["StopTime"])
          && parse_json<int>::is_valid(m_values["SubFrame"])
          && parse_json<int>::is_valid(m_values["Page"])
          && parse_json<bool>::is_valid(m_values["UpdateCRC"])
          && parse_json<std::string>::is_valid(m_values["BitsMods"])
          && parse_json<bool>::is_valid(m_values["E1"])
          && parse_json<bool>::is_valid(m_values["E5b"])
          && parse_json<std::string>::is_valid(m_values["Id"])
        ;

    }

    std::string GetGalileoINavMessageResult::documentation() const { return Documentation; }


    int GetGalileoINavMessageResult::prn() const
    {
      return parse_json<int>::parse(m_values["Prn"]);
    }

    void GetGalileoINavMessageResult::setPrn(int prn)
    {
      m_values.AddMember("Prn", parse_json<int>::format(prn, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetGalileoINavMessageResult::startTime() const
    {
      return parse_json<int>::parse(m_values["StartTime"]);
    }

    void GetGalileoINavMessageResult::setStartTime(int startTime)
    {
      m_values.AddMember("StartTime", parse_json<int>::format(startTime, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetGalileoINavMessageResult::stopTime() const
    {
      return parse_json<int>::parse(m_values["StopTime"]);
    }

    void GetGalileoINavMessageResult::setStopTime(int stopTime)
    {
      m_values.AddMember("StopTime", parse_json<int>::format(stopTime, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetGalileoINavMessageResult::subFrame() const
    {
      return parse_json<int>::parse(m_values["SubFrame"]);
    }

    void GetGalileoINavMessageResult::setSubFrame(int subFrame)
    {
      m_values.AddMember("SubFrame", parse_json<int>::format(subFrame, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetGalileoINavMessageResult::page() const
    {
      return parse_json<int>::parse(m_values["Page"]);
    }

    void GetGalileoINavMessageResult::setPage(int page)
    {
      m_values.AddMember("Page", parse_json<int>::format(page, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool GetGalileoINavMessageResult::updateCRC() const
    {
      return parse_json<bool>::parse(m_values["UpdateCRC"]);
    }

    void GetGalileoINavMessageResult::setUpdateCRC(bool updateCRC)
    {
      m_values.AddMember("UpdateCRC", parse_json<bool>::format(updateCRC, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string GetGalileoINavMessageResult::bitsMods() const
    {
      return parse_json<std::string>::parse(m_values["BitsMods"]);
    }

    void GetGalileoINavMessageResult::setBitsMods(const std::string& bitsMods)
    {
      m_values.AddMember("BitsMods", parse_json<std::string>::format(bitsMods, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool GetGalileoINavMessageResult::e1() const
    {
      return parse_json<bool>::parse(m_values["E1"]);
    }

    void GetGalileoINavMessageResult::setE1(bool e1)
    {
      m_values.AddMember("E1", parse_json<bool>::format(e1, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool GetGalileoINavMessageResult::e5b() const
    {
      return parse_json<bool>::parse(m_values["E5b"]);
    }

    void GetGalileoINavMessageResult::setE5b(bool e5b)
    {
      m_values.AddMember("E5b", parse_json<bool>::format(e5b, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string GetGalileoINavMessageResult::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void GetGalileoINavMessageResult::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
