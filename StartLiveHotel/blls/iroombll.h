#ifndef IROOMBLL_H
#define IROOMBLL_H

#include "iabstractbll.h"

class IRoomBLL : public IAbstractBLL
{
    Q_OBJECT
public:
    explicit IRoomBLL(QObject *parent = nullptr);
    virtual ~IRoomBLL();

    virtual void addData(const IDataSerialize& data) override;
    virtual void deleteData(const IDataSerialize& data)override;
    virtual void update(const IDataSerialize& data) override;
    virtual void getData(const IDataSerialize& data) override;

signals:

};

#endif // IROOMBLL_H
