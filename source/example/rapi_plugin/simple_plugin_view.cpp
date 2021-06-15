#include "simple_plugin_view.h"

#include <QComboBox>
#include <QLineEdit>
#include <QPushButton>

#include "ui_simple_plugin_view.h"

SimplePluginView::SimplePluginView(QWidget* parent) : QWidget(parent), m_ui(new Ui::SimplePluginView)
{
  m_ui->setupUi(this);

  connect(m_ui->sendNotification, &QPushButton::clicked, this, &SimplePluginView::sendNotificationClicked);
  connect(m_ui->message, &QLineEdit::textChanged, this, &SimplePluginView::messageChanged);
  connect(m_ui->type, qOverload<int>(&QComboBox::currentIndexChanged), this, &SimplePluginView::typeChanged);
}

SimplePluginView::~SimplePluginView()
{
  delete m_ui;
}

void SimplePluginView::setNotification(const QString& message, int type)
{
  m_ui->message->setText(message);
  m_ui->type->setCurrentIndex(type);
}
