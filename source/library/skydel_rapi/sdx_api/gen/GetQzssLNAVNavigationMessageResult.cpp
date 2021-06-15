#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetQzssLNAVNavigationMessageResult
///
#include "gen/GetQzssLNAVNavigationMessageResult.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetQzssLNAVNavigationMessageResult::CmdName = "GetQzssLNAVNavigationMessageResult";
    const char* const GetQzssLNAVNavigationMessageResult::Documentation = "Result of GetQzssLNAVNavigationMessage.";

    REGISTER_COMMAND_RESULT_FACTORY(GetQzssLNAVNavigationMessageResult);


    GetQzssLNAVNavigationMessageResult::GetQzssLNAVNavigationMessageResult()
      : CommandResult(CmdName)
    {}

    GetQzssLNAVNavigationMessageResult::GetQzssLNAVNavigationMessageResult(CommandBasePtr relatedCommand, int svId, int startTime, int stopTime, int subFrame, int transmittedSvId, int word, bool updateParity, const std::string& modification, const std::string& id)
      : CommandResult(CmdName, relatedCommand)
    {

      setSvId(svId);
      setStartTime(startTime);
      setStopTime(stopTime);
      setSubFrame(subFrame);
      setTransmittedSvId(transmittedSvId);
      setWord(word);
      setUpdateParity(updateParity);
      setModification(modification);
      setId(id);
    }


    GetQzssLNAVNavigationMessageResultPtr GetQzssLNAVNavigationMessageResult::create(CommandBasePtr relatedCommand, int svId, int startTime, int stopTime, int subFrame, int transmittedSvId, int word, bool updateParity, const std::string& modification, const std::string& id)
    {
      return GetQzssLNAVNavigationMessageResultPtr(new GetQzssLNAVNavigationMessageResult(relatedCommand, svId, startTime, stopTime, subFrame, transmittedSvId, word, updateParity, modification, id));
    }

    GetQzssLNAVNavigationMessageResultPtr GetQzssLNAVNavigationMessageResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetQzssLNAVNavigationMessageResult>(ptr);
    }

    bool GetQzssLNAVNavigationMessageResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<int>::is_valid(m_values["StartTime"])
          && parse_json<int>::is_valid(m_values["StopTime"])
          && parse_json<int>::is_valid(m_values["SubFrame"])
          && parse_json<int>::is_valid(m_values["TransmittedSvId"])
          && parse_json<int>::is_valid(m_values["Word"])
          && parse_json<bool>::is_valid(m_values["UpdateParity"])
          && parse_json<std::string>::is_valid(m_values["Modification"])
          && parse_json<std::string>::is_valid(m_values["Id"])
        ;

    }

    std::string GetQzssLNAVNavigationMessageResult::documentation() const { return Documentation; }


    int GetQzssLNAVNavigationMessageResult::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void GetQzssLNAVNavigationMessageResult::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetQzssLNAVNavigationMessageResult::startTime() const
    {
      return parse_json<int>::parse(m_values["StartTime"]);
    }

    void GetQzssLNAVNavigationMessageResult::setStartTime(int startTime)
    {
      m_values.AddMember("StartTime", parse_json<int>::format(startTime, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetQzssLNAVNavigationMessageResult::stopTime() const
    {
      return parse_json<int>::parse(m_values["StopTime"]);
    }

    void GetQzssLNAVNavigationMessageResult::setStopTime(int stopTime)
    {
      m_values.AddMember("StopTime", parse_json<int>::format(stopTime, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetQzssLNAVNavigationMessageResult::subFrame() const
    {
      return parse_json<int>::parse(m_values["SubFrame"]);
    }

    void GetQzssLNAVNavigationMessageResult::setSubFrame(int subFrame)
    {
      m_values.AddMember("SubFrame", parse_json<int>::format(subFrame, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetQzssLNAVNavigationMessageResult::transmittedSvId() const
    {
      return parse_json<int>::parse(m_values["TransmittedSvId"]);
    }

    void GetQzssLNAVNavigationMessageResult::setTransmittedSvId(int transmittedSvId)
    {
      m_values.AddMember("TransmittedSvId", parse_json<int>::format(transmittedSvId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetQzssLNAVNavigationMessageResult::word() const
    {
      return parse_json<int>::parse(m_values["Word"]);
    }

    void GetQzssLNAVNavigationMessageResult::setWord(int word)
    {
      m_values.AddMember("Word", parse_json<int>::format(word, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool GetQzssLNAVNavigationMessageResult::updateParity() const
    {
      return parse_json<bool>::parse(m_values["UpdateParity"]);
    }

    void GetQzssLNAVNavigationMessageResult::setUpdateParity(bool updateParity)
    {
      m_values.AddMember("UpdateParity", parse_json<bool>::format(updateParity, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string GetQzssLNAVNavigationMessageResult::modification() const
    {
      return parse_json<std::string>::parse(m_values["Modification"]);
    }

    void GetQzssLNAVNavigationMessageResult::setModification(const std::string& modification)
    {
      m_values.AddMember("Modification", parse_json<std::string>::format(modification, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string GetQzssLNAVNavigationMessageResult::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void GetQzssLNAVNavigationMessageResult::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
