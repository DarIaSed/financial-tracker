// dbmanager.cpp
#include "data_base.h"

// Конструктор класса DBManager.
// Инициализирует объект базы данных с использованием драйвера QMYSQL.
DBManager::DBManager(const QString& host, const QString& databaseName, const QString& user, const QString& password)
    : m_database(QSqlDatabase::addDatabase("QMYSQL"))  // Создаёт и добавляет объект базы данных с драйвером QMYSQL.
{
    // Устанавливает параметры подключения к базе данных.
    m_database.setHostName(host);           // Имя хоста базы данных.
    m_database.setDatabaseName(databaseName); // Имя базы данных.
    m_database.setUserName(user);           // Имя пользователя для подключения.
    m_database.setPassword(password);       // Пароль пользователя для подключения.
}

// Деструктор класса DBManager.
// Закрывает соединение с базой данных при уничтожении объекта.
DBManager::~DBManager() {
    disconnect();  // Закрывает соединение, если оно открыто.
}

// Метод для установления соединения с базой данных.
// Возвращает true, если соединение успешно, и false в противном случае.
bool DBManager::connect() {
    if (!m_database.open()) {  // Пытается открыть соединение с базой данных.
        return false;           // Возвращает false, если соединение не удалось.
    }
    return true;  // Возвращает true, если соединение успешно открыто.
}

// Метод для закрытия соединения с базой данных.
// Закрывает соединение, если оно было открыто.
void DBManager::disconnect() {
    if (m_database.isOpen()) {  // Проверяет, открыто ли соединение.
        m_database.close();     // Закрывает соединение.
    }
}

// Метод для выполнения SQL-запроса без возврата данных.
// Возвращает true, если запрос выполнен успешно, и false в противном случае.
bool DBManager::executeQuery(const QString& query) {
    QSqlQuery sqlQuery;  // Создаёт объект запроса.
    if (!sqlQuery.exec(query)) {  // Выполняет запрос.
        return false;  // Возвращает false, если выполнение запроса не удалось.
    }
    return true;  // Возвращает true, если запрос выполнен успешно.
}

// Метод для выполнения SQL-запроса и возврата результата.
// Возвращает объект QSqlQuery, содержащий результаты запроса.
QSqlQuery DBManager::fetchQuery(const QString& query) {
    QSqlQuery sqlQuery;  // Создаёт объект запроса.
    sqlQuery.exec(query);  // Выполняет запрос и заполняет объект результатами.
    return sqlQuery;  // Возвращает объект запроса с результатами.
}

// Метод для получения текста последней ошибки при работе с базой данных.
// Возвращает строку с текстом ошибки.
QString DBManager::getLastError() const {
    return m_database.lastError().text();  // Получает текст последней ошибки базы данных.
}
