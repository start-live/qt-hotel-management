#include "imainwidget.h"

#include <QtGui/qevent.h>

#include <QtWidgets/qboxlayout.h>

#include "widgets/mainWidgets/ioperationmenubar.h"
#include "widgets/mainWidgets/idisplaywidget.h"

IMainWidget::IMainWidget(QWidget *parent)
    : IAbstractWidget(parent)
{
    m_pMainLayout = nullptr;
    m_pOperationMenuBar = nullptr;
    m_pDisplayWidget = nullptr;

    //初始化界面
    this->setupUi();
}

IMainWidget::~IMainWidget()
{
}

bool IMainWidget::instance()
{
    I_INSTANCE(m_pMainLayout, QHBoxLayout, nullptr);
    I_INSTANCE(m_pOperationMenuBar, IOperationMenuBar, this);
    I_INSTANCE(m_pDisplayWidget, IDisplayWidget, this);

    return true;
}

bool IMainWidget::retranslateUi()
{
    if (m_pMainLayout == nullptr)
        return false;

//    m_pMainLayout = nullptr;
//    m_pOperationMenuBar = nullptr;
//    m_pDisplayWidget = nullptr;

    return true;
}

void IMainWidget::layout()
{
    m_pMainLayout->addWidget(m_pOperationMenuBar);
    m_pMainLayout->addWidget(m_pDisplayWidget);
    this->setLayout(m_pMainLayout);
}

bool IMainWidget::connect()
{
    QMetaObject::Connection connection;
    bool result = true;

//    m_pMainLayout = nullptr;
//    m_pOperationMenuBar = nullptr;
//    m_pDisplayWidget = nullptr;

    return result;
}

void IMainWidget::objectNameSetting()
{
    m_pMainLayout->setObjectName("MainLayout");
    m_pOperationMenuBar->setObjectName("OperationMenuBar");
    m_pDisplayWidget->setObjectName("DisplayWidget");
    this->setObjectName("MainLayout");
}

bool IMainWidget::decorate()
{
//    m_pMainLayout = nullptr;
//    m_pOperationMenuBar = nullptr;
//    m_pDisplayWidget = nullptr;

    this->setAttribute(Qt::WidgetAttribute::WA_StyledBackground);

    return true;
}

void IMainWidget::release()
{
    I_RELEASE(m_pMainLayout);
    I_RELEASE(m_pOperationMenuBar);
    I_RELEASE(m_pDisplayWidget);
}
