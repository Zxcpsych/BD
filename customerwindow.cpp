#include "customerwindow.h"
#include "ui_customerwindow.h"

CustomerWindow::CustomerWindow(DatabaseManager *dbManager, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CustomerWindow),
    dbManager(dbManager)
{
    ui->setupUi(this);
}

CustomerWindow::~CustomerWindow()
{
    delete ui;
}

void CustomerWindow::on_registerButton_clicked()
{
    QString projectName = ui->projectNameLineEdit->text();
    QString projectId = ui->projectIdLineEdit->text();



    if (projectName.isEmpty() || projectId.isEmpty()) {
        ui->statusLabel->setText("Заполните все обязательные поля");
        return;
    }

    if (dbManager->registerProject(projectName,projectId)) {
        ui->statusLabel->setText("Регистрация проекта успешна");
    } else {
        ui->statusLabel->setText("Ошибка регистрации проекта");
    }
}
