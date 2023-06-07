#include "ioperationmenubar.h"

#include <QtWidgets/qboxlayout.h>
#include <QtWidgets/qlabel.h>
#include <QtWidgets/qpushbutton.h>
#include <QtWidgets/qlistwidget.h>

IOperationMenuBar::IOperationMenuBar(QWidget *parent)
    : IAbstractWidget(parent)
{
    m_pMainLayout = nullptr;
    m_pTitleLabel = nullptr;
    m_pHomeButton = nullptr;
    m_pPersonalButton = nullptr;
    m_pOperationListWidget = nullptr;
    m_pFeedbackButton = nullptr;

    //初始化界面
    this->setupUi();
}

IOperationMenuBar::~IOperationMenuBar()
{

}

bool IOperationMenuBar::instance()
{
    I_INSTANCE(m_pMainLayout, QVBoxLayout, nullptr);
    I_INSTANCE(m_pTitleLabel, QLabel, this);
    I_INSTANCE(m_pHomeButton, QPushButton, this);
    I_INSTANCE(m_pPersonalButton, QPushButton, this);
    I_INSTANCE(m_pOperationListWidget, QListWidget, this);
    I_INSTANCE(m_pFeedbackButton, QPushButton, this);

    return true;
}

bool IOperationMenuBar::retranslateUi()
{
    if (m_pMainLayout == nullptr)
        return false;

    m_pTitleLabel->setText(this->tr("酒店管理"));
    m_pHomeButton->setText(this->tr("主页"));
    m_pPersonalButton->setText(this->tr("个人中心"));
    m_pFeedbackButton->setText(this->tr("意见反馈"));

    return true;
}

void IOperationMenuBar::layout()
{
    m_pMainLayout->addWidget(m_pTitleLabel);
    m_pMainLayout->addWidget(m_pHomeButton);
    m_pMainLayout->addWidget(m_pPersonalButton);
    m_pMainLayout->addWidget(m_pOperationListWidget);
    m_pMainLayout->addWidget(m_pFeedbackButton);
    this->setLayout(m_pMainLayout);
}

bool IOperationMenuBar::connect()
{
    QMetaObject::Connection connection;
    bool result = true;

    connection = QObject::connect(m_pHomeButton, SIGNAL(clicked())
                                  , this, SLOT(onHomeButtonClicked()));
    result &= bool(connection);

    connection = QObject::connect(m_pPersonalButton, SIGNAL(clicked())
                                  , this, SLOT(onPersonalButtonClicked()));
    result &= bool(connection);

    //m_pOperationListWidget;

    connection = QObject::connect(m_pFeedbackButton, SIGNAL(clicked())
                                  , this, SLOT(onFeedbackButtonClicked()));
    result &= bool(connection);

    return result;
}

void IOperationMenuBar::objectNameSetting()
{
    m_pMainLayout->setObjectName("MainLayout");
    m_pTitleLabel->setObjectName("TitleLabel");
    m_pHomeButton->setObjectName("HomeButton");
    m_pPersonalButton->setObjectName("PersonalButton");
    m_pOperationListWidget->setObjectName("OperationListWidget");
    m_pFeedbackButton->setObjectName("FeedbackButton");
    this->setObjectName("OperationMenuBar");
}

bool IOperationMenuBar::decorate()
{
//    m_pMainLayout;
//    m_pTitleLabel;
//    m_pHomeButton;
//    m_pPersonalButton;
//    m_pOperationListWidget;
//    m_pFeedbackButton;

    this->setAttribute(Qt::WidgetAttribute::WA_StyledBackground);

    return true;
}

void IOperationMenuBar::release()
{
    I_RELEASE(m_pMainLayout);
    I_RELEASE(m_pTitleLabel);
    I_RELEASE(m_pHomeButton);
    I_RELEASE(m_pPersonalButton);
    I_RELEASE(m_pOperationListWidget);
    I_RELEASE(m_pFeedbackButton);
}

void IOperationMenuBar::onHomeButtonClicked()
{

}

void IOperationMenuBar::onPersonalButtonClicked()
{

}

void IOperationMenuBar::onFeedbackButtonClicked()
{

}
