#include "gameoverwindow.h"
#include "ui_gameoverwindow.h"

GameOverWindow::GameOverWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GameOverWindow)
{
    ui->setupUi(this);

    //установка фонового изображения
    QPixmap trava(QCoreApplication::applicationDirPath() +  QDir::toNativeSeparators(QDir::separator())  + "trava.png");
    trava = trava.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, trava);
    this->setPalette(palette);
}

GameOverWindow::~GameOverWindow()
{
    delete ui;
    delete mus;
}

void GameOverWindow::on_Exit_clicked()
{
    this->close();
    mus->main_mus(); //включение музыки главного меню
    //QProcess::startDetached(QApplication::applicationFilePath(), QStringList(), QApplication::applicationDirPath());
    emit SnakeWindow(); //вызываем сигнал на открытие предыдущего окна
}
