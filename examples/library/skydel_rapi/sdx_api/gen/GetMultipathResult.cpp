#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetMultipathResult
///
#include "gen/GetMultipathResult.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetMultipathResult::CmdName = "GetMultipathResult";
    const char* const GetMultipathResult::Documentation = "Result of GetMultipathResult.";

    REGISTER_COMMAND_RESULT_FACTORY(GetMultipathResult);


    GetMultipathResult::GetMultipathResult()
      : CommandResult(CmdName)
    {}

    GetMultipathResult::GetMultipathResult(CommandBasePtr relatedCommand, int prn, const std::string& system, const std::string& signal, double powerLoss, double pseudorange, double doppler, double carrierPhase, int echo, const std::string& id)
      : CommandResult(CmdName, relatedCommand)
    {

      setPrn(prn);
      setSystem(system);
      setSignal(signal);
      setPowerLoss(powerLoss);
      setPseudorange(pseudorange);
      setDoppler(doppler);
      setCarrierPhase(carrierPhase);
      setEcho(echo);
      setId(id);
    }


    GetMultipathResultPtr GetMultipathResult::create(CommandBasePtr relatedCommand, int prn, const std::string& system, const std::string& signal, double powerLoss, double pseudorange, double doppler, double carrierPhase, int echo, const std::string& id)
    {
      return GetMultipathResultPtr(new GetMultipathResult(relatedCommand, prn, system, signal, powerLoss, pseudorange, doppler, carrierPhase, echo, id));
    }

    GetMultipathResultPtr GetMultipathResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetMultipathResult>(ptr);
    }

    bool GetMultipathResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["Prn"])
          && parse_json<std::string>::is_valid(m_values["System"])
          && parse_json<std::string>::is_valid(m_values["Signal"])
          && parse_json<double>::is_valid(m_values["PowerLoss"])
          && parse_json<double>::is_valid(m_values["Pseudorange"])
          && parse_json<double>::is_valid(m_values["Doppler"])
          && parse_json<double>::is_valid(m_values["CarrierPhase"])
          && parse_json<int>::is_valid(m_values["Echo"])
          && parse_json<std::string>::is_valid(m_values["Id"])
        ;

    }

    std::string GetMultipathResult::documentation() const { return Documentation; }


    int GetMultipathResult::prn() const
    {
      return parse_json<int>::parse(m_values["Prn"]);
    }

    void GetMultipathResult::setPrn(int prn)
    {
      m_values.AddMember("Prn", parse_json<int>::format(prn, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string GetMultipathResult::system() const
    {
      return parse_json<std::string>::parse(m_values["System"]);
    }

    void GetMultipathResult::setSystem(const std::string& system)
    {
      m_values.AddMember("System", parse_json<std::string>::format(system, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string GetMultipathResult::signal() const
    {
      return parse_json<std::string>::parse(m_values["Signal"]);
    }

    void GetMultipathResult::setSignal(const std::string& signal)
    {
      m_values.AddMember("Signal", parse_json<std::string>::format(signal, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double GetMultipathResult::powerLoss() const
    {
      return parse_json<double>::parse(m_values["PowerLoss"]);
    }

    void GetMultipathResult::setPowerLoss(double powerLoss)
    {
      m_values.AddMember("PowerLoss", parse_json<double>::format(powerLoss, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double GetMultipathResult::pseudorange() const
    {
      return parse_json<double>::parse(m_values["Pseudorange"]);
    }

    void GetMultipathResult::setPseudorange(double pseudorange)
    {
      m_values.AddMember("Pseudorange", parse_json<double>::format(pseudorange, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double GetMultipathResult::doppler() const
    {
      return parse_json<double>::parse(m_values["Doppler"]);
    }

    void GetMultipathResult::setDoppler(double doppler)
    {
      m_values.AddMember("Doppler", parse_json<double>::format(doppler, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double GetMultipathResult::carrierPhase() const
    {
      return parse_json<double>::parse(m_values["CarrierPhase"]);
    }

    void GetMultipathResult::setCarrierPhase(double carrierPhase)
    {
      m_values.AddMember("CarrierPhase", parse_json<double>::format(carrierPhase, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetMultipathResult::echo() const
    {
      return parse_json<int>::parse(m_values["Echo"]);
    }

    void GetMultipathResult::setEcho(int echo)
    {
      m_values.AddMember("Echo", parse_json<int>::format(echo, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string GetMultipathResult::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void GetMultipathResult::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
