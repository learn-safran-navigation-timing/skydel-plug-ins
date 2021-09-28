#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetSVAntennaModelToPrn
///
#include "gen/GetSVAntennaModelToPrn.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetSVAntennaModelToPrn::CmdName = "GetSVAntennaModelToPrn";
    const char* const GetSVAntennaModelToPrn::Documentation = "Please note the command GetSVAntennaModelToPrn is deprecated since 21.3. You may use GetSVAntennaModelForSV.\n\nGet the antenna model used by the PRN.";

    REGISTER_COMMAND_FACTORY(GetSVAntennaModelToPrn);


    GetSVAntennaModelToPrn::GetSVAntennaModelToPrn()
      : CommandBase(CmdName)
    {}

    GetSVAntennaModelToPrn::GetSVAntennaModelToPrn(int prn, const std::string& system)
      : CommandBase(CmdName)
    {

      setPrn(prn);
      setSystem(system);
    }


    GetSVAntennaModelToPrnPtr GetSVAntennaModelToPrn::create(int prn, const std::string& system)
    {
      return GetSVAntennaModelToPrnPtr(new GetSVAntennaModelToPrn(prn, system));
    }

    GetSVAntennaModelToPrnPtr GetSVAntennaModelToPrn::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetSVAntennaModelToPrn>(ptr);
    }

    bool GetSVAntennaModelToPrn::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["Prn"])
          && parse_json<std::string>::is_valid(m_values["System"])
        ;

    }

    std::string GetSVAntennaModelToPrn::documentation() const { return Documentation; }


    int GetSVAntennaModelToPrn::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    int GetSVAntennaModelToPrn::prn() const
    {
      return parse_json<int>::parse(m_values["Prn"]);
    }

    void GetSVAntennaModelToPrn::setPrn(int prn)
    {
      m_values.AddMember("Prn", parse_json<int>::format(prn, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string GetSVAntennaModelToPrn::system() const
    {
      return parse_json<std::string>::parse(m_values["System"]);
    }

    void GetSVAntennaModelToPrn::setSystem(const std::string& system)
    {
      m_values.AddMember("System", parse_json<std::string>::format(system, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
