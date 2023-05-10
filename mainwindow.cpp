#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "avatarwidget.h"
#include "heroavatar.h"
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
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

//    ui->centralwidget->

//    ui->textBrowser->hide();
//    ui->lineEdit->hide();

    hide_text_elements();

    setFocusPolicy(Qt::StrongFocus);

    heroAvatar = new HeroAvatar(this, new QPointF(651, 350), ":images/hero.png");

    std::string mapPath = ":/images/field.png";

//    QPixmap pixmap(":/images/field.png");
//    pixmap = pixmap.scaled(QSize(770, 770));
//    QPalette palette;
//    palette.setBrush(QPalette::Window, pixmap);
//    this->setPalette(palette);

    AvatarWidget *monster = new AvatarWidget(this, new QPointF(100, 100), ":images/demon.png");

    AvatarWidget *tool = new AvatarWidget(this, new QPointF(0, 450), ":images/sword.png");

    currentLevel = new Level(this, heroAvatar, monster, tool, mapPath);
    currentLevel->generateLevel();

    this->northButton = new QPushButton("North", this);
    this->southButton = new QPushButton("South", this);
    this->eastButton = new QPushButton("East", this);
    this->westButton = new QPushButton("West", this);

    this->northButton->setGeometry(620, 580, 60, 50);
    this->southButton->setGeometry(620, 680, 60, 50);
    this->eastButton->setGeometry(670, 630, 60, 50);
    this->westButton->setGeometry(570, 630, 60, 50);

    connect(this->northButton, &QPushButton::clicked, this, &MainWindow::northclicked);
    connect(this->southButton, &QPushButton::clicked, this, &MainWindow::southclicked);
    connect(this->eastButton, &QPushButton::clicked, this, &MainWindow::eastclicked);
    connect(this->westButton, &QPushButton::clicked, this, &MainWindow::westclicked);

//    for(int i = 0; i < 3; i++) {



//    }

    QString title = "Zork | GUI-Based View";
    setWindowTitle(title);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent *event) {

    if(event->key() == Qt::Key_Up || event->key() == Qt::Key_W) {
        this->northclicked();
    }
    if(event->key() == Qt::Key_Down || event->key() == Qt::Key_S) {
        this->southclicked();
    }
    if(event->key() == Qt::Key_Right || event->key() == Qt::Key_D) {
        this->eastclicked();
    }
    if(event->key() == Qt::Key_Left || event->key() == Qt::Key_A) {
        this->westclicked();
    }

}

void MainWindow::on_actionText_Based_triggered()
{
    QString title = "Zork | Text-Based View";
    setWindowTitle(title);
    this->hide_ui_elements();
    this->show_text_elements();
//    this->setStyleSheet("#MainWindow { background-image: ; }" "#MainWindow:size { height: 1000px; width: 1000px; }");
    QPalette palette;
    this->setPalette(palette);
}


void MainWindow::on_actionGUI_Based_triggered()
{
    QString title = "Zork | GUI-Based View";
    setWindowTitle(title);
    this->hide_text_elements();
    this->show_ui_elements();
    QPixmap pixmap(this->currentLevel->mapPath.c_str());
    pixmap = pixmap.scaled(QSize(770, 770));
    QPalette palette;
    palette.setBrush(QPalette::Window, pixmap);
    this->setPalette(palette);
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


void MainWindow::westclicked()
{

    HeroAvatar *heroAvatar = this->currentLevel->hero;


    heroAvatar->moveDirection(-50, 0);

}


void MainWindow::southclicked()
{
    HeroAvatar *heroAvatar = this->currentLevel->hero;

    heroAvatar->moveDirection(0, 50);
}


void MainWindow::northclicked()
{

    HeroAvatar *heroAvatar = this->currentLevel->hero;

//    int newX = heroAvatar->x();
//    int newY = heroAvatar->y() - 100;
//    heroAvatar->move(newX, newY);

    heroAvatar->moveDirection(0, -50);

}


void MainWindow::eastclicked()
{

    HeroAvatar *heroAvatar = this->currentLevel->hero;

//    int oldX = heroAvatar->x();
//    int oldY = heroAvatar->y();
//    int newX = oldX + 100;

    heroAvatar->moveDirection(50, 0);

}

void MainWindow::hide_ui_elements()
{

    this->northButton->hide();
    this->southButton->hide();
    this->eastButton->hide();
    this->westButton->hide();

    this->heroAvatar->hide();

}

void MainWindow::show_ui_elements()
{

    this->northButton->show();
    this->southButton->show();
    this->eastButton->show();
    this->westButton->show();

    this->heroAvatar->show();

}

void MainWindow::show_text_elements(){

    this->ui->textBrowser->show();
    ui->lineEdit->show();
    ui->pushButton->show();

}

void MainWindow::hide_text_elements(){

    this->ui->textBrowser->hide();
    ui->lineEdit->hide();
    ui->pushButton->hide();

}
