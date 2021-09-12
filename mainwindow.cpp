#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    mus->main_mus(); //музыка главного меню

    //установка фонового изображения
    QPixmap trava(QCoreApplication::applicationDirPath() +  QDir::toNativeSeparators(QDir::separator())  + "cover.png");
    trava = trava.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, trava);
    this->setPalette(palette);

    //окно описания игры
    about = new AboutWindow();
    connect(about, &AboutWindow::firstWindow, this, &MainWindow::show);

    //окно управления в игре
    control = new ControlWindow();
    connect(control, &ControlWindow::firstWindow, this, &MainWindow::show);

    //окно выбора уровня сложности
    level = new LevelWindow();
    connect(level, &LevelWindow::firstWindow, this, &MainWindow::show);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete mus;
    delete about;
    delete level;
    delete control;
    delete window;
}

//играть в змеюку
void MainWindow::on_Play_clicked()
{
    //окно игры
    window = new Snake(level);
    connect(window, &Snake::firstWindow, this, &MainWindow::show);

    window->setWindowTitle("Змеюка"); //установка названия окна
    window->setFixedSize(900, 900);   //фиксированный размер окна
    window->show();                   //открытие окна игры
    this->close();                    //закрытие окна меню
}

//выход из игры
void MainWindow::on_pushButton_clicked()
{
    this->close();
}

//выбор сложности
void MainWindow::on_pushButton_2_clicked()
{
    level->setFixedSize(800, 900);
    level->show();
    level->setWindowTitle("Уровень сложности");
    this->close();
}

//об игре
void MainWindow::on_About_clicked()
{
    about->setFixedSize(800, 900);
    about->show();
    about->setWindowTitle("Об игре");
    this->close();
}

//управление в игре
void MainWindow::on_Control_clicked()
{
    control->setFixedSize(800, 900);
    control->show();
    control->setWindowTitle("Как играть");
    this->close();
}
