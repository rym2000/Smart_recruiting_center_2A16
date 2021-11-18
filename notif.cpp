#include "notif.h"
#include <QSystemTrayIcon>
#include<QString>
Notifications::Notifications()
{
}
    void Notifications::notifications_ajouter()
    {

        QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;


        notifyIcon->show();
        notifyIcon->showMessage("Gestion des entreprises ","entreprise presque ajouté ",QSystemTrayIcon::Information,15000);
    }

