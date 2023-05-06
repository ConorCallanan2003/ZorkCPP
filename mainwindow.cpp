#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "avatarwidget.h"
#include <iostream>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <thread>
#include <QPropertyAnimation>
#include <QPalette>
#include <QSize>
#include <QKeyEvent>
#include <QPointF>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->textEdit->hide();

    setFocusPolicy(Qt::StrongFocus);

    avatarWidget = new AvatarWidget(this, new QPointF(651, 350), ":images/hero.png");

    QPixmap pixmap(":/images/field.png");
    pixmap = pixmap.scaled(QSize(770, 770));
    QPalette palette;
    palette.setBrush(QPalette::Window, pixmap);
    this->setPalette(palette);

    QPushButton *northButton = new QPushButton("North", this);
    QPushButton *southButton = new QPushButton("South", this);
    QPushButton *eastButton = new QPushButton("East", this);
    QPushButton *westButton = new QPushButton("West", this);

    northButton->setGeometry(620, 580, 60, 50);
    southButton->setGeometry(620, 680, 60, 50);
    eastButton->setGeometry(670, 630, 60, 50);
    westButton->setGeometry(570, 630, 60, 50);

    connect(northButton, &QPushButton::clicked, this, &MainWindow::on_northButton_clicked);
    connect(southButton, &QPushButton::clicked, this, &MainWindow::on_southButton_clicked);
    connect(eastButton, &QPushButton::clicked, this, &MainWindow::on_eastButton_clicked);
    connect(westButton, &QPushButton::clicked, this, &MainWindow::on_westButton_clicked);

    QString title = "Zork | GUI-Based View";
    setWindowTitle(title);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent *event) {

    if(event->key() == Qt::Key_Up || event->key() == Qt::Key_W) {
        this->on_northButton_clicked();
    }
    if(event->key() == Qt::Key_Down || event->key() == Qt::Key_S) {
        this->on_southButton_clicked();
    }
    if(event->key() == Qt::Key_Right || event->key() == Qt::Key_D) {
        this->on_eastButton_clicked();
    }
    if(event->key() == Qt::Key_Left || event->key() == Qt::Key_A) {
        this->on_westButton_clicked();
    }

}

void MainWindow::on_actionText_Based_triggered()
{
    QString title = "Zork | Text-Based View";
    setWindowTitle(title);
    this->hide_ui_elements();
    this->show_text_elements();
    this->setStyleSheet("#MainWindow { background-image: ; }" "#MainWindow:size { height: 1000px; width: 1000px; }");
}


void MainWindow::on_actionGUI_Based_triggered()
{
    QString title = "Zork | GUI-Based View";
    setWindowTitle(title);
    this->hide_text_elements();
    this->show_ui_elements();
    this->setStyleSheet("#MainWindow { background-image: url(:/images/map.png); background-repeat: no-repeat; background-position: center;}" "#MainWindow:size { height: 1000px; width: 1000px; }");
}


void MainWindow::disable_buttons() {

    QPushButton *northButton = this->northButton;
    QPushButton *southButton = this->southButton;
    QPushButton *eastButton = this->eastButton;
    QPushButton *westButton = this->westButton;

    westButton->setEnabled(false);
    northButton->setEnabled(false);
    eastButton->setEnabled(false);
    southButton->setEnabled(false);

}

void MainWindow::enable_buttons() {

    QPushButton *northButton = this->northButton;
    QPushButton *southButton = this->southButton;
    QPushButton *eastButton = this->eastButton;
    QPushButton *westButton = this->westButton;

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

void MainWindow::hide_ui_elements()
{

    this->northButton->hide();
    this->southButton->hide();
    this->eastButton->hide();
    this->westButton->hide();

    this->avatarWidget->hide();

}

void MainWindow::show_ui_elements()
{

    this->northButton->show();
    this->southButton->show();
    this->eastButton->show();
    this->westButton->show();

    this->avatarWidget->show();

}

void MainWindow::show_text_elements(){

    this->ui->textEdit->show();

}

void MainWindow::hide_text_elements(){

    this->ui->textEdit->hide();

}
