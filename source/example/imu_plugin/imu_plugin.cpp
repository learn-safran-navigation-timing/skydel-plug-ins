#include "imu_plugin.h"

#include "imu_view.h"

void ImuPlugin::setConfiguration(const QString&, const QJsonObject& configuration)
{
  m_configuration.setConfiguration(m_skydelNotifier, configuration);
  emit configurationChanged();
}

QWidget* ImuPlugin::createUI()
{
  auto view = new ImuView(m_configuration);

  connect(view, &ImuView::checkBoxFileLoggingClicked, [this](bool checked) {
    m_configuration.setValue(m_skydelNotifier, "fileLoggingEnabled", checked);
  });

  connect(view, &ImuView::comboBoxFileLoggingActivated, [this](int index) {
    m_configuration.setValue(m_skydelNotifier, "fileLoggingFormat", index);
  });

  connect(view, &ImuView::checkBoxNetworkLoggingClicked, [this](bool checked) {
    m_configuration.setValue(m_skydelNotifier, "networkLoggingEnabled", checked);
  });

  connect(view, &ImuView::comboBoxNetworkLoggingActivated, [this](int index) {
    m_configuration.setValue(m_skydelNotifier, "networkLoggingFormat", index);
  });

  connect(view, &ImuView::lineEditNetworkLoggingTextChanged, [this](const QString& text) {
    m_configuration.setValue(m_skydelNotifier, "networkLoggingAddress", text);
  });

  connect(view, &ImuView::spinBoxNetworkLoggingValueChanged, [this](int i) {
    m_configuration.setValue(m_skydelNotifier, "networkLoggingPort", i);
  });

  connect(view, &ImuView::comboBoxGravityModelActivated, [this](int index) {
    m_configuration.setValue(m_skydelNotifier, "gravityModel", index);
  });

  connect(this, &ImuPlugin::configurationChanged, [this, view]() { view->setConfiguration(m_configuration); });

  return view;
}
