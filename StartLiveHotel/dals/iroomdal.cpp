#include "iroomdal.h"

IRoomDAL::IRoomDAL(QObject *parent)
    : IAbstractDAL(parent)
{

}

IRoomDAL::~IRoomDAL()
{

}

void IRoomDAL::addData(const IDataSerialize &data)
{
    Q_UNUSED(data);
}

void IRoomDAL::deleteData(const IDataSerialize &data)
{
    Q_UNUSED(data);
}

void IRoomDAL::update(const IDataSerialize &data)
{
    Q_UNUSED(data);
}

void IRoomDAL::getData(const IDataSerialize &data)
{
    Q_UNUSED(data);
}

void IRoomDAL::getDatas(const QString &condition, qint32 page, qint32 pageSize)
{
    QNetworkAccessManager* pManager = manager();
    if (pManager == nullptr)
        return;

    QString urlStr = QString("https://www.baidu.com/#")
            .arg(condition, QString::number(page), QString::number(pageSize));
    QUrl url(urlStr);
    QNetworkRequest request(url);
    QNetworkReply* pReply = pManager->get(request);
    connect(pReply, &QNetworkReply::finished, this, &IRoomDAL::onGetDatasFinished);
}
