#ifndef DDD_H
#define DDD_H

#include <QDeclarativeItem>
#include <QQuickItem>
#include <QSharedDataPointer>

class dddData;

class ddd : public QPushButton
{
public:
    ddd();
    ddd(const ddd &);
    ddd &operator=(const ddd &);
    ~ddd();

private:
    QSharedDataPointer<dddData> data;
};

#endif // DDD_H
