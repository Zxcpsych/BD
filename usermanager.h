#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QCryptographicHash>

class UserManager {
public:
    UserManager(QSqlDatabase& database);
    bool registerUser(const QString &username, const QString &password);
    bool authenticateUser(const QString &username, const QString &password);
    bool isLoginUnique(const QString &username);

private:
    QSqlDatabase db;
};

#endif // USERMANAGER_H
