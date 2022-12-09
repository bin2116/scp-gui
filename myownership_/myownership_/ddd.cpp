#include "ddd.h"

class dddData : public QSharedData
{
public:

};

ddd::ddd() : data(new dddData)
{

}

ddd::ddd(const ddd &rhs) : data(rhs.data)
{

}

ddd &ddd::operator=(const ddd &rhs)
{
    if (this != &rhs)
        data.operator=(rhs.data);
    return *this;
}

ddd::~ddd()
{

}
