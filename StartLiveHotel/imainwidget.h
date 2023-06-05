/*
 *
*/

#ifndef IMAINWIDGET_H
#define IMAINWIDGET_H

#include <QtWidgets/qwidget.h>

class IMainWidget : public QWidget
{
    Q_OBJECT

public:
    IMainWidget(QWidget *parent = nullptr);
    ~IMainWidget();

protected:
    virtual void changeEvent(QEvent *pEvent) override;
};

#endif // IMAINWIDGET_H
