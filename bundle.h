#ifndef BUNDLE_H
#define BUNDLE_H

#include <QString>
#include <products.h>

class bundle : public products
{
protected:
    QString m_name;
    double m_price;
    QString m_savings;

public:
    bundle(QString name, QString price, QString savings)
    {
        m_name = name;
        m_price = price.toDouble();
        m_savings = savings;
    }

    virtual QString getName() const {return m_name;}

    virtual double getPrice() const {return m_price;}

    QString getSavings() const {return m_savings;}

    virtual ~bundle();
};


#endif // BUNDLE_H
