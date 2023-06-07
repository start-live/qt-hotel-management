#include "iroombll.h"

#include "utils/idataresult.h"
#include "utils/idataserialize.h"

#include "dals/iroomdal.h"

IRoomBLL::IRoomBLL(QObject *parent)
    : IAbstractBLL(parent)
{
    QStringList keyList;
    keyList << "roomNumber";
    keyList << "type";
    keyList << "storePrice";
    keyList << "vipPrice";
    keyList << "deposit";
    keyList << "status";
    IAbstractBLL::setKeyList(keyList);

    IRoomDAL* pRoomDAL = new IRoomDAL(this);
    IAbstractBLL::setDataDAL(pRoomDAL);
}

IRoomBLL::~IRoomBLL()
{

}

void IRoomBLL::addData(const IDataSerialize &data)
{
    IRoomDAL* pRoomDAL = dynamic_cast<IRoomDAL*>(dataDAL());
    if (pRoomDAL == nullptr)
        return;

    Q_UNUSED(data);
    //判断

    //pRoomDAL->addData();
    //todo

}

void IRoomBLL::deleteData(const IDataSerialize &data)
{
Q_UNUSED(data);
}

void IRoomBLL::update(const IDataSerialize &data)
{
Q_UNUSED(data);
}

void IRoomBLL::getData(const IDataSerialize& data)
{
    Q_UNUSED(data);
}
