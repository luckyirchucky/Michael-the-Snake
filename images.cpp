#include "images.h"

void Images::load_all(){
    dot.load(QCoreApplication::applicationDirPath() +  QDir::toNativeSeparators(QDir::separator())  + "dot.png");
    head.load(QCoreApplication::applicationDirPath() +  QDir::toNativeSeparators(QDir::separator())  + "head.png");
    ball.load(QCoreApplication::applicationDirPath() +  QDir::toNativeSeparators(QDir::separator())  + "ball.png");
    nora.load(QCoreApplication::applicationDirPath() +  QDir::toNativeSeparators(QDir::separator())  + "nora.png");
    apple.load(QCoreApplication::applicationDirPath() +  QDir::toNativeSeparators(QDir::separator())  + "apple.png");
}
