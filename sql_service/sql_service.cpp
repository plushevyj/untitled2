#include "sql_service.h"

QSqlDatabase SqlService::connectToDB() {
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("127.0.0.1");
    db.setUserName("root");
    db.setPassword("");
    db.setDatabaseName("crmqt");
    return db;
}
