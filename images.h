#ifndef IMAGES_H
#define IMAGES_H

#include <QWidget>
#include <QDir>
#include <QApplication>

class Images : public QWidget
{
    Q_OBJECT

public:
    QImage dot;  //1 часть тела змеи или яблоко
    QImage head; //голова
    QImage apple;//яблоко
    QImage trava;//трава
    QImage ball; //мяч
    QImage nora; //норень

    void load_all(); //загрузка изображений
};

#endif // IMAGES_H
