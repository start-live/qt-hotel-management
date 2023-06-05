/*
 * 文件：iabstractwidget.h
 * 描述：抽象界面组件，实现监听语言改变事件，为实现国际化做准备
 * 创建者：start-live
 * 时间：2023年06月05日
*/

#ifndef IABSTRACTWIDGET_H
#define IABSTRACTWIDGET_H

#include <QtWidgets/qwidget.h>

class IAbstractWidget : public QWidget
{
    Q_OBJECT
public:
    explicit IAbstractWidget(QWidget *parent = nullptr);
    virtual ~IAbstractWidget();

    bool setupUi();

protected:
    //主要为实现国际化做准备，监听语言改变事件
    virtual void changeEvent(QEvent *pEvent) override;

    //以下方法由子类进行实现
    //分配内存
    virtual bool instance() = 0;
    //设置文本
    virtual bool retranslateUi() = 0;
    //设置布局
    virtual void layout() = 0;
    //关联信号与槽
    virtual bool connect() = 0;
    //设置对象名，为qss的编写做准备
    virtual void objectNameSetting() = 0;
    //装饰，设置无法通过qss进行设置的属性
    virtual bool decorate() = 0;
    //如果内存分配失败，则对部分已经分配过内存的控件进行释放
    virtual void release() = 0;
};

#endif // IABSTRACTWIDGET_H
