#ifndef ITABLEOPERATIONWIDGET_H
#define ITABLEOPERATIONWIDGET_H

#include "widgets/iabstractwidget.h"

class QHBoxLayout;
class QPushButton;

class ITableOperationWidget : public IAbstractWidget
{
    Q_OBJECT
public:
    explicit ITableOperationWidget(QWidget *parent = nullptr);
    virtual ~ITableOperationWidget();

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
    void refresh();
    void add();
    void print();

private slots:
    void onRefreshButtonClicked();
    void onAddButtonClicked();
    void onPrintButtonClicked();

private:
    QHBoxLayout* m_pMainLayout;
    QPushButton* m_pRefreshButton;
    QPushButton* m_pAddButton;
    QPushButton* m_pPrintButton;
};

#endif // ITABLEOPERATIONWIDGET_H
