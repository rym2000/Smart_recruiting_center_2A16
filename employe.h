#ifndef EMPLOYE_H
#define EMPLOYE_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <QString>
#include <QSqlQueryModel>
#include <QSqlQuery>

class employe
{
    QString id;
    QString salaire;
    QString nom,prenom,adresse_mail,mdp;
public:
    employe();
    employe(QString,QString,QString,QString,QString,QString);
      QString get_id();
      QString get_nom();
      QString get_prenom();
      QString get_salaire();
      QString get_adresse_mail();
      QString get_mdp();
      bool ajouter();
      bool supprimer(QString id);
      bool modifier(QString x,QString nom,QString prenom,QString salaire,QString adresse_mail,QString mdp);
      QSqlQueryModel * trier(QString x);
      QSqlQueryModel * rechercher(QString x);
      QSqlQueryModel * afficher();
      bool rech(QString x);
      bool connecter(QString x,QString y);
};

#endif
