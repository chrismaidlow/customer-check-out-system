#ifndef PRODUCTS_H
#define PRODUCTS_H

#include <QString>

class products
{
public:

    virtual QString getName() const = 0;
    virtual double getPrice() const = 0;

    virtual ~products();

};

#endif // PRODUCTS_H
