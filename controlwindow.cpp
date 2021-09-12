#include "controlwindow.h"
#include "ui_controlwindow.h"

ControlWindow::ControlWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ControlWindow)
{
    ui->setupUi(this);

    //установка фонового изображения
    QPixmap trava(QCoreApplication::applicationDirPath() +  QDir::toNativeSeparators(QDir::separator())  + "control.png");
    trava = trava.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, trava);
    this->setPalette(palette);
}

ControlWindow::~ControlWindow()
{
    delete ui;
}

void ControlWindow::on_pushButton_clicked()
{
    this->close();      // Закрываем окно
    emit firstWindow(); // И вызываем сигнал на открытие главного окна
}
