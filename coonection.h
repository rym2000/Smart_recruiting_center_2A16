#ifndef COONECTION_H
#define COONECTION_H


#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>

class Connection
{
public:
    Connection();
    bool createconnect();
};

#endif // CONNECTION_H
