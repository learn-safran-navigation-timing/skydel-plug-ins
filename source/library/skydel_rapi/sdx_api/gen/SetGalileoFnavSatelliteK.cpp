
#include "SetGalileoFnavSatelliteK.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetGalileoFnavSatelliteK
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetGalileoFnavSatelliteK::CmdName = "SetGalileoFnavSatelliteK";
    const char* const SetGalileoFnavSatelliteK::Documentation = "Set the almanac satellite id for subframe 1 (Parameter K described in ICD 4.2.3 Frame Layout).\n"
      "\n"
      "Name Type Description\n"
      "---- ---- -----------------------\n"
      "Prn  int  Satellite PRN number\n"
      "K    int  Satellite K PRN number.";
    const char* const SetGalileoFnavSatelliteK::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(SetGalileoFnavSatelliteK);
    REGISTER_COMMAND_TO_FACTORY_IMPL(SetGalileoFnavSatelliteK);


    SetGalileoFnavSatelliteK::SetGalileoFnavSatelliteK()
      : CommandBase(CmdName, TargetId)
    {}

    SetGalileoFnavSatelliteK::SetGalileoFnavSatelliteK(int prn, int k)
      : CommandBase(CmdName, TargetId)
    {

      setPrn(prn);
      setK(k);
    }

    SetGalileoFnavSatelliteKPtr SetGalileoFnavSatelliteK::create(int prn, int k)
    {
      return std::make_shared<SetGalileoFnavSatelliteK>(prn, k);
    }

    SetGalileoFnavSatelliteKPtr SetGalileoFnavSatelliteK::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetGalileoFnavSatelliteK>(ptr);
    }

    bool SetGalileoFnavSatelliteK::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["Prn"])
          && parse_json<int>::is_valid(m_values["K"])
        ;

    }

    std::string SetGalileoFnavSatelliteK::documentation() const { return Documentation; }

    const std::vector<std::string>& SetGalileoFnavSatelliteK::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Prn", "K"}; 
      return names; 
    }


    int SetGalileoFnavSatelliteK::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    int SetGalileoFnavSatelliteK::prn() const
    {
      return parse_json<int>::parse(m_values["Prn"]);
    }

    void SetGalileoFnavSatelliteK::setPrn(int prn)
    {
      m_values.AddMember("Prn", parse_json<int>::format(prn, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int SetGalileoFnavSatelliteK::k() const
    {
      return parse_json<int>::parse(m_values["K"]);
    }

    void SetGalileoFnavSatelliteK::setK(int k)
    {
      m_values.AddMember("K", parse_json<int>::format(k, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
