#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of IsPrnEnabled
///
#include "gen/IsPrnEnabled.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const IsPrnEnabled::CmdName = "IsPrnEnabled";
    const char* const IsPrnEnabled::Documentation = "Please note the command IsPrnEnabled is deprecated since 21.3. You may use IsSVEnabled.\n\nGet  enabled or disabled satellite for this constellation.";

    REGISTER_COMMAND_FACTORY(IsPrnEnabled);


    IsPrnEnabled::IsPrnEnabled()
      : CommandBase(CmdName)
    {}

    IsPrnEnabled::IsPrnEnabled(const std::string& system, int prn)
      : CommandBase(CmdName)
    {

      setSystem(system);
      setPrn(prn);
    }


    IsPrnEnabledPtr IsPrnEnabled::create(const std::string& system, int prn)
    {
      return IsPrnEnabledPtr(new IsPrnEnabled(system, prn));
    }

    IsPrnEnabledPtr IsPrnEnabled::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<IsPrnEnabled>(ptr);
    }

    bool IsPrnEnabled::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["System"])
          && parse_json<int>::is_valid(m_values["Prn"])
        ;

    }

    std::string IsPrnEnabled::documentation() const { return Documentation; }


    int IsPrnEnabled::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string IsPrnEnabled::system() const
    {
      return parse_json<std::string>::parse(m_values["System"]);
    }

    void IsPrnEnabled::setSystem(const std::string& system)
    {
      m_values.AddMember("System", parse_json<std::string>::format(system, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int IsPrnEnabled::prn() const
    {
      return parse_json<int>::parse(m_values["Prn"]);
    }

    void IsPrnEnabled::setPrn(int prn)
    {
      m_values.AddMember("Prn", parse_json<int>::format(prn, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
