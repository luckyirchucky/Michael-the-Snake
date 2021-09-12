#ifndef CONTROLWINDOW_H
#define CONTROLWINDOW_H

#include <QWidget>
#include <QDir>

namespace Ui {
class ControlWindow;
}

class ControlWindow : public QWidget
{
    Q_OBJECT

public:
    explicit ControlWindow(QWidget *parent = nullptr);
    ~ControlWindow();

signals:
    void firstWindow();  // Сигнал на открытие первого окна

private slots:
    void on_pushButton_clicked(); //выход в главное меню

private:
    Ui::ControlWindow *ui;
};

#endif // CONTROLWINDOW_H
