#ifndef TECHBUILDER_H
#define TECHBUILDER_H

#include <QString>
#include "builder.h"
#include "tech.h"

class TechBuilder : public builder
{
public:

    TechBuilder(){}

    virtual tech* returnObject(QString);

    virtual ~TechBuilder(){}

};

#endif // TECHBUILDER_H
