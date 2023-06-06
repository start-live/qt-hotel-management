#include "idataresult.h"

IDataResult::IDataResult(QObject *parent)
    : QObject(parent)
{

}

IDataResult::IDataResult(const IDataResult &other)
    : QObject(other.parent())
{
    m_code = other.m_code;
    m_message = other.m_message;
    m_data = other.m_data;
}

IDataResult &IDataResult::operator=(const IDataResult &other)
{
    if (this != &other)
    {
        m_code = other.m_code;
        m_message = other.m_message;
        m_data = other.m_data;
    }

    return *this;
}

IResultCode IDataResult::code() const
{
    return m_code;
}

void IDataResult::setCode(const IResultCode &code)
{
    m_code = code;
}

QString IDataResult::message() const
{
    return m_message;
}

void IDataResult::setMessage(const QString &message)
{
    m_message = message;
}

QVariant IDataResult::data() const
{
    return m_data;
}

void IDataResult::setData(const QVariant &data)
{
    m_data = data;
}
