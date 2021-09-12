#ifndef MUSIC_H
#define MUSIC_H

#include <QWidget>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QDir>
#include <QApplication>

class Music : public QWidget
{
    Q_OBJECT

public:

    QMediaPlayer * music;
    QMediaPlayer * music2;
    QMediaPlayer * music3;
    QMediaPlaylist * repeat;

    void main_mus(); //загрузка музыки в главном меню
    void main_stop();//остановка музыки
    void play_mus(); //загрузка музыки для игры
    void play_stop();//остановка музыки
    void win_mus();  //загрузка музыки при победе
    void lose_mus(); //загрузка музыки при проигрыше
};

#endif // MUSIC_H
