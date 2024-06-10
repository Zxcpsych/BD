#ifndef PROJECTREGISTRATIONWINDOW_H
#define PROJECTREGISTRATIONWINDOW_H

#include <QMainWindow>

namespace Ui {
class ProjectRegistrationWindow;
}

class ProjectRegistrationWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit ProjectRegistrationWindow(QWidget *parent = nullptr);
    ~ProjectRegistrationWindow();

private slots:
    void on_registerButton_clicked();

private:
    Ui::ProjectRegistrationWindow *ui;
};

#endif // PROJECTREGISTRATIONWINDOW_H
