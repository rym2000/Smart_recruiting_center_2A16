#ifndef CANDIDAT_H
#define CANDIDAT_H

#include <QString>

class Candidat
{
public:
    Candidat();
    Candidat(int,int,QString,QString,QString,QString);
    int getCIN ();
    int getnum ();
    QString getnom ();
    QString getprenom ();
    QString getadresse ();
    QString getdiplome ();
    void setCIN(int);
     void setnum(int);
       void setnom(QString);
        void setprenom(QString);
          void setadresse(QString);
            void setdiplome(QString);

    private:
    int CIN , num ;
    QString nom,prenom,adresse,diplome ;
};

#endif // CANDIDAT_H
