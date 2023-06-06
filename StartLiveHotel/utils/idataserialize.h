/*
 * 文件：idataserialize.h
 * 描述：数据序列化器，数据以键值对存放
 * 创建者：start-live
 * 时间：2023年06月06日
*/

#ifndef IDATASERIALIZE_H
#define IDATASERIALIZE_H

#include <QtCore/qobject.h>
#include <QtCore/qmetatype.h>
#include <QtCore/qmap.h>
#include <QtCore/qvariant.h>

class IDataSerialize : public QObject
{
    Q_OBJECT
public:
    explicit IDataSerialize(QObject *parent = nullptr);
    IDataSerialize(const IDataSerialize& other);
    IDataSerialize& operator=(const IDataSerialize& other);

    QVariant value(const QString& key) const;
    void setValue(const QString& key, const QVariant& value);

    QList<QVariant> values() const;

private:
    QMap<QString, QVariant> m_dataMap;
};

//元对象注册
Q_DECLARE_METATYPE(IDataSerialize)
Q_DECLARE_METATYPE(QList<IDataSerialize>)

#endif // IDATASERIALIZE_H
