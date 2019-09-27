#ifndef PROTABLE_H
#define PROTABLE_H

#include <QTableWidget>
#include "visitor.h"

class ProTable: public QTableWidget
{

    Q_OBJECT

public:

    ProTable(QWidget* qw) : QTableWidget (qw){}
    void accept(visitor* v){v->visitTable(this);}

};

#endif // PROTABLE_H
