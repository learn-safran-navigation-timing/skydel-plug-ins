#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetMultipathForIDResult
///
#include "gen/GetMultipathForIDResult.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetMultipathForIDResult::CmdName = "GetMultipathForIDResult";
    const char* const GetMultipathForIDResult::Documentation = "Result of GetMultipathForID.";

    REGISTER_COMMAND_RESULT_FACTORY(GetMultipathForIDResult);


    GetMultipathForIDResult::GetMultipathForIDResult()
      : CommandResult(CmdName)
    {}

    GetMultipathForIDResult::GetMultipathForIDResult(CommandBasePtr relatedCommand, const std::string& id, const std::string& system, const std::string& signal, int svId, double powerLoss, double pseudorange, double doppler, double carrierPhase, int echo)
      : CommandResult(CmdName, relatedCommand)
    {

      setId(id);
      setSystem(system);
      setSignal(signal);
      setSvId(svId);
      setPowerLoss(powerLoss);
      setPseudorange(pseudorange);
      setDoppler(doppler);
      setCarrierPhase(carrierPhase);
      setEcho(echo);
    }


    GetMultipathForIDResultPtr GetMultipathForIDResult::create(CommandBasePtr relatedCommand, const std::string& id, const std::string& system, const std::string& signal, int svId, double powerLoss, double pseudorange, double doppler, double carrierPhase, int echo)
    {
      return std::make_shared<GetMultipathForIDResult>(relatedCommand, id, system, signal, svId, powerLoss, pseudorange, doppler, carrierPhase, echo);
    }

    GetMultipathForIDResultPtr GetMultipathForIDResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetMultipathForIDResult>(ptr);
    }

    bool GetMultipathForIDResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Id"])
          && parse_json<std::string>::is_valid(m_values["System"])
          && parse_json<std::string>::is_valid(m_values["Signal"])
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<double>::is_valid(m_values["PowerLoss"])
          && parse_json<double>::is_valid(m_values["Pseudorange"])
          && parse_json<double>::is_valid(m_values["Doppler"])
          && parse_json<double>::is_valid(m_values["CarrierPhase"])
          && parse_json<int>::is_valid(m_values["Echo"])
        ;

    }

    std::string GetMultipathForIDResult::documentation() const { return Documentation; }


    std::string GetMultipathForIDResult::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void GetMultipathForIDResult::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string GetMultipathForIDResult::system() const
    {
      return parse_json<std::string>::parse(m_values["System"]);
    }

    void GetMultipathForIDResult::setSystem(const std::string& system)
    {
      m_values.AddMember("System", parse_json<std::string>::format(system, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string GetMultipathForIDResult::signal() const
    {
      return parse_json<std::string>::parse(m_values["Signal"]);
    }

    void GetMultipathForIDResult::setSignal(const std::string& signal)
    {
      m_values.AddMember("Signal", parse_json<std::string>::format(signal, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetMultipathForIDResult::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void GetMultipathForIDResult::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double GetMultipathForIDResult::powerLoss() const
    {
      return parse_json<double>::parse(m_values["PowerLoss"]);
    }

    void GetMultipathForIDResult::setPowerLoss(double powerLoss)
    {
      m_values.AddMember("PowerLoss", parse_json<double>::format(powerLoss, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double GetMultipathForIDResult::pseudorange() const
    {
      return parse_json<double>::parse(m_values["Pseudorange"]);
    }

    void GetMultipathForIDResult::setPseudorange(double pseudorange)
    {
      m_values.AddMember("Pseudorange", parse_json<double>::format(pseudorange, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double GetMultipathForIDResult::doppler() const
    {
      return parse_json<double>::parse(m_values["Doppler"]);
    }

    void GetMultipathForIDResult::setDoppler(double doppler)
    {
      m_values.AddMember("Doppler", parse_json<double>::format(doppler, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double GetMultipathForIDResult::carrierPhase() const
    {
      return parse_json<double>::parse(m_values["CarrierPhase"]);
    }

    void GetMultipathForIDResult::setCarrierPhase(double carrierPhase)
    {
      m_values.AddMember("CarrierPhase", parse_json<double>::format(carrierPhase, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetMultipathForIDResult::echo() const
    {
      return parse_json<int>::parse(m_values["Echo"]);
    }

    void GetMultipathForIDResult::setEcho(int echo)
    {
      m_values.AddMember("Echo", parse_json<int>::format(echo, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
