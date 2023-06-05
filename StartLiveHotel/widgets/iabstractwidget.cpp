#include "iabstractwidget.h"

#include <QtGui/qevent.h>

IAbstractWidget::IAbstractWidget(QWidget *parent)
    : QWidget(parent)
{

}

IAbstractWidget::~IAbstractWidget()
{

}

bool IAbstractWidget::setupUi()
{
    bool result = true;
    //检测内存分配是否成功
    result = instance();
    if (!result)
    {
        return result;
    }

    //设置文本
    retranslateUi();
    //布局
    layout();
    //关联信号槽
    connect();
    //设置对象名
    objectNameSetting();
    //装饰界面
    decorate();

    return result;
}

void IAbstractWidget::changeEvent(QEvent *pEvent)
{
    if (pEvent->type() == QEvent::LanguageChange)
        this->retranslateUi();

    QWidget::changeEvent(pEvent);
}
