#include "imainwidget.h"
#include "widgets/roomWidgets/iroommanagementwidget.h"
#include <QApplication>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    IRoomManagementWidget w;
    w.show();
    return a.exec();
}
