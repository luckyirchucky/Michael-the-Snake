#ifndef WINWINDOW_H
#define WINWINDOW_H

#include <QWidget>
#include <QProcess>
#include <QApplication>
#include <QDir>
#include "music.h"

namespace Ui {
class winWindow;
}

class winWindow : public QWidget
{
    Q_OBJECT

public:
    explicit winWindow(QWidget *parent = nullptr);
    ~winWindow();

private slots:
    void on_Exit_clicked(); //выход из проигрышного окна

signals:
    void SnakeWindow(); //сигнал на возврат

private:
    Ui::winWindow *ui;
    Music *mus = new Music; //музыка
};

#endif // WINWINDOW_H
