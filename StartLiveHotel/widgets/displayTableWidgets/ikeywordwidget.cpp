#include "ikeywordwidget.h"

#include <QtWidgets/qboxlayout.h>
#include <QtWidgets/qlabel.h>
#include <QtWidgets/qlineedit.h>
#include <QtWidgets/qpushbutton.h>

IKeywordWidget::IKeywordWidget(QWidget *parent)
    : IAbstractWidget(parent)
{
    m_pMainLayout = nullptr;
    m_pKeywordLabel = nullptr;
    m_pKeywordLineEdit = nullptr;
    m_pSearchButton = nullptr;

    //初始化
    this->setupUi();
}

IKeywordWidget::~IKeywordWidget()
{

}

QString IKeywordWidget::keyword() const
{
    if (m_pKeywordLineEdit == nullptr)
        return "";

    return m_pKeywordLineEdit->text();
}

bool IKeywordWidget::instance()
{
    I_INSTANCE(m_pMainLayout, QHBoxLayout, nullptr);
    I_INSTANCE(m_pKeywordLabel, QLabel, this);
    I_INSTANCE(m_pKeywordLineEdit, QLineEdit, this);
    I_INSTANCE(m_pSearchButton, QPushButton, this);

    return true;
}

bool IKeywordWidget::retranslateUi()
{
    if (m_pMainLayout == nullptr)
        return false;

    m_pKeywordLabel->setText(this->tr("关键词："));
    m_pKeywordLineEdit->setPlaceholderText(this->tr("请输入关键词"));
    m_pSearchButton->setText(this->tr("查找"));

    return true;
}

void IKeywordWidget::layout()
{
    m_pMainLayout->addWidget(m_pKeywordLabel);
    m_pMainLayout->addWidget(m_pKeywordLineEdit);
    m_pMainLayout->addWidget(m_pSearchButton);
    this->setLayout(m_pMainLayout);
}

bool IKeywordWidget::connect()
{
    QMetaObject::Connection connection;
    bool result = true;

    connection = QObject::connect(m_pKeywordLineEdit, SIGNAL(returnPressed())
                                  , this, SLOT(onKeywordLineEditReturnPressed()));
    result &= bool(connection);

    connection = QObject::connect(m_pSearchButton, SIGNAL(clicked())
                                  , this, SLOT(onSearchButtonClicked()));
    result &= bool(connection);

    return result;
}

void IKeywordWidget::objectNameSetting()
{
    m_pMainLayout->setObjectName("MainLayout");
    m_pKeywordLabel->setObjectName("KeywordLabel");
    m_pKeywordLineEdit->setObjectName("KeywordLineEdit");
    m_pSearchButton->setObjectName("SearchButton");
    this->setObjectName("KeywordWidget");
}

bool IKeywordWidget::decorate()
{
    this->setAttribute(Qt::WidgetAttribute::WA_StyledBackground);
    return true;
}

void IKeywordWidget::release()
{
    I_RELEASE(m_pMainLayout);
    I_RELEASE(m_pKeywordLabel);
    I_RELEASE(m_pKeywordLineEdit);
    I_RELEASE(m_pSearchButton);
}

void IKeywordWidget::onKeywordLineEditReturnPressed()
{
    search(m_pKeywordLineEdit->text());
}

void IKeywordWidget::onSearchButtonClicked()
{
    search(m_pKeywordLineEdit->text());
}
