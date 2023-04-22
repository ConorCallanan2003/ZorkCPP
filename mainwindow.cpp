#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "avatarwidget.h"
#include <iostream>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <thread>
#include <QPropertyAnimation>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    int parentWidth = this->width();
    int parentHeight = this->height();

    this->setStyleSheet("#MainWindow { background-image: url(:/images/map.png); background-repeat: no-repeat; background-position: center;}" "#MainWindow:size { height: 1000px; width: 1000px; }");


    int centerX = parentWidth / 2;
    int centerY = parentHeight / 2;

    avatarWidget = new AvatarWidget(this);

    int avatarWidgetX = centerX - avatarWidget->width() / 2;
    int avatarWidgetY = centerY - avatarWidget->height() / 2;

    avatarWidget->xPos = avatarWidgetX;
    avatarWidget->yPos = avatarWidgetY;

    avatarWidget->setGeometry(avatarWidgetX, avatarWidgetY, avatarWidget->height(), avatarWidget->width());

//    QVBoxLayout *layout = new QVBoxLayout(centralWidget());

    avatarWidget->setDiameter(40);

//    dialog = new QDialog(this);
//    QLabel *label = new QLabel("You are going west!", dialog);
//    QVBoxLayout *dialog_layout = new QVBoxLayout(dialog);
//    dialog_layout->addWidget(label, 0, Qt::AlignCenter);

//    dialog->setLayout(dialog_layout);
    QString title = "Zork | Text-Based View";
    setWindowTitle(title);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionText_Based_triggered()
{
    QString title = "Zork | Text-Based View";
    setWindowTitle(title);
}


void MainWindow::on_actionGUI_Based_triggered()
{
    QString title = "Zork | GUI-Based View";
    setWindowTitle(title);

}


void MainWindow::disable_buttons() {

    QPushButton *northButton = this->ui->northButton;
    QPushButton *southButton = this->ui->southButton;
    QPushButton *eastButton = this->ui->eastButton;
    QPushButton *westButton = this->ui->westButton;

    westButton->setEnabled(false);
    northButton->setEnabled(false);
    eastButton->setEnabled(false);
    southButton->setEnabled(false);

}

void MainWindow::enable_buttons() {

    QPushButton *northButton = this->ui->northButton;
    QPushButton *southButton = this->ui->southButton;
    QPushButton *eastButton = this->ui->eastButton;
    QPushButton *westButton = this->ui->westButton;

    northButton->setEnabled(true);
    southButton->setEnabled(true);
    eastButton->setEnabled(true);
    westButton->setEnabled(true);

}


void MainWindow::on_westButton_clicked()
{

    AvatarWidget *avatarWidget = this->avatarWidget;


    avatarWidget->moveDirection(-50, 0);

//    QPropertyAnimation *animation = new QPropertyAnimation(avatarWidget, "pos");

//    animation->setDuration(200);

//    QPoint startPos = avatarWidget->pos();
//    QPoint endPos = QPoint(startPos.x() - 50, startPos.y());
//    animation->setStartValue(startPos);
//    animation->setEndValue(endPos);

//    animation->start();

}


void MainWindow::on_southButton_clicked()
{
    AvatarWidget *avatarWidget = this->avatarWidget;

    avatarWidget->moveDirection(0, 50);
}


void MainWindow::on_northButton_clicked()
{

    AvatarWidget *avatarWidget = this->avatarWidget;

//    int newX = avatarWidget->x();
//    int newY = avatarWidget->y() - 100;
//    avatarWidget->move(newX, newY);

    avatarWidget->moveDirection(0, -50);

}


void MainWindow::on_eastButton_clicked()
{

    AvatarWidget *avatarWidget = this->avatarWidget;

//    int oldX = avatarWidget->x();
//    int oldY = avatarWidget->y();
//    int newX = oldX + 100;

    avatarWidget->moveDirection(50, 0);

}

