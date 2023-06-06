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

class IAbstractDAL : public QObject
{
    Q_OBJECT
public:
    explicit IAbstractDAL(QObject *parent = nullptr);
    virtual ~IAbstractDAL();

    virtual void getDatas(const QString& condition, qint32 page, qint32 pageSize);

signals:
    void getDatasFinished(const QJsonObject& dataObject);

private slots:
    void onGetDatasFinished();

private:
    QNetworkAccessManager* m_pNetwordAccessManager;
};

#endif // IABSTRACTDAL_H
