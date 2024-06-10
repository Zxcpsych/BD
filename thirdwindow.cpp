#include "thirdwindow.h"
#include "ui_thirdwindow.h"


#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

ThirdWindow::ThirdWindow(DatabaseManager *dbManager, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ThirdWindow),
    dbManager(dbManager)

{
    ui->setupUi(this);
}

ThirdWindow::~ThirdWindow()
{
    delete ui;
}

void ThirdWindow::on_registerButton_clicked()
{
    QSqlQuery query;
    query.prepare("SELECT * FROM "+ ui->comboBox->currentText() + " ");

    if(query.exec())
    {

        QString column1;
        QString column2;
        int Row_Number=0;
        ui->tableWidget->setRowCount(query.size());
        while(query.next())
        {
            ui->tableWidget->setItem(Row_Number,0,new QTableWidgetItem(QString(query.value(""+ column1 +"").toString())));
            ui->tableWidget->setItem(Row_Number,1,new QTableWidgetItem(QString(query.value(""+ column2 +"").toString())));

        }
    }
}

