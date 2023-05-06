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
    w.show();
    return a.exec();

//    std::vector<std::string> abilities = {"Sharp"};

//    std::string name = "Sword";

//    Item item(name, 25, abilities);

//    QString qDesc = QString::fromStdString(item.description());


//    qDebug() << qDesc;
    qDebug() << "test";

}
