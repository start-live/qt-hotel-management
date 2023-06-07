/*
 * 文件：idatatablewidget.h
 * 描述：数据管理表格组件
 * 创建者：start-live
 * 时间：2023年06月05日
*/

#ifndef IDATATABLEWIDGET_H
#define IDATATABLEWIDGET_H

#include "widgets/iabstractwidget.h"

class QVBoxLayout;
class QHBoxLayout;
class QSpacerItem;
class IKeywordWidget;
class ISearchModeWidget;
class IDisplayInfoWidget;
class ITableOperationWidget;
class QTableView;
class ITableStatusBar;

class QStandardItemModel;
class IAbstractBLL;
class IDataSerialize;
class IDataResult;

class IDataTableWidget : public IAbstractWidget
{
    Q_OBJECT
public:
    explicit IDataTableWidget(QWidget *parent = nullptr);
    virtual ~IDataTableWidget();

    IAbstractBLL* pBLL() const;
    void setDataBLL(IAbstractBLL* pBLL);

    QStringList keyList() const;
    void setKeyList(const QStringList& keyList);

    void setModeNameList(const QStringList& modeNameList);
    void setTableColumnNameList(const QStringList& columnNameList);

    void refreshData();

protected:
    void refreshData(qint32 page, qint32 pageSize);
    void initModel();

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
    void onDataBLLGetDatasFinished(const IDataResult& result);
    void refreshRecords(const QList<IDataSerialize>& recordList);
    void onKeywordWidgetSearch(const QString& keyword);
    void onSearchModeWidgetModeChanged(const QList<qint32>& modeList);
    void onTableOperationWidgetRefresh();
    void onTableOperationWidgetAdd();
    void onTableOperationWidgetPrint();
    //    m_pTableView = nullptr;
    void onTableStatusBarPageChanged(qint32 page, qint32 pageSize);

private:
    QVBoxLayout* m_pMainLayout;
    IKeywordWidget* m_pKeywordWidget;
    ISearchModeWidget* m_pSearchModeWidget;
    QHBoxLayout* m_pOperationLayout;
    IDisplayInfoWidget* m_pDisplayInfoWidget;
    QSpacerItem* m_pCenterSpacer;
    ITableOperationWidget* m_pTableOperationWidget;
    QTableView* m_pTableView;
    ITableStatusBar* m_pTableStatusBar;

private:
    QStandardItemModel* m_pModel;
    IAbstractBLL* m_pDataBLL;
    QStringList m_keyList;
};

#endif // IDATATABLEWIDGET_H
