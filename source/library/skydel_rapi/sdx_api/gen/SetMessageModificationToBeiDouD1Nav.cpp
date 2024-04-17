
#include "SetMessageModificationToBeiDouD1Nav.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetMessageModificationToBeiDouD1Nav
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetMessageModificationToBeiDouD1Nav::CmdName = "SetMessageModificationToBeiDouD1Nav";
    const char* const SetMessageModificationToBeiDouD1Nav::Documentation = "Set (or Modify) event to change BeiDou D1 NAV navigation message bits.\n"
      "\n"
      "Note that start and stop time are automatically extended to beginning and ending of overlapped\n"
      "subframes. The Modification parameter is a string where the first character applies to the first\n"
      "bit of subframe word and last character applies to last bit of subframe word.\n"
      "   '0' will force bit to zero\n"
      "   '1' will for bit to one\n"
      "   'X' will negate bit value\n"
      "   any other byte value will have no effect\n"
      "\n"
      "Example: \"-00------------------1-X------\" will force bits 1 and 2 to zero and bit 22 to one\n"
      "                      and negate bit 24\n"
      "\n"
      "Note: if UpdateParity is true, any modification to parity bits will have no effect.\n"
      "\n"
      "The ID parameter is automatically updated with a unique ID by the simulator for future reference.\n"
      "If the ID is set with a value other than an empty string, the simulator will try to find a match\n"
      "with previously added events. If there is a match, the event is updated with this message\n"
      "instead of adding a new event. If there is no match, the event is added and the ID is not\n"
      "changed.\n"
      "\n"
      "Name             Type         Description\n"
      "---------------- ------------ ---------------------------------------------------------------------------------------------------\n"
      "SignalArray      array string Array of signals to apply the message modification to, accepts \"B1\", \"B2\" and \"B3I\" (empty for all)\n"
      "SvId             int          The satellite's SV ID 1..35 (use 0 to apply modification to all SVs)\n"
      "StartTime        int          Elapsed time in seconds since start of simulation\n"
      "StopTime         int          Elapsed time in seconds since start of simulation (use 0 for no stop time)\n"
      "Subframe         int          Subframe 1..5 (use 0 to apply modification to all subframes)\n"
      "Page             int          Page 1..24 (use 0 to apply modification to all pages)\n"
      "Word             int          Word 1..10 (use 0 to apply modification to all words)\n"
      "UpdateParity     bool         Recalculate parity after making modification\n"
      "WordModification string       Modification string must be 30 bits long\n"
      "Id               string       Unique identifier of the event";
    const char* const SetMessageModificationToBeiDouD1Nav::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(SetMessageModificationToBeiDouD1Nav);
    REGISTER_COMMAND_TO_FACTORY_IMPL(SetMessageModificationToBeiDouD1Nav);


    SetMessageModificationToBeiDouD1Nav::SetMessageModificationToBeiDouD1Nav()
      : CommandBase(CmdName, TargetId)
    {}

    SetMessageModificationToBeiDouD1Nav::SetMessageModificationToBeiDouD1Nav(const std::vector<std::string>& signalArray, int svId, int startTime, int stopTime, int subframe, int page, int word, bool updateParity, const std::string& wordModification, const std::string& id)
      : CommandBase(CmdName, TargetId)
    {

      setSignalArray(signalArray);
      setSvId(svId);
      setStartTime(startTime);
      setStopTime(stopTime);
      setSubframe(subframe);
      setPage(page);
      setWord(word);
      setUpdateParity(updateParity);
      setWordModification(wordModification);
      setId(id);
    }

    SetMessageModificationToBeiDouD1NavPtr SetMessageModificationToBeiDouD1Nav::create(const std::vector<std::string>& signalArray, int svId, int startTime, int stopTime, int subframe, int page, int word, bool updateParity, const std::string& wordModification, const std::string& id)
    {
      return std::make_shared<SetMessageModificationToBeiDouD1Nav>(signalArray, svId, startTime, stopTime, subframe, page, word, updateParity, wordModification, id);
    }

    SetMessageModificationToBeiDouD1NavPtr SetMessageModificationToBeiDouD1Nav::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetMessageModificationToBeiDouD1Nav>(ptr);
    }

    bool SetMessageModificationToBeiDouD1Nav::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::vector<std::string>>::is_valid(m_values["SignalArray"])
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<int>::is_valid(m_values["StartTime"])
          && parse_json<int>::is_valid(m_values["StopTime"])
          && parse_json<int>::is_valid(m_values["Subframe"])
          && parse_json<int>::is_valid(m_values["Page"])
          && parse_json<int>::is_valid(m_values["Word"])
          && parse_json<bool>::is_valid(m_values["UpdateParity"])
          && parse_json<std::string>::is_valid(m_values["WordModification"])
          && parse_json<std::string>::is_valid(m_values["Id"])
        ;

    }

    std::string SetMessageModificationToBeiDouD1Nav::documentation() const { return Documentation; }

    const std::vector<std::string>& SetMessageModificationToBeiDouD1Nav::fieldNames() const 
    { 
      static const std::vector<std::string> names {"SignalArray", "SvId", "StartTime", "StopTime", "Subframe", "Page", "Word", "UpdateParity", "WordModification", "Id"}; 
      return names; 
    }


    int SetMessageModificationToBeiDouD1Nav::executePermission() const
    {
      return EXECUTE_IF_SIMULATING | EXECUTE_IF_IDLE;
    }


    std::vector<std::string> SetMessageModificationToBeiDouD1Nav::signalArray() const
    {
      return parse_json<std::vector<std::string>>::parse(m_values["SignalArray"]);
    }

    void SetMessageModificationToBeiDouD1Nav::setSignalArray(const std::vector<std::string>& signalArray)
    {
      m_values.AddMember("SignalArray", parse_json<std::vector<std::string>>::format(signalArray, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int SetMessageModificationToBeiDouD1Nav::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void SetMessageModificationToBeiDouD1Nav::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int SetMessageModificationToBeiDouD1Nav::startTime() const
    {
      return parse_json<int>::parse(m_values["StartTime"]);
    }

    void SetMessageModificationToBeiDouD1Nav::setStartTime(int startTime)
    {
      m_values.AddMember("StartTime", parse_json<int>::format(startTime, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int SetMessageModificationToBeiDouD1Nav::stopTime() const
    {
      return parse_json<int>::parse(m_values["StopTime"]);
    }

    void SetMessageModificationToBeiDouD1Nav::setStopTime(int stopTime)
    {
      m_values.AddMember("StopTime", parse_json<int>::format(stopTime, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int SetMessageModificationToBeiDouD1Nav::subframe() const
    {
      return parse_json<int>::parse(m_values["Subframe"]);
    }

    void SetMessageModificationToBeiDouD1Nav::setSubframe(int subframe)
    {
      m_values.AddMember("Subframe", parse_json<int>::format(subframe, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int SetMessageModificationToBeiDouD1Nav::page() const
    {
      return parse_json<int>::parse(m_values["Page"]);
    }

    void SetMessageModificationToBeiDouD1Nav::setPage(int page)
    {
      m_values.AddMember("Page", parse_json<int>::format(page, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int SetMessageModificationToBeiDouD1Nav::word() const
    {
      return parse_json<int>::parse(m_values["Word"]);
    }

    void SetMessageModificationToBeiDouD1Nav::setWord(int word)
    {
      m_values.AddMember("Word", parse_json<int>::format(word, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool SetMessageModificationToBeiDouD1Nav::updateParity() const
    {
      return parse_json<bool>::parse(m_values["UpdateParity"]);
    }

    void SetMessageModificationToBeiDouD1Nav::setUpdateParity(bool updateParity)
    {
      m_values.AddMember("UpdateParity", parse_json<bool>::format(updateParity, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string SetMessageModificationToBeiDouD1Nav::wordModification() const
    {
      return parse_json<std::string>::parse(m_values["WordModification"]);
    }

    void SetMessageModificationToBeiDouD1Nav::setWordModification(const std::string& wordModification)
    {
      m_values.AddMember("WordModification", parse_json<std::string>::format(wordModification, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string SetMessageModificationToBeiDouD1Nav::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void SetMessageModificationToBeiDouD1Nav::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
