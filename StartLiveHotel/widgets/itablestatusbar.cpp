#include "itablestatusbar.h"

#include <QtWidgets/qboxlayout.h>
#include <QtWidgets/qlayoutitem.h>
#include <QtWidgets/qlabel.h>
#include <QtWidgets/qspinbox.h>
#include <QtWidgets/qcombobox.h>
#include <QtWidgets/qpushbutton.h>

#include "irangerecordwidget.h"

ITableStatusBar::ITableStatusBar(QWidget *parent)
    : IAbstractWidget(parent)
{
    m_pMainLayout = nullptr;
    m_pPageSizeLeftLabel = nullptr;
    m_pPageSizeComboBox = nullptr;
    m_pPageSizeRightLabel = nullptr;
    m_pLeftHorizontalSpacer = nullptr;
    m_pFirstButton = nullptr;
    m_pPreviousButton = nullptr;
    m_pRangeRecordWidget = nullptr;
    m_pNextButton = nullptr;
    m_pLastButton = nullptr;
    m_pRightHorizontalSpacer = nullptr;
    m_pJumpToLabel = nullptr;
    m_pJumpPageSpinBox = nullptr;
    m_pJumpButton = nullptr;
}

ITableStatusBar::~ITableStatusBar()
{

}

qint32 ITableStatusBar::page() const
{
    if (m_pRangeRecordWidget == nullptr)
        return -1;

    return m_pRangeRecordWidget->currentValue();
}

void ITableStatusBar::setPage(qint32 page)
{
    if (m_pRangeRecordWidget == nullptr)
        return;

    m_pRangeRecordWidget->setCurrentValue(page);
}

qint32 ITableStatusBar::pageSize() const
{
    if (m_pPageSizeComboBox == nullptr)
        return -1;

    return m_pPageSizeComboBox->currentText().toInt();
}

void ITableStatusBar::setPageSize(qint32 size)
{
    Q_UNUSED(size);
}

qint32 ITableStatusBar::totalPage() const
{
    if (m_pRangeRecordWidget == nullptr)
        return -1;

    return m_pRangeRecordWidget->totalValue();
}

void ITableStatusBar::setTotalPage(qint32 totalPage)
{
    if (m_pRangeRecordWidget == nullptr)
        return;

    m_pRangeRecordWidget->setTotalValue(totalPage);
}

bool ITableStatusBar::instance()
{
    I_INSTANCE(m_pMainLayout, QHBoxLayout, nullptr);
    I_INSTANCE(m_pPageSizeLeftLabel, QLabel, this);
    I_INSTANCE(m_pPageSizeComboBox, QComboBox, this);
    I_INSTANCE(m_pPageSizeRightLabel, QLabel, this);

    m_pLeftHorizontalSpacer = new QSpacerItem(40, 20);
    if (m_pLeftHorizontalSpacer == nullptr)
        return false;

    I_INSTANCE(m_pFirstButton, QPushButton, this);
    I_INSTANCE(m_pPreviousButton, QPushButton, this);
    I_INSTANCE(m_pRangeRecordWidget, IRangeRecordWidget, this);
    I_INSTANCE(m_pNextButton, QPushButton, this);
    I_INSTANCE(m_pLastButton, QPushButton, this);

    m_pRightHorizontalSpacer = new QSpacerItem(40, 20);
    if (m_pRightHorizontalSpacer == nullptr)
        return false;

    I_INSTANCE(m_pJumpToLabel, QLabel, this);
    I_INSTANCE(m_pJumpPageSpinBox, QSpinBox, this);
    I_INSTANCE(m_pJumpButton, QPushButton, this);

    return true;
}

bool ITableStatusBar::retranslateUi()
{
    if (m_pMainLayout == nullptr)
        return false;

    m_pPageSizeLeftLabel->setText(this->tr("最大显示"));

    while (m_pPageSizeComboBox->count() != 4)
        m_pPageSizeComboBox->addItem("");
    m_pPageSizeComboBox->setItemText(0, "10");
    m_pPageSizeComboBox->setItemText(1, "20");
    m_pPageSizeComboBox->setItemText(2, "50");
    m_pPageSizeComboBox->setItemText(3, "100");

    m_pPageSizeRightLabel->setText(this->tr("条"));
    m_pFirstButton->setText(this->tr("首页"));
    m_pPreviousButton->setText(this->tr("上一页"));
    m_pNextButton->setText(this->tr("下一页"));
    m_pLastButton->setText(this->tr("尾页"));
    m_pJumpToLabel->setText(this->tr("跳转到"));
    m_pJumpButton->setText(this->tr("跳转"));

    return true;
}

void ITableStatusBar::layout()
{
    m_pMainLayout->addWidget(m_pPageSizeLeftLabel);
    m_pMainLayout->addWidget(m_pPageSizeComboBox);
    m_pMainLayout->addWidget(m_pPageSizeRightLabel);
    m_pMainLayout->addItem(m_pLeftHorizontalSpacer);
    m_pMainLayout->addWidget(m_pFirstButton);
    m_pMainLayout->addWidget(m_pPreviousButton);
    m_pMainLayout->addWidget(m_pRangeRecordWidget);
    m_pMainLayout->addWidget(m_pNextButton);
    m_pMainLayout->addWidget(m_pLastButton);
    m_pMainLayout->addItem(m_pRightHorizontalSpacer);
    m_pMainLayout->addWidget(m_pJumpToLabel);
    m_pMainLayout->addWidget(m_pJumpPageSpinBox);
    m_pMainLayout->addWidget(m_pJumpButton);
    this->setLayout(m_pMainLayout);
}

