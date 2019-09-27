#include "bundlebuilder.h"

bundle* BundleBuilder::returnObject(QString line)
{

    entryList = line.split(',');
    for(int i = 2; i < entryList.size(); ++i)
    {
        name_list.push_back(entryList[i]);
    }
    QString save = calcSavings(name_list,entryList[1]);
    bundle* b_entry = new bundle(entryList[0],entryList[1],save);
    name_list.clear();
    return b_entry;

}

QString BundleBuilder::calcSavings(vector<QString> prods, QString price) const
{
    double price2 = price.toDouble();
    double price_tot = 0;
    for (unsigned i = 0; i < prods.size(); i++)
    {
        for (unsigned j = 0; j < database.size(); j++)
        {
            if (prods[i] == database[j]->getName())
            {
                price_tot += database[j]->getPrice();
            }
        }
    }

    double final = 100 * (1-(price2/price_tot));
    int teger = round(final);
    QString conv = QString::number(teger) + "%";
    return conv;
}
