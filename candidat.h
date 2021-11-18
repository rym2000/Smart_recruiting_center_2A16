#ifndef CANDIDAT_H
#define CANDIDAT_H

#include <QString>
#include <QSqlQueryModel>



class Candidat
{

public:
    int CIN  ;
    QString nom,prenom,date,diplome ;

public:
            Candidat();
            Candidat(int,QString,QString,QString,QString);

            int getCIN ();
            QString getnom ();
            QString getprenom ();
            QString getdate ();
            QString getdiplome ();

            bool ajouter();
            bool supprimer(int);
            QSqlQueryModel* afficher();
            bool modifier(int,QString,QString,QString,QString) ;
            QSqlQueryModel* rechercherdynamique(QString input,QString filter);
            QSqlQueryModel* afficher_unemploye();
            QSqlQueryModel* afficher_unemploye_nom();
            QSqlQueryModel* afficher_unemploye_nom_prenom();


};

#endif // CANDIDAT_H
