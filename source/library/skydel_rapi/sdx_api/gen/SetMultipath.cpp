#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetMultipath
///
#include "gen/SetMultipath.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetMultipath::CmdName = "SetMultipath";
    const char* const SetMultipath::Documentation = "Please note the command SetMultipath is deprecated since 21.3. You may use SetMultipathForSV.\n\nAdd or update signal echo (multipath). Offsets (power loss, pseudorange, Doppler and carrier phase) are all relative to line-of-sight signal.\nIf Id is not set, or unknown to Skydel, a new echo will be added. Otherwise, existing echo will be updated.";

    REGISTER_COMMAND_FACTORY(SetMultipath);


    SetMultipath::SetMultipath()
      : CommandBase(CmdName)
    {}

    SetMultipath::SetMultipath(int prn, const std::string& system, const std::string& signal, double powerLoss, double pseudorange, double doppler, double carrierPhase, int echo, const std::string& id)
      : CommandBase(CmdName)
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


    SetMultipathPtr SetMultipath::create(int prn, const std::string& system, const std::string& signal, double powerLoss, double pseudorange, double doppler, double carrierPhase, int echo, const std::string& id)
    {
      return SetMultipathPtr(new SetMultipath(prn, system, signal, powerLoss, pseudorange, doppler, carrierPhase, echo, id));
    }

    SetMultipathPtr SetMultipath::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetMultipath>(ptr);
    }

    bool SetMultipath::isValid() const
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

    std::string SetMultipath::documentation() const { return Documentation; }


    int SetMultipath::executePermission() const
    {
      return EXECUTE_IF_SIMULATING | EXECUTE_IF_IDLE;
    }


    int SetMultipath::prn() const
    {
      return parse_json<int>::parse(m_values["Prn"]);
    }

    void SetMultipath::setPrn(int prn)
    {
      m_values.AddMember("Prn", parse_json<int>::format(prn, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string SetMultipath::system() const
    {
      return parse_json<std::string>::parse(m_values["System"]);
    }

    void SetMultipath::setSystem(const std::string& system)
    {
      m_values.AddMember("System", parse_json<std::string>::format(system, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string SetMultipath::signal() const
    {
      return parse_json<std::string>::parse(m_values["Signal"]);
    }

    void SetMultipath::setSignal(const std::string& signal)
    {
      m_values.AddMember("Signal", parse_json<std::string>::format(signal, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double SetMultipath::powerLoss() const
    {
      return parse_json<double>::parse(m_values["PowerLoss"]);
    }

    void SetMultipath::setPowerLoss(double powerLoss)
    {
      m_values.AddMember("PowerLoss", parse_json<double>::format(powerLoss, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double SetMultipath::pseudorange() const
    {
      return parse_json<double>::parse(m_values["Pseudorange"]);
    }

    void SetMultipath::setPseudorange(double pseudorange)
    {
      m_values.AddMember("Pseudorange", parse_json<double>::format(pseudorange, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double SetMultipath::doppler() const
    {
      return parse_json<double>::parse(m_values["Doppler"]);
    }

    void SetMultipath::setDoppler(double doppler)
    {
      m_values.AddMember("Doppler", parse_json<double>::format(doppler, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double SetMultipath::carrierPhase() const
    {
      return parse_json<double>::parse(m_values["CarrierPhase"]);
    }

    void SetMultipath::setCarrierPhase(double carrierPhase)
    {
      m_values.AddMember("CarrierPhase", parse_json<double>::format(carrierPhase, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int SetMultipath::echo() const
    {
      return parse_json<int>::parse(m_values["Echo"]);
    }

    void SetMultipath::setEcho(int echo)
    {
      m_values.AddMember("Echo", parse_json<int>::format(echo, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string SetMultipath::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void SetMultipath::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
