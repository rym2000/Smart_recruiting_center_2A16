#ifndef ENTREPRISE_H
#define ENTREPRISE_H
#include <QString>
#include <QSqlQueryModel>
#include <QTableView>
#include <QTableView>
#include <QPdfWriter>
#include <QPainter>

#include <QString>
#include <QSqlQueryModel>
#include <QTableView>





class Entreprise
{
public:
    Entreprise();
    Entreprise(int , QString , QString , int , QString);
    int getidentifiant();
    QString getnom();
    QString getoffre();
    QString getadresse_mail();
    int getdelai() ;
    void setidentifiant (int );
    void setnom (QString );
    void setoffre ( QString );
    void setdelai (int );
    void setadresse_mail (QString );
    bool ajouter();
    QSqlQueryModel* afficher();
    bool supprimer(int);
    bool modifier(int, QString,QString,int,QString);
    QSqlQueryModel* trier();
    QSqlQueryModel* trier1();
    QSqlQueryModel* trier2();
    void rechercher(QTableView * tabl, int,QString,QString);



   private :
    int identifiant ;
    QString nom;
    QString offre ;
    int delai ;
    QString adresse_mail;
};

#endif // ENTREPRISE_H
