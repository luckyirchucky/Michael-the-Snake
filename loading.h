#ifndef LOADING_H
#define LOADING_H
#include <QApplication>
#include <QLabel>
#include <QSplashScreen>
#include <QPainter>
#include <QTime>

static const int LOAD_TIME_MSEC = 5 * 1000;
static const int PROGRESS_X_PX = 272;
static const int PROGRESS_Y_PX = 333;
static const int PROGRESS_WIDTH_PX = 310;
static const int PROGRESS_HEIGHT_PX = 28;

class Loading
{
public:
    void load(QSplashScreen* psplash); //загрузочная заставка
};

#endif // LOADING_H
