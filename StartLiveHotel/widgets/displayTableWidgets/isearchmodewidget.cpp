#include "isearchmodewidget.h"

#include <QtWidgets/qboxlayout.h>
#include <QtWidgets/qlabel.h>
#include <QtWidgets/qcheckbox.h>

ISearchModeWidget::ISearchModeWidget(QWidget *parent)
    : IAbstractWidget(parent)
{
    m_pMainLayout = nullptr;
    m_pModeLabel = nullptr;
    m_pAllCheck = nullptr;

    //初始化界面
    this->setupUi();
}

ISearchModeWidget::~ISearchModeWidget()
{

}

QStringList ISearchModeWidget::modeNameList() const
{
    return m_modeNameList;
}

void ISearchModeWidget::setModeNameList(const QStringList &modeNameList)
{
    //如果已经存在个数一样的模式
    qint32 count = m_modeCheckBoxList.count();
    if (count == modeNameList.count())
    {
        for (qint32 index = 0; index < count; index++)
        {
            m_modeCheckBoxList[index]->setText(modeNameList[index]);
        }
        return;
    }

    //清空原来的模式名
    for (QCheckBox* pCheckBox : m_modeCheckBoxList)
    {
        m_pMainLayout->removeWidget(pCheckBox);
        delete pCheckBox;
    }
    m_modeCheckBoxList.clear();

    //添加新的模式
    for (QString modeName : modeNameList)
    {
        QCheckBox* pCheckBox = new QCheckBox(modeName, this);
        if (pCheckBox == nullptr)
            return;

        m_pMainLayout->addWidget(pCheckBox);
        m_modeCheckBoxList.append(pCheckBox);
    }
}

QList<qint32> ISearchModeWidget::modeList() const
{
    return m_modeList;
}

bool ISearchModeWidget::instance()
{
    I_INSTANCE(m_pMainLayout, QHBoxLayout, nullptr);
    I_INSTANCE(m_pModeLabel, QLabel, this);
    I_INSTANCE(m_pAllCheck, QCheckBox, this);

    return true;
}

bool ISearchModeWidget::retranslateUi()
{
    if (m_pMainLayout == nullptr)
        return false;

    m_pModeLabel->setText(this->tr("查找模式："));
    m_pAllCheck->setText(this->tr("所有"));

    return true;
}

void ISearchModeWidget::layout()
{
    m_pMainLayout->addWidget(m_pModeLabel);
    m_pMainLayout->addWidget(m_pAllCheck);
    this->setLayout(m_pMainLayout);
}

bool ISearchModeWidget::connect()
{
    QMetaObject::Connection connection;
    bool result = true;

    connection = QObject::connect(m_pAllCheck, SIGNAL(clicked())
                                  , this, SLOT(onCheckBoxClicked()));
    result &= bool(connection);

    return result;
}

void ISearchModeWidget::objectNameSetting()
{
    m_pMainLayout->setObjectName("MainLayout");
    m_pModeLabel->setObjectName("ModeLabel");
    m_pAllCheck->setObjectName("AllCheckBox");
}

bool ISearchModeWidget::decorate()
{
//    m_pMainLayout = nullptr;
//    m_pModeLabel = nullptr;

    m_pAllCheck->setChecked(true);

    this->setAttribute(Qt::WidgetAttribute::WA_StyledBackground);

    return true;
}

void ISearchModeWidget::release()
{
    I_RELEASE(m_pMainLayout);
    I_RELEASE(m_pModeLabel);
    I_RELEASE(m_pAllCheck);
}

void ISearchModeWidget::onCheckBoxClicked()
{
    //设置选中状态
    bool singleChecked = false;
    for (QCheckBox* pCheckBox : m_modeCheckBoxList)
    {
        singleChecked |= pCheckBox->isChecked();
    }
    m_pAllCheck->setChecked(!singleChecked);

    //生成新的模式
    qint32 count = m_modeCheckBoxList.count();
    QList<qint32> mlist;
    for (qint32 index = 0; index < count; index++)
    {
        if (m_pAllCheck->isChecked() || m_modeCheckBoxList[index]->isChecked())
            mlist.append(index);
    }
    if (mlist != m_modeList)
    {
        m_modeList = mlist;
        emit modeChanged(m_modeList);
    }
}
