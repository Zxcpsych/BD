#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <QObject>
#include <QtSql/QSqlDatabase>

class DatabaseManager : public QObject
{
    Q_OBJECT
public:
    explicit DatabaseManager(const QString &hostname, int port, const QString &dbname, const QString &username, const QString &password, QObject *parent = nullptr);

    bool registerWorker(const QString &workerName, const QString &workerId);


    bool registerProject(const QString &projectName,const QString &projectId);

private:
    QSqlDatabase db;
};

#endif // DATABASEMANAGER_H
