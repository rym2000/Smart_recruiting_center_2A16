#include "connexion.h"

Connection::Connection()
{

}

bool Connection::createconnect()
{
 db = QSqlDatabase::addDatabase("QODBC");
 bool test=false;
db.setDatabaseName("Source_Projet2A");
db.setUserName("Rym");//inserer nom de l'utilisateur
db.setPassword("Rym123");//inserer mot de passe de cet utilisateur

if (db.open())
test=true;
return  test;
}
void Connection::closeconnect()
{
    db.close();
}
