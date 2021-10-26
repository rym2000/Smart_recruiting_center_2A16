#include "coonection.h"

Connection::Connection()
{

}

bool Connection::createconnect()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("hassan_project2A");
db.setUserName("hassan");//inserer nom de l'utilisateur
db.setPassword("hassan");//inserer mot de passe de cet utilisateur

if (db.open())
test=true;





    return  test;
}
