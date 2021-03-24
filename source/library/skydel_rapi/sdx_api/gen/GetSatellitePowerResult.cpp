#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetSatellitePowerResult
///
#include "gen/GetSatellitePowerResult.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetSatellitePowerResult::CmdName = "GetSatellitePowerResult";
    const char* const GetSatellitePowerResult::Documentation = "Result of GetSatellitePower.";

    REGISTER_COMMAND_RESULT_FACTORY(GetSatellitePowerResult);


    GetSatellitePowerResult::GetSatellitePowerResult()
      : CommandResult(CmdName)
    {}

    GetSatellitePowerResult::GetSatellitePowerResult(CommandBasePtr relatedCommand, double nominalPower, double signalStrengthModel, double antenna, double signalLevelOffset, double manualGain, double total)
      : CommandResult(CmdName, relatedCommand)
    {

      setNominalPower(nominalPower);
      setSignalStrengthModel(signalStrengthModel);
      setAntenna(antenna);
      setSignalLevelOffset(signalLevelOffset);
      setManualGain(manualGain);
      setTotal(total);
    }


    GetSatellitePowerResultPtr GetSatellitePowerResult::create(CommandBasePtr relatedCommand, double nominalPower, double signalStrengthModel, double antenna, double signalLevelOffset, double manualGain, double total)
    {
      return GetSatellitePowerResultPtr(new GetSatellitePowerResult(relatedCommand, nominalPower, signalStrengthModel, antenna, signalLevelOffset, manualGain, total));
    }

    GetSatellitePowerResultPtr GetSatellitePowerResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetSatellitePowerResult>(ptr);
    }

    bool GetSatellitePowerResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<double>::is_valid(m_values["NominalPower"])
          && parse_json<double>::is_valid(m_values["SignalStrengthModel"])
          && parse_json<double>::is_valid(m_values["Antenna"])
          && parse_json<double>::is_valid(m_values["SignalLevelOffset"])
          && parse_json<double>::is_valid(m_values["ManualGain"])
          && parse_json<double>::is_valid(m_values["Total"])
        ;

    }

    std::string GetSatellitePowerResult::documentation() const { return Documentation; }


    double GetSatellitePowerResult::nominalPower() const
    {
      return parse_json<double>::parse(m_values["NominalPower"]);
    }

    void GetSatellitePowerResult::setNominalPower(double nominalPower)
    {
      m_values.AddMember("NominalPower", parse_json<double>::format(nominalPower, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double GetSatellitePowerResult::signalStrengthModel() const
    {
      return parse_json<double>::parse(m_values["SignalStrengthModel"]);
    }

    void GetSatellitePowerResult::setSignalStrengthModel(double signalStrengthModel)
    {
      m_values.AddMember("SignalStrengthModel", parse_json<double>::format(signalStrengthModel, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double GetSatellitePowerResult::antenna() const
    {
      return parse_json<double>::parse(m_values["Antenna"]);
    }

    void GetSatellitePowerResult::setAntenna(double antenna)
    {
      m_values.AddMember("Antenna", parse_json<double>::format(antenna, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double GetSatellitePowerResult::signalLevelOffset() const
    {
      return parse_json<double>::parse(m_values["SignalLevelOffset"]);
    }

    void GetSatellitePowerResult::setSignalLevelOffset(double signalLevelOffset)
    {
      m_values.AddMember("SignalLevelOffset", parse_json<double>::format(signalLevelOffset, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double GetSatellitePowerResult::manualGain() const
    {
      return parse_json<double>::parse(m_values["ManualGain"]);
    }

    void GetSatellitePowerResult::setManualGain(double manualGain)
    {
      m_values.AddMember("ManualGain", parse_json<double>::format(manualGain, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double GetSatellitePowerResult::total() const
    {
      return parse_json<double>::parse(m_values["Total"]);
    }

    void GetSatellitePowerResult::setTotal(double total)
    {
      m_values.AddMember("Total", parse_json<double>::format(total, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
