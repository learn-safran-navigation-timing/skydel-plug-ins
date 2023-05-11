#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of ExportIonoGridGIVEI
///
#include "gen/ExportIonoGridGIVEI.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const ExportIonoGridGIVEI::CmdName = "ExportIonoGridGIVEI";
    const char* const ExportIonoGridGIVEI::Documentation = "Export ionospheric grid GIVEI.";

    REGISTER_COMMAND_FACTORY(ExportIonoGridGIVEI);


    ExportIonoGridGIVEI::ExportIonoGridGIVEI()
      : CommandBase(CmdName)
    {}

    ExportIonoGridGIVEI::ExportIonoGridGIVEI(bool overwriting, const std::string& path, const Sdx::optional<std::string>& serviceProvider)
      : CommandBase(CmdName)
    {

      setOverwriting(overwriting);
      setPath(path);
      setServiceProvider(serviceProvider);
    }


    ExportIonoGridGIVEIPtr ExportIonoGridGIVEI::create(bool overwriting, const std::string& path, const Sdx::optional<std::string>& serviceProvider)
    {
      return std::make_shared<ExportIonoGridGIVEI>(overwriting, path, serviceProvider);
    }

    ExportIonoGridGIVEIPtr ExportIonoGridGIVEI::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<ExportIonoGridGIVEI>(ptr);
    }

    bool ExportIonoGridGIVEI::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<bool>::is_valid(m_values["Overwriting"])
          && parse_json<std::string>::is_valid(m_values["Path"])
          && parse_json<Sdx::optional<std::string>>::is_valid(m_values["ServiceProvider"])
        ;

    }

    std::string ExportIonoGridGIVEI::documentation() const { return Documentation; }


    int ExportIonoGridGIVEI::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    bool ExportIonoGridGIVEI::overwriting() const
    {
      return parse_json<bool>::parse(m_values["Overwriting"]);
    }

    void ExportIonoGridGIVEI::setOverwriting(bool overwriting)
    {
      m_values.AddMember("Overwriting", parse_json<bool>::format(overwriting, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string ExportIonoGridGIVEI::path() const
    {
      return parse_json<std::string>::parse(m_values["Path"]);
    }

    void ExportIonoGridGIVEI::setPath(const std::string& path)
    {
      m_values.AddMember("Path", parse_json<std::string>::format(path, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::optional<std::string> ExportIonoGridGIVEI::serviceProvider() const
    {
      return parse_json<Sdx::optional<std::string>>::parse(m_values["ServiceProvider"]);
    }

    void ExportIonoGridGIVEI::setServiceProvider(const Sdx::optional<std::string>& serviceProvider)
    {
      m_values.AddMember("ServiceProvider", parse_json<Sdx::optional<std::string>>::format(serviceProvider, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
