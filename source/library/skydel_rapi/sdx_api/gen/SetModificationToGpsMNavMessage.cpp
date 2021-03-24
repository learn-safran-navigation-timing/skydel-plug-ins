#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetModificationToGpsMNavMessage
///
#include "gen/SetModificationToGpsMNavMessage.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetModificationToGpsMNavMessage::CmdName = "SetModificationToGpsMNavMessage";
    const char* const SetModificationToGpsMNavMessage::Documentation = "Please note the command SetModificationToGpsMNavMessage is deprecated since 21.3. You may use SetMessageModificationToGpsMNav.\n\nSet (or Modify) event to change MNAV message bits. If you send this command without setting the Id\nparameter, or if you set the Id with a value never used before, a new Modification event will be\ncreated. If you reuse the same event Id, it will modify the existing event.\n\nNote that start and stop time are automatically extended to beginning and ending of overlapped\nmessages.\n\nThe Condition parameter is optional and allows you to add content matching condition before applying\nbits mods.\n\nBitsMods can be an empty string. The Modification will have no effect until you modify it with at\nleast one bits mod.\n\nA bits mod is represented with a string using the following format: \"I:Bits\" where I is a bit\nindex (1 refers to the first transmitted bit) and Bits is a modification mask where each\ncharacter describes a modification to a single bit. The allowed characters are:\n   0 : force bit to 0\n   1 : force bit to 1\n   - : leave bit unchanged\n   X : revert bit (0 becomes 1 and 1 becomes 0)\n\nFor example: \"24:X---10XX\" will: revert bits 24, 30 and 31\n                 set bit 28 to 1\n                 set bit 29 to 0\nThe other bits are not affected.\n\nYou can add multiple bits mods using commas. For example: \"24:X---10XX,127:100X,231:01\"";

    REGISTER_COMMAND_FACTORY(SetModificationToGpsMNavMessage);


    SetModificationToGpsMNavMessage::SetModificationToGpsMNavMessage()
      : CommandBase(CmdName)
    {}

    SetModificationToGpsMNavMessage::SetModificationToGpsMNavMessage(int prn, int startTime, int stopTime, int msgTypeId, int occurrence, const std::string& condition, const std::string& bitsMods, const std::string& id)
      : CommandBase(CmdName)
    {

      setPrn(prn);
      setStartTime(startTime);
      setStopTime(stopTime);
      setMsgTypeId(msgTypeId);
      setOccurrence(occurrence);
      setCondition(condition);
      setBitsMods(bitsMods);
      setId(id);
    }


    SetModificationToGpsMNavMessagePtr SetModificationToGpsMNavMessage::create(int prn, int startTime, int stopTime, int msgTypeId, int occurrence, const std::string& condition, const std::string& bitsMods, const std::string& id)
    {
      return SetModificationToGpsMNavMessagePtr(new SetModificationToGpsMNavMessage(prn, startTime, stopTime, msgTypeId, occurrence, condition, bitsMods, id));
    }

    SetModificationToGpsMNavMessagePtr SetModificationToGpsMNavMessage::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetModificationToGpsMNavMessage>(ptr);
    }

    bool SetModificationToGpsMNavMessage::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["Prn"])
          && parse_json<int>::is_valid(m_values["StartTime"])
          && parse_json<int>::is_valid(m_values["StopTime"])
          && parse_json<int>::is_valid(m_values["MsgTypeId"])
          && parse_json<int>::is_valid(m_values["Occurrence"])
          && parse_json<std::string>::is_valid(m_values["Condition"])
          && parse_json<std::string>::is_valid(m_values["BitsMods"])
          && parse_json<std::string>::is_valid(m_values["Id"])
        ;

    }

    std::string SetModificationToGpsMNavMessage::documentation() const { return Documentation; }


    int SetModificationToGpsMNavMessage::executePermission() const
    {
      return EXECUTE_IF_SIMULATING | EXECUTE_IF_IDLE;
    }


    int SetModificationToGpsMNavMessage::prn() const
    {
      return parse_json<int>::parse(m_values["Prn"]);
    }

    void SetModificationToGpsMNavMessage::setPrn(int prn)
    {
      m_values.AddMember("Prn", parse_json<int>::format(prn, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int SetModificationToGpsMNavMessage::startTime() const
    {
      return parse_json<int>::parse(m_values["StartTime"]);
    }

    void SetModificationToGpsMNavMessage::setStartTime(int startTime)
    {
      m_values.AddMember("StartTime", parse_json<int>::format(startTime, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int SetModificationToGpsMNavMessage::stopTime() const
    {
      return parse_json<int>::parse(m_values["StopTime"]);
    }

    void SetModificationToGpsMNavMessage::setStopTime(int stopTime)
    {
      m_values.AddMember("StopTime", parse_json<int>::format(stopTime, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int SetModificationToGpsMNavMessage::msgTypeId() const
    {
      return parse_json<int>::parse(m_values["MsgTypeId"]);
    }

    void SetModificationToGpsMNavMessage::setMsgTypeId(int msgTypeId)
    {
      m_values.AddMember("MsgTypeId", parse_json<int>::format(msgTypeId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int SetModificationToGpsMNavMessage::occurrence() const
    {
      return parse_json<int>::parse(m_values["Occurrence"]);
    }

    void SetModificationToGpsMNavMessage::setOccurrence(int occurrence)
    {
      m_values.AddMember("Occurrence", parse_json<int>::format(occurrence, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string SetModificationToGpsMNavMessage::condition() const
    {
      return parse_json<std::string>::parse(m_values["Condition"]);
    }

    void SetModificationToGpsMNavMessage::setCondition(const std::string& condition)
    {
      m_values.AddMember("Condition", parse_json<std::string>::format(condition, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string SetModificationToGpsMNavMessage::bitsMods() const
    {
      return parse_json<std::string>::parse(m_values["BitsMods"]);
    }

    void SetModificationToGpsMNavMessage::setBitsMods(const std::string& bitsMods)
    {
      m_values.AddMember("BitsMods", parse_json<std::string>::format(bitsMods, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string SetModificationToGpsMNavMessage::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void SetModificationToGpsMNavMessage::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
