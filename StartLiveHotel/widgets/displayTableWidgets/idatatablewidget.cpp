﻿#include "idatatablewidget.h"

#include <QtWidgets/qboxlayout.h>
#include <QtWidgets/qlayoutitem.h>
#include <QtWidgets/qtableview.h>

#include "widgets/displayTableWidgets/ikeywordwidget.h"
#include "widgets/displayTableWidgets/isearchmodewidget.h"
#include "widgets/displayTableWidgets/idisplayinfowidget.h"
#include "widgets/displayTableWidgets/itableoperationwidget.h"
#include "widgets/displayTableWidgets/itablestatusbar.h"

IDataTableWidget::IDataTableWidget(QWidget *parent)
    : IAbstractWidget(parent)
{
    m_pMainLayout = nullptr;
    m_pKeywordWidget = nullptr;
    m_pSearchModeWidget = nullptr;
    m_pOperationLayout = nullptr;
    m_pDisplayInfoWidget = nullptr;
    m_pCenterSpacer = nullptr;
    m_pTableOperationWidget = nullptr;
    m_pTableView = nullptr;
    m_pTableStatusBar = nullptr;

    //初始化界面
    this->setupUi();
}

IDataTableWidget::~IDataTableWidget()
{

}

bool IDataTableWidget::instance()
{
    I_INSTANCE(m_pMainLayout, QVBoxLayout, nullptr);
    I_INSTANCE(m_pKeywordWidget, IKeywordWidget, this);
    I_INSTANCE(m_pSearchModeWidget, ISearchModeWidget, this);
    I_INSTANCE(m_pOperationLayout, QHBoxLayout, nullptr);
    I_INSTANCE(m_pDisplayInfoWidget, IDisplayInfoWidget, this);

    m_pCenterSpacer = new QSpacerItem(40, 20);
    if (m_pCenterSpacer == nullptr)
        return false;

    I_INSTANCE(m_pTableOperationWidget, ITableOperationWidget, this);
    I_INSTANCE(m_pTableView, QTableView, this);
    I_INSTANCE(m_pTableStatusBar, ITableStatusBar, this);

    return true;
}

bool IDataTableWidget::retranslateUi()
{
    if (m_pMainLayout == nullptr)
        return false;

//    m_pKeywordWidget = nullptr;
    //m_pSearchModeWidget
//    m_pOperationLayout = nullptr;
//    m_pDisplayInfoWidget = nullptr;
//    m_pTableOperationWidget = nullptr;
//    m_pTableView = nullptr;
//    m_pTableStatusBar = nullptr;

    return true;
}

void IDataTableWidget::layout()
{
    m_pOperationLayout->addWidget(m_pDisplayInfoWidget);
    m_pOperationLayout->addItem(m_pCenterSpacer);
    m_pOperationLayout->addWidget(m_pTableOperationWidget);

    m_pMainLayout->addWidget(m_pKeywordWidget);
    m_pMainLayout->addWidget(m_pSearchModeWidget);
    m_pMainLayout->addLayout(m_pOperationLayout);
    m_pMainLayout->addWidget(m_pTableView);
    m_pMainLayout->addWidget(m_pTableStatusBar);
    this->setLayout(m_pMainLayout);
}

bool IDataTableWidget::connect()
{
    QMetaObject::Connection connection;
    bool result = true;

    connection = QObject::connect(m_pKeywordWidget, SIGNAL(search(const QString&))
                                  , this, SLOT(onKeywordWidgetSearch(const QString&)));
    result &= bool(connection);

    connection = QObject::connect(m_pSearchModeWidget, SIGNAL(modeChanged(const QList<qint32>&))
                                  , this, SLOT(onSearchModeWidgetModeChanged(const QList<qint32>&)));
    result &= bool(connection);

    connection = QObject::connect(m_pSearchModeWidget, SIGNAL(refresh())
                                  , this, SLOT(onTableOperationWidgetRefresh()));
    result &= bool(connection);

    connection = QObject::connect(m_pSearchModeWidget, SIGNAL(add())
                                  , this, SLOT(onTableOperationWidgetAdd()));
    result &= bool(connection);

    connection = QObject::connect(m_pSearchModeWidget, SIGNAL(print())
                                  , this, SLOT(onTableOperationWidgetPrint()));
    result &= bool(connection);

//    m_pTableView = nullptr;

    connection = QObject::connect(m_pTableStatusBar, SIGNAL(pageChanged(qint32, qint32))
                                  , this, SLOT(onTableStatusBarPageChanged(qint32, qint32)));
    result &= bool(connection);

    return result;
}

void IDataTableWidget::objectNameSetting()
{
    m_pMainLayout->setObjectName("MainLayout");
    m_pKeywordWidget->setObjectName("KeywordWidget");
    m_pSearchModeWidget->setObjectName("SearchModeWidget");
    m_pOperationLayout->setObjectName("OperationLayout");
    m_pDisplayInfoWidget->setObjectName("DisplayInfoWidget");
    m_pTableOperationWidget->setObjectName("TableOperationWidget");
    m_pTableView->setObjectName("TableView");
    m_pTableStatusBar->setObjectName("TableStatusBar");
    this->setObjectName("DataTableWidget");
}

bool IDataTableWidget::decorate()
{
//    m_pMainLayout = nullptr;
//    m_pKeywordWidget = nullptr;
    //m_pSearchModeWidget
//    m_pOperationLayout = nullptr;
//    m_pDisplayInfoWidget = nullptr;

    m_pCenterSpacer->changeSize(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

//    m_pTableOperationWidget = nullptr;
//    m_pTableView = nullptr;
//    m_pTableStatusBar = nullptr;

    this->setAttribute(Qt::WidgetAttribute::WA_StyledBackground);

    return true;
}

void IDataTableWidget::release()
{
    I_RELEASE(m_pMainLayout);
    I_RELEASE(m_pKeywordWidget);
    I_RELEASE(m_pSearchModeWidget);
    I_RELEASE(m_pOperationLayout);
    I_RELEASE(m_pDisplayInfoWidget);
    I_RELEASE(m_pCenterSpacer);
    I_RELEASE(m_pTableOperationWidget);
    I_RELEASE(m_pTableView);
    I_RELEASE(m_pTableStatusBar);
}

void IDataTableWidget::onKeywordWidgetSearch(const QString &keyword)
{
    Q_UNUSED(keyword);
}

void IDataTableWidget::onSearchModeWidgetModeChanged(const QList<qint32> &modeList)
{
    Q_UNUSED(modeList);
}

void IDataTableWidget::onTableOperationWidgetRefresh()
{

}

void IDataTableWidget::onTableOperationWidgetAdd()
{

}

void IDataTableWidget::onTableOperationWidgetPrint()
{

}

void IDataTableWidget::onTableStatusBarPageChanged(qint32 page, qint32 pageSize)
{
    Q_UNUSED(page);
    Q_UNUSED(pageSize);
}
