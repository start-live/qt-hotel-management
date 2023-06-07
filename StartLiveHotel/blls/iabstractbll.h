/*
 * 文件：iabstractbll.h
 * 描述：业务逻辑层抽象类，处理页面数据数据获取逻辑
 * 创建者：start-live
 * 时间：2023年06月06日
*/

#ifndef IABSTRACTBLL_H
#define IABSTRACTBLL_H

#include <QtCore/qobject.h>
#include <QtCore/qjsonobject.h>
#include <QtCore/qjsonvalue.h>
#include <QtCore/qjsonarray.h>
#include <QtCore/qjsondocument.h>

class IDataSerialize;
class IDataResult;
class IAbstractDAL;

class IAbstractBLL : public QObject
{
    Q_OBJECT
public:
    explicit IAbstractBLL(QObject *parent = nullptr);
    virtual ~IAbstractBLL();

    IAbstractDAL* dataDAL() const;
    void setDataDAL(IAbstractDAL* pDAL);

    QStringList keyList() const;
    void setKeyList(const QStringList& keyList);

    QString searchCondition(const QString& keyword, const QList<qint32>& modeList) const;
    virtual QString columnCondition(qint32 column, const QString& keyword) const;

    virtual void addData(const IDataSerialize& data) = 0;
    virtual void deleteData(const IDataSerialize& data) = 0;
    virtual void update(const IDataSerialize& data) = 0;
    virtual void getData(const IDataSerialize& data) = 0;
    virtual void getDatas(const QString& keyword
                          , const QList<qint32>& modeList
                          , qint32 page
                          , qint32 pageSize);

signals:
    void addDataFinished(const IDataResult& result);
    void deleteDataFinished(const IDataResult& result);
    void updateDataFinished(const IDataResult& result);
    void getDataFinished(const IDataResult& result);
    void getDatasFinished(const IDataResult& result);

private slots:
    void onDALAddDataFinished(const QJsonObject& dataObject);
    void onDALDeleteDataFinished(const QJsonObject& dataObject);
    void onDALUpdateDataFinished(const QJsonObject& dataObject);
    void onDALGetDataFinished(const QJsonObject& dataObject);
    void onDALGetDatasFinished(const QJsonObject& dataObject);

private:
    IAbstractDAL* m_pDataDAL;
    QStringList m_keyList;
};

#endif // IABSTRACTBLL_H
