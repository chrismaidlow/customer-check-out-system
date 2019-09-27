#ifndef BUILDER_H
#define BUILDER_H

#include <QString>
#include "products.h"
#include <QStringList>
#include <vector>

class builder
{
protected:
    QStringList entryList;
public:
    virtual products* returnObject(QString) = 0;
    virtual ~builder();

};

#endif // BUILDER_H
