#include "mainwindow.h"
#include "item.h"

#include <QApplication>
#include <string>
#include <vector>
//#include <QBrowser>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setFixedSize(QSize(750, 750));
    w.show();
    return a.exec();
}
