/*
 * 文件：ikeywordwidget.h
 * 描述：显示信息条数记录信息
 * 创建者：start-live
 * 时间：2023年06月05日
*/

#ifndef IDISPLAYINFOWIDGET_H
#define IDISPLAYINFOWIDGET_H

#include "widgets/iabstractwidget.h"

class QHBoxLayout;
class QLabel;

class IDisplayInfoWidget : public IAbstractWidget
{
    Q_OBJECT
public:
    explicit IDisplayInfoWidget(QWidget *parent = nullptr);
    virtual ~IDisplayInfoWidget();

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

private:
    QHBoxLayout* m_pMainLayout;
    QLabel* m_pTotalLeftLabel;//总记录12条，当前显示12-23条
    QLabel* m_pTotalLabel;
    QLabel* m_pTotalRightLabel;
    QLabel* m_pCenterLabel;
    QLabel* m_pCurrentLeftLabel;
    QLabel* m_pCurrentFirstLabel;
    QLabel* m_pCurrentPointLabel;
    QLabel* m_pCurrentLastLabel;
    QLabel* m_pCurrentRightLabel;
};

#endif // IDISPLAYINFOWIDGET_H
