#include "tablevisitor.h"

void TableVisitor::visitTable(const ProTable* table)
{
    for (int i=0;i<table->rowCount();i++)
    {
        QTableWidgetItem* value = (table->item(i,1));
        double dub_val = value->data(Qt::DisplayRole).toDouble();
        total += dub_val;
    }
}
