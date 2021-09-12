#include "loading.h"

void Loading::load(QSplashScreen* psplash)
{
    QTime time;
    time.start();

    //загрузка игры
    for (int i = 0; i < 100; ) {
        if (time.elapsed() > 5) {
            time.start();
            ++i;
        }

        //сообщение о загрузке и его свойства
        psplash->showMessage("Loading modules: "
        + QString::number(i) + "%",
        Qt::AlignRight | Qt::AlignBottom,
        Qt::black);
    }
}
