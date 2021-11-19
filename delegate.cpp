#include "delegate.h"

Delegate::Delegate(QObject *parent):QItemDelegate(parent)
{

}


QWidget* Delegate::create(QWidget *parent){
    QLineEdit *n=new QLineEdit(parent);

        return n;

}
void Delegate::set(QWidget *editor, const QModelIndex &index){
    QVariant value=index.model()->data(index,Qt::EditRole);

    QLineEdit* spinbox=static_cast<QLineEdit*>(editor);
    spinbox->setText(value.toString());

}

