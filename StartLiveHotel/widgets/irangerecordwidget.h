/*
 * 文件：itablestatusbar.h
 * 描述：范围记录组件，显示当前值和总值
 * 创建者：start-live
 * 时间：2023年06月05日
*/

#ifndef IRANGERECORDWIDGET_H
#define IRANGERECORDWIDGET_H

#include "iabstractwidget.h"

class QHBoxLayout;
class QLabel;

class IRangeRecordWidget : public IAbstractWidget
{
    Q_OBJECT
public:
    explicit IRangeRecordWidget(QWidget *parent = nullptr);
    virtual ~IRangeRecordWidget();

    qint32 currentValue() const;
    void setCurrentValue(qint32 value);

    qint32 totalValue() const;
    void setTotalValue(qint32 value);

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
    QLabel* m_pCurrentValueLabel;
    QLabel* m_pLsolationLineLabel;
    QLabel* m_pTotalValueLabel;
};

#endif // IRANGERECORDWIDGET_H
