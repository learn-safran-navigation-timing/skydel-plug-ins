#ifndef RAPI_PLUGIN_VIEW_H
#define RAPI_PLUGIN_VIEW_H

#include <QString>
#include <QWidget>

namespace Ui
{
class RapiPluginView;
}

class RapiPluginView : public QWidget
{
  Q_OBJECT

public:
  explicit RapiPluginView(QWidget* parent = nullptr);
  ~RapiPluginView();

  void setSimulatorState(const QString& state);

signals:
  void buttonUpdateClicked();

private:
  Ui::RapiPluginView* m_ui;
};

#endif // RAPI_PLUGIN_VIEW_H
