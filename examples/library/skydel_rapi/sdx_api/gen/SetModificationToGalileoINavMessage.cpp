#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetModificationToGalileoINavMessage
///
#include "gen/SetModificationToGalileoINavMessage.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetModificationToGalileoINavMessage::CmdName = "SetModificationToGalileoINavMessage";
    const char* const SetModificationToGalileoINavMessage::Documentation = "Please note the command SetModificationToGalileoINavMessage is deprecated since 21.3. You may use SetMessageModificationToGalileoINav.\n\nSet (or Modify) event to change INAV message bits. If you send this command without setting the Id\nparameter, or if you set the Id with a value never used before, a new Modification event will be\ncreated. If you reuse the same event Id, it will modify the existing event.\n\nNote that start and stop time are automatically extended to beginning and ending of overlapped\nmessages.\n\nBitsMods can be an empty string. The Modification will have no effect until you modify it with at\nleast one bits mod.\n\nA bits mod is represented with a string using the following format: \"I:Bits\" where I is a bit\nindex (1 refers to the first transmitted bit) and Bits is a modification mask where each\ncharacter describes a modification to a single bit. The allowed characters are:\n   0 : force bit to 0\n   1 : force bit to 1\n   - : leave bit unchanged\n   X : revert bit (0 becomes 1 and 1 becomes 0)\n\nFor example: \"24:X---10XX\" will: revert bits 24, 30 and 31\n                 set bit 28 to 1\n                 set bit 29 to 0\nThe other bits are not affected.\n\nYou can add multiple bits mods using commas. For example: \"24:X---10XX,127:100X,231:01\"";

    REGISTER_COMMAND_FACTORY(SetModificationToGalileoINavMessage);


    SetModificationToGalileoINavMessage::SetModificationToGalileoINavMessage()
      : CommandBase(CmdName)
    {}

    SetModificationToGalileoINavMessage::SetModificationToGalileoINavMessage(int prn, int startTime, int stopTime, int subFrame, int page, bool updateCRC, const std::string& bitsMods, bool e1, bool e5b, const std::string& id)
      : CommandBase(CmdName)
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


    SetModificationToGalileoINavMessagePtr SetModificationToGalileoINavMessage::create(int prn, int startTime, int stopTime, int subFrame, int page, bool updateCRC, const std::string& bitsMods, bool e1, bool e5b, const std::string& id)
    {
      return SetModificationToGalileoINavMessagePtr(new SetModificationToGalileoINavMessage(prn, startTime, stopTime, subFrame, page, updateCRC, bitsMods, e1, e5b, id));
    }

    SetModificationToGalileoINavMessagePtr SetModificationToGalileoINavMessage::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetModificationToGalileoINavMessage>(ptr);
    }

    bool SetModificationToGalileoINavMessage::isValid() const
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

    std::string SetModificationToGalileoINavMessage::documentation() const { return Documentation; }


    int SetModificationToGalileoINavMessage::executePermission() const
    {
      return EXECUTE_IF_SIMULATING | EXECUTE_IF_IDLE;
    }


    int SetModificationToGalileoINavMessage::prn() const
    {
      return parse_json<int>::parse(m_values["Prn"]);
    }

    void SetModificationToGalileoINavMessage::setPrn(int prn)
    {
      m_values.AddMember("Prn", parse_json<int>::format(prn, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int SetModificationToGalileoINavMessage::startTime() const
    {
      return parse_json<int>::parse(m_values["StartTime"]);
    }

    void SetModificationToGalileoINavMessage::setStartTime(int startTime)
    {
      m_values.AddMember("StartTime", parse_json<int>::format(startTime, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int SetModificationToGalileoINavMessage::stopTime() const
    {
      return parse_json<int>::parse(m_values["StopTime"]);
    }

    void SetModificationToGalileoINavMessage::setStopTime(int stopTime)
    {
      m_values.AddMember("StopTime", parse_json<int>::format(stopTime, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int SetModificationToGalileoINavMessage::subFrame() const
    {
      return parse_json<int>::parse(m_values["SubFrame"]);
    }

    void SetModificationToGalileoINavMessage::setSubFrame(int subFrame)
    {
      m_values.AddMember("SubFrame", parse_json<int>::format(subFrame, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int SetModificationToGalileoINavMessage::page() const
    {
      return parse_json<int>::parse(m_values["Page"]);
    }

    void SetModificationToGalileoINavMessage::setPage(int page)
    {
      m_values.AddMember("Page", parse_json<int>::format(page, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool SetModificationToGalileoINavMessage::updateCRC() const
    {
      return parse_json<bool>::parse(m_values["UpdateCRC"]);
    }

    void SetModificationToGalileoINavMessage::setUpdateCRC(bool updateCRC)
    {
      m_values.AddMember("UpdateCRC", parse_json<bool>::format(updateCRC, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string SetModificationToGalileoINavMessage::bitsMods() const
    {
      return parse_json<std::string>::parse(m_values["BitsMods"]);
    }

    void SetModificationToGalileoINavMessage::setBitsMods(const std::string& bitsMods)
    {
      m_values.AddMember("BitsMods", parse_json<std::string>::format(bitsMods, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool SetModificationToGalileoINavMessage::e1() const
    {
      return parse_json<bool>::parse(m_values["E1"]);
    }

    void SetModificationToGalileoINavMessage::setE1(bool e1)
    {
      m_values.AddMember("E1", parse_json<bool>::format(e1, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool SetModificationToGalileoINavMessage::e5b() const
    {
      return parse_json<bool>::parse(m_values["E5b"]);
    }

    void SetModificationToGalileoINavMessage::setE5b(bool e5b)
    {
      m_values.AddMember("E5b", parse_json<bool>::format(e5b, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string SetModificationToGalileoINavMessage::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void SetModificationToGalileoINavMessage::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
