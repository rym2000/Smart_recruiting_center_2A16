#ifndef ENTRETIENN_H
#define ENTRETIENN_H
#include"entretien.h"
#include "smtp.h"
#include <QDialog>

namespace Ui {
class entretienn;
}

class entretienn : public QDialog
{
    Q_OBJECT

public:
    explicit entretienn(QWidget *parent = nullptr);
    ~entretienn();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_5_clicked();

    void on_comboBox_activated(const QString &arg1);

    void on_pushButton_4_clicked();

    void on_pushButton_3_clicked();


private:
    Ui::entretienn *ui;
       Entretien e;
};

#endif // ENTRETIENN_H
