#include "imainwidget.h"

#include <QtGui/qevent.h>

IMainWidget::IMainWidget(QWidget *parent)
    : IAbstractWidget(parent)
{
}

IMainWidget::~IMainWidget()
{
}

bool IMainWidget::instance()
{

    return true;
}

bool IMainWidget::retranslateUi()
{

    return true;
}

void IMainWidget::layout()
{

}

bool IMainWidget::connect()
{

    return true;
}

void IMainWidget::objectNameSetting()
{

}

bool IMainWidget::decorate()
{

    return true;
}

void IMainWidget::release()
{

}
