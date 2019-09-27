#ifndef VISITOR_H
#define VISITOR_H

class ProTable;

class visitor
{
public:

    virtual void visitTable(const ProTable*)=0;
    virtual ~visitor();

};

#endif // VISITOR_H
