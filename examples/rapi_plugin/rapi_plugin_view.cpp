#include "rapi_plugin_view.h"

#include <QLabel>
#include <QPushButton>

#include "ui_rapi_plugin_view.h"

RapiPluginView::RapiPluginView(QWidget* parent) : QWidget(parent), m_ui(new Ui::RapiPluginView)
{
  m_ui->setupUi(this);

  connect(m_ui->buttonUpdate, &QPushButton::clicked, this, &RapiPluginView::buttonUpdateClicked);
}

RapiPluginView::~RapiPluginView()
{
  delete m_ui;
}

void RapiPluginView::setSimulatorState(const QString& state)
{
  m_ui->labelSimulatorState->setText(state);
}
