#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetPrnOfSVIDResult
///
#include "gen/GetPrnOfSVIDResult.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetPrnOfSVIDResult::CmdName = "GetPrnOfSVIDResult";
    const char* const GetPrnOfSVIDResult::Documentation = "Result of GetPrnOfSVID.";

    REGISTER_COMMAND_RESULT_FACTORY(GetPrnOfSVIDResult);


    GetPrnOfSVIDResult::GetPrnOfSVIDResult()
      : CommandResult(CmdName)
    {}

    GetPrnOfSVIDResult::GetPrnOfSVIDResult(CommandBasePtr relatedCommand, const std::string& signal, int svId, int prn)
      : CommandResult(CmdName, relatedCommand)
    {

      setSignal(signal);
      setSvId(svId);
      setPrn(prn);
    }


    GetPrnOfSVIDResultPtr GetPrnOfSVIDResult::create(CommandBasePtr relatedCommand, const std::string& signal, int svId, int prn)
    {
      return std::make_shared<GetPrnOfSVIDResult>(relatedCommand, signal, svId, prn);
    }

    GetPrnOfSVIDResultPtr GetPrnOfSVIDResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetPrnOfSVIDResult>(ptr);
    }

    bool GetPrnOfSVIDResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Signal"])
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<int>::is_valid(m_values["Prn"])
        ;

    }

    std::string GetPrnOfSVIDResult::documentation() const { return Documentation; }


    std::string GetPrnOfSVIDResult::signal() const
    {
      return parse_json<std::string>::parse(m_values["Signal"]);
    }

    void GetPrnOfSVIDResult::setSignal(const std::string& signal)
    {
      m_values.AddMember("Signal", parse_json<std::string>::format(signal, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetPrnOfSVIDResult::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void GetPrnOfSVIDResult::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetPrnOfSVIDResult::prn() const
    {
      return parse_json<int>::parse(m_values["Prn"]);
    }

    void GetPrnOfSVIDResult::setPrn(int prn)
    {
      m_values.AddMember("Prn", parse_json<int>::format(prn, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
