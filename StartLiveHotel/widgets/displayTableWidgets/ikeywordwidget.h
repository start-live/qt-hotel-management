/*
 * 文件：ikeywordwidget.h
 * 描述：关键词输入组件
 * 创建者：start-live
 * 时间：2023年06月05日
*/

#ifndef IKEYWORDWIDGET_H
#define IKEYWORDWIDGET_H

#include "widgets/iabstractwidget.h"

class QHBoxLayout;
class QLabel;
class QLineEdit;
class QPushButton;

class IKeywordWidget : public IAbstractWidget
{
    Q_OBJECT
public:
    explicit IKeywordWidget(QWidget *parent = nullptr);
    virtual ~IKeywordWidget();

    QString keyword() const;

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
    void search(const QString& keyword);

private slots:
    void onKeywordLineEditReturnPressed();
    void onSearchButtonClicked();

private:
    QHBoxLayout* m_pMainLayout;
    QLabel* m_pKeywordLabel;
    QLineEdit* m_pKeywordLineEdit;
    QPushButton* m_pSearchButton;
};

#endif // IKEYWORDWIDGET_H
