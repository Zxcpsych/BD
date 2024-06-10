#include "workerwindow.h"
#include "ui_workerwindow.h"

WorkerWindow::WorkerWindow(DatabaseManager *dbManager, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::WorkerWindow),
    dbManager(dbManager)
{
    ui->setupUi(this);
}

WorkerWindow::~WorkerWindow()
{
    delete ui;
}

void WorkerWindow::on_registerButton_clicked()
{
    QString workerName = ui->workerNameLineEdit->text();
    QString workerId = ui->workerIdLineEdit->text();


    if (workerName.isEmpty() || workerId.isEmpty()) {
        ui->statusLabel->setText("Заполните все обязательные поля");
        return;
    }

    if (dbManager->registerWorker(workerName, workerId)) {
        ui->statusLabel->setText("Регистрация работника успешна");
    } else {
        ui->statusLabel->setText("Ошибка регистрации работника");
    }
}


void WorkerWindow::on_loginButton_clicked()
{
    QString workerId = ui->workerIdLineEdit->text();

    if (workerId.isEmpty()) {
        ui->statusLabel->setText("Введите ID работника");
        return;
    }

}
