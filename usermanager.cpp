#include "usermanager.h"

UserManager::UserManager(QSqlDatabase& database) : db(database) {}

bool UserManager::registerUser(const QString &username, const QString &password) {
    if (!isLoginUnique(username)) {
        qDebug() << "Login is not unique: " << username;
        return false;
    }

    QSqlQuery query(db);
    query.prepare("INSERT INTO verification (login, password) VALUES (:login, :password)");
    query.bindValue(":login", username);
    query.bindValue(":password", QString(QCryptographicHash::hash(password.toUtf8(), QCryptographicHash::Sha256).toHex()));
    if (!query.exec()) {
        qDebug() << "Failed to register user: " << query.lastError().text();
        return false;
    }
    return true;
}

bool UserManager::authenticateUser(const QString &username, const QString &password) {
    QSqlQuery query(db);
    query.prepare("SELECT password FROM verification WHERE login = :login");
    query.bindValue(":login", username);
    if (!query.exec() || !query.next()) {
        qDebug() << "Authentication failed: " << query.lastError().text();
        return false;
    }
    QString storedPassword = query.value(0).toString();
    QString hashedPassword = QString(QCryptographicHash::hash(password.toUtf8(), QCryptographicHash::Sha256).toHex());
    return storedPassword == hashedPassword;
}

bool UserManager::isLoginUnique(const QString &username) {
    QSqlQuery query(db);
    query.prepare("SELECT COUNT(*) FROM verification WHERE login = :login");
    query.bindValue(":login", username);
    if (!query.exec() || !query.next()) {
        qDebug() << "Failed to check login uniqueness: " << query.lastError().text();
        return false;
    }
    return query.value(0).toInt() == 0;
}
