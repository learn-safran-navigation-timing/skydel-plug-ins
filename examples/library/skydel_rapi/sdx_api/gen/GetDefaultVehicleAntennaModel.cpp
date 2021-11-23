#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetDefaultVehicleAntennaModel
///
#include "gen/GetDefaultVehicleAntennaModel.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetDefaultVehicleAntennaModel::CmdName = "GetDefaultVehicleAntennaModel";
    const char* const GetDefaultVehicleAntennaModel::Documentation = "Get the default vehicle antenna model.";

    REGISTER_COMMAND_FACTORY(GetDefaultVehicleAntennaModel);


    GetDefaultVehicleAntennaModel::GetDefaultVehicleAntennaModel()
      : CommandBase(CmdName)
    {

    }


    GetDefaultVehicleAntennaModelPtr GetDefaultVehicleAntennaModel::create()
    {
      return GetDefaultVehicleAntennaModelPtr(new GetDefaultVehicleAntennaModel());
    }

    GetDefaultVehicleAntennaModelPtr GetDefaultVehicleAntennaModel::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetDefaultVehicleAntennaModel>(ptr);
    }

    bool GetDefaultVehicleAntennaModel::isValid() const
    {
      
        return m_values.IsObject()
        ;

    }

    std::string GetDefaultVehicleAntennaModel::documentation() const { return Documentation; }


    int GetDefaultVehicleAntennaModel::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }

  }
}
