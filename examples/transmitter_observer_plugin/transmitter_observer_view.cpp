#include "transmitter_observer_view.h"

#include <QCheckBox>
#include <QComboBox>

#include "ui_transmitter_observer_view.h"

TransmitterObserverView::TransmitterObserverView(QWidget* parent) :
  QWidget(parent),
  m_ui(new Ui::TransmitterObserverView)
{
  m_ui->setupUi(this);

  clear();

  connect(m_ui->fileLogging, &QCheckBox::clicked, this, &TransmitterObserverView::enableFileLoggingClicked);
  connect(m_ui->networkLogging, &QCheckBox::clicked, this, &TransmitterObserverView::enableNetworkLoggingClicked);
  connect(m_ui->address, &QLineEdit::textChanged, this, &TransmitterObserverView::addressChanged);
  connect(m_ui->portSpinBox, QOverload<int>::of(&QSpinBox::valueChanged), this, &TransmitterObserverView::portChanged);
}

TransmitterObserverView::~TransmitterObserverView()
{
  delete m_ui;
}

void TransmitterObserverView::setEnableFileLogging(bool enable)
{
  m_ui->fileLogging->setChecked(enable);
}

void TransmitterObserverView::setEnableNetworkLogging(bool enable)
{
  m_ui->networkLogging->setChecked(enable);
}

void TransmitterObserverView::setAddress(const QString& address)
{
  m_ui->address->setText(address);
}

void TransmitterObserverView::setPort(int port)
{
  m_ui->portSpinBox->setValue(port);
}

void TransmitterObserverView::updatePosition(const SkydelRuntimePositionObserver::TimedPosition& timedPosition)
{
  if (timedPosition.time % 1000 != 0)
  {
    return;
  }

  updateLabelValue(m_ui->x, timedPosition.position.x);
  updateLabelValue(m_ui->y, timedPosition.position.y);
  updateLabelValue(m_ui->z, timedPosition.position.z);
}

QString buildTransmitterInfo(const std::vector<SkydelRuntimeTransmitterObserver::Transmitter>& transmitters)
{
  QString transmitterInfo("");
  for (const auto& tx : transmitters)
  {
    auto thisTx = QString("%1: %2 %3 %4 | %5")
                    .arg(tx.name,
                         QString::number(tx.position.x, 'f', 2),
                         QString::number(tx.position.y, 'f', 2),
                         QString::number(tx.position.z, 'f', 2),
                         QString::number(tx.interferenceSignals.size()));

    transmitterInfo = transmitterInfo + thisTx + "\n";
  }

  return transmitterInfo;
}

void TransmitterObserverView::updateTransmitters(
  const SkydelRuntimeTransmitterObserver::TimedTransmitters& timedTransmitters)
{
  if (timedTransmitters.elapsedTimeMs % 1000 != 0)
  {
    return;
  }

  auto transmitterInfo = QString("Transmitters\n");
  transmitterInfo += buildTransmitterInfo(timedTransmitters.interferences);
  transmitterInfo += "\nSpoofers\n";
  transmitterInfo += buildTransmitterInfo(timedTransmitters.spoofers);

  m_ui->labelTransmitters->setText(transmitterInfo);
  m_ui->labelTransmitters->adjustSize();
}

void TransmitterObserverView::clear()
{
  updateLabelValue(m_ui->x, 0.0);
  updateLabelValue(m_ui->y, 0.0);
  updateLabelValue(m_ui->z, 0.0);

  m_ui->labelTransmitters->setText("N/A");
}

void TransmitterObserverView::lockConfiguration(bool lock)
{
  m_ui->configuration->setEnabled(!lock);
}

void TransmitterObserverView::updateLabelValue(QLabel* label, double value)
{
  label->setText(QString::number(value, 'f', 6));
}
