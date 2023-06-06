#include "iroommanagementwidget.h"

#include <QtWidgets/qboxlayout.h>
#include <QtWidgets/qlabel.h>

#include "widgets/displayTableWidgets/idatatablewidget.h"

#include "blls/iroombll.h"

IRoomManagementWidget::IRoomManagementWidget(QWidget *parent)
    : IAbstractWidget(parent)
{
    m_pMainLayout = nullptr;
    m_pTitleLabel = nullptr;
    m_pTableWidget = nullptr;

    //初始化界面
    this->setupUi();
    this->initTable();
}

IRoomManagementWidget::~IRoomManagementWidget()
{

}

void IRoomManagementWidget::initTable()
{
    if (m_pMainLayout == nullptr)
        return;

    //设置数据键
    QStringList keyList;
    keyList << "roomNumber";
    keyList << "type";
    keyList << "storePrice";
    keyList << "vipPrice";
    keyList << "deposit";
    keyList << "status";
    m_pTableWidget->setKeyList(keyList);

    //设置业务逻辑对象
    IRoomBLL* pRoomBLL = new IRoomBLL(this);
    m_pTableWidget->setDataBLL(pRoomBLL);

    //刷新界面数据
    m_pTableWidget->refreshData();
}

bool IRoomManagementWidget::instance()
{
    I_INSTANCE(m_pMainLayout, QVBoxLayout, nullptr);
    I_INSTANCE(m_pTitleLabel, QLabel, this);
    I_INSTANCE(m_pTableWidget, IDataTableWidget, this);

    return true;
}

bool IRoomManagementWidget::retranslateUi()
{
    if (m_pMainLayout == nullptr)
        return false;

    m_pTitleLabel->setText(this->tr("客房管理"));

    //房间号 类型 门市价格 会员价格 押金 状态
    QStringList modeNameList;
    modeNameList << this->tr("房间号");
    modeNameList << this->tr("类型");
    modeNameList << this->tr("门市价格");
    modeNameList << this->tr("会员价格");
    modeNameList << this->tr("押金");
    modeNameList << this->tr("状态");
    m_pTableWidget->setModeNameList(modeNameList);

    QStringList columnNameList = modeNameList;
    columnNameList << this->tr("操作");
    m_pTableWidget->setTableColumnNameList(columnNameList);

    return true;
}

void IRoomManagementWidget::layout()
{
    m_pMainLayout->addWidget(m_pTitleLabel);
    m_pMainLayout->addWidget(m_pTableWidget);
    this->setLayout(m_pMainLayout);
}

bool IRoomManagementWidget::connect()
{
    return true;
}

void IRoomManagementWidget::objectNameSetting()
{
    m_pMainLayout->setObjectName("MainLayout");
    m_pTitleLabel->setObjectName("TitleLabel");
    m_pTableWidget->setObjectName("TableWidget");
}

bool IRoomManagementWidget::decorate()
{
//    m_pMainLayout = nullptr;
//    m_pTitleLabel = nullptr;
//    m_pTableWidget = nullptr;

    this->setAttribute(Qt::WA_StyledBackground);

    return true;
}

void IRoomManagementWidget::release()
{
    I_RELEASE(m_pMainLayout);
    I_RELEASE(m_pTitleLabel);
    I_RELEASE(m_pTableWidget);
}
