/*
 * 文件：iabstractdal.h
 * 描述：数据访问层抽象类
 * 创建者：start-live
 * 时间：2023年06月06日
*/

#ifndef IABSTRACTDAL_H
#define IABSTRACTDAL_H

#include <QtCore/qobject.h>
#include <QtCore/qvariant.h>
#include <QtCore/qjsonobject.h>
#include <QtCore/qjsonvalue.h>
#include <QtCore/qjsonarray.h>
#include <QtCore/qjsondocument.h>

#include <QtNetwork/qnetworkaccessmanager.h>
#include <QtNetwork/qnetworkreply.h>
#include <QtNetwork/qnetworkrequest.h>

class IDataResult;
class IDataSerialize;

class IAbstractDAL : public QObject
{
    Q_OBJECT
public:
    explicit IAbstractDAL(QObject *parent = nullptr);
    virtual ~IAbstractDAL();

    QNetworkAccessManager* manager() const;

    virtual void addData(const IDataSerialize& data) = 0;
    virtual void deleteData(const IDataSerialize& data) = 0;
    virtual void update(const IDataSerialize& data) = 0;
    virtual void getData(const IDataSerialize& data) = 0;
    virtual void getDatas(const QString& condition, qint32 page, qint32 pageSize) = 0;

signals:
    void addDataFinished(const QJsonObject& result);
    void deleteDataFinished(const QJsonObject& result);
    void updateDataFinished(const QJsonObject& result);
    void getDataFinished(const QJsonObject& result);
    void getDatasFinished(const QJsonObject& dataObject);

protected slots:
    void onAddDataFinished();
    void onDeleteDataFinished();
    void onUpdateDataFinished();
    void onGetDataFinished();
    void onGetDatasFinished();

private:
    QNetworkAccessManager* m_pNetwordAccessManager;
};

#endif // IABSTRACTDAL_H
