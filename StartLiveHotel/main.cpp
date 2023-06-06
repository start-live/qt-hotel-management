#include "imainwidget.h"
#include "widgets/displayTableWidgets/idatatablewidget.h"
#include <QApplication>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    IDataTableWidget w;
    w.show();
    return a.exec();
}
