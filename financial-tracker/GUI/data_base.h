// dbmanager.hpp
#ifndef DATA_BASE_H
#define DATA_BASE_H

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QString>
#include <QVariant>
#include <QSqlError>

class DBManager {
public:
    explicit DBManager(const QString& host, const QString& databaseName, const QString& user, const QString& password);
    ~DBManager();

    bool connect();
    void disconnect();

    bool executeQuery(const QString& query);
    QSqlQuery fetchQuery(const QString& query);

    QString getLastError() const;

private:
    QSqlDatabase m_database;
};

#endif // DATA_BASE_H
