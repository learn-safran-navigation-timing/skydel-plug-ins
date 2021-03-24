#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetAllMultipathForPrn
///
#include "gen/GetAllMultipathForPrn.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetAllMultipathForPrn::CmdName = "GetAllMultipathForPrn";
    const char* const GetAllMultipathForPrn::Documentation = "Please note the command GetAllMultipathForPrn is deprecated since 21.3. You may use GetAllMultipathForSV.\n\nGet all multipath ID for the specified satellite of the constellation.";

    REGISTER_COMMAND_FACTORY(GetAllMultipathForPrn);


    GetAllMultipathForPrn::GetAllMultipathForPrn()
      : CommandBase(CmdName)
    {}

    GetAllMultipathForPrn::GetAllMultipathForPrn(const std::string& system, int prn)
      : CommandBase(CmdName)
    {

      setSystem(system);
      setPrn(prn);
    }


    GetAllMultipathForPrnPtr GetAllMultipathForPrn::create(const std::string& system, int prn)
    {
      return GetAllMultipathForPrnPtr(new GetAllMultipathForPrn(system, prn));
    }

    GetAllMultipathForPrnPtr GetAllMultipathForPrn::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetAllMultipathForPrn>(ptr);
    }

    bool GetAllMultipathForPrn::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["System"])
          && parse_json<int>::is_valid(m_values["Prn"])
        ;

    }

    std::string GetAllMultipathForPrn::documentation() const { return Documentation; }


    int GetAllMultipathForPrn::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string GetAllMultipathForPrn::system() const
    {
      return parse_json<std::string>::parse(m_values["System"]);
    }

    void GetAllMultipathForPrn::setSystem(const std::string& system)
    {
      m_values.AddMember("System", parse_json<std::string>::format(system, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetAllMultipathForPrn::prn() const
    {
      return parse_json<int>::parse(m_values["Prn"]);
    }

    void GetAllMultipathForPrn::setPrn(int prn)
    {
      m_values.AddMember("Prn", parse_json<int>::format(prn, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
