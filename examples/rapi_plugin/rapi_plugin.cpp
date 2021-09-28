#include "rapi_plugin.h"

#include <exception>

#include "all_commands.h"
#include "rapi_plugin_view.h"

QWidget* RapiPlugin::createUI()
{
  auto view = new RapiPluginView;

  connect(view, &RapiPluginView::buttonUpdateClicked, [this, view]() {
    post(Sdx::Cmd::GetSimulatorState::create(), [=](Sdx::CommandResultPtr result) {
      if (auto simulatorStateResult = Sdx::Cmd::SimulatorStateResult::dynamicCast(result))
        view->setSimulatorState(QString::fromStdString(simulatorStateResult->state()));
    });
  });

  return view;
}
