#include "techbuilder.h"

tech* TechBuilder::returnObject(QString line)
{
    entryList = line.split(',');
    tech* entry =  new tech(entryList[1],entryList[4],entryList[0],entryList[5]);
    return entry;
}

