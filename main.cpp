#include "mainwindow.h"
#include <QApplication>
#include "snake.h"
#include "loading.h"

int main(int argc, char *argv[])
{
    QApplication  a(argc, argv);

    //загрузочная заставка
    Loading l;
    QSplashScreen splash(QPixmap(QCoreApplication::applicationDirPath() +  QDir::toNativeSeparators(QDir::separator()) + "splash.png"));
    splash.show();
    l.load(&splash);

    //меню игры
    MainWindow w;
    w.setWindowTitle("Главное меню");
    w.setFixedSize(800, 900);
    w.show();
    splash.close();
    return a.exec();
}
