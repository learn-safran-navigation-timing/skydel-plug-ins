#ifndef IMU_VIEW_H
#define IMU_VIEW_H

#include <QWidget>

#include "imu_configuration.h"

namespace Ui
{
class ImuView;
}

class ImuView : public QWidget
{
  Q_OBJECT

public:
  explicit ImuView(const ImuConfiguration& configuration, QWidget* parent = nullptr);
  ~ImuView();

  void setConfiguration(const ImuConfiguration& configuration);

signals:
  void checkBoxFileLoggingClicked(bool checked);
  void comboBoxFileLoggingActivated(int index);
  void checkBoxNetworkLoggingClicked(bool checked);
  void comboBoxNetworkLoggingActivated(int index);
  void lineEditNetworkLoggingTextChanged(const QString& text);
  void spinBoxNetworkLoggingValueChanged(int i);
  void comboBoxGravityModelActivated(int index);

private:
  Ui::ImuView* m_ui;
};

#endif // IMU_VIEW_H
