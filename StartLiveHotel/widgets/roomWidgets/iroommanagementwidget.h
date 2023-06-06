/*
 * 文件：iroommanagementwidget.h
 * 描述：客房管理界面
 * 创建者：start-live
 * 时间：2023年06月06日
*/

#ifndef IROOMMANAGEMENTWIDGET_H
#define IROOMMANAGEMENTWIDGET_H

#include "widgets/iabstractwidget.h"

class QVBoxLayout;
class QLabel;
class IDataTableWidget;

class IRoomManagementWidget : public IAbstractWidget
{
    Q_OBJECT
public:
    explicit IRoomManagementWidget(QWidget *parent = nullptr);
    virtual ~IRoomManagementWidget();

protected:
    void initTable();

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

private:
    QVBoxLayout* m_pMainLayout;
    QLabel* m_pTitleLabel;
    IDataTableWidget* m_pTableWidget;
};

#endif // IROOMMANAGEMENTWIDGET_H
