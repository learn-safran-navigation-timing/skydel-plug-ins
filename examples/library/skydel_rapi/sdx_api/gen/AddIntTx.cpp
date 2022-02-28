#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of AddIntTx
///
#include "gen/AddIntTx.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const AddIntTx::CmdName = "AddIntTx";
    const char* const AddIntTx::Documentation = "Set an interference transmitter. For set : the transmitter Id parameter is not set (empty string),\nSkydel will assign a unique Id to the transmitter. If the Id is set and already used by Skydel, the\ncommand will fail.";

    REGISTER_COMMAND_FACTORY(AddIntTx);


    AddIntTx::AddIntTx()
      : CommandBase(CmdName)
    {}

    AddIntTx::AddIntTx(const std::string& usualName, bool enabled, int group, bool dynamic, double power, const std::string& id)
      : CommandBase(CmdName)
    {

      setUsualName(usualName);
      setEnabled(enabled);
      setGroup(group);
      setDynamic(dynamic);
      setPower(power);
      setId(id);
    }


    AddIntTxPtr AddIntTx::create(const std::string& usualName, bool enabled, int group, bool dynamic, double power, const std::string& id)
    {
      return std::make_shared<AddIntTx>(usualName, enabled, group, dynamic, power, id);
    }

    AddIntTxPtr AddIntTx::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<AddIntTx>(ptr);
    }

    bool AddIntTx::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["UsualName"])
          && parse_json<bool>::is_valid(m_values["Enabled"])
          && parse_json<int>::is_valid(m_values["Group"])
          && parse_json<bool>::is_valid(m_values["Dynamic"])
          && parse_json<double>::is_valid(m_values["Power"])
          && parse_json<std::string>::is_valid(m_values["Id"])
        ;

    }

    std::string AddIntTx::documentation() const { return Documentation; }


    int AddIntTx::executePermission() const
    {
      return EXECUTE_IF_SIMULATING | EXECUTE_IF_IDLE;
    }


    std::string AddIntTx::usualName() const
    {
      return parse_json<std::string>::parse(m_values["UsualName"]);
    }

    void AddIntTx::setUsualName(const std::string& usualName)
    {
      m_values.AddMember("UsualName", parse_json<std::string>::format(usualName, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool AddIntTx::enabled() const
    {
      return parse_json<bool>::parse(m_values["Enabled"]);
    }

    void AddIntTx::setEnabled(bool enabled)
    {
      m_values.AddMember("Enabled", parse_json<bool>::format(enabled, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int AddIntTx::group() const
    {
      return parse_json<int>::parse(m_values["Group"]);
    }

    void AddIntTx::setGroup(int group)
    {
      m_values.AddMember("Group", parse_json<int>::format(group, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool AddIntTx::dynamic() const
    {
      return parse_json<bool>::parse(m_values["Dynamic"]);
    }

    void AddIntTx::setDynamic(bool dynamic)
    {
      m_values.AddMember("Dynamic", parse_json<bool>::format(dynamic, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double AddIntTx::power() const
    {
      return parse_json<double>::parse(m_values["Power"]);
    }

    void AddIntTx::setPower(double power)
    {
      m_values.AddMember("Power", parse_json<double>::format(power, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string AddIntTx::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void AddIntTx::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
