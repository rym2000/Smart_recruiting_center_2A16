#ifndef STAT_H
#define STAT_H
#include <QDialog>
#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include <QtCharts/QBarCategoryAxis>

// Used to create stacked bar charts
#include <QtCharts/QHorizontalStackedBarSeries>

// Used to create a line chart
#include <QtCharts/QLineSeries>

// Used to change names on axis
#include <QtCharts/QCategoryAxis>

// Used to make Pie Charts
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QDialog>
#include "entreprise.h"
QT_CHARTS_USE_NAMESPACE
namespace Ui {
class stat;
}

class stat : public QDialog
{
    Q_OBJECT

public:
    explicit stat(QWidget *parent = nullptr);
      void make();
    ~stat();
private slots :

      ^
      void on_lineEdit_ingenieur_textChanged(const QString &arg1);

private:
    Ui::stat *ui;
    Entreprise E ;
    QString ingenieur;
          QString architecte;
           QString techniciensup;

};

#endif // STAT_H
