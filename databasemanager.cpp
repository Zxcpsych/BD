#include "databasemanager.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

DatabaseManager::DatabaseManager(const QString &hostname, int port, const QString &dbname, const QString &username, const QString &password, QObject *parent)
    : QObject(parent)
{
    db = QSqlDatabase::addDatabase("QPSQL");
    db.setHostName(hostname);
    db.setPort(port);
    db.setDatabaseName(dbname);
    db.setUserName(username);
    db.setPassword(password);

    if (!db.open()) {
        qDebug() << "Ошибка подключения к базе данных:" << db.lastError().text();
    }
}

bool DatabaseManager::registerWorker(const QString &workerName, const QString &workerId)
{
    QSqlQuery query;
    query.prepare("INSERT INTO workers (w_name, w_id) VALUES (:w_name, :w_id)");
    query.bindValue(":w_name", workerName);
    query.bindValue(":w_id", workerId);

    if (query.exec()) {
        return true;
    } else {
        qDebug() << "Ошибка выполнения запроса:" << query.lastError().text();
        return false;
    }
}




bool DatabaseManager::registerProject(const QString &projectName,const QString &projectId)
{
    QSqlQuery query;
    query.prepare("INSERT INTO projects (p_name, p_id) VALUES (:p_name, :p_id)");
    query.bindValue(":p_name", projectName);
    query.bindValue(":p_id", projectId);


    if (query.exec()) {
        return true;
    } else {
        qDebug() << "Ошибка выполнения запроса:" << query.lastError().text();
        return false;
    }
}
