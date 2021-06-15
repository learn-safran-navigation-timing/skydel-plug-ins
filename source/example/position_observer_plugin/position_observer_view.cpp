#include "position_observer_view.h"

#include <QCheckBox>
#include <QComboBox>

#include "ui_position_observer_view.h"

PositionObserverView::PositionObserverView(QWidget* parent) : QWidget(parent), m_ui(new Ui::PositionObserverView)
{
  m_ui->setupUi(this);

  clear();

  connect(m_ui->fileLogging, &QCheckBox::clicked, this, &PositionObserverView::enableFileLoggingClicked);
  connect(m_ui->networkLogging, &QCheckBox::clicked, this, &PositionObserverView::enableNetworkLoggingClicked);
  connect(m_ui->address, &QLineEdit::textChanged, this, &PositionObserverView::addressChanged);
  connect(m_ui->portSpinBox, QOverload<int>::of(&QSpinBox::valueChanged), this, &PositionObserverView::portChanged);
}

PositionObserverView::~PositionObserverView()
{
  delete m_ui;
}

void PositionObserverView::setEnableFileLogging(bool enable)
{
  m_ui->fileLogging->setChecked(enable);
}

void PositionObserverView::setEnableNetworkLogging(bool enable)
{
  m_ui->networkLogging->setChecked(enable);
}

void PositionObserverView::setAddress(const QString& address)
{
  m_ui->address->setText(address);
}

void PositionObserverView::setPort(int port)
{
  m_ui->portSpinBox->setValue(port);
}

void PositionObserverView::clear()
{
  updateLabelValue(m_ui->x, 0.0);
  updateLabelValue(m_ui->y, 0.0);
  updateLabelValue(m_ui->z, 0.0);

  updateLabelValue(m_ui->roll, 0.0);
  updateLabelValue(m_ui->pitch, 0.0);
  updateLabelValue(m_ui->yaw, 0.0);
}

void PositionObserverView::updatePosition(const SkydelRuntimePositionObserver::TimedPosition& timedPosition)
{
  updateLabelValue(m_ui->x, timedPosition.position.x);
  updateLabelValue(m_ui->y, timedPosition.position.y);
  updateLabelValue(m_ui->z, timedPosition.position.z);

  updateLabelValue(m_ui->roll, timedPosition.orientation.roll);
  updateLabelValue(m_ui->pitch, timedPosition.orientation.pitch);
  updateLabelValue(m_ui->yaw, timedPosition.orientation.yaw);
}

void PositionObserverView::lockConfiguration(bool lock)
{
  m_ui->configuration->setEnabled(!lock);
}

void PositionObserverView::updateLabelValue(QLabel* label, double value)
{
  label->setText(QString::number(value, 'f', 6));
}
