#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetGalileoFnavSatelliteKResult
///
#include "gen/GetGalileoFnavSatelliteKResult.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetGalileoFnavSatelliteKResult::CmdName = "GetGalileoFnavSatelliteKResult";
    const char* const GetGalileoFnavSatelliteKResult::Documentation = "Result of GetGalileoFnavSatelliteK.";

    REGISTER_COMMAND_RESULT_FACTORY(GetGalileoFnavSatelliteKResult);


    GetGalileoFnavSatelliteKResult::GetGalileoFnavSatelliteKResult()
      : CommandResult(CmdName)
    {}

    GetGalileoFnavSatelliteKResult::GetGalileoFnavSatelliteKResult(CommandBasePtr relatedCommand, int prn, int k)
      : CommandResult(CmdName, relatedCommand)
    {

      setPrn(prn);
      setK(k);
    }


    GetGalileoFnavSatelliteKResultPtr GetGalileoFnavSatelliteKResult::create(CommandBasePtr relatedCommand, int prn, int k)
    {
      return std::make_shared<GetGalileoFnavSatelliteKResult>(relatedCommand, prn, k);
    }

    GetGalileoFnavSatelliteKResultPtr GetGalileoFnavSatelliteKResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetGalileoFnavSatelliteKResult>(ptr);
    }

    bool GetGalileoFnavSatelliteKResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["Prn"])
          && parse_json<int>::is_valid(m_values["K"])
        ;

    }

    std::string GetGalileoFnavSatelliteKResult::documentation() const { return Documentation; }


    int GetGalileoFnavSatelliteKResult::prn() const
    {
      return parse_json<int>::parse(m_values["Prn"]);
    }

    void GetGalileoFnavSatelliteKResult::setPrn(int prn)
    {
      m_values.AddMember("Prn", parse_json<int>::format(prn, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetGalileoFnavSatelliteKResult::k() const
    {
      return parse_json<int>::parse(m_values["K"]);
    }

    void GetGalileoFnavSatelliteKResult::setK(int k)
    {
      m_values.AddMember("K", parse_json<int>::format(k, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
