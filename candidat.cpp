 #include "candidat.h"

Candidat::Candidat()
{
    CIN =0;num=0; nom=" ";prenom=" ";adresse=" ";diplome=" ";
}
Candidat::Candidat(int CIN,int num,QString nom,QString prenom,QString adresse,QString diplome)
{this->CIN=CIN;this->num=num;this->nom=nom;this->prenom=prenom;this->adresse=adresse;this->diplome=diplome ; }
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
