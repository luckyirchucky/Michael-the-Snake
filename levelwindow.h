#ifndef LEVELWINDOW_H
#define LEVELWINDOW_H

#include <QWidget>
#include <QDir>

namespace Ui {
class LevelWindow;
}

class LevelWindow : public QWidget
{
    Q_OBJECT

public:
    explicit LevelWindow(QWidget *parent = nullptr);
    ~LevelWindow();
    int speed_snake;
    int count_apple = 10;
    int get_speed_snake(); //скорость змеюки и мячей
    int get_count_apple(); //количество яблок для поедания

signals:
    void firstWindow();  //сигнал на открытие первого окна

public slots:
    void on_pushButton_clicked(); //выход в главное меню

private:
    Ui::LevelWindow *ui;
};

#endif // LEVELWINDOW_H
