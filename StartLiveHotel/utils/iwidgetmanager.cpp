#include "iwidgetmanager.h"

#include <QtWidgets/qwidget.h>

IWidgetManager &IWidgetManager::manager()
{
    static IWidgetManager instance;
    return instance;
}

bool IWidgetManager::addWidget(const QString &key, QWidget *pWidget)
{
    QWidget* pOriginalWidget = m_widgetMap[key];
    if (pOriginalWidget != nullptr)
        return false;

    m_widgetMap[key] = pWidget;
    return true;
}

bool IWidgetManager::removeWidget(const QString &key)
{
    QWidget* pOriginalWidget = m_widgetMap[key];
    if (pOriginalWidget == nullptr)
        return false;

    delete pOriginalWidget;
    m_widgetMap[key] = nullptr;
    return true;
}

bool IWidgetManager::removeWidget(QWidget *pWidget)
{
    auto keyValueItBegin = m_widgetMap.keyValueBegin();
    for (auto it = keyValueItBegin; it != m_widgetMap.keyValueEnd(); it++)
    {
        if ((*it).second == pWidget)
        {
            delete pWidget;
            (*it).second = nullptr;
            return true;
        }
    }

    return false;
}

QWidget *IWidgetManager::findWidget(const QString &key) const
{
    return m_widgetMap[key];
}

IWidgetManager::IWidgetManager(QObject *parent)
    : QObject(parent)
{

}
