/*
 * 文件：ioperationmenubar.h
 * 描述：左侧快捷操作菜单栏
 * 创建者：start-live
 * 时间：2023年06月07日
*/

#ifndef IOPERATIONMENUBAR_H
#define IOPERATIONMENUBAR_H

#include "widgets/iabstractwidget.h"

class QVBoxLayout;
class QLabel;
class QPushButton;
class QListWidget;

class IOperationMenuBar : public IAbstractWidget
{
    Q_OBJECT
public:
    explicit IOperationMenuBar(QWidget *parent = nullptr);
    virtual ~IOperationMenuBar();

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
    void onHomeButtonClicked();
    void onPersonalButtonClicked();
    //m_pOperationListWidget
    void onFeedbackButtonClicked();

private:
    QVBoxLayout* m_pMainLayout;
    QLabel* m_pTitleLabel;
    QPushButton* m_pHomeButton;
    QPushButton* m_pPersonalButton;
    QListWidget* m_pOperationListWidget;
    QPushButton* m_pFeedbackButton;
};

#endif // IOPERATIONMENUBAR_H
