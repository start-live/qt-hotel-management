#include "iabstractdal.h"

#include <QtCore/qdebug.h>

IAbstractDAL::IAbstractDAL(QObject *parent)
    : QObject(parent)
{
    m_pNetwordAccessManager = new QNetworkAccessManager(this);
}

IAbstractDAL::~IAbstractDAL()
{

}

void IAbstractDAL::getDatas(const QString &condition, qint32 page, qint32 pageSize)
{
    if (m_pNetwordAccessManager == nullptr)
        return;

    QString urlStr = QString("https://www.baidu.com/hotel?condition=%1&page=%2&pageSize=%3")
            .arg(condition, QString::number(page), QString::number(pageSize));
    QUrl url(urlStr);
    QNetworkRequest request(url);
    QNetworkReply* pReply = m_pNetwordAccessManager->get(request);
    connect(pReply, &QNetworkReply::finished, this, &IAbstractDAL::onGetDatasFinished);
}

void IAbstractDAL::onGetDatasFinished()
{
    QNetworkReply* pReply = qobject_cast<QNetworkReply*>(sender());
    QJsonObject dataObject;
    if (pReply->error() == QNetworkReply::NoError)
    {
        QByteArray data = pReply->readAll();
        QJsonDocument jsonDoc = QJsonDocument::fromBinaryData(data);
        if (jsonDoc.isEmpty())
            return;

        dataObject = jsonDoc.object();
    }
    else
    {
        QString errorString = pReply->errorString();
        dataObject.insert("error", errorString);
        qDebug() << errorString;
    }
    pReply->deleteLater();
    emit getDatasFinished(dataObject);
}
