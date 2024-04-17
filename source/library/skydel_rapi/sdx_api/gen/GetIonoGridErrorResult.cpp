
#include "GetIonoGridErrorResult.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetIonoGridErrorResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetIonoGridErrorResult::CmdName = "GetIonoGridErrorResult";
    const char* const GetIonoGridErrorResult::Documentation = "Result of GetIonoGridError.\n"
      "\n"
      "Name  Type   Description\n"
      "----- ------ -------------------------------\n"
      "Band  int    The ionospheric grid band index\n"
      "Point int    The IGP index\n"
      "Error double The error offset at the IGP";
    const char* const GetIonoGridErrorResult::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_IMPL(GetIonoGridErrorResult);


    GetIonoGridErrorResult::GetIonoGridErrorResult()
      : CommandResult(CmdName, TargetId)
    {}

    GetIonoGridErrorResult::GetIonoGridErrorResult(int band, int point, double error)
      : CommandResult(CmdName, TargetId)
    {

      setBand(band);
      setPoint(point);
      setError(error);
    }

    GetIonoGridErrorResult::GetIonoGridErrorResult(CommandBasePtr relatedCommand, int band, int point, double error)
      : CommandResult(CmdName, TargetId, relatedCommand)
    {

      setBand(band);
      setPoint(point);
      setError(error);
    }


    GetIonoGridErrorResultPtr GetIonoGridErrorResult::create(int band, int point, double error)
    {
      return std::make_shared<GetIonoGridErrorResult>(band, point, error);
    }

    GetIonoGridErrorResultPtr GetIonoGridErrorResult::create(CommandBasePtr relatedCommand, int band, int point, double error)
    {
      return std::make_shared<GetIonoGridErrorResult>(relatedCommand, band, point, error);
    }

    GetIonoGridErrorResultPtr GetIonoGridErrorResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetIonoGridErrorResult>(ptr);
    }

    bool GetIonoGridErrorResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["Band"])
          && parse_json<int>::is_valid(m_values["Point"])
          && parse_json<double>::is_valid(m_values["Error"])
        ;

    }

    std::string GetIonoGridErrorResult::documentation() const { return Documentation; }

    const std::vector<std::string>& GetIonoGridErrorResult::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Band", "Point", "Error"}; 
      return names; 
    }


    int GetIonoGridErrorResult::band() const
    {
      return parse_json<int>::parse(m_values["Band"]);
    }

    void GetIonoGridErrorResult::setBand(int band)
    {
      m_values.AddMember("Band", parse_json<int>::format(band, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetIonoGridErrorResult::point() const
    {
      return parse_json<int>::parse(m_values["Point"]);
    }

    void GetIonoGridErrorResult::setPoint(int point)
    {
      m_values.AddMember("Point", parse_json<int>::format(point, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double GetIonoGridErrorResult::error() const
    {
      return parse_json<double>::parse(m_values["Error"]);
    }

    void GetIonoGridErrorResult::setError(double error)
    {
      m_values.AddMember("Error", parse_json<double>::format(error, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
