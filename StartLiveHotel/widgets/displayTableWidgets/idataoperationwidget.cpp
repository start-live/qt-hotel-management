#include "idataoperationwidget.h"

#include <QtWidgets/qboxlayout.h>
#include <QtWidgets/qpushbutton.h>

IDataOperationWidget::IDataOperationWidget(QWidget *parent)
    : IAbstractWidget(parent)
{
    m_pMainLayout = nullptr;
    m_pUpdateButton = nullptr;
    m_pDeleteButton = nullptr;
    m_pDetailButton = nullptr;

    //初始化界面
    this->setupUi();
}

IDataOperationWidget::~IDataOperationWidget()
{

}

bool IDataOperationWidget::instance()
{
    I_INSTANCE(m_pMainLayout, QHBoxLayout, nullptr);
    I_INSTANCE(m_pUpdateButton, QPushButton, this);
    I_INSTANCE(m_pDeleteButton, QPushButton, this);
    I_INSTANCE(m_pDetailButton, QPushButton, this);

    return true;
}

bool IDataOperationWidget::retranslateUi()
{
    if (m_pMainLayout == nullptr)
        return false;

    m_pUpdateButton->setText(this->tr("修改"));
    m_pDeleteButton->setText(this->tr("删除"));
    m_pDetailButton->setText(this->tr("详情"));

    return true;
}

void IDataOperationWidget::layout()
{
    m_pMainLayout->addWidget(m_pUpdateButton);
    m_pMainLayout->addWidget(m_pDeleteButton);
    m_pMainLayout->addWidget(m_pDetailButton);
    this->setLayout(m_pMainLayout);
}

bool IDataOperationWidget::connect()
{
    QMetaObject::Connection connection;
    bool result = true;

    connection = QObject::connect(m_pUpdateButton, SIGNAL(clicked())
                                  , this, SLOT(onUpdateButtonClicked()));
    result &= bool(connection);

    connection = QObject::connect(m_pDeleteButton, SIGNAL(clicked())
                                  , this, SLOT(onDeleteButtonClicked()));
    result &= bool(connection);

    connection = QObject::connect(m_pDetailButton, SIGNAL(clicked())
                                  , this, SLOT(onDetailButtonClicked()));
    result &= bool(connection);

    return result;
}

void IDataOperationWidget::objectNameSetting()
{
    m_pMainLayout->setObjectName("MainLayout");
    m_pUpdateButton->setObjectName("UpdateButton");
    m_pDeleteButton->setObjectName("DeleteButton");
    m_pDetailButton->setObjectName("DetailButton");
}

bool IDataOperationWidget::decorate()
{
//    m_pMainLayout;
//    m_pUpdateButton;
//    m_pDeleteButton;
//    m_pDetailButton;
    this->setAttribute(Qt::WidgetAttribute::WA_StyledBackground);

    return true;
}

void IDataOperationWidget::release()
{
    I_RELEASE(m_pMainLayout);
    I_RELEASE(m_pUpdateButton);
    I_RELEASE(m_pDeleteButton);
    I_RELEASE(m_pDetailButton);
}

void IDataOperationWidget::onUpdateButtonClicked()
{

}

void IDataOperationWidget::onDeleteButtonClicked()
{

}

void IDataOperationWidget::onDetailButtonClicked()
{

}
