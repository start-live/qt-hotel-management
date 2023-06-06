#include "idisplayinfowidget.h"

#include <QtWidgets/qboxlayout.h>
#include <QtWidgets/qlabel.h>

IDisplayInfoWidget::IDisplayInfoWidget(QWidget *parent)
    : IAbstractWidget(parent)
{
    m_pMainLayout = nullptr;
    m_pTotalLeftLabel = nullptr;
    m_pTotalLabel = nullptr;
    m_pTotalRightLabel = nullptr;
    m_pCenterLabel = nullptr;
    m_pCurrentLeftLabel = nullptr;
    m_pCurrentFirstLabel = nullptr;
    m_pCurrentPointLabel = nullptr;
    m_pCurrentLastLabel = nullptr;
    m_pCurrentRightLabel = nullptr;

    //初始化界面
    this->setupUi();
}

IDisplayInfoWidget::~IDisplayInfoWidget()
{

}

void IDisplayInfoWidget::setTotal(qint32 record)
{
    if (m_pTotalLabel == nullptr)
        return;

    m_pTotalLabel->setText(QString::number(record));
}

void IDisplayInfoWidget::setCurrentFirst(qint32 record)
{
    if (m_pCurrentFirstLabel == nullptr)
        return;

    m_pCurrentFirstLabel->setText(QString::number(record));
}

void IDisplayInfoWidget::setCurrentLast(qint32 record)
{
    if (m_pCurrentLastLabel == nullptr)
        return;

    m_pCurrentLastLabel->setText(QString::number(record));
}

bool IDisplayInfoWidget::instance()
{
    I_INSTANCE(m_pMainLayout, QHBoxLayout, nullptr);
    I_INSTANCE(m_pTotalLeftLabel, QLabel, this);
    I_INSTANCE(m_pTotalLabel, QLabel, this);
    I_INSTANCE(m_pTotalRightLabel, QLabel, this);
    I_INSTANCE(m_pCenterLabel, QLabel, this);
    I_INSTANCE(m_pCurrentLeftLabel, QLabel, this);
    I_INSTANCE(m_pCurrentFirstLabel, QLabel, this);
    I_INSTANCE(m_pCurrentPointLabel, QLabel, this);
    I_INSTANCE(m_pCurrentLastLabel, QLabel, this);
    I_INSTANCE(m_pCurrentRightLabel, QLabel, this);

    return true;
}

bool IDisplayInfoWidget::retranslateUi()
{
    if (m_pMainLayout == nullptr)
        return false;

    m_pTotalLeftLabel->setText(this->tr("总记录"));
    m_pTotalLabel->setText(this->tr("0"));
    m_pTotalRightLabel->setText(this->tr("条"));
    m_pCenterLabel->setText(this->tr("，"));
    m_pCurrentLeftLabel->setText(this->tr("当前显示"));
    m_pCurrentFirstLabel->setText(this->tr("0"));
    m_pCurrentPointLabel->setText(this->tr("-"));
    m_pCurrentLastLabel->setText(this->tr("0"));
    m_pCurrentRightLabel->setText(this->tr("条"));

    return true;
}

void IDisplayInfoWidget::layout()
{
    m_pMainLayout->addWidget(m_pTotalLeftLabel);
    m_pMainLayout->addWidget(m_pTotalLabel);
    m_pMainLayout->addWidget(m_pTotalRightLabel);
    m_pMainLayout->addWidget(m_pCenterLabel);
    m_pMainLayout->addWidget(m_pCurrentLeftLabel);
    m_pMainLayout->addWidget(m_pCurrentFirstLabel);
    m_pMainLayout->addWidget(m_pCurrentPointLabel);
    m_pMainLayout->addWidget(m_pCurrentLastLabel);
    m_pMainLayout->addWidget(m_pCurrentRightLabel);
    this->setLayout(m_pMainLayout);
}

bool IDisplayInfoWidget::connect()
{
    return true;
}

void IDisplayInfoWidget::objectNameSetting()
{
    m_pMainLayout->setObjectName("MainLayout");
    m_pTotalLeftLabel->setObjectName("TotalLeftLabel");
    m_pTotalLabel->setObjectName("TotalLabel");
    m_pTotalRightLabel->setObjectName("TotalRightLabel");
    m_pCenterLabel->setObjectName("TotalCenterLabel");
    m_pCurrentLeftLabel->setObjectName("CurrentLeftLabel");
    m_pCurrentFirstLabel->setObjectName("CurrentFirstLabel");
    m_pCurrentPointLabel->setObjectName("CurrentPointLabel");
    m_pCurrentLastLabel->setObjectName("CurrentLastLabel");
    m_pCurrentRightLabel->setObjectName("CurrentRightLabel");
    this->setObjectName("DisplayInfoWidget");
}

bool IDisplayInfoWidget::decorate()
{
//    m_pMainLayout = nullptr;
//    m_pTotalLeftLabel = nullptr;
//    m_pTotalLabel = nullptr;
//    m_pTotalRightLabel = nullptr;
//    m_pCenterLabel = nullptr;
//    m_pCurrentLeftLabel = nullptr;
//    m_pCurrentFirstLabel = nullptr;
//    m_pCurrentPointLabel = nullptr;
//    m_pCurrentLastLabel = nullptr;
//    m_pCurrentRightLabel = nullptr;

    this->setAttribute(Qt::WidgetAttribute::WA_StyledBackground);

    return true;
}

void IDisplayInfoWidget::release()
{
    I_RELEASE(m_pMainLayout);
    I_RELEASE(m_pTotalLeftLabel);
    I_RELEASE(m_pTotalLabel);
    I_RELEASE(m_pTotalRightLabel);
    I_RELEASE(m_pCenterLabel);
    I_RELEASE(m_pCurrentLeftLabel);
    I_RELEASE(m_pCurrentFirstLabel);
    I_RELEASE(m_pCurrentPointLabel);
    I_RELEASE(m_pCurrentLastLabel);
    I_RELEASE(m_pCurrentRightLabel);
}
