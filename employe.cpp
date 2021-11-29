#include "employe.h"
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDebug>
#include "mainwindow.h"

employe::employe()
{
id="";
nom="";
prenom="";
salaire="";
adresse_mail="";
mdp="";
}

employe::employe(QString id,QString nom,QString prenom,QString salaire,QString adresse_mail,QString mdp )
{
this->id=id;
this->nom=nom;
this->prenom=prenom;
this->salaire=salaire;
this->adresse_mail=adresse_mail;
this->mdp=mdp;
}


QString employe::get_id()
{

    return this->id;
}
QString employe::get_nom()
{
    return this->nom;

}
QString employe::get_prenom()
{
    return this->prenom;

}
QString employe::get_salaire()
{
    return this->salaire;

}
QString employe::get_adresse_mail()
{
    return this->adresse_mail;

}
QString employe::get_mdp()
{
    return this->mdp;

}

bool employe::ajouter()
{
    QSqlQuery query;
   // QString res=QString::number(id);
    query.prepare("INSERT INTO employes (id,nom,prenom,salaire,adresse_mail,mdp) VALUES (:id,:nom,:prenom,:salaire,:adresse_mail,:mdp)");
    query.bindValue(":id",id);
    query.bindValue(":nom",nom);
    query.bindValue(":prenom",prenom);
    query.bindValue(":salaire",salaire);
    query.bindValue(":adresse_mail",adresse_mail);
    query.bindValue(":mdp",mdp);
    return query.exec();

}
QSqlQueryModel * employe::afficher()
{
   QSqlQueryModel * model=new QSqlQueryModel();
   model->setQuery("select * from employes");
   model->setHeaderData(0,Qt::Horizontal,QObject::tr("id"));
   model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
   model->setHeaderData(2,Qt::Horizontal,QObject::tr("prenom"));
   model->setHeaderData(3,Qt::Horizontal,QObject::tr("salaire"));
   model->setHeaderData(4,Qt::Horizontal,QObject::tr("adresse_mail"));
   model->setHeaderData(5,Qt::Horizontal,QObject::tr("mdp"));
   return model;
}
QSqlQueryModel * employe::trier(QString x)
{
    QSqlQueryModel * model= new QSqlQueryModel();
    qDebug()<<x<<endl;
    if(x=="nom")
        model->setQuery("select * from employes order by nom ");
    else if(x=="prenom")
        model->setQuery("select * from employes order by prenom ");
    else if (x=="salaire")
        model->setQuery("select * from employes order by salaire ");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("id"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("prenom"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("salaire"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("adresse_mail"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("mdp"));
return model;

}


QSqlQueryModel * employe::rechercher(QString a){
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from employes where id ='"+a+"' ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("salaire"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("adresse_mail"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("mdp"));
        return model;
}


bool employe::supprimer(QString id)
{
    QSqlQuery query;
    //QString res=QString::number(id);
    query.prepare("DELETE  FROM employes WHERE id = :id");
    query.bindValue(":id",id);
    return query.exec();

}
bool employe::modifier(QString x,QString nom,QString prenom,QString salaire,QString adresse_mail,QString mdp)
{
     QSqlQuery query;
    query.prepare("update employes set nom=:nom,prenom=:prenom,salaire=:salaire,adresse_mail=:adresse_mail,mdp=:mdp where id=:'"+x+"'");
    query.bindValue(":nom",nom);
    query.bindValue(":prenom",prenom);
    query.bindValue(":salaire",salaire);
    query.bindValue(":adresse_mail",adresse_mail);
    query.bindValue(":mdp",mdp);
    return query.exec();

}
bool employe::connecter(QString x,QString y){
    QSqlQuery query;
    query.prepare("SELECT * FROM EMPLOYES");
        query.exec();
        bool test = false;
        while(!test){
            query.next();
            if(query.value(0).toString() == x){
                test = true;
            }
        }
        if(test){
            if(query.value(5) == y){
                return true;
            }
            else return false;
        }
        else return false;
}

bool employe::rech(QString x){
    QSqlQuery query;
    query.prepare("SELECT * FROM EMPLOYES");
    query.exec();
    bool test = false;
    while(!test){
        query.next();
        if(query.value(0).toString() == x){
            test= true;
        }
    }
    if (test){
        return true;
    }
    else return false;
}