bool ITableStatusBar::connect()
{
    QMetaObject::Connection connection;
    bool result = true;

    connection = QObject::connect(m_pPageSizeComboBox, SIGNAL(currentIndexChanged(const QString&))
                             , this, SLOT(onPageSizeComboBoxCurrentIndexChanged(const QString&)));
    result &= bool(connection);

    connection = QObject::connect(m_pFirstButton, SIGNAL(clicked())
                             , this, SLOT(onFirstButtonClickd()));
    result &= bool(connection);

    connection = QObject::connect(m_pPreviousButton, SIGNAL(clicked())
                             , this, SLOT(onPreviousButtonClickd()));
    result &= bool(connection);

    connection = QObject::connect(m_pNextButton, SIGNAL(clicked())
                             , this, SLOT(onNextButtonClickd()));
    result &= bool(connection);

    connection = QObject::connect(m_pLastButton, SIGNAL(clicked())
                             , this, SLOT(onLastButtonClickd()));
    result &= bool(connection);

    connection = QObject::connect(m_pJumpButton, SIGNAL(clicked())
                             , this, SLOT(onJumpButtonClickd()));
    result &= bool(connection);

    return result;
}

void ITableStatusBar::objectNameSetting()
{
    m_pMainLayout->setObjectName("MainLayout");
    m_pPageSizeLeftLabel->setObjectName("PageSizeLeftLabel");
    m_pPageSizeComboBox->setObjectName("PageSizeComboBox");
    m_pPageSizeRightLabel->setObjectName("PageSizeRightLabel");
    m_pFirstButton->setObjectName("FirstButton");
    m_pPreviousButton->setObjectName("PreviousButton");
    m_pRangeRecordWidget->setObjectName("RangeRecordWidget");
    m_pNextButton->setObjectName("NextButton");
    m_pLastButton->setObjectName("LastButton");
    m_pJumpToLabel->setObjectName("JumpToLabel");
    m_pJumpPageSpinBox->setObjectName("JumpPageSpinBox");
    m_pJumpButton->setObjectName("JumpButton");
}

bool ITableStatusBar::decorate()
{
//    m_pMainLayout = nullptr;
//    m_pPageSizeLeftLabel = nullptr;
//    m_pPageSizeComboBox = nullptr;
//    m_pPageSizeRightLabel = nullptr;
    m_pLeftHorizontalSpacer->changeSize(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);
//    m_pFirstButton = nullptr;
//    m_pPreviousButton = nullptr;
//    m_pRangeRecordWidget = nullptr;
//    m_pNextButton = nullptr;
//    m_pLastButton = nullptr;
    m_pRightHorizontalSpacer->changeSize(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);
//    m_pJumpToLabel = nullptr;
//    m_pJumpPageSpinBox = nullptr;
//    m_pJumpButton = nullptr;

    this->setAttribute(Qt::WidgetAttribute::WA_StyledBackground);

    return true;
}

void ITableStatusBar::release()
{
    I_RELEASE(m_pMainLayout);
    I_RELEASE(m_pPageSizeLeftLabel);
    I_RELEASE(m_pPageSizeComboBox);
    I_RELEASE(m_pPageSizeRightLabel);
    I_RELEASE(m_pLeftHorizontalSpacer);
    I_RELEASE(m_pFirstButton);
    I_RELEASE(m_pPreviousButton);
    I_RELEASE(m_pRangeRecordWidget);
    I_RELEASE(m_pNextButton);
    I_RELEASE(m_pLastButton);
    I_RELEASE(m_pRightHorizontalSpacer);
    I_RELEASE(m_pJumpToLabel);
    I_RELEASE(m_pJumpPageSpinBox);
    I_RELEASE(m_pJumpButton);
}

void ITableStatusBar::onPageSizeComboBoxCurrentIndexChanged(const QString &text)
{
    qint32 pageSize = text.toInt();
    qint32 page = m_pRangeRecordWidget->currentValue();
    emit pageChanged(page, pageSize);
}

void ITableStatusBar::onFirstButtonClicked()
{
    qint32 pageSize = m_pPageSizeComboBox->currentText().toInt();
    qint32 page = 1;
    emit pageChanged(page, pageSize);
}

void ITableStatusBar::onPreviousButtonClicked()
{
    qint32 pageSize = m_pPageSizeComboBox->currentText().toInt();
    qint32 page = m_pRangeRecordWidget->currentValue() - 1;
    emit pageChanged(page, pageSize);
}

void ITableStatusBar::onNextButtonClicked()
{
    qint32 pageSize = m_pPageSizeComboBox->currentText().toInt();
    qint32 page = m_pRangeRecordWidget->currentValue() + 1;
    emit pageChanged(page, pageSize);
}

void ITableStatusBar::onLastButtonClicked()
{
    qint32 pageSize = m_pPageSizeComboBox->currentText().toInt();
    qint32 page = m_pRangeRecordWidget->totalValue();
    emit pageChanged(page, pageSize);
}

void ITableStatusBar::onJumpButtonClicked()
{
    qint32 pageSize = m_pPageSizeComboBox->currentText().toInt();
    qint32 page = m_pJumpPageSpinBox->value();
    emit pageChanged(page, pageSize);
}
