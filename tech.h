#ifndef TECH_H
#define TECH_H

#include <QString>
#include <products.h>

class tech : public products
{
protected:
    QString m_name;
    double m_price;
    QString m_type;
    QString m_feature;

public:
    tech(QString name, QString price, QString type, QString feature)
    {
        m_name = name;
        m_price = price.toDouble();
        m_type = type;
        m_feature = feature;
    }

    virtual QString getName() const
    {
        return m_name;
    }

    virtual double getPrice() const
    {
        return m_price;
    }

    QString getAttribute() const
    {
        return m_feature;
    }

    QString getType() const
    {
        return m_type;
    }

    virtual ~tech();

};

#endif // TECH_H
