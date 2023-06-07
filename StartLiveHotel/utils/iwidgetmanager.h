/*
 * 文件：iwidgetmanager.h
 * 描述：界面管理器
 * 创建者：start-live
 * 时间：2023年06月07日
*/

#ifndef IWIDGETMANAGER_H
#define IWIDGETMANAGER_H

#include <QtCore/qobject.h>
#include <QtCore/qmap.h>

class IWidgetManager : public QObject
{
    Q_OBJECT
public:
    static IWidgetManager& manager();
    bool addWidget(const QString& key, QWidget* pWidget);
    bool removeWidget(const QString& key);
    QWidget* findWidget(const QString& key) const;

private:
    explicit IWidgetManager(QObject *parent = nullptr);
    Q_DISABLE_COPY(IWidgetManager);

signals:
    void addNewWidget(QWidget* pWidget, const QString& title);
    void showCurrentWidget(QWidget* pWidget);
    void changedWidgetTitle(QWidget* pWidget, const QString& title);

private:
    QMap<QString, QWidget*> m_widgetMap;
};

#endif // IWIDGETMANAGER_H
