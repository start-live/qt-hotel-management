/*
 * 文件：idataresult.h
 * 描述：数据操作组件，修改、删除、展示
 * 创建者：start-live
 * 时间：2023年06月06日
*/

#ifndef IDATAOPERATIONWIDGET_H
#define IDATAOPERATIONWIDGET_H

#include "widgets/iabstractwidget.h"

class QHBoxLayout;
class QPushButton;

class IDataOperationWidget : public IAbstractWidget
{
    Q_OBJECT
public:
    explicit IDataOperationWidget(QWidget *parent = nullptr);
    virtual ~IDataOperationWidget();

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
    void updateDate();
    void deleteData();
    void detailData();

private slots:
    void onUpdateButtonClicked();
    void onDeleteButtonClicked();
    void onDetailButtonClicked();

private:
    QHBoxLayout* m_pMainLayout;
    QPushButton* m_pUpdateButton;
    QPushButton* m_pDeleteButton;
    QPushButton* m_pDetailButton;
};

#endif // IDATAOPERATIONWIDGET_H
