#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetModificationToBeiDouD2NavigationMessage
///
#include "gen/SetModificationToBeiDouD2NavigationMessage.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetModificationToBeiDouD2NavigationMessage::CmdName = "SetModificationToBeiDouD2NavigationMessage";
    const char* const SetModificationToBeiDouD2NavigationMessage::Documentation = "Please note the command SetModificationToBeiDouD2NavigationMessage is deprecated since 21.3. You may use SetMessageModificationToBeiDouD2Nav.\n\nSet (or Modify) event to change navigation message bits.\n\nNote that start and stop time are automatically extended to beginning and ending of overlapped\nsubframes. The Modification parameter is a string where the first character applies to the first\nbit of subframe word and last character applies to last bit of subframe word.\n   '0' will force bit to zero\n   '1' will for bit to one\n   'X' will negate bit value\n   any other byte value will have no effect\n\nExample: \"-00------------------1-X------\" will force bits 1 and 2 to zero and bit 22 to one\n                      and negate bit 24\n\nNote: if UpdateParity is true, any modification to parity bits will have no effect.\n\nThe Id parameter is automatically updated with a unique id by the simulator for future reference.\nIf the Id is set with a value other than an empty string, the simulator will try to find a match\nwith previously added events. If there is a match, the event is updated with this message\ninstead of adding a new event. If there is no match, the event is added and the id is not\nchanged.";

    REGISTER_COMMAND_FACTORY(SetModificationToBeiDouD2NavigationMessage);


    SetModificationToBeiDouD2NavigationMessage::SetModificationToBeiDouD2NavigationMessage()
      : CommandBase(CmdName)
    {}

    SetModificationToBeiDouD2NavigationMessage::SetModificationToBeiDouD2NavigationMessage(int prn, int startTime, int stopTime, int subFrame, int page, int word, bool updateParity, const std::string& modification, const std::string& id)
      : CommandBase(CmdName)
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


    SetModificationToBeiDouD2NavigationMessagePtr SetModificationToBeiDouD2NavigationMessage::create(int prn, int startTime, int stopTime, int subFrame, int page, int word, bool updateParity, const std::string& modification, const std::string& id)
    {
      return SetModificationToBeiDouD2NavigationMessagePtr(new SetModificationToBeiDouD2NavigationMessage(prn, startTime, stopTime, subFrame, page, word, updateParity, modification, id));
    }

    SetModificationToBeiDouD2NavigationMessagePtr SetModificationToBeiDouD2NavigationMessage::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetModificationToBeiDouD2NavigationMessage>(ptr);
    }

    bool SetModificationToBeiDouD2NavigationMessage::isValid() const
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

    std::string SetModificationToBeiDouD2NavigationMessage::documentation() const { return Documentation; }


    int SetModificationToBeiDouD2NavigationMessage::executePermission() const
    {
      return EXECUTE_IF_SIMULATING | EXECUTE_IF_IDLE;
    }


    int SetModificationToBeiDouD2NavigationMessage::prn() const
    {
      return parse_json<int>::parse(m_values["Prn"]);
    }

    void SetModificationToBeiDouD2NavigationMessage::setPrn(int prn)
    {
      m_values.AddMember("Prn", parse_json<int>::format(prn, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int SetModificationToBeiDouD2NavigationMessage::startTime() const
    {
      return parse_json<int>::parse(m_values["StartTime"]);
    }

    void SetModificationToBeiDouD2NavigationMessage::setStartTime(int startTime)
    {
      m_values.AddMember("StartTime", parse_json<int>::format(startTime, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int SetModificationToBeiDouD2NavigationMessage::stopTime() const
    {
      return parse_json<int>::parse(m_values["StopTime"]);
    }

    void SetModificationToBeiDouD2NavigationMessage::setStopTime(int stopTime)
    {
      m_values.AddMember("StopTime", parse_json<int>::format(stopTime, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int SetModificationToBeiDouD2NavigationMessage::subFrame() const
    {
      return parse_json<int>::parse(m_values["SubFrame"]);
    }

    void SetModificationToBeiDouD2NavigationMessage::setSubFrame(int subFrame)
    {
      m_values.AddMember("SubFrame", parse_json<int>::format(subFrame, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int SetModificationToBeiDouD2NavigationMessage::page() const
    {
      return parse_json<int>::parse(m_values["Page"]);
    }

    void SetModificationToBeiDouD2NavigationMessage::setPage(int page)
    {
      m_values.AddMember("Page", parse_json<int>::format(page, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int SetModificationToBeiDouD2NavigationMessage::word() const
    {
      return parse_json<int>::parse(m_values["Word"]);
    }

    void SetModificationToBeiDouD2NavigationMessage::setWord(int word)
    {
      m_values.AddMember("Word", parse_json<int>::format(word, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool SetModificationToBeiDouD2NavigationMessage::updateParity() const
    {
      return parse_json<bool>::parse(m_values["UpdateParity"]);
    }

    void SetModificationToBeiDouD2NavigationMessage::setUpdateParity(bool updateParity)
    {
      m_values.AddMember("UpdateParity", parse_json<bool>::format(updateParity, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string SetModificationToBeiDouD2NavigationMessage::modification() const
    {
      return parse_json<std::string>::parse(m_values["Modification"]);
    }

    void SetModificationToBeiDouD2NavigationMessage::setModification(const std::string& modification)
    {
      m_values.AddMember("Modification", parse_json<std::string>::format(modification, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string SetModificationToBeiDouD2NavigationMessage::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void SetModificationToBeiDouD2NavigationMessage::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
