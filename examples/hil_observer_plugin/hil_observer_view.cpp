#include "hil_observer_view.h"

#include <QCheckBox>

#include "ui_hil_observer_view.h"

HilObserverView::HilObserverView(QWidget* parent) : QWidget(parent), m_ui(new Ui::HilObserverView)
{
  m_ui->setupUi(this);

  clear();

  connect(m_ui->fileLogging, &QCheckBox::clicked, this, &HilObserverView::enableFileLoggingClicked);
}

HilObserverView::~HilObserverView()
{
  delete m_ui;
}

void HilObserverView::setEnableFileLogging(bool enable)
{
  m_ui->fileLogging->setChecked(enable);
}

void HilObserverView::clear()
{
  updateLabelValue(m_ui->x, 0.0);
  updateLabelValue(m_ui->y, 0.0);
  updateLabelValue(m_ui->z, 0.0);

  updateLabelValue(m_ui->roll, 0.0);
  updateLabelValue(m_ui->pitch, 0.0);
  updateLabelValue(m_ui->yaw, 0.0);
}

void HilObserverView::updatePosition(const SkydelRuntimeHilObserver::TimedPosition& timedPosition)
{
  updateLabelValue(m_ui->x, timedPosition.position.x);
  updateLabelValue(m_ui->y, timedPosition.position.y);
  updateLabelValue(m_ui->z, timedPosition.position.z);

  updateLabelValue(m_ui->roll, timedPosition.orientation.roll);
  updateLabelValue(m_ui->pitch, timedPosition.orientation.pitch);
  updateLabelValue(m_ui->yaw, timedPosition.orientation.yaw);
}

void HilObserverView::lockConfiguration(bool lock)
{
  m_ui->configuration->setEnabled(!lock);
}

void HilObserverView::updateLabelValue(QLabel* label, double value)
{
  label->setText(QString::number(value, 'f', 6));
}
