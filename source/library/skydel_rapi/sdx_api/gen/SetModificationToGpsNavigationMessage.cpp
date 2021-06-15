#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetModificationToGpsNavigationMessage
///
#include "gen/SetModificationToGpsNavigationMessage.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetModificationToGpsNavigationMessage::CmdName = "SetModificationToGpsNavigationMessage";
    const char* const SetModificationToGpsNavigationMessage::Documentation = "Please note the command SetModificationToGpsNavigationMessage is deprecated since 21.3. You may use SetMessageModificationToGpsLNav.\n\nSet (or Modify) event to change navigation message bits.\n\nNote that start and stop time are automatically extended to beginning and ending of overlapped\nsubframes. The Modification parameter is a string where the first character applies to the first\nbit of subframe word and last character applies to last bit of subframe word.\n   '0' will force bit to zero\n   '1' will for bit to one\n   'X' will negate bit value\n   any other byte value will have no effect\n\nExample: \"-00------------------1-X------\" will force bits 1 and 2 to zero and bit 22 to one\n                      and negate bit 24\n\nNote: if UpdateParity is true, any modification to bits 25..30 will have no effect.\n\nThe Id parameter is automatically updated with a unique id by the simulator for future reference.\nIf the Id is set with a value other than an empty string, the simulator will try to find a match\nwith previously added events. If there is a match, the event is updated with this message\ninstead of adding a new event. If there is no match, the event is added and the id is not\nchanged.";

    REGISTER_COMMAND_FACTORY(SetModificationToGpsNavigationMessage);


    SetModificationToGpsNavigationMessage::SetModificationToGpsNavigationMessage()
      : CommandBase(CmdName)
    {}

    SetModificationToGpsNavigationMessage::SetModificationToGpsNavigationMessage(int prn, int startTime, int stopTime, int subFrame, int page, int word, bool updateParity, const std::string& modification, const std::string& id)
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


    SetModificationToGpsNavigationMessagePtr SetModificationToGpsNavigationMessage::create(int prn, int startTime, int stopTime, int subFrame, int page, int word, bool updateParity, const std::string& modification, const std::string& id)
    {
      return SetModificationToGpsNavigationMessagePtr(new SetModificationToGpsNavigationMessage(prn, startTime, stopTime, subFrame, page, word, updateParity, modification, id));
    }

    SetModificationToGpsNavigationMessagePtr SetModificationToGpsNavigationMessage::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetModificationToGpsNavigationMessage>(ptr);
    }

    bool SetModificationToGpsNavigationMessage::isValid() const
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

    std::string SetModificationToGpsNavigationMessage::documentation() const { return Documentation; }


    int SetModificationToGpsNavigationMessage::executePermission() const
    {
      return EXECUTE_IF_SIMULATING | EXECUTE_IF_IDLE;
    }


    int SetModificationToGpsNavigationMessage::prn() const
    {
      return parse_json<int>::parse(m_values["Prn"]);
    }

    void SetModificationToGpsNavigationMessage::setPrn(int prn)
    {
      m_values.AddMember("Prn", parse_json<int>::format(prn, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int SetModificationToGpsNavigationMessage::startTime() const
    {
      return parse_json<int>::parse(m_values["StartTime"]);
    }

    void SetModificationToGpsNavigationMessage::setStartTime(int startTime)
    {
      m_values.AddMember("StartTime", parse_json<int>::format(startTime, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int SetModificationToGpsNavigationMessage::stopTime() const
    {
      return parse_json<int>::parse(m_values["StopTime"]);
    }

    void SetModificationToGpsNavigationMessage::setStopTime(int stopTime)
    {
      m_values.AddMember("StopTime", parse_json<int>::format(stopTime, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int SetModificationToGpsNavigationMessage::subFrame() const
    {
      return parse_json<int>::parse(m_values["SubFrame"]);
    }

    void SetModificationToGpsNavigationMessage::setSubFrame(int subFrame)
    {
      m_values.AddMember("SubFrame", parse_json<int>::format(subFrame, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int SetModificationToGpsNavigationMessage::page() const
    {
      return parse_json<int>::parse(m_values["Page"]);
    }

    void SetModificationToGpsNavigationMessage::setPage(int page)
    {
      m_values.AddMember("Page", parse_json<int>::format(page, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int SetModificationToGpsNavigationMessage::word() const
    {
      return parse_json<int>::parse(m_values["Word"]);
    }

    void SetModificationToGpsNavigationMessage::setWord(int word)
    {
      m_values.AddMember("Word", parse_json<int>::format(word, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool SetModificationToGpsNavigationMessage::updateParity() const
    {
      return parse_json<bool>::parse(m_values["UpdateParity"]);
    }

    void SetModificationToGpsNavigationMessage::setUpdateParity(bool updateParity)
    {
      m_values.AddMember("UpdateParity", parse_json<bool>::format(updateParity, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string SetModificationToGpsNavigationMessage::modification() const
    {
      return parse_json<std::string>::parse(m_values["Modification"]);
    }

    void SetModificationToGpsNavigationMessage::setModification(const std::string& modification)
    {
      m_values.AddMember("Modification", parse_json<std::string>::format(modification, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string SetModificationToGpsNavigationMessage::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void SetModificationToGpsNavigationMessage::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
