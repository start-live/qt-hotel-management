/*
 * 文件：itablestatusbar.h
 * 描述：查找方式组件，按一列或者多列进行查找，拼接查找条件
 * 创建者：start-live
 * 时间：2023年06月06日
*/

#ifndef ISEARCHMODEWIDGET_H
#define ISEARCHMODEWIDGET_H

#include "widgets/iabstractwidget.h"

class QHBoxLayout;
class QSpacerItem;
class QLabel;
class QCheckBox;

class ISearchModeWidget : public IAbstractWidget
{
    Q_OBJECT
public:
    explicit ISearchModeWidget(QWidget *parent = nullptr);
    virtual ~ISearchModeWidget();

    QStringList modeNameList() const;
    void setModeNameList(const QStringList& modeNameList);

    QList<qint32> modeList() const;

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
    void modeChanged(const QList<qint32> &modeList);

private slots:
    void onCheckBoxClicked();

private:
    QHBoxLayout* m_pMainLayout;
    QLabel* m_pModeLabel;
    QCheckBox* m_pAllCheck;
    QSpacerItem* m_pRightHorizontalSpacer;

private:
    QList<QCheckBox*> m_modeCheckBoxList;
    QList<QString> m_modeNameList;
    QList<qint32> m_modeList;
};

#endif // ISEARCHMODEWIDGET_H
