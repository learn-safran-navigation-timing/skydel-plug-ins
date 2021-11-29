#include "radio_time_observer_view.h"

#include <math.h>

#include <QCheckBox>
#include <QComboBox>

#include "ui_radio_time_observer_view.h"

RadioTimeObserverView::RadioTimeObserverView(QWidget* parent) : QWidget(parent), m_ui(new Ui::RadioTimeObserverView)
{
  m_ui->setupUi(this);

  clear();

  connect(m_ui->fileLogging, &QCheckBox::clicked, this, &RadioTimeObserverView::enableFileLoggingClicked);
  connect(m_ui->networkLogging, &QCheckBox::clicked, this, &RadioTimeObserverView::enableNetworkLoggingClicked);
  connect(m_ui->address, &QLineEdit::textChanged, this, &RadioTimeObserverView::addressChanged);
  connect(m_ui->portSpinBox, QOverload<int>::of(&QSpinBox::valueChanged), this, &RadioTimeObserverView::portChanged);
}

RadioTimeObserverView::~RadioTimeObserverView()
{
  delete m_ui;
}

void RadioTimeObserverView::setEnableFileLogging(bool enable)
{
  m_ui->fileLogging->setChecked(enable);
}

void RadioTimeObserverView::setEnableNetworkLogging(bool enable)
{
  m_ui->networkLogging->setChecked(enable);
}

void RadioTimeObserverView::setAddress(const QString& address)
{
  m_ui->address->setText(address);
}

void RadioTimeObserverView::setPort(int port)
{
  m_ui->portSpinBox->setValue(port);
}

void RadioTimeObserverView::clear()
{
  updateLabelValue(m_ui->sim_x, 0.0);
  updateLabelValue(m_ui->sim_y, 0.0);
  updateLabelValue(m_ui->sim_z, 0.0);
  updateLabelValue(m_ui->simulationTime, 0.0);

  updateLabelValue(m_ui->radio_x, 0.0);
  updateLabelValue(m_ui->radio_y, 0.0);
  updateLabelValue(m_ui->radio_z, 0.0);
  updateLabelValue(m_ui->radioTime, 0.0);

  m_processedPositions.clear();
  for (int64_t i = 0; i < 1000; i++)
  {
    m_processedPositions.push_back(SkydelRuntimePositionObserver::TimedPosition {i, {0, 0, 0}, {0, 0, 0}});
  }
}

void RadioTimeObserverView::updatePosition(const SkydelRuntimePositionObserver::TimedPosition& timedPosition,
                                           int64_t usUntilRfTx)
{
  m_processedPositions[timedPosition.time % 1000] = timedPosition;
  if (timedPosition.time % 10 != 0)
  {
    return;
  }

  updateLabelValue(m_ui->sim_x, timedPosition.position.x);
  updateLabelValue(m_ui->sim_y, timedPosition.position.y);
  updateLabelValue(m_ui->sim_z, timedPosition.position.z);
  updateLabelValue(m_ui->simulationTime, timedPosition.time);

  const auto msOfRadio = static_cast<int64_t>(timedPosition.time - usUntilRfTx / 1000);
  if (msOfRadio < 0)
  {
    return;
  }

  const auto radioPosition = m_processedPositions[msOfRadio % 1000].position;
  updateLabelValue(m_ui->radio_x, radioPosition.x);
  updateLabelValue(m_ui->radio_y, radioPosition.y);
  updateLabelValue(m_ui->radio_z, radioPosition.z);
  updateLabelValue(m_ui->radioTime, timedPosition.time - (usUntilRfTx / 1000.0));

  updateLabelValue(m_ui->deltaTime, usUntilRfTx);

  const auto distance = std::sqrt(std::pow(timedPosition.position.x - radioPosition.x, 2) +
                                  std::pow(timedPosition.position.y - radioPosition.y, 2) +
                                  std::pow(timedPosition.position.z - radioPosition.z, 2));

  updateLabelValue(m_ui->deltaDistance, distance);
}

void RadioTimeObserverView::updateRadioTime(const SkydelRuntimeRadioTimeObserver::RadioTimeEstimate&)
{
}

void RadioTimeObserverView::lockConfiguration(bool lock)
{
  m_ui->configuration->setEnabled(!lock);
}

void RadioTimeObserverView::updateLabelValue(QLabel* label, double value)
{
  label->setText(QString::number(value, 'f', 6));
}
