/*
 * 文件：iroomdal.h
 * 描述：客房数据访问对象
 * 创建者：start-live
 * 时间：2023年06月06日
*/

#ifndef IROOMDAL_H
#define IROOMDAL_H

#include "iabstractdal.h"

class IRoomDAL : public IAbstractDAL
{
    Q_OBJECT
public:
    explicit IRoomDAL(QObject *parent = nullptr);
    virtual ~IRoomDAL();

    virtual void addData(const IDataSerialize& data) override;
    virtual void deleteData(const IDataSerialize& data) override;
    virtual void update(const IDataSerialize& data) override;
    virtual void getData(const IDataSerialize& data) override;
    virtual void getDatas(const QString& condition, qint32 page, qint32 pageSize) override;

signals:

};

#endif // IROOMDAL_H
