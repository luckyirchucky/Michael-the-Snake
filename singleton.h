#ifndef SINGLETON_H
#define SINGLETON_H

class Singleton
{

public:
    static Singleton *GetInstance();
    int size_dot();//размер яблока / 1й части змеи
    int width();   //ширина поля
    int heigth();  //высота поля
    int all_dots();//максимальное количество возможных точек на доске (900*900)/(30*30)
    int rand_pos();//для вычисления случайной позиции яблока

private:
    static Singleton * instance;
};

#endif // SINGLETON_H
