#ifndef SIMPLE_PLUGIN_VIEW_H
#define SIMPLE_PLUGIN_VIEW_H

#include <QWidget>

namespace Ui
{
class SimplePluginView;
}

class SimplePluginView : public QWidget
{
  Q_OBJECT
public:
  explicit SimplePluginView(QWidget* parent = nullptr);
  ~SimplePluginView();

  void setNotification(const QString& message, int type);

signals:
  void sendNotificationClicked();
  void messageChanged(const QString& message);
  void typeChanged(int type);

private:
  Ui::SimplePluginView* m_ui;
};

#endif // SIMPLE_PLUGIN_VIEW_H
