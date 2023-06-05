/*
 * 文件：imainwidget.h
 * 描述：程序主界面，整个程序的入口实现
 * 创建者：start-live
 * 时间：2023年06月05日
*/

#ifndef IMAINWIDGET_H
#define IMAINWIDGET_H

#include "widgets/iabstractwidget.h"

class IMainWidget : public IAbstractWidget
{
    Q_OBJECT

public:
    explicit IMainWidget(QWidget *parent = nullptr);
    virtual ~IMainWidget();

protected:
    //分配内存
    virtual bool instance() override;
    //设置文本
    virtual bool retranslateUi() override;
    //设置布局
    virtual void layout() override;
    //关联信号与槽
    virtual bool connect() override;
    //设置对象名，为qss的编写做准备
    virtual void objectNameSetting() override;
    //装饰，设置无法通过qss进行设置的属性
    virtual bool decorate() override;
    //如果内存分配失败，则对部分已经分配过内存的控件进行释放
    virtual void release() override;
};

#endif // IMAINWIDGET_H
