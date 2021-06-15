#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetModificationToGlonassNavigationMessage
///
#include "gen/SetModificationToGlonassNavigationMessage.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetModificationToGlonassNavigationMessage::CmdName = "SetModificationToGlonassNavigationMessage";
    const char* const SetModificationToGlonassNavigationMessage::Documentation = "Please note the command SetModificationToGlonassNavigationMessage is deprecated since 21.3. You may use SetMessageModificationToGlonassNav.\n\nSet (or Modify) event to change navigation message bits.\n\nNote that start and stop time are automatically extended to beginning and ending of overlapped\nmessage strings. The Modification parameter is a string where the first character applies to bit\n85 of frame string and last character applies to Hamming Code bit 1.\n   '0' will force bit to zero\n   '1' will for bit to one\n   'X' will negate bit value\n   ' ' white space are ignored (use them to separate the string into bytes to help reading)\n   '-' or any other byte value will have no effect\n\nExample:\n\n\"-0--- 1------- -------- -------- -------- -------- -------- -------- -------- -------- ---1--X-\"\n  |  |                                           |  |\n  |  +- Force bit 80 to '1'               Force Hamming code bit 5 to '1' -+  |\n  |                                               |\n  +------ Force bit 84 to 0                   Negate Hamming code bit 2 ----+\n\nNote: if UpdateHammingCode is true, any modification to bits 1..8 will have no effect.\n\nThe Id parameter is automatically updated with a unique id by the simulator for future reference.\nIf the Id is set with a value other than an empty string, the simulator will try to find a match\nwith previously added events. If there is a match, the event is updated with this message\ninstead of adding a new event. If there is no match, the event is added and the id is not\nchanged.";

    REGISTER_COMMAND_FACTORY(SetModificationToGlonassNavigationMessage);


    SetModificationToGlonassNavigationMessage::SetModificationToGlonassNavigationMessage()
      : CommandBase(CmdName)
    {}

    SetModificationToGlonassNavigationMessage::SetModificationToGlonassNavigationMessage(int prn, int startTime, int stopTime, int frame, int stringNumber, bool updateHammingCode, const std::string& modification, const std::string& id)
      : CommandBase(CmdName)
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


    SetModificationToGlonassNavigationMessagePtr SetModificationToGlonassNavigationMessage::create(int prn, int startTime, int stopTime, int frame, int stringNumber, bool updateHammingCode, const std::string& modification, const std::string& id)
    {
      return SetModificationToGlonassNavigationMessagePtr(new SetModificationToGlonassNavigationMessage(prn, startTime, stopTime, frame, stringNumber, updateHammingCode, modification, id));
    }

    SetModificationToGlonassNavigationMessagePtr SetModificationToGlonassNavigationMessage::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetModificationToGlonassNavigationMessage>(ptr);
    }

    bool SetModificationToGlonassNavigationMessage::isValid() const
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

    std::string SetModificationToGlonassNavigationMessage::documentation() const { return Documentation; }


    int SetModificationToGlonassNavigationMessage::executePermission() const
    {
      return EXECUTE_IF_SIMULATING | EXECUTE_IF_IDLE;
    }


    int SetModificationToGlonassNavigationMessage::prn() const
    {
      return parse_json<int>::parse(m_values["Prn"]);
    }

    void SetModificationToGlonassNavigationMessage::setPrn(int prn)
    {
      m_values.AddMember("Prn", parse_json<int>::format(prn, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int SetModificationToGlonassNavigationMessage::startTime() const
    {
      return parse_json<int>::parse(m_values["StartTime"]);
    }

    void SetModificationToGlonassNavigationMessage::setStartTime(int startTime)
    {
      m_values.AddMember("StartTime", parse_json<int>::format(startTime, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int SetModificationToGlonassNavigationMessage::stopTime() const
    {
      return parse_json<int>::parse(m_values["StopTime"]);
    }

    void SetModificationToGlonassNavigationMessage::setStopTime(int stopTime)
    {
      m_values.AddMember("StopTime", parse_json<int>::format(stopTime, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int SetModificationToGlonassNavigationMessage::frame() const
    {
      return parse_json<int>::parse(m_values["Frame"]);
    }

    void SetModificationToGlonassNavigationMessage::setFrame(int frame)
    {
      m_values.AddMember("Frame", parse_json<int>::format(frame, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int SetModificationToGlonassNavigationMessage::stringNumber() const
    {
      return parse_json<int>::parse(m_values["StringNumber"]);
    }

    void SetModificationToGlonassNavigationMessage::setStringNumber(int stringNumber)
    {
      m_values.AddMember("StringNumber", parse_json<int>::format(stringNumber, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool SetModificationToGlonassNavigationMessage::updateHammingCode() const
    {
      return parse_json<bool>::parse(m_values["UpdateHammingCode"]);
    }

    void SetModificationToGlonassNavigationMessage::setUpdateHammingCode(bool updateHammingCode)
    {
      m_values.AddMember("UpdateHammingCode", parse_json<bool>::format(updateHammingCode, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string SetModificationToGlonassNavigationMessage::modification() const
    {
      return parse_json<std::string>::parse(m_values["Modification"]);
    }

    void SetModificationToGlonassNavigationMessage::setModification(const std::string& modification)
    {
      m_values.AddMember("Modification", parse_json<std::string>::format(modification, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string SetModificationToGlonassNavigationMessage::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void SetModificationToGlonassNavigationMessage::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
