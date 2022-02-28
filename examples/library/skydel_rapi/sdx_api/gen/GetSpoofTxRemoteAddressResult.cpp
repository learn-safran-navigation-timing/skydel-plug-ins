#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetSpoofTxRemoteAddressResult
///
#include "gen/GetSpoofTxRemoteAddressResult.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetSpoofTxRemoteAddressResult::CmdName = "GetSpoofTxRemoteAddressResult";
    const char* const GetSpoofTxRemoteAddressResult::Documentation = "Result of GetSpoofTxRemoteAddress.";

    REGISTER_COMMAND_RESULT_FACTORY(GetSpoofTxRemoteAddressResult);


    GetSpoofTxRemoteAddressResult::GetSpoofTxRemoteAddressResult()
      : CommandResult(CmdName)
    {}

    GetSpoofTxRemoteAddressResult::GetSpoofTxRemoteAddressResult(CommandBasePtr relatedCommand, const std::string& address, int instanceId, const std::string& id)
      : CommandResult(CmdName, relatedCommand)
    {

      setAddress(address);
      setInstanceId(instanceId);
      setId(id);
    }


    GetSpoofTxRemoteAddressResultPtr GetSpoofTxRemoteAddressResult::create(CommandBasePtr relatedCommand, const std::string& address, int instanceId, const std::string& id)
    {
      return GetSpoofTxRemoteAddressResultPtr(new GetSpoofTxRemoteAddressResult(relatedCommand, address, instanceId, id));
    }

    GetSpoofTxRemoteAddressResultPtr GetSpoofTxRemoteAddressResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetSpoofTxRemoteAddressResult>(ptr);
    }

    bool GetSpoofTxRemoteAddressResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Address"])
          && parse_json<int>::is_valid(m_values["InstanceId"])
          && parse_json<std::string>::is_valid(m_values["Id"])
        ;

    }

    std::string GetSpoofTxRemoteAddressResult::documentation() const { return Documentation; }


    std::string GetSpoofTxRemoteAddressResult::address() const
    {
      return parse_json<std::string>::parse(m_values["Address"]);
    }

    void GetSpoofTxRemoteAddressResult::setAddress(const std::string& address)
    {
      m_values.AddMember("Address", parse_json<std::string>::format(address, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetSpoofTxRemoteAddressResult::instanceId() const
    {
      return parse_json<int>::parse(m_values["InstanceId"]);
    }

    void GetSpoofTxRemoteAddressResult::setInstanceId(int instanceId)
    {
      m_values.AddMember("InstanceId", parse_json<int>::format(instanceId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string GetSpoofTxRemoteAddressResult::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void GetSpoofTxRemoteAddressResult::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
