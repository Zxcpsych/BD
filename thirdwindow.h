#ifndef THIRDWINDOW_H
#define THIRDWINDOW_H

#include <QDialog>
#include "databasemanager.h"

namespace Ui {
class ThirdWindow;
}

class ThirdWindow : public QDialog
{
    Q_OBJECT

public:
    explicit ThirdWindow(DatabaseManager *dbManager, QWidget *parent = nullptr);
    ~ThirdWindow();

private slots:
    void on_registerButton_clicked();
    void on_authButton_clicked();

private:
    Ui::ThirdWindow *ui;
    DatabaseManager *dbManager;
};

#endif // THIRDWINDOW_H
