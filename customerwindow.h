#ifndef CUSTOMERWINDOW_H
#define CUSTOMERWINDOW_H

#include <QMainWindow>
#include "databasemanager.h"

namespace Ui {
class CustomerWindow;
}

class CustomerWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit CustomerWindow(DatabaseManager *dbManager, QWidget *parent = nullptr);
    ~CustomerWindow();

private slots:
    void on_registerButton_clicked();

private:
    Ui::CustomerWindow *ui;
    DatabaseManager *dbManager;
};

#endif // CUSTOMERWINDOW_H
