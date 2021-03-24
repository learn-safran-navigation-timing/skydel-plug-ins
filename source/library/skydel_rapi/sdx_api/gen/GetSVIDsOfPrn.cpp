#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetSVIDsOfPrn
///
#include "gen/GetSVIDsOfPrn.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetSVIDsOfPrn::CmdName = "GetSVIDsOfPrn";
    const char* const GetSVIDsOfPrn::Documentation = "Mapping PRN to the corresponding SV ID. Get a list of SV IDs based on a specific signal. Accepted signal keys: \"GPS_L1_CA\", \"GPS_L1C\", \"GPS_L2C\", \"GPS_L5\", \"GLONASS_G1\", \"GLONASS_G2\", \"GALILEO_E1\", \"GALILEO_E5a\", \"GALILEO_E5b\", \"GALILEO_E6\", \"BEIDOU_B1\", \"BEIDOU_B2\", \"BEIDOU_B1C\", \"BEIDOU_B2a\", \"SBAS_L1\", \"SBAS_L5\", \"QZSS_L1_CA\", \"QZSS_L1C\", \"QZSS_L5\", \"QZSS_L1S\", \"QZSS_L5S\", \"NAVIC_L5\", \"CS1\", \"CS2\", \"CS3\", \"CS4\", \"CS5\", \"CS6\", \"CS7\", \"CS8\", \"SIGNAL_COUNT\"";

    REGISTER_COMMAND_FACTORY(GetSVIDsOfPrn);


    GetSVIDsOfPrn::GetSVIDsOfPrn()
      : CommandBase(CmdName)
    {}

    GetSVIDsOfPrn::GetSVIDsOfPrn(const std::string& signal, int prn)
      : CommandBase(CmdName)
    {

      setSignal(signal);
      setPrn(prn);
    }


    GetSVIDsOfPrnPtr GetSVIDsOfPrn::create(const std::string& signal, int prn)
    {
      return GetSVIDsOfPrnPtr(new GetSVIDsOfPrn(signal, prn));
    }

    GetSVIDsOfPrnPtr GetSVIDsOfPrn::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetSVIDsOfPrn>(ptr);
    }

    bool GetSVIDsOfPrn::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Signal"])
          && parse_json<int>::is_valid(m_values["Prn"])
        ;

    }

    std::string GetSVIDsOfPrn::documentation() const { return Documentation; }


    int GetSVIDsOfPrn::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string GetSVIDsOfPrn::signal() const
    {
      return parse_json<std::string>::parse(m_values["Signal"]);
    }

    void GetSVIDsOfPrn::setSignal(const std::string& signal)
    {
      m_values.AddMember("Signal", parse_json<std::string>::format(signal, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetSVIDsOfPrn::prn() const
    {
      return parse_json<int>::parse(m_values["Prn"]);
    }

    void GetSVIDsOfPrn::setPrn(int prn)
    {
      m_values.AddMember("Prn", parse_json<int>::format(prn, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
