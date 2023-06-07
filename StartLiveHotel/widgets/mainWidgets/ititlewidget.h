/*
 * 文件：ititlewidget.h
 * 描述：标题栏
 * 创建者：start-live
 * 时间：2023年06月07日
*/

#ifndef ITITLEWIDGET_H
#define ITITLEWIDGET_H

#include "widgets/iabstractwidget.h"

class QHBoxLayout;
class QSpacerItem;
class QLabel;
class QPushButton;

class ITitleWidget : public IAbstractWidget
{
    Q_OBJECT
public:
    explicit ITitleWidget(QWidget *parent = nullptr);
    virtual ~ITitleWidget();

protected:
    //分配内存
    virtual bool instance() override;
    //设置文本
    virtual bool retranslateUi() override;
    //设置布局
    virtual void layout() override;
    //关联信号与槽
    virtual bool connect() override;
    //设置对象名，为qss的编写做准备
    virtual void objectNameSetting() override;
    //装饰，设置无法通过qss进行设置的属性
    virtual bool decorate() override;
    //如果内存分配失败，则对部分已经分配过内存的控件进行释放
    virtual void release() override;

signals:

private slots:
    void onLoginButtonClicked();
    void onLanguageButtonClicked();
    void onAboutButtonClicked();

private:
    QHBoxLayout* m_pMainLayout;
    QSpacerItem* m_pLeftHorizontalSpacer;
    QLabel* m_pCityLabel;
    QLabel* m_pWeatherLabel;
    QLabel* m_pTemperatureLabel;
    QLabel* m_pDateTimeLabel;
    QPushButton* m_pLoginButton;
    QPushButton* m_pLanguageButton;
    QPushButton* m_pAboutButton;
};

#endif // ITITLEWIDGET_H
