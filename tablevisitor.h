#ifndef TABLEVISITOR_H
#define TABLEVISITOR_H

#include "protable.h"
#include "visitor.h"
#include <QTableWidgetItem>

class TableVisitor : public visitor
{
private:
    double total = 0.00;

protected:
    virtual void visitTable(const ProTable*);

public: 

    TableVisitor(){}
    double getValue() const {return total;}
    virtual ~TableVisitor() {}

};

#endif // TABLEVISITOR_H
