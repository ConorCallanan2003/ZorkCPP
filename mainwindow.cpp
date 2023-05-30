#include "mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::start() {
    runGame(Level::levels[0]);
}

int MainWindow::runGame(Level *level) {

    ui->setupUi(this);
    hide_text_elements();
    setFocusPolicy(Qt::StrongFocus);

    extern LevelInfo levelInfo;

    ui->label->text() = QString::number(getScore(levelInfo));

    ui->textBrowser->insertHtml("<h1>Welcome!</h1><p>You find yourself in a VERY dangerous place. You will meet many monsters, but also the tools necessary to defeat them. Choose wisely...</p>");
    ui->textBrowser->insertHtml("<br><br><code>COMMANDS AVAILABLE: goto {item or monster}, take {item}, kill {monster}</code>");
    std::string itemsString = "";
    itemsString += level->items[0]->name + ", a ";
    itemsString += level->items[1]->name + ", and a ";
    itemsString += level->items[2]->name + ".";

    std::string string1 = "<br><br>You are in a " + level->name + ". You see a " + level->monster->name + ", a " + itemsString;
    ui->textBrowser->insertHtml(QString::fromStdString(string1));
//    ui->textBrowser->insertHtml();

    extern int levelIndex;

    currentLevel = Level::levels[levelIndex];

    deadDialog = new Dialog(this, new QPointF(100, 150), ":images/you-died.png");
    wonDialog = new Dialog(this, new QPointF(100, 100), ":images/you-won.png");

    congratsDialog = new Dialog(this, new QPointF(100, 0), ":images/congrats.png");
    congratsDialog->lower();

    deadDialog->hide();
    wonDialog->hide();

    items = level->items;

    std::vector<QPointF*> points = {new QPointF(0, 450), new QPointF(350, 550), new QPointF(400, 50)};

    for (int var = 0; var < level->items.size(); ++var) {
        AvatarWidget *newItemAvatar = new AvatarWidget(this, points[var], level->items[var]->imagePath);
        Item *newItem = items[var];
        newItem->avatar = newItemAvatar;
    }

    level->monster->avatar = new AvatarWidget(this, new QPointF(100, 100), level->monster->path);

    hero = new Hero(deadDialog, wonDialog, this);

    HeroAvatar *heroAvatar = new HeroAvatar(this, new QPointF(651, 350), ":images/hero.png", level->monster, hero, items, this);
    hero->avatar = heroAvatar;

    QPixmap pixmap(level->mapPath.c_str());
    pixmap = pixmap.scaled(QSize(770, 770));
    QPalette palette;
    palette.setBrush(QPalette::Window, pixmap);
    this->setPalette(palette);

    ui->label->raise();

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
    hero->avatar->moveDirection(-50, 0);
}


void MainWindow::southclicked()
{
    hero->avatar->moveDirection(0, 50);
}


void MainWindow::northclicked()
{

    hero->avatar->moveDirection(0, -50);

}


void MainWindow::eastclicked()
{

   hero->avatar->moveDirection(50, 0);

}

void MainWindow::hide_ui_elements()
{

    this->northButton->hide();
    this->southButton->hide();
    this->eastButton->hide();
    this->westButton->hide();

    if(this->hero->avatar->path != "") {
        this->hero->avatar->hide();
    }
    if(this->currentLevel->monster->avatar->path != "") {
        this->currentLevel->monster->avatar->hide();
    }
    foreach (Item* item, this->items) {
        if(item->avatar->path != "") {
            item->avatar->hide();
        }
    }

}

void MainWindow::show_ui_elements()
{

    this->northButton->show();
    this->southButton->show();
    this->eastButton->show();
    this->westButton->show();

    if(this->hero->avatar->path != "") {
        this->hero->avatar->show();
    }
    if(this->currentLevel->monster->avatar->path != "") {
        this->currentLevel->monster->avatar->show();
    }
    foreach (Item* item, this->items) {
        if(item->avatar->path != "") {
            item->avatar->show();
        }
    }

}

void MainWindow::show_text_elements(){
    if(this->ui->textBrowser != nullptr && ui->lineEdit != nullptr && ui->submitButton) {
        this->ui->textBrowser->show();
        ui->lineEdit->show();
        ui->submitButton->show();
    }
}

void MainWindow::hide_text_elements(){

    this->ui->textBrowser->hide();
    ui->lineEdit->hide();
    ui->submitButton->hide();

}

void MainWindow::resetGame(){
    this->hero->avatar->deleteLater();
    this->currentLevel->monster->avatar->deleteLater();
    foreach (Item* item, this->items) {
        item->avatar->deleteLater();
    }
}

void MainWindow::on_submitButton_clicked()
{
    this->ui->textBrowser->clear();
    QLineEdit *lineEdit = this->ui->lineEdit;
    std::string result = commandHandler->handleCommand(lineEdit->text().toStdString(), currentLevel, hero);
    if(result == "survived") {
        this->close();
    }
//    if(result == "dead") {
//    }
    this->ui->textBrowser->insertHtml(QString(result.c_str()));

    lineEdit->clear();
//    hero->moveTo(new QPoint(0, 0));
}

template <typename T>
T multiply(T a, T b) {
    return a * b;
}

int MainWindow::getScore(LevelInfo levelInfo) {
    return multiply(levelInfo.round, levelInfo.score);
}
