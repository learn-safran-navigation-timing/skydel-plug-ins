#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of RemoveAllMultipathForPrn
///
#include "gen/RemoveAllMultipathForPrn.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const RemoveAllMultipathForPrn::CmdName = "RemoveAllMultipathForPrn";
    const char* const RemoveAllMultipathForPrn::Documentation = "Please note the command RemoveAllMultipathForPrn is deprecated since 21.3. You may use RemoveAllMultipathForSV.\n\nDisable all multipath for the specified satellite.";

    REGISTER_COMMAND_FACTORY(RemoveAllMultipathForPrn);


    RemoveAllMultipathForPrn::RemoveAllMultipathForPrn()
      : CommandBase(CmdName)
    {}

    RemoveAllMultipathForPrn::RemoveAllMultipathForPrn(int prn, const std::string& system, bool reset)
      : CommandBase(CmdName)
    {

      setPrn(prn);
      setSystem(system);
      setReset(reset);
    }


    RemoveAllMultipathForPrnPtr RemoveAllMultipathForPrn::create(int prn, const std::string& system, bool reset)
    {
      return RemoveAllMultipathForPrnPtr(new RemoveAllMultipathForPrn(prn, system, reset));
    }

    RemoveAllMultipathForPrnPtr RemoveAllMultipathForPrn::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<RemoveAllMultipathForPrn>(ptr);
    }

    bool RemoveAllMultipathForPrn::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["Prn"])
          && parse_json<std::string>::is_valid(m_values["System"])
          && parse_json<bool>::is_valid(m_values["Reset"])
        ;

    }

    std::string RemoveAllMultipathForPrn::documentation() const { return Documentation; }


    int RemoveAllMultipathForPrn::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    int RemoveAllMultipathForPrn::prn() const
    {
      return parse_json<int>::parse(m_values["Prn"]);
    }

    void RemoveAllMultipathForPrn::setPrn(int prn)
    {
      m_values.AddMember("Prn", parse_json<int>::format(prn, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string RemoveAllMultipathForPrn::system() const
    {
      return parse_json<std::string>::parse(m_values["System"]);
    }

    void RemoveAllMultipathForPrn::setSystem(const std::string& system)
    {
      m_values.AddMember("System", parse_json<std::string>::format(system, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool RemoveAllMultipathForPrn::reset() const
    {
      return parse_json<bool>::parse(m_values["Reset"]);
    }

    void RemoveAllMultipathForPrn::setReset(bool reset)
    {
      m_values.AddMember("Reset", parse_json<bool>::format(reset, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
