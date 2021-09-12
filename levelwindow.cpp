#include "levelwindow.h"
#include "ui_levelwindow.h"
#include <QTime>
#include <QRandomGenerator>

LevelWindow::LevelWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LevelWindow)
{
    ui->setupUi(this);

    //установка фонового изображения
    QPixmap trava(QCoreApplication::applicationDirPath() +  QDir::toNativeSeparators(QDir::separator()) + "trava.png");
    trava = trava.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, trava);
    this->setPalette(palette);

    connect(ui->radioButton, SIGNAL(toggled()), this, SLOT(isChecked()));
    connect(ui->radioButton_2, SIGNAL(toggled()), this, SLOT(isChecked()));
    connect(ui->radioButton_3, SIGNAL(toggled()), this, SLOT(isChecked()));
    connect(ui->radioButton_4, SIGNAL(toggled()), this, SLOT(isChecked()));
    ui->radioButton->setChecked(true); //изначально выбран легкий уровень сложности
    ui->radioButton_2->setChecked(false);
    ui->radioButton_3->setChecked(false);
    ui->radioButton_4->setChecked(false);

}

LevelWindow::~LevelWindow()
{
    delete ui;
}

//в главное меню
void LevelWindow::on_pushButton_clicked()
{
    this->count_apple = get_count_apple(); //выбранное кол-во яблок
    this->speed_snake = get_speed_snake(); //выбранная скорость
    this->close();      // Закрываем окно
    emit firstWindow(); // И вызываем сигнал на открытие главного окна
}

int LevelWindow::get_speed_snake()
{
    QTime time = QTime::currentTime();
    QRandomGenerator qrand ((uint) time.msec());

    if (ui->radioButton->isChecked()){ //выбор скорости
        speed_snake = 120 + (qrand() % 1);
        return speed_snake;
    }
    if (ui->radioButton_2->isChecked()){
        speed_snake = 100 + (qrand() % 1);
        return speed_snake;
    }
    if (ui->radioButton_3->isChecked()){
        speed_snake = 80 + (qrand() % 1);
        return speed_snake;
    }
    if (ui->radioButton_4->isChecked()){
        speed_snake = 120 + (qrand() % (120-100)+1);
        return speed_snake;
    }
    speed_snake = 0;
    return speed_snake;
}

int LevelWindow::get_count_apple()
{
    QTime time = QTime::currentTime();
    QRandomGenerator qrand ((uint) time.msec());

    if (ui->radioButton->isChecked()){  //выбор кол-ва яблок
        count_apple = 10 + (qrand() % 1);
        return count_apple;
    }
    if (ui->radioButton_2->isChecked()){
        count_apple = 15 + (qrand() % 1);
        return count_apple;
    }
    if (ui->radioButton_3->isChecked()){
        count_apple = 20 + (qrand() % 1);
        return count_apple;
    }
    if (ui->radioButton_4->isChecked()){
        count_apple = 10 + (qrand() % (20-10)+1);
        return count_apple;
    }
    return count_apple;
}
