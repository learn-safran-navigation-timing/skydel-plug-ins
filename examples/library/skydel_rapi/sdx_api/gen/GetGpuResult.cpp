#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetGpuResult
///
#include "gen/GetGpuResult.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetGpuResult::CmdName = "GetGpuResult";
    const char* const GetGpuResult::Documentation = "Result of GetGpu.";

    REGISTER_COMMAND_RESULT_FACTORY(GetGpuResult);


    GetGpuResult::GetGpuResult()
      : CommandResult(CmdName)
    {}

    GetGpuResult::GetGpuResult(CommandBasePtr relatedCommand, int gpuIdx, int output, const std::string& id)
      : CommandResult(CmdName, relatedCommand)
    {

      setGpuIdx(gpuIdx);
      setOutput(output);
      setId(id);
    }


    GetGpuResultPtr GetGpuResult::create(CommandBasePtr relatedCommand, int gpuIdx, int output, const std::string& id)
    {
      return GetGpuResultPtr(new GetGpuResult(relatedCommand, gpuIdx, output, id));
    }

    GetGpuResultPtr GetGpuResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetGpuResult>(ptr);
    }

    bool GetGpuResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["GpuIdx"])
          && parse_json<int>::is_valid(m_values["Output"])
          && parse_json<std::string>::is_valid(m_values["Id"])
        ;

    }

    std::string GetGpuResult::documentation() const { return Documentation; }


    int GetGpuResult::gpuIdx() const
    {
      return parse_json<int>::parse(m_values["GpuIdx"]);
    }

    void GetGpuResult::setGpuIdx(int gpuIdx)
    {
      m_values.AddMember("GpuIdx", parse_json<int>::format(gpuIdx, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetGpuResult::output() const
    {
      return parse_json<int>::parse(m_values["Output"]);
    }

    void GetGpuResult::setOutput(int output)
    {
      m_values.AddMember("Output", parse_json<int>::format(output, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string GetGpuResult::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void GetGpuResult::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
