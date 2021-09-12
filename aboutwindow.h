#ifndef ABOUTWINDOW_H
#define ABOUTWINDOW_H

#include <QWidget>
#include <QDir>

namespace Ui {
class AboutWindow;
}

class AboutWindow : public QWidget
{
    Q_OBJECT

public:
    explicit AboutWindow(QWidget *parent = nullptr);
    ~AboutWindow();

private slots:
    void on_pushButton_clicked(); //выход в главное меню

signals:
    void firstWindow();  // Сигнал для открытия первого окна

private:
    Ui::AboutWindow *ui;
};

#endif // ABOUTWINDOW_H
