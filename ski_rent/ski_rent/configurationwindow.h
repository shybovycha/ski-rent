#ifndef CONFIGURATIONWINDOW_H
#define CONFIGURATIONWINDOW_H

#include <QWidget>

namespace Ui {
class ConfigurationWindow;
}

class ConfigurationWindow : public QWidget
{
    Q_OBJECT

public:
    explicit ConfigurationWindow(QWidget *parent = 0);
    ~ConfigurationWindow();

private:
    Ui::ConfigurationWindow *ui;
};

#endif // CONFIGURATIONWINDOW_H
