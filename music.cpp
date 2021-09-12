#include "music.h"

void Music::main_mus(){
    music = new QMediaPlayer();
    music->setMedia(QUrl::fromLocalFile(QCoreApplication::applicationDirPath() +  QDir::toNativeSeparators(QDir::separator()) + "main.mp3")); //чтение муз. файла
    music->setVolume(100); //установка громкости
    music->play();         //включение музыки

    repeat = new QMediaPlaylist(); //повтор музыкальной композиции
    repeat->setPlaybackMode(QMediaPlaylist::CurrentItemInLoop);
}

void Music::main_stop(){
    music->stop(); //остановка воспроизведения муз. файла
}


void Music::play_mus(){
    music2 = new QMediaPlayer();
    music2->setMedia(QUrl::fromLocalFile(QCoreApplication::applicationDirPath() +  QDir::toNativeSeparators(QDir::separator()) + "playing.mp3"));
    music2->setVolume(100);
    music2->play();

    repeat = new QMediaPlaylist();
    repeat->setPlaybackMode(QMediaPlaylist::Loop);
}

void Music::play_stop(){
    music2->stop();
}

void Music::win_mus(){
    music = new QMediaPlayer();
    music->setMedia(QUrl::fromLocalFile(QCoreApplication::applicationDirPath() +  QDir::toNativeSeparators(QDir::separator()) + "win.mp3"));
    music->setVolume(100);
    music->play();

    repeat = new QMediaPlaylist();
    repeat->setPlaybackMode(QMediaPlaylist::Loop);
}

void Music::lose_mus(){
    music3 = new QMediaPlayer();
    music3->setMedia(QUrl::fromLocalFile(QCoreApplication::applicationDirPath() +  QDir::toNativeSeparators(QDir::separator()) + "lose.mp3"));
    music3->setVolume(100);
    music3->play();

    repeat = new QMediaPlaylist();
    repeat->setPlaybackMode(QMediaPlaylist::Loop);
}
