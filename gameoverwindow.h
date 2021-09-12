#ifndef GAMEOVERWINDOW_H
#define GAMEOVERWINDOW_H

#include <QWidget>
#include <QProcess>
#include <QApplication>
#include "music.h"
#include <QDir>

namespace Ui {
class GameOverWindow;
}

class GameOverWindow : public QWidget
{
    Q_OBJECT

public:
    explicit GameOverWindow(QWidget *parent = nullptr);
    ~GameOverWindow();

private slots:
    void on_Exit_clicked(); //выход из окна

signals:
    void SnakeWindow(); //сигнал на возврат

private:
    Ui::GameOverWindow *ui;
    Music *mus = new Music;
};

#endif // GAMEOVERWINDOW_H
