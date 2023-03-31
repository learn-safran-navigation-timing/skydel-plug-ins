#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetModificationToBeiDouCNav2Message
///
#include "gen/SetModificationToBeiDouCNav2Message.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetModificationToBeiDouCNav2Message::CmdName = "SetModificationToBeiDouCNav2Message";
    const char* const SetModificationToBeiDouCNav2Message::Documentation = "Please note the command SetModificationToBeiDouCNav2Message is deprecated since 21.3. You may use SetMessageModificationToBeiDouCNav2.\n\nSet (or Modify) event to change CNAV2 message bits. If you send this command without setting the Id\nparameter, or if you set the Id with a value never used before, a new Modification event will be\ncreated. If you reuse the same event Id, it will modify the existing event.\n\nNote that start and stop time are automatically extended to beginning and ending of overlapped\nmessages.\n\nThe Condition parameter is optional and allows you to add content matching condition before applying\nbits mods.\n\nBitsMods can be an empty string. The Modification will have no effect until you modify it with at\nleast one bits mod.\n\nA bits mod is represented with a string using the following format: \"I:Bits\" where I is a bit\nindex (1 refers to the first transmitted bit) and Bits is a modification mask where each\ncharacter describes a modification to a single bit. The allowed characters are:\n   0 : force bit to 0\n   1 : force bit to 1\n   - : leave bit unchanged\n   X : revert bit (0 becomes 1 and 1 becomes 0)\n\nFor example: \"24:X---10XX\" will: revert bits 24, 30 and 31\n                 set bit 28 to 1\n                 set bit 29 to 0\nThe other bits are not affected.\n\nYou can add multiple bits mods using commas. For example: \"24:X---10XX,127:100X,231:01\"";

    REGISTER_COMMAND_FACTORY(SetModificationToBeiDouCNav2Message);


    SetModificationToBeiDouCNav2Message::SetModificationToBeiDouCNav2Message()
      : CommandBase(CmdName)
    {}

    SetModificationToBeiDouCNav2Message::SetModificationToBeiDouCNav2Message(int prn, int startTime, int stopTime, int messageType, const std::string& condition, bool updateCRC, const std::string& bitsMods, const std::string& id)
      : CommandBase(CmdName)
    {

      setPrn(prn);
      setStartTime(startTime);
      setStopTime(stopTime);
      setMessageType(messageType);
      setCondition(condition);
      setUpdateCRC(updateCRC);
      setBitsMods(bitsMods);
      setId(id);
    }


    SetModificationToBeiDouCNav2MessagePtr SetModificationToBeiDouCNav2Message::create(int prn, int startTime, int stopTime, int messageType, const std::string& condition, bool updateCRC, const std::string& bitsMods, const std::string& id)
    {
      return SetModificationToBeiDouCNav2MessagePtr(new SetModificationToBeiDouCNav2Message(prn, startTime, stopTime, messageType, condition, updateCRC, bitsMods, id));
    }

    SetModificationToBeiDouCNav2MessagePtr SetModificationToBeiDouCNav2Message::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetModificationToBeiDouCNav2Message>(ptr);
    }

    bool SetModificationToBeiDouCNav2Message::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["Prn"])
          && parse_json<int>::is_valid(m_values["StartTime"])
          && parse_json<int>::is_valid(m_values["StopTime"])
          && parse_json<int>::is_valid(m_values["MessageType"])
          && parse_json<std::string>::is_valid(m_values["Condition"])
          && parse_json<bool>::is_valid(m_values["UpdateCRC"])
          && parse_json<std::string>::is_valid(m_values["BitsMods"])
          && parse_json<std::string>::is_valid(m_values["Id"])
        ;

    }

    std::string SetModificationToBeiDouCNav2Message::documentation() const { return Documentation; }


    int SetModificationToBeiDouCNav2Message::executePermission() const
    {
      return EXECUTE_IF_SIMULATING | EXECUTE_IF_IDLE;
    }


    int SetModificationToBeiDouCNav2Message::prn() const
    {
      return parse_json<int>::parse(m_values["Prn"]);
    }

    void SetModificationToBeiDouCNav2Message::setPrn(int prn)
    {
      m_values.AddMember("Prn", parse_json<int>::format(prn, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int SetModificationToBeiDouCNav2Message::startTime() const
    {
      return parse_json<int>::parse(m_values["StartTime"]);
    }

    void SetModificationToBeiDouCNav2Message::setStartTime(int startTime)
    {
      m_values.AddMember("StartTime", parse_json<int>::format(startTime, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int SetModificationToBeiDouCNav2Message::stopTime() const
    {
      return parse_json<int>::parse(m_values["StopTime"]);
    }

    void SetModificationToBeiDouCNav2Message::setStopTime(int stopTime)
    {
      m_values.AddMember("StopTime", parse_json<int>::format(stopTime, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int SetModificationToBeiDouCNav2Message::messageType() const
    {
      return parse_json<int>::parse(m_values["MessageType"]);
    }

    void SetModificationToBeiDouCNav2Message::setMessageType(int messageType)
    {
      m_values.AddMember("MessageType", parse_json<int>::format(messageType, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string SetModificationToBeiDouCNav2Message::condition() const
    {
      return parse_json<std::string>::parse(m_values["Condition"]);
    }

    void SetModificationToBeiDouCNav2Message::setCondition(const std::string& condition)
    {
      m_values.AddMember("Condition", parse_json<std::string>::format(condition, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool SetModificationToBeiDouCNav2Message::updateCRC() const
    {
      return parse_json<bool>::parse(m_values["UpdateCRC"]);
    }

    void SetModificationToBeiDouCNav2Message::setUpdateCRC(bool updateCRC)
    {
      m_values.AddMember("UpdateCRC", parse_json<bool>::format(updateCRC, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string SetModificationToBeiDouCNav2Message::bitsMods() const
    {
      return parse_json<std::string>::parse(m_values["BitsMods"]);
    }

    void SetModificationToBeiDouCNav2Message::setBitsMods(const std::string& bitsMods)
    {
      m_values.AddMember("BitsMods", parse_json<std::string>::format(bitsMods, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string SetModificationToBeiDouCNav2Message::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void SetModificationToBeiDouCNav2Message::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
