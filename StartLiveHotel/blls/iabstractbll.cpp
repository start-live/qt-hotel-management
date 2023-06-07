#include "iabstractbll.h"

#include "utils/idataresult.h"
#include "utils/idataserialize.h"

#include "dals/iabstractdal.h"

IAbstractBLL::IAbstractBLL(QObject *parent)
    : QObject(parent)
    , m_pDataDAL(nullptr)
{

}

IAbstractBLL::~IAbstractBLL()
{

}

IAbstractDAL *IAbstractBLL::dataDAL() const
{
    return m_pDataDAL;
}

void IAbstractBLL::setDataDAL(IAbstractDAL *pDAL)
{
    m_pDataDAL = pDAL;
}

QStringList IAbstractBLL::keyList() const
{
    return m_keyList;
}

void IAbstractBLL::setKeyList(const QStringList &keyList)
{
    m_keyList = keyList;
}

QString IAbstractBLL::searchCondition(const QString& keyword, const QList<qint32>& modeList) const
{
    if (keyword.isEmpty())
            return "TRUE";

        QString condition = "FALSE";
        qint32 count = m_keyList.count();
        for (qint32 index = 0;index < count;index++)
        {
            if (modeList.contains(index))
            {
                condition += " OR (" + columnCondition(index, keyword) + ")";
            }
        }

        return condition;
}

QString IAbstractBLL::columnCondition(qint32 column, const QString &keyword) const
{
    return m_keyList[column] + " LIKE '%" + keyword + "%'";
}

void IAbstractBLL::getDatas(const QString &keyword
                            , const QList<qint32> &modeList
                            , qint32 page
                            , qint32 pageSize)
{
    if (m_pDataDAL == nullptr)
    {
        IDataResult res;
        res.setCode(IResultCode::Fail);
        res.setMessage(this->tr("无法进行数据访问！"));
        emit getDatasFinished(res);
        return;
    }

    if (page < 1 || pageSize < 1)
    {
        IDataResult res;
        res.setCode(IResultCode::Fail);
        res.setMessage(this->tr("页数小于1或者页面条数小于1！"));
        emit getDatasFinished(res);
        return;
    }

    QString condition = searchCondition(keyword, modeList);
    m_pDataDAL->getDatas(condition, page, pageSize);
}

void IAbstractBLL::onDALAddDataFinished(const QJsonObject &dataObject)
{
    IDataResult result;
    qint32 code = dataObject.value("code").toInt();
    QString message = dataObject.value("message").toString();
    result.setCode(IResultCode(code));
    result.setMessage(message);
    emit addDataFinished(result);
}

void IAbstractBLL::onDALDeleteDataFinished(const QJsonObject &dataObject)
{
    IDataResult result;
    qint32 code = dataObject.value("code").toInt();
    QString message = dataObject.value("message").toString();
    result.setCode(IResultCode(code));
    result.setMessage(message);
    emit deleteDataFinished(result);
}

void IAbstractBLL::onDALUpdateDataFinished(const QJsonObject &dataObject)
{
    IDataResult result;
    qint32 code = dataObject.value("code").toInt();
    QString message = dataObject.value("message").toString();
    result.setCode(IResultCode(code));
    result.setMessage(message);
    emit updateDataFinished(result);
}

void IAbstractBLL::onDALGetDataFinished(const QJsonObject &dataObject)
{
    IDataResult result;
    qint32 code = dataObject.value("code").toInt();
    QString message = dataObject.value("message").toString();
    QJsonObject valueObject = dataObject.value("data").toObject();
    IDataSerialize record;
    for (QString key : m_keyList)
    {
        record.setValue(key, valueObject.value(key).toVariant());
    }
    QVariant data;
    data.setValue(record);
    result.setCode(IResultCode(code));
    result.setMessage(message);
    result.setData(data);
    emit getDataFinished(result);
}

void IAbstractBLL::onDALGetDatasFinished(const QJsonObject &dataObject)
{
    IDataResult result;
    qint32 code = dataObject.value("code").toInt();
    QString message = dataObject.value("message").toString();
    QJsonArray dataArray = dataObject.value("data").toArray();
    QList<IDataSerialize> recordList;
    for (QJsonValue value : dataArray)
    {
        QJsonObject obj = value.toObject();
        IDataSerialize record;
        for (QString key : m_keyList)
        {
            record.setValue(key, obj.value(key).toVariant());
        }
        recordList.append(record);
    }
    QVariant data;
    data.setValue(recordList);
    result.setCode(IResultCode(code));
    result.setMessage(message);
    result.setData(data);
    emit getDatasFinished(result);
}
