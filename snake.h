#ifndef SNAKE_H
#define SNAKE_H

#include <QMainWindow>
#include <QKeyEvent>
#include <QThread>
#include <QCoreApplication>
#include <QPainter>
#include <QTime>
#include <QDir>
#include <QTimer>
#include <QRandomGenerator>
#include "levelwindow.h"
#include "gameoverwindow.h"
#include "winwindow.h"
#include "music.h"
#include "images.h"
#include "singleton.h"

namespace Ui {
class Snake;
}

class Snake : public QMainWindow
{
    Q_OBJECT

public:
    explicit Snake(LevelWindow*, QWidget *parent = nullptr);
    ~Snake();

protected:
    void paintEvent(QPaintEvent *);  //отрисовка игровых элементов
    void timerEvent(QTimerEvent *);  //таймер в игре
    void keyPressEvent(QKeyEvent *); //управление с клавиатуры

public slots:
    int get_apple(); //кол-во яблок
    void addLevel(LevelWindow* lvl); //выбор уровня сложности
    //установка яблок
    void locateApple();
    void newlocateApple();
    void newlocateApple2();
    void newlocateApple3();

signals:
    void firstWindow(); //сигнал на возврат в главное меню

private:
    GameOverWindow *over; //окно проигрыша
    winWindow *win;       //окно победы
    QTimer *timer;        //включение таймера
    Music m;              //загрузка музыки
    Singleton s;          //использование констант с помощью паттерна
    Images img;           //загрузка игровых изображений
    LevelWindow *l;       //уровень сложности
    Ui::Snake *ui;

    int timerId;          //скорость передвижения объектов
    int dots;             //части  змеи

    bool draw = true;     //отрисовка объектов, пока все яблоки не съедены

    //координаты яблок
    int apple_x;
    int apple_y;
    int apple2_x;
    int apple2_y;
    int apple3_x;
    int apple3_y;
    int apple4_x;
    int apple4_y;

    //координаты норки
    int nora_x;
    int nora_y;

    //координаты мячей
    int ball_x;
    int ball_y;
    int ball2_x;
    int ball2_y;
    int ball3_x;
    int ball3_y;
    int ball4_x;
    int ball4_y;

    //координаты поля
    int x[900];
    int y[900];

    //направления движения змеи/мячей
    bool leftDirection;
    bool rightDirection;
    bool upDirection;
    bool downDirection;

    bool inGame; //пока не конец игры

    //проверка на съеденное яблоко
    void checkApple();
    void checkBall();
    void checkCollision();

    void Nora(); //попадание в норку

    //движение мячей
    void move();
    void move_ball();
    void move_ball2();
    void move_ball3();
    void move_ball4();

    void initGame(); //инициализация(начальная установка всех элементов)
    void doDrawing();//отрисовка игровых объектов
    void gameOver(); //конец игры

    void locateNora(); //установка норки на поле

    //установка мячей на поле
    void locateBall();
    void locateBall2();
    void locateBall3();
    void locateBall4();
};

#endif // SNAKE_H
