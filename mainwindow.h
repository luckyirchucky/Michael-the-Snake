#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "snake.h"
#include "aboutwindow.h"
#include "controlwindow.h"
#include "levelwindow.h"
#include "music.h"
#include <QDir>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_Play_clicked();         //играть в игру
    void on_pushButton_clicked();   //выход из игры
    void on_pushButton_2_clicked(); //уровень сложности
    void on_About_clicked();        //информация об игре
    void on_Control_clicked();      //информация об управлении в игре

private:
    Ui::MainWindow *ui;    //главное окно
    AboutWindow *about;    //окно описания игры
    ControlWindow *control;//окно управления в игре
    LevelWindow *level;    //окно уровней сложности
    Snake *window;         //окно игры
    Music *mus = new Music;//музыка
};
#endif // MAINWINDOW_H
