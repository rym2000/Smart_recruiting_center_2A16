#ifndef ENTREPRISES_H
#define ENTREPRISES_H
#include "entreprise.h"
#include "QWidget"


#include <QDialog>
#include <QFileDialog>
#include "Excel.h"
namespace Ui {
class Entreprises;
}

class Entreprises : public QDialog
{
    Q_OBJECT

public:
    explicit Entreprises(QWidget *parent = nullptr);
    ~Entreprises();

private slots:
    void on_pushButton_ajouter_clicked();

    void on_pushButton_supprimer_clicked();

    void on_pushButton_modifier_clicked();

    void on_pushButton_trier_clicked();

    void on_comboBox_activated(const QString &arg1);

    void on_pushButton_trier1_clicked();

    void on_pushButton_trier2_clicked();

    void on_rech_textChanged(const QString &arg1);

    void on_pushButton_browse_email_clicked();

    void on_pushButton_send_email_clicked();
    void mailSent(QString);

    void on_exporterExel_clicked();

private:
    Ui::Entreprises *ui;
    Entreprise E ;
    QStringList files;


};

#endif // ENTREPRISES_H
