#ifndef DELEGATE_H
#define DELEGATE_H

#include <QObject>
#include <QItemDelegate>
#include <QWidget>
#include <QModelIndex>
#include <QSize>
#include <QString>

#include <QSpinBox>
#include <QLineEdit>
class Delegate : public QItemDelegate
{
    Q_OBJECT

public:
    explicit Delegate(QObject* parent=0);
    QWidget* create(QWidget *parent);
    void set(QWidget *editor, const QModelIndex &index);
    QString setmodel(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index);



};

#endif // DELEGATE_H

