#ifndef IROOMDAL_H
#define IROOMDAL_H

#include "iabstractdal.h"

class IRoomDAL : public IAbstractDAL
{
    Q_OBJECT
public:
    explicit IRoomDAL(QObject *parent = nullptr);
    virtual ~IRoomDAL();

signals:


};

#endif // IROOMDAL_H
