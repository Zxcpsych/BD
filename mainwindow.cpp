#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "secondwindow.h"

MainWindow::MainWindow(DatabaseManager *dbManager, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    dbManager(dbManager)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_loginButton_clicked()
{
    QString workerId = ui->workerIdLineEdit->text();

    if (workerId.isEmpty()) {
        ui->statusLabel->setText("Введите ID работника");
        return;
    }

    if (dbManager->loginWorker(workerId)) {
        ui->statusLabel->setText("Авторизация успешна");
        SecondWindow *secondWindow = new SecondWindow(dbManager);
        secondWindow->show();
        this->close();
    } else {
        ui->statusLabel->setText("Ошибка авторизации");
    }
}
