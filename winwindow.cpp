#include "winwindow.h"
#include "ui_winwindow.h"

winWindow::winWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::winWindow)
{
    ui->setupUi(this);

    //установка фонового изображения
    QPixmap trava(QCoreApplication::applicationDirPath() +  QDir::toNativeSeparators(QDir::separator()) + "trava.png");
    trava = trava.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, trava);
    this->setPalette(palette);

}

winWindow::~winWindow()
{
    delete ui;
    delete mus;
}

void winWindow::on_Exit_clicked()
{
    this->close();      //закрываем окно
    mus->main_mus();     //воспроизведение музыки главного меню
    //QProcess::startDetached(QApplication::applicationFilePath(), QStringList(), QApplication::applicationDirPath());
    emit SnakeWindow(); //сигнал на возврат в предыдущее окно
}
