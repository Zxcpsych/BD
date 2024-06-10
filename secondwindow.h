#ifndef SECONDWINDOW_H
#define SECONDWINDOW_H

#include <QDialog>
#include "databasemanager.h"

namespace Ui {
class SecondWindow;
}

class SecondWindow : public QDialog
{
    Q_OBJECT

public:
    explicit SecondWindow(DatabaseManager *dbManager, QWidget *parent = nullptr);
    ~SecondWindow();

private slots:
    void on_customerButton_clicked();
    void on_workerButton_clicked();
    void on_leaderButton_clicked();

private:
    Ui::SecondWindow *ui;
    DatabaseManager *dbManager;
};

#endif // SECONDWINDOW_H
