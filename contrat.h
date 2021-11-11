#ifndef CONTRAT_H
#define CONTRAT_H
#include <QSqlQueryModel>
#include <QSqlQuery>
class contrat
{
public:
    contrat();
    contrat(int,QString,QString,float,QString,int,int);
    bool ajouter();
    bool supprimer(int);
    bool modifier(int);
    QSqlQueryModel* afficher();
    QSqlQueryModel* trier(QString);
private:
    int id;
    QString nom;
    QString prenom;
    float duree;
    QString type;
    int id_candidat;
    int id_entreprise;

};

#endif // CONTRAT_H
