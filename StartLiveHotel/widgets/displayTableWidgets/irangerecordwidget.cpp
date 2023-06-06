#include "irangerecordwidget.h"

#include <QtWidgets/qboxlayout.h>
#include <QtWidgets/qlabel.h>

IRangeRecordWidget::IRangeRecordWidget(QWidget *parent)
    : IAbstractWidget(parent)
{
    m_pMainLayout = nullptr;
    m_pCurrentValueLabel = nullptr;
    m_pLsolationLineLabel = nullptr;
    m_pTotalValueLabel = nullptr;

    //初始化界面
    this->setupUi();
}

IRangeRecordWidget::~IRangeRecordWidget()
{

}

qint32 IRangeRecordWidget::currentValue() const
{
    if (m_pCurrentValueLabel == nullptr)
        return -1;

    return m_pCurrentValueLabel->text().toInt();
}

void IRangeRecordWidget::setCurrentValue(qint32 value)
{
    if (m_pCurrentValueLabel == nullptr)
        return;

    m_pCurrentValueLabel->setText(QString::number(value));
}

qint32 IRangeRecordWidget::totalValue() const
{
    if (m_pTotalValueLabel == nullptr)
        return -1;

    return m_pTotalValueLabel->text().toInt();
}

void IRangeRecordWidget::setTotalValue(qint32 value)
{
    if (m_pTotalValueLabel == nullptr)
        return;

    m_pTotalValueLabel->setText(QString::number(value));
}

bool IRangeRecordWidget::instance()
{
    I_INSTANCE(m_pMainLayout, QHBoxLayout, nullptr);
    I_INSTANCE(m_pCurrentValueLabel, QLabel, this);
    I_INSTANCE(m_pLsolationLineLabel, QLabel, this);
    I_INSTANCE(m_pTotalValueLabel, QLabel, this);

    return true;
}

bool IRangeRecordWidget::retranslateUi()
{
    return true;
}

void IRangeRecordWidget::layout()
{
    m_pMainLayout->addWidget(m_pCurrentValueLabel);
    m_pMainLayout->addWidget(m_pLsolationLineLabel);
    m_pMainLayout->addWidget(m_pTotalValueLabel);
    this->setLayout(m_pMainLayout);
}

bool IRangeRecordWidget::connect()
{
    return true;
}

void IRangeRecordWidget::objectNameSetting()
{
    m_pMainLayout->setObjectName("MainLayout");
    m_pCurrentValueLabel->setObjectName("CurrentValueLabel");
    m_pLsolationLineLabel->setObjectName("LsolationLineLabel");
    m_pTotalValueLabel->setObjectName("TotalValueLabel");
    this->setObjectName("RangeRecordWidget");
}

bool IRangeRecordWidget::decorate()
{
    m_pCurrentValueLabel->setText("0");
    m_pLsolationLineLabel->setText("/");
    m_pTotalValueLabel->setText("0");
    this->setAttribute(Qt::WidgetAttribute::WA_StyledBackground);
    return true;
}

void IRangeRecordWidget::release()
{
    I_RELEASE(m_pMainLayout);
    I_RELEASE(m_pCurrentValueLabel);
    I_RELEASE(m_pLsolationLineLabel);
    I_RELEASE(m_pTotalValueLabel);
}
