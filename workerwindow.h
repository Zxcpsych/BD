#ifndef WORKERWINDOW_H
#define WORKERWINDOW_H

#include <QMainWindow>
#include "databasemanager.h"

namespace Ui {
class WorkerWindow;
}

class WorkerWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit WorkerWindow(DatabaseManager *dbManager, QWidget *parent = nullptr);
    ~WorkerWindow();

private slots:
    void on_registerButton_clicked();
    void on_authButton_clicked();
    void on_loginButton_clicked();

private:
    Ui::WorkerWindow *ui;
    DatabaseManager *dbManager;
};

#endif // WORKERWINDOW_H
