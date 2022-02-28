#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of ClearSpoofTxGpuIdx
///
#include "gen/ClearSpoofTxGpuIdx.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const ClearSpoofTxGpuIdx::CmdName = "ClearSpoofTxGpuIdx";
    const char* const ClearSpoofTxGpuIdx::Documentation = "Reset the spoofer's signal GPU index to default.";

    REGISTER_COMMAND_FACTORY(ClearSpoofTxGpuIdx);


    ClearSpoofTxGpuIdx::ClearSpoofTxGpuIdx()
      : CommandBase(CmdName)
    {}

    ClearSpoofTxGpuIdx::ClearSpoofTxGpuIdx(int signalId, const std::string& id)
      : CommandBase(CmdName)
    {

      setSignalId(signalId);
      setId(id);
    }


    ClearSpoofTxGpuIdxPtr ClearSpoofTxGpuIdx::create(int signalId, const std::string& id)
    {
      return ClearSpoofTxGpuIdxPtr(new ClearSpoofTxGpuIdx(signalId, id));
    }

    ClearSpoofTxGpuIdxPtr ClearSpoofTxGpuIdx::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<ClearSpoofTxGpuIdx>(ptr);
    }

    bool ClearSpoofTxGpuIdx::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["SignalId"])
          && parse_json<std::string>::is_valid(m_values["Id"])
        ;

    }

    std::string ClearSpoofTxGpuIdx::documentation() const { return Documentation; }


    int ClearSpoofTxGpuIdx::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    int ClearSpoofTxGpuIdx::signalId() const
    {
      return parse_json<int>::parse(m_values["SignalId"]);
    }

    void ClearSpoofTxGpuIdx::setSignalId(int signalId)
    {
      m_values.AddMember("SignalId", parse_json<int>::format(signalId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string ClearSpoofTxGpuIdx::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void ClearSpoofTxGpuIdx::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
