#include "imainwidget.h"

#include <QtWidgets/qapplication.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    IMainWidget w;
    w.show();
    return a.exec();
}
