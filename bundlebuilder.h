#ifndef BUNDLEBUILDER_H
#define BUNDLEBUILDER_H


#include <QString>
#include "builder.h"
#include "bundle.h"
#include <vector>
#include <cmath>

using std::vector;

class BundleBuilder : public builder
{
public:

    vector<products*> database;
    vector<QString> name_list;

    BundleBuilder(){}

    virtual bundle* returnObject(QString);

    void linkProducts(vector<products*> prods){ database = prods;}

    QString calcSavings(vector<QString>, QString) const;

    virtual ~BundleBuilder(){}

};


#endif // BUNDLEBUILDER_H
