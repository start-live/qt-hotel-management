/*
 * 文件：idisplaywidget.h
 * 描述：所有界面的展示管理
 * 创建者：start-live
 * 时间：2023年06月07日
*/

#ifndef IDISPLAYWIDGET_H
#define IDISPLAYWIDGET_H

#include "widgets/iabstractwidget.h"

class QVBoxLayout;
class ITitleWidget;
class QTabWidget;

class IDisplayWidget : public IAbstractWidget
{
    Q_OBJECT
public:
    explicit IDisplayWidget(QWidget *parent = nullptr);
    virtual ~IDisplayWidget();

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

signals:

private slots:


private:
    QVBoxLayout* m_pMainLayout;
    ITitleWidget* m_pTitleWidget;
    QTabWidget* m_pTabWidget;
};

#endif // IDISPLAYWIDGET_H
