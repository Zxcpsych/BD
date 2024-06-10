#include "secondwindow.h"
#include "ui_secondwindow.h"
#include "customerwindow.h"
#include "workerwindow.h"
#include "thirdwindow.h"

SecondWindow::SecondWindow(DatabaseManager *dbManager, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SecondWindow),
    dbManager(dbManager)
{
    ui->setupUi(this);
}

SecondWindow::~SecondWindow()
{
    delete ui;
}

void SecondWindow::on_customerButton_clicked()
{
    CustomerWindow *customerWindow = new CustomerWindow(dbManager);
    customerWindow->show();

}

void SecondWindow::on_workerButton_clicked()
{
    WorkerWindow *workerWindow = new WorkerWindow(dbManager);
    workerWindow->show();

}

void SecondWindow::on_leaderButton_clicked()
{
    ThirdWindow *thirdWindow = new ThirdWindow(dbManager);
    thirdWindow->show();

}
