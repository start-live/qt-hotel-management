/*
 * 文件：itablestatusbar.h
 * 描述：表格状态栏，状态包括显示记录条数、当前页数、总页数、页码跳转
 * 创建者：start-live
 * 时间：2023年06月05日
*/

#ifndef ITABLESTATUSBAR_H
#define ITABLESTATUSBAR_H

#include "iabstractwidget.h"

class QHBoxLayout;
class QSpacerItem;
class QLabel;
class QComboBox;
class QPushButton;
class QSpinBox;
class IRangeRecordWidget;

class ITableStatusBar : public IAbstractWidget
{
    Q_OBJECT
public:
    explicit ITableStatusBar(QWidget *parent = nullptr);
    virtual ~ITableStatusBar();

    qint32 page() const;
    void setPage(qint32 page);

    qint32 pageSize() const;
    void setPageSize(qint32 size);

    qint32 totalPage() const;
    void setTotalPage(qint32 totalPage);

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
    void pageChanged(qint32 page, qint32 pageSize);

private slots:
    void onPageSizeComboBoxCurrentIndexChanged(const QString& text);
    void onFirstButtonClicked();
    void onPreviousButtonClicked();
    void onNextButtonClicked();
    void onLastButtonClicked();
    void onJumpButtonClicked();

private:
    QHBoxLayout* m_pMainLayout;
    QLabel* m_pPageSizeLeftLabel;
    QComboBox* m_pPageSizeComboBox;
    QLabel* m_pPageSizeRightLabel;
    QSpacerItem* m_pLeftHorizontalSpacer;
    QPushButton* m_pFirstButton;
    QPushButton* m_pPreviousButton;
    IRangeRecordWidget* m_pRangeRecordWidget;
    QPushButton* m_pNextButton;
    QPushButton* m_pLastButton;
    QSpacerItem* m_pRightHorizontalSpacer;
    QLabel* m_pJumpToLabel;
    QSpinBox* m_pJumpPageSpinBox;
    QPushButton* m_pJumpButton;
};

#endif // ITABLESTATUSBAR_H
