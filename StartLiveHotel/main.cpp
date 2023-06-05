#include "imainwidget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    IMainWidget w;
    w.show();
    return a.exec();
}
