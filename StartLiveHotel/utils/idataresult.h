/*
 * 文件：idataresult.h
 * 描述：数据操作结果
 * 创建者：start-live
 * 时间：2023年06月06日
*/

#ifndef IDATARESULT_H
#define IDATARESULT_H

#include <QtCore/qobject.h>
#include <QtCore/qvariant.h>

enum class IResultCode
{
    Node,
    Success,
    Fail
};

class IDataResult : public QObject
{
    Q_OBJECT
public:
    explicit IDataResult(QObject *parent = nullptr);
    IDataResult(const IDataResult& other);
    IDataResult& operator=(const IDataResult& other);

    IResultCode code() const;
    void setCode(const IResultCode &code);

    QString message() const;
    void setMessage(const QString &message);

    QVariant data() const;
    void setData(const QVariant &data);

private:
    IResultCode m_code;
    QString m_message;
    QVariant m_data;
};

#endif // IDATARESULT_H
