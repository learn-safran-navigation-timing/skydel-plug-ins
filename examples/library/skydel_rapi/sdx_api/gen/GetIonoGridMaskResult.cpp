#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetIonoGridMaskResult
///
#include "gen/GetIonoGridMaskResult.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetIonoGridMaskResult::CmdName = "GetIonoGridMaskResult";
    const char* const GetIonoGridMaskResult::Documentation = "Result of GetIonoGridMask.";

    REGISTER_COMMAND_RESULT_FACTORY(GetIonoGridMaskResult);


    GetIonoGridMaskResult::GetIonoGridMaskResult()
      : CommandResult(CmdName)
    {}

    GetIonoGridMaskResult::GetIonoGridMaskResult(CommandBasePtr relatedCommand, const std::string& serviceProvider, int band, int point, bool flag)
      : CommandResult(CmdName, relatedCommand)
    {

      setServiceProvider(serviceProvider);
      setBand(band);
      setPoint(point);
      setFlag(flag);
    }


    GetIonoGridMaskResultPtr GetIonoGridMaskResult::create(CommandBasePtr relatedCommand, const std::string& serviceProvider, int band, int point, bool flag)
    {
      return GetIonoGridMaskResultPtr(new GetIonoGridMaskResult(relatedCommand, serviceProvider, band, point, flag));
    }

    GetIonoGridMaskResultPtr GetIonoGridMaskResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetIonoGridMaskResult>(ptr);
    }

    bool GetIonoGridMaskResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["ServiceProvider"])
          && parse_json<int>::is_valid(m_values["Band"])
          && parse_json<int>::is_valid(m_values["Point"])
          && parse_json<bool>::is_valid(m_values["Flag"])
        ;

    }

    std::string GetIonoGridMaskResult::documentation() const { return Documentation; }


    std::string GetIonoGridMaskResult::serviceProvider() const
    {
      return parse_json<std::string>::parse(m_values["ServiceProvider"]);
    }

    void GetIonoGridMaskResult::setServiceProvider(const std::string& serviceProvider)
    {
      m_values.AddMember("ServiceProvider", parse_json<std::string>::format(serviceProvider, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetIonoGridMaskResult::band() const
    {
      return parse_json<int>::parse(m_values["Band"]);
    }

    void GetIonoGridMaskResult::setBand(int band)
    {
      m_values.AddMember("Band", parse_json<int>::format(band, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetIonoGridMaskResult::point() const
    {
      return parse_json<int>::parse(m_values["Point"]);
    }

    void GetIonoGridMaskResult::setPoint(int point)
    {
      m_values.AddMember("Point", parse_json<int>::format(point, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool GetIonoGridMaskResult::flag() const
    {
      return parse_json<bool>::parse(m_values["Flag"]);
    }

    void GetIonoGridMaskResult::setFlag(bool flag)
    {
      m_values.AddMember("Flag", parse_json<bool>::format(flag, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
