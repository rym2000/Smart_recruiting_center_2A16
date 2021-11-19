#include "contrat.h"

contrat::contrat()
{

}
contrat::contrat(int id,QString nom,QString prenom,float duree,QString type)
{
    this->id=id;
    this->nom=nom;
    this->prenom=prenom;
    this->duree=duree;
    this->type=type;
}
bool contrat::ajouter()
{
    QString d=QString::number(duree);
   QSqlQuery q;
   q.prepare("insert into contrat(id,nom,prenom,duree,type) VALUES(:id,:nom,:prenom,:duree,:type)");//preparation du requete
   q.bindValue(":id",id);//injection sql srcurité
   q.bindValue(":nom",nom);
   q.bindValue(":prenom",prenom);
   q.bindValue(":duree",d);
   q.bindValue(":type",type);
   return q.exec();//execution du requete
}
bool contrat::modifier(int id)
{
      QString d=QString::number(duree);
    QSqlQuery q;
    q.prepare("update contrat set nom=:nom,prenom=:prenom,duree=:duree,type=:type where id=:id");//preparation du requete
    q.bindValue(":id",id);//injection sql srcurité
    q.bindValue(":nom",nom);
    q.bindValue(":prenom",prenom);
    q.bindValue(":duree",d);
    q.bindValue(":type",type);
    q.exec();//execution du requete
    return rechercher(id);
}
bool contrat::supprimer(int id)
{
    bool test=rechercher(id);
    QSqlQuery q;
    q.prepare("delete from contrat where id=:id");
    q.bindValue(":id",id);
    q.exec();
    return test;
}
QSqlQueryModel* contrat::afficher()
{
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("select * from contrat");
    return model;
}
QSqlQueryModel* contrat::trier(QString type)
{
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("select * from contrat order by "+type);
    return model;
}
bool contrat::rechercher(int id)
{
    QString res=QString::number(id);
    QSqlQuery q("select * from contrat where id="+res);
    while (q.next()) {
        return true;
    }
    return false;
}
