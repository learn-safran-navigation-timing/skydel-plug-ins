#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetModificationToQzssLNAVNavigationMessage
///
#include "gen/SetModificationToQzssLNAVNavigationMessage.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetModificationToQzssLNAVNavigationMessage::CmdName = "SetModificationToQzssLNAVNavigationMessage";
    const char* const SetModificationToQzssLNAVNavigationMessage::Documentation = "Please note the command SetModificationToQzssLNAVNavigationMessage is deprecated since 21.3. You may use SetMessageModificationToQzssLNav.\n\nSet (or Modify) event to change navigation message bits.\n\nNote that start and stop time are automatically extended to beginning and ending of overlapped\nsubframes. The Modification parameter is a string where the first character applies to the first\nbit of subframe word and last character applies to last bit of subframe word.\n   '0' will force bit to zero\n   '1' will for bit to one\n   'X' will negate bit value\n   any other byte value will have no effect\n\nExample: \"-00------------------1-X------\" will force bits 1 and 2 to zero and bit 22 to one\n                      and negate bit 24\n\nNote: if UpdateParity is true, any modification to bits 25..30 will have no effect.\n\nThe Id parameter is automatically updated with a unique id by the simulator for future reference.\nIf the ID is set with a value other than an empty string, the simulator will try to find a match\nwith previously added events. If there is a match, the event is updated with this message\ninstead of adding a new event. If there is no match, the event is added and the ID is not\nchanged.";

    REGISTER_COMMAND_FACTORY(SetModificationToQzssLNAVNavigationMessage);


    SetModificationToQzssLNAVNavigationMessage::SetModificationToQzssLNAVNavigationMessage()
      : CommandBase(CmdName)
    {}

    SetModificationToQzssLNAVNavigationMessage::SetModificationToQzssLNAVNavigationMessage(int svId, int startTime, int stopTime, int subFrame, int transmittedSvId, int word, bool updateParity, const std::string& modification, const std::string& id)
      : CommandBase(CmdName)
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


    SetModificationToQzssLNAVNavigationMessagePtr SetModificationToQzssLNAVNavigationMessage::create(int svId, int startTime, int stopTime, int subFrame, int transmittedSvId, int word, bool updateParity, const std::string& modification, const std::string& id)
    {
      return SetModificationToQzssLNAVNavigationMessagePtr(new SetModificationToQzssLNAVNavigationMessage(svId, startTime, stopTime, subFrame, transmittedSvId, word, updateParity, modification, id));
    }

    SetModificationToQzssLNAVNavigationMessagePtr SetModificationToQzssLNAVNavigationMessage::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetModificationToQzssLNAVNavigationMessage>(ptr);
    }

    bool SetModificationToQzssLNAVNavigationMessage::isValid() const
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

    std::string SetModificationToQzssLNAVNavigationMessage::documentation() const { return Documentation; }


    int SetModificationToQzssLNAVNavigationMessage::executePermission() const
    {
      return EXECUTE_IF_SIMULATING | EXECUTE_IF_IDLE;
    }


    int SetModificationToQzssLNAVNavigationMessage::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void SetModificationToQzssLNAVNavigationMessage::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int SetModificationToQzssLNAVNavigationMessage::startTime() const
    {
      return parse_json<int>::parse(m_values["StartTime"]);
    }

    void SetModificationToQzssLNAVNavigationMessage::setStartTime(int startTime)
    {
      m_values.AddMember("StartTime", parse_json<int>::format(startTime, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int SetModificationToQzssLNAVNavigationMessage::stopTime() const
    {
      return parse_json<int>::parse(m_values["StopTime"]);
    }

    void SetModificationToQzssLNAVNavigationMessage::setStopTime(int stopTime)
    {
      m_values.AddMember("StopTime", parse_json<int>::format(stopTime, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int SetModificationToQzssLNAVNavigationMessage::subFrame() const
    {
      return parse_json<int>::parse(m_values["SubFrame"]);
    }

    void SetModificationToQzssLNAVNavigationMessage::setSubFrame(int subFrame)
    {
      m_values.AddMember("SubFrame", parse_json<int>::format(subFrame, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int SetModificationToQzssLNAVNavigationMessage::transmittedSvId() const
    {
      return parse_json<int>::parse(m_values["TransmittedSvId"]);
    }

    void SetModificationToQzssLNAVNavigationMessage::setTransmittedSvId(int transmittedSvId)
    {
      m_values.AddMember("TransmittedSvId", parse_json<int>::format(transmittedSvId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int SetModificationToQzssLNAVNavigationMessage::word() const
    {
      return parse_json<int>::parse(m_values["Word"]);
    }

    void SetModificationToQzssLNAVNavigationMessage::setWord(int word)
    {
      m_values.AddMember("Word", parse_json<int>::format(word, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool SetModificationToQzssLNAVNavigationMessage::updateParity() const
    {
      return parse_json<bool>::parse(m_values["UpdateParity"]);
    }

    void SetModificationToQzssLNAVNavigationMessage::setUpdateParity(bool updateParity)
    {
      m_values.AddMember("UpdateParity", parse_json<bool>::format(updateParity, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string SetModificationToQzssLNAVNavigationMessage::modification() const
    {
      return parse_json<std::string>::parse(m_values["Modification"]);
    }

    void SetModificationToQzssLNAVNavigationMessage::setModification(const std::string& modification)
    {
      m_values.AddMember("Modification", parse_json<std::string>::format(modification, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string SetModificationToQzssLNAVNavigationMessage::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void SetModificationToQzssLNAVNavigationMessage::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
