#include "itableoperationwidget.h"

#include <QtWidgets/qboxlayout.h>
#include <QtWidgets/qpushbutton.h>

ITableOperationWidget::ITableOperationWidget(QWidget *parent)
    : IAbstractWidget(parent)
{
    m_pMainLayout = nullptr;
    m_pRefreshButton = nullptr;
    m_pAddButton = nullptr;
    m_pPrintButton = nullptr;

    //初始化界面
    this->setupUi();
}

ITableOperationWidget::~ITableOperationWidget()
{

}

bool ITableOperationWidget::instance()
{
    I_INSTANCE(m_pMainLayout, QHBoxLayout, nullptr);
    I_INSTANCE(m_pRefreshButton, QPushButton, this);
    I_INSTANCE(m_pAddButton, QPushButton, this);
    I_INSTANCE(m_pPrintButton, QPushButton, this);

    return true;
}

bool ITableOperationWidget::retranslateUi()
{
    if (m_pMainLayout == nullptr)
        return false;

    m_pRefreshButton->setText(this->tr("刷新"));
    m_pAddButton->setText(this->tr("添加"));
    m_pPrintButton->setText(this->tr("打印"));

    return true;
}

void ITableOperationWidget::layout()
{
    m_pMainLayout->addWidget(m_pRefreshButton);
    m_pMainLayout->addWidget(m_pAddButton);
    m_pMainLayout->addWidget(m_pPrintButton);
    this->setLayout(m_pMainLayout);
}

bool ITableOperationWidget::connect()
{
    QMetaObject::Connection connection;
    bool result = true;

    connection = QObject::connect(m_pRefreshButton, SIGNAL(clicked())
                                  , this, SLOT(onRefreshButtonClicked()));
    result &= bool(connection);

    connection = QObject::connect(m_pAddButton, SIGNAL(clicked())
                                  , this, SLOT(onAddButtonClicked()));
    result &= bool(connection);

    connection = QObject::connect(m_pPrintButton, SIGNAL(clicked())
                                  , this, SLOT(onPrintButtonClicked()));
    result &= bool(connection);

    return  result;
}

void ITableOperationWidget::objectNameSetting()
{
    m_pMainLayout->setObjectName("MainLayout");
    m_pRefreshButton->setObjectName("RefreshButton");
    m_pAddButton->setObjectName("AddButton");
    m_pPrintButton->setObjectName("PrintButton");
    this->setObjectName("TableOperationWidget");
}

bool ITableOperationWidget::decorate()
{
//    m_pMainLayout = nullptr;
//    m_pRefreshButton = nullptr;
//    m_pAddButton = nullptr;
//    m_pPrintButton = nullptr;

    this->setAttribute(Qt::WidgetAttribute::WA_StyledBackground);

    return true;
}

void ITableOperationWidget::release()
{
    I_RELEASE(m_pMainLayout);
    I_RELEASE(m_pRefreshButton);
    I_RELEASE(m_pAddButton);
    I_RELEASE(m_pPrintButton);
}

void ITableOperationWidget::onRefreshButtonClicked()
{
    emit refresh();
}

void ITableOperationWidget::onAddButtonClicked()
{
    emit add();
}

void ITableOperationWidget::onPrintButtonClicked()
{
    emit print();
}
