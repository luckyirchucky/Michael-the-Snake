#include "singleton.h"

Singleton* Singleton::instance = 0;

Singleton* Singleton::GetInstance() {
  if(instance == 0)
     instance = new Singleton;
  return instance;
}

//размер игрового элемена
int Singleton::size_dot(){
    return 30;
}

//ширина игрового поля
int Singleton::width(){
    return 900;
}

//высота игрового поля
int Singleton::heigth(){
    return 900;
}

//максимальное кол-во элементов на поле
int Singleton::all_dots(){
    return 900;
}

//позиция элемента для рандома
int Singleton::rand_pos(){
    return 29;
}
