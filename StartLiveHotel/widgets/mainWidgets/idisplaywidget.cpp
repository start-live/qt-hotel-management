#include "idisplaywidget.h"

#include <QtWidgets/qboxlayout.h>
#include <QtWidgets/qtabwidget.h>

#include "widgets/mainWidgets/ititlewidget.h"

IDisplayWidget::IDisplayWidget(QWidget *parent)
    : IAbstractWidget(parent)
{
    m_pMainLayout = nullptr;
    m_pTitleWidget = nullptr;
    m_pTabWidget = nullptr;

    //初始化界面
    this->setupUi();
}

IDisplayWidget::~IDisplayWidget()
{

}

bool IDisplayWidget::instance()
{
    I_INSTANCE(m_pMainLayout, QVBoxLayout, nullptr);
    I_INSTANCE(m_pTitleWidget, ITitleWidget, this);
    I_INSTANCE(m_pTabWidget, QTabWidget, this);

    return true;
}

bool IDisplayWidget::retranslateUi()
{
    if (m_pMainLayout == nullptr)
        return false;

//    m_pMainLayout = nullptr;
//    m_pTitleWidget = nullptr;
//    m_pTabWidget = nullptr;

    return true;
}

void IDisplayWidget::layout()
{
    m_pMainLayout->addWidget(m_pTitleWidget);
    m_pMainLayout->addWidget(m_pTabWidget);
    this->setLayout(m_pMainLayout);
}

bool IDisplayWidget::connect()
{
    QMetaObject::Connection connection;
    bool result = true;
//    m_pMainLayout = nullptr;
//    m_pTitleWidget = nullptr;
//    m_pTabWidget = nullptr;
    return result;
}

void IDisplayWidget::objectNameSetting()
{
    m_pMainLayout->setObjectName("MainLayout");
    m_pTitleWidget->setObjectName("TitleWidget");
    m_pTabWidget->setObjectName("TabWidget");
    this->setObjectName("DisplayWidget");
}

bool IDisplayWidget::decorate()
{
//    m_pMainLayout = nullptr;
//    m_pTitleWidget = nullptr;
//    m_pTabWidget = nullptr;

    this->setAttribute(Qt::WidgetAttribute::WA_StyledBackground);

    return true;
}

void IDisplayWidget::release()
{
    I_RELEASE(m_pMainLayout);
    I_RELEASE(m_pTitleWidget);
    I_RELEASE(m_pTabWidget);
}
