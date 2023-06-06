#ifndef IABSTRACTBLL_H
#define IABSTRACTBLL_H

#include <QtCore/qobject.h>

class IDataSerialize;
class IDataResult;

class IAbstractBLL : public QObject
{
    Q_OBJECT
public:
    explicit IAbstractBLL(QObject *parent = nullptr);
    virtual ~IAbstractBLL();

    virtual void addData(const IDataSerialize& data) = 0;
    virtual void deleteData(const IDataSerialize& data) = 0;
    virtual void update(const IDataSerialize& data) = 0;
    virtual void getData(const QString& keyword) = 0;
    virtual void getDatas(const QString& keyword
                          , const QList<qint32>& modeList
                          , qint32 page
                          , qint32 pageSize) = 0;

signals:
    void addResult(const IDataResult& result);
    void deleteResult(const IDataResult& result);
    void updateResult(const IDataResult& result);
    void getResult(const IDataResult& result);
    void getDatasResult(const IDataResult& result);
};

#endif // IABSTRACTBLL_H
