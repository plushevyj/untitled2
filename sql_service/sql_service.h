#ifndef UNTITLED2_SQL_SERVICE_H
#define UNTITLED2_SQL_SERVICE_H

#include <QtSql>
#include <QSqlDatabase>

class SqlService {
public:
    static QSqlDatabase connectToDB();
};


#endif //UNTITLED2_SQL_SERVICE_H
