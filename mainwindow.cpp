#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "avatarwidget.h"
#include "heroavatar.h"
#include "monster.h"
#include "dialog.h"
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

}

MainWindow::~MainWindow()
{
    delete ui;
}

//void game2() {
//        qDebug() << "RAN";
//    runGame(":/images/desert.png", ":/images/gremlin.png", ":/images/gold.png", new Item("Gold"), nullptr);
//}

void MainWindow::start() {

//    extern std::vector<Level*> levels;

    runGame(&Level::levels[0]);

//    runGame(new Level(":/images/field.png", ":/images/goblin.png", ":/images/sword.png", new Item("Sword")));

}

int MainWindow::runGame(Level *level) {

    ui->setupUi(this);
    hide_text_elements();
    setFocusPolicy(Qt::StrongFocus);

    Dialog *deadDialog = new Dialog(this, new QPointF(100, 100), ":images/you-died.png");
    Dialog *wonDialog = new Dialog(this, new QPointF(100, 100), ":images/you-won.png");

    deadDialog->hide();
    wonDialog->hide();

    AvatarWidget *monsterAvatar = new AvatarWidget(this, new QPointF(100, 100), level->monsterPath);
    AvatarWidget *item1Avatar = new AvatarWidget(this, new QPointF(0, 450), level->item1->imagePath);
    AvatarWidget *item2Avatar = new AvatarWidget(this, new QPointF(380, 550), level->item2->imagePath);
    AvatarWidget *item3Avatar = new AvatarWidget(this, new QPointF(400, 50), level->item3->imagePath);

    item1 = level->item1;
    item2 = level->item2;
    item3 = level->item3;

    item1->avatar = item1Avatar;
    item2->avatar = item2Avatar;
    item3->avatar = item3Avatar;
    monster = new Monster(item2, monsterAvatar);
    hero = new Hero(deadDialog, wonDialog, this);

    HeroAvatar *heroAvatar = new HeroAvatar(this, new QPointF(651, 350), ":images/hero.png", monster, item1, item2, item3);
    hero->avatar = heroAvatar;

    QPixmap pixmap(level->mapPath.c_str());
    pixmap = pixmap.scaled(QSize(770, 770));
    QPalette palette;
    palette.setBrush(QPalette::Window, pixmap);
    this->setPalette(palette);

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

    QString title = "Zork | GUI-Based View";
    setWindowTitle(title);

    show();

    return 0;
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
    QPalette palette;
    this->setPalette(palette);
}


void MainWindow::on_actionGUI_Based_triggered()
{
    QString title = "Zork | GUI-Based View";
    setWindowTitle(title);
    this->hide_text_elements();
    this->show_ui_elements();
    QPixmap pixmap(":images/field.png");
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

//    HeroAvatar *heroAvatar = this->hero;


    hero->moveDirection(-50, 0);

}


void MainWindow::southclicked()
{
//    HeroAvatar *heroAvatar = this->hero;

    hero->moveDirection(0, 50);
}


void MainWindow::northclicked()
{

//    HeroAvatar *heroAvatar = this->hero;

//    int newX = heroAvatar->x();
//    int newY = heroAvatar->y() - 100;
//    heroAvatar->move(newX, newY);

    hero->moveDirection(0, -50);

}


void MainWindow::eastclicked()
{

//    HeroAvatar *heroAvatar = this->hero;

//    int oldX = heroAvatar->x();
//    int oldY = heroAvatar->y();
//    int newX = oldX + 100;

    hero->moveDirection(50, 0);

}

void MainWindow::hide_ui_elements()
{

    this->northButton->hide();
    this->southButton->hide();
    this->eastButton->hide();
    this->westButton->hide();

    this->hero->avatar->hide();
    this->monster->avatar->hide();
    this->item1->avatar->hide();

}

void MainWindow::show_ui_elements()
{

    this->northButton->show();
    this->southButton->show();
    this->eastButton->show();
    this->westButton->show();

    this->hero->avatar->show();
    this->monster->avatar->show();
    this->item1->avatar->show();

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

void MainWindow::resetGame(){
    this->hero->avatar->deleteLater();
    this->monster->avatar->deleteLater();
    this->item1->avatar->deleteLater();
}
