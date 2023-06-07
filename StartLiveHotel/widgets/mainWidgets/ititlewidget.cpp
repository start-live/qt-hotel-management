#include "ititlewidget.h"

#include <QtWidgets/qboxlayout.h>
#include <QtWidgets/qlayoutitem.h>
#include <QtWidgets/qlabel.h>
#include <QtWidgets/qpushbutton.h>

ITitleWidget::ITitleWidget(QWidget *parent)
    : IAbstractWidget(parent)
{
    m_pMainLayout = nullptr;
    m_pLeftHorizontalSpacer = nullptr;
    m_pCityLabel = nullptr;
    m_pWeatherLabel = nullptr;
    m_pTemperatureLabel = nullptr;
    m_pDateTimeLabel = nullptr;
    m_pLoginButton = nullptr;
    m_pLanguageButton = nullptr;
    m_pAboutButton = nullptr;

    //初始化界面
    this->setupUi();
}

ITitleWidget::~ITitleWidget()
{

}

bool ITitleWidget::instance()
{
    I_INSTANCE(m_pMainLayout, QHBoxLayout, nullptr);

    m_pLeftHorizontalSpacer = new QSpacerItem(40, 20);
    if (m_pLeftHorizontalSpacer == nullptr)
        return false;

    I_INSTANCE(m_pCityLabel, QLabel, this);
    I_INSTANCE(m_pWeatherLabel, QLabel, this);
    I_INSTANCE(m_pTemperatureLabel, QLabel, this);
    I_INSTANCE(m_pDateTimeLabel, QLabel, this);
    I_INSTANCE(m_pLoginButton, QPushButton, this);
    I_INSTANCE(m_pLanguageButton, QPushButton, this);
    I_INSTANCE(m_pAboutButton, QPushButton, this);

    return true;
}

bool ITitleWidget::retranslateUi()
{
    if (m_pMainLayout == nullptr)
        return false;

    m_pCityLabel->setText(this->tr("武汉"));
    m_pWeatherLabel->setText(this->tr("天气"));
    m_pTemperatureLabel->setText(this->tr("温度"));
    m_pDateTimeLabel->setText(this->tr("2023-06-07 11:51:35"));
    m_pLoginButton->setText(this->tr("登录"));
    m_pLanguageButton->setText(this->tr("语言"));
    m_pAboutButton->setText(this->tr("关于"));

    return true;
}

void ITitleWidget::layout()
{
    m_pMainLayout->addItem(m_pLeftHorizontalSpacer);
    m_pMainLayout->addWidget(m_pCityLabel);
    m_pMainLayout->addWidget(m_pWeatherLabel);
    m_pMainLayout->addWidget(m_pTemperatureLabel);
    m_pMainLayout->addWidget(m_pDateTimeLabel);
    m_pMainLayout->addWidget(m_pLoginButton);
    m_pMainLayout->addWidget(m_pLanguageButton);
    m_pMainLayout->addWidget(m_pAboutButton);
    this->setLayout(m_pMainLayout);
}

bool ITitleWidget::connect()
{
    QMetaObject::Connection connection;
    bool result = true;

    connection = QObject::connect(m_pLoginButton, SIGNAL(clicked())
                                  , this, SLOT(onLoginButtonClicked()));
    result &= bool(connection);

    connection = QObject::connect(m_pLanguageButton, SIGNAL(clicked())
                                  , this, SLOT(onLanguageButtonClicked()));
    result &= bool(connection);

    connection = QObject::connect(m_pAboutButton, SIGNAL(clicked())
                                  , this, SLOT(onAboutButtonClicked()));
    result &= bool(connection);

    return result;
}

void ITitleWidget::objectNameSetting()
{
    m_pMainLayout->setObjectName("MainLayout");
    m_pCityLabel->setObjectName("CityLabel");
    m_pWeatherLabel->setObjectName("WeatherLabel");
    m_pTemperatureLabel->setObjectName("TemperatureLabel");
    m_pDateTimeLabel->setObjectName("DateTimeLabel");
    m_pLoginButton->setObjectName("LoginButton");
    m_pLanguageButton->setObjectName("LanguageButton");
    m_pAboutButton->setObjectName("AboutButton");
    this->setObjectName("TitleWidget");
}

bool ITitleWidget::decorate()
{
//    m_pMainLayout;
    m_pLeftHorizontalSpacer->changeSize(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);
//    m_pCityLabel;
//    m_pWeatherLabel;
//    m_pTemperatureLabel;
//    m_pDateTimeLabel;
//    m_pLoginButton;
//    m_pLanguageButton;
//    m_pAboutButton;

    this->setAttribute(Qt::WidgetAttribute::WA_StyledBackground);

    return true;
}

void ITitleWidget::release()
{
    I_RELEASE(m_pMainLayout);
    I_RELEASE(m_pLeftHorizontalSpacer);
    I_RELEASE(m_pCityLabel);
    I_RELEASE(m_pWeatherLabel);
    I_RELEASE(m_pTemperatureLabel);
    I_RELEASE(m_pDateTimeLabel);
    I_RELEASE(m_pLoginButton);
    I_RELEASE(m_pLanguageButton);
    I_RELEASE(m_pAboutButton);
}

void ITitleWidget::onLoginButtonClicked()
{

}

void ITitleWidget::onLanguageButtonClicked()
{

}

void ITitleWidget::onAboutButtonClicked()
{

}
