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

QNetworkAccessManager *IAbstractDAL::manager() const
{
    return m_pNetwordAccessManager;
}

void IAbstractDAL::onAddDataFinished()
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
    emit addDataFinished(dataObject);
}

void IAbstractDAL::onDeleteDataFinished()
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
    emit deleteDataFinished(dataObject);
}

void IAbstractDAL::onUpdateDataFinished()
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
    emit updateDataFinished(dataObject);
}

void IAbstractDAL::onGetDataFinished()
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
    emit getDataFinished(dataObject);
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
