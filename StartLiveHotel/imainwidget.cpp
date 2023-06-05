#include "imainwidget.h"

#include <QtGui/qevent.h>

IMainWidget::IMainWidget(QWidget *parent)
    : QWidget(parent)
{
}

IMainWidget::~IMainWidget()
{
}

void IMainWidget::changeEvent(QEvent *pEvent)
{

    QWidget::changeEvent(pEvent);
}

