#include "idataserialize.h"

IDataSerialize::IDataSerialize(QObject *parent)
    : QObject(parent)
{

}

IDataSerialize::IDataSerialize(const IDataSerialize &other)
    : QObject(other.parent())
{
    m_dataMap = other.m_dataMap;
}

IDataSerialize &IDataSerialize::operator=(const IDataSerialize &other)
{
    m_dataMap = other.m_dataMap;
    return *this;
}

QVariant IDataSerialize::value(const QString &key) const
{
    return m_dataMap[key];
}

void IDataSerialize::setValue(const QString &key, const QVariant &value)
{
    m_dataMap[key] = value;
}

QList<QVariant> IDataSerialize::values() const
{
    return  m_dataMap.values();
}
