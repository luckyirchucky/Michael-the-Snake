#include "snake.h"
#include "ui_snake.h"
#include "mainwindow.h"

Snake::Snake(LevelWindow* lvl, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Snake)
{
    ui->setupUi(this);
    this->addLevel(lvl); //выбранный уровень сложности

    //установка фонового изображения
    QPixmap trava(QCoreApplication::applicationDirPath() +  QDir::toNativeSeparators(QDir::separator()) + "trava.png");
    trava = trava.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, trava);
    this->setPalette(palette);

    //окно проигрыша
    over = new GameOverWindow();
    connect(over, &GameOverWindow::SnakeWindow, this, &Snake::show);

    //окно выигрыша
    win = new winWindow();
    connect(win, &winWindow::SnakeWindow, this, &Snake::show);

    //напрвления движения
    leftDirection = false;
    rightDirection = false;
    upDirection = false;
    downDirection = false;

    inGame = true; //игра не окончена

    resize(s.GetInstance()->width(), s.GetInstance()->heigth()); //установкар размера игрового поля
    img.load_all(); //загрузка игровых изображений
    initGame();     //инициализая, установка на начальные позиции элементов

    timer = new QTimer(this); //таймер для обновления позиций яблок
    connect(timer, SIGNAL(timeout()), this, SLOT(newlocateApple()));
    connect(timer, SIGNAL(timeout()), this, SLOT(newlocateApple2()));
    connect(timer, SIGNAL(timeout()), this, SLOT(newlocateApple3()));
    connect(timer, SIGNAL(timeout()), this, SLOT(locateApple()));
    timer->start(5000); //смена позиций каждые 5 сек

    ui->label_2->setText(QString::number(get_apple())); //оставшееся кол-во яблок

    m.play_mus(); //воспроизведение музыки во время игры
}

//уровень сложности
void Snake::addLevel(LevelWindow* lvl){
   this->l=lvl;
}

Snake::~Snake()
{
    delete ui;
    delete over;
    delete win;
    delete l;
}

void Snake::initGame() {

    dots = 3; //изначальный размер змеюки

    for (int z = 0; z < dots; z++) { //позиция начальная змеюки
        x[z] = 150 - z * 60;
        y[z] = 150;
    }

    //установки мячей и яблок в начале игры
    locateBall();
    locateBall2();
    locateBall3();
    locateBall4();
    locateApple();
    newlocateApple();
    newlocateApple2();
    newlocateApple3();

    timerId = startTimer(l->get_speed_snake()); //скорость объектов
}

void Snake::paintEvent(QPaintEvent *e) {

    Q_UNUSED(e);

    doDrawing(); //отрисовка
}

int Snake::get_apple(){
    return l->count_apple; //кол-во яблок
}

void Snake::doDrawing() {

    QPainter qp(this);

    if (inGame) { //пока игра не окончена

        if (get_apple() == 0){ //если яблоки закончились
            timer->stop(); //остановка таймера
            draw = false;  //яблоки не рисуются
            qp.drawImage(nora_x, nora_y, img.nora); //отрисовка норки
            locateNora(); //установка норки на игровом поле
        }

        if(draw == true){ //пока яблоки не съедены, отрисовка
            qp.drawImage(apple_x, apple_y, img.apple);
            qp.drawImage(apple2_x, apple2_y, img.apple);
            qp.drawImage(apple3_x, apple3_y, img.apple);
            qp.drawImage(apple4_x, apple4_y, img.apple);
        }

        //отрисовка мячей
        qp.drawImage(ball_x, ball_y, img.ball);
        qp.drawImage(ball2_x, ball2_y, img.ball);
        qp.drawImage(ball3_x, ball3_y, img.ball);
        qp.drawImage(ball4_x, ball4_y, img.ball);

        //отрисовка змеюки
        for (int z = 0; z < dots; z++) {
            if (z == 0) { //вначале отрисовка головы
                qp.drawImage(x[z], y[z], img.head);
            } else { //потом туловища
                qp.drawImage(x[z], y[z], img.dot);
            }
        }

    } else {
        this->close(); //закрытие игрового окна
    }
}

//конец игры
void Snake::gameOver() {
    emit firstWindow(); //вызов главного меню
    over->setFixedSize(800, 900); //установка размера окна
    over->show(); //открытия окна проигрыша
    over->setWindowTitle("Проигрыш");   
    this->close(); //закрытие игрового окна
    m.play_stop(); //остановка воспроизведения игровой музыки
    m.lose_mus();  //включения музыки при поражении
}

void Snake::checkApple() {
 if (draw == true){ //если не все яблоки съедены
    if ((x[0] == apple_x) && (y[0] == apple_y)){ //если Майк съел яблоко

        dots++; //увеличение длины Майка
        l->count_apple--; //уменьшение кол-ва яблок
        ui->label_2->setText(QString::number(get_apple())); //отображение кол_ва яблок
        locateApple(); //установка нового яблока
    }

    if ((x[0] == apple2_x) && (y[0] == apple2_y)){

        dots++;
        l->count_apple--;
        ui->label_2->setText(QString::number(get_apple()));
        newlocateApple();
    }

    if ((x[0] == apple3_x) && (y[0] == apple3_y)){

        dots++;
        l->count_apple--;
        ui->label_2->setText(QString::number(get_apple()));
        newlocateApple2();
    }

    if ((x[0] == apple4_x) && (y[0] == apple4_y)){

        dots++;
        l->count_apple--;
        ui->label_2->setText(QString::number(get_apple()));
        newlocateApple3();
    }

 } else {

    Nora(); //иначе установка на поле норки
 }
}

void Snake::checkBall() {

    if ((x[0] == ball_x) && (y[0] == ball_y)) { //если в голову Майка прилетел мяч

        inGame = false; //конец игры
        gameOver();     //открытие окна проигрыша
    }

    if ((x[0] == ball2_x) && (y[0] == ball2_y)) {

        inGame = false;
        gameOver();
    }

    if ((x[0] == ball3_x) && (y[0] == ball3_y)) {

        inGame = false;
        gameOver();
    }

    if ((x[0] == ball4_x) && (y[0] == ball4_y)) {

        inGame = false;
        gameOver();
    }

}

void Snake::Nora(){

    if ((x[0] == nora_x) && (y[0] == nora_y)){ //если майк залез в норку

        inGame = false; //конец игры
        emit firstWindow(); //открытие окна главного меню
        this->close(); //закрытие игрового окна
        win->setFixedSize(800, 900); //фиксированный размер окна
        win->show(); //открытие победного окна
        win->setWindowTitle("Победа");
        m.win_mus(); //включение музыки победы
        m.play_stop(); //выключение игровой музыки
    }
}

void Snake::move_ball(){

     //если змеюка ползет влево или вниз
     if ((downDirection || leftDirection) && ball_x < s.GetInstance()->width()-390) {
         ball_x += s.GetInstance()->size_dot(); //мяч движется вправо
     }
     //если змеюка ползет вправо или вверх
     if ((upDirection || rightDirection) && ball_x > 300) {
         ball_x -= s.GetInstance()->size_dot(); //мяч движется влево
     }
}

void Snake::move_ball2(){

    if ((downDirection || leftDirection) && ball2_x < s.GetInstance()->width()-390) {
        ball2_x += s.GetInstance()->size_dot();
    }
    if ((upDirection || rightDirection) && ball2_x > 300) {
        ball2_x -= s.GetInstance()->size_dot();
    }
}

void Snake::move_ball3(){

    if ((downDirection || leftDirection) && ball3_y > 0) {
        ball3_y -= s.GetInstance()->size_dot();
    }
    if ((upDirection || rightDirection) && ball3_y < s.GetInstance()->heigth()-30) {
        ball3_y += s.GetInstance()->size_dot();
    }
}

void Snake::move_ball4(){

    if ((downDirection || leftDirection) && ball4_y  > 0) {
        ball4_y -= s.GetInstance()->size_dot();
    }
    if ((upDirection || rightDirection) && ball4_y < s.GetInstance()->heigth()-30) {
        ball4_y += s.GetInstance()->size_dot();
    }
}

void Snake::move() {

    //движение всей змеюки вслед за головой
    for (int z = dots; z > 0; z--) {
        x[z] = x[(z - 1)];
        y[z] = y[(z - 1)];
    }

    //влево
    if (leftDirection) {
        x[0] -= s.GetInstance()->size_dot();
    }

    //вправо
    if (rightDirection) {
        x[0] += s.GetInstance()->size_dot();
    }

    //вверх
    if (upDirection) {
        y[0] -= s.GetInstance()->size_dot();
    }

    //вниз
    if (downDirection) {
        y[0] += s.GetInstance()->size_dot();
    }
}

void Snake::checkCollision() {

    //если змеюка врезалась сама в себя, то конец игры
    for (int z = dots; z > 0; z--) {

        if ((z > 4) && (x[0] == x[z]) && (y[0] == y[z])) {
            inGame = false;
            gameOver();
        }
    }

    //если змеюка вышла за пределы игрового поля, то конец игры
    if (y[0] >= s.GetInstance()->heigth()) {
        inGame = false;
        gameOver();
    }

    if (y[0] < 0) {
        inGame = false;
        gameOver();
    }

    if (x[0] >= s.GetInstance()->width()) {
        inGame = false;
        gameOver();
    }

    if (x[0] < 0) {
        inGame = false;
        gameOver();
    }

    //если конец игры, то остановка движения объектов
    if(!inGame) {
        killTimer(timerId);
    }
}

void Snake::locateNora() {

    //установка норки на игровом поле
    nora_x = (10 * s.GetInstance()->size_dot());
    nora_y = (1 * s.GetInstance()->size_dot());
}

//установка яблок через рандом на игровом поле
void Snake::locateApple() {

    QTime time = QTime::currentTime();
    QRandomGenerator qrand ((uint) time.msec());

    int r = qrand() % s.GetInstance()->rand_pos();
    apple_x = (r * s.GetInstance()->size_dot());

    r = qrand() % s.GetInstance()->rand_pos();
    apple_y = (r * s.GetInstance()->size_dot());
}

void Snake::newlocateApple() {

    QTime time = QTime::currentTime();
    QRandomGenerator qrand ((uint) time.msec());

    int r = qrand() % s.GetInstance()->rand_pos()-3;
    apple2_x = (r * s.GetInstance()->size_dot());

    r = qrand() % s.GetInstance()->rand_pos()+6;
    apple2_y = (r * s.GetInstance()->size_dot());
}

void Snake::newlocateApple2() {

    QTime time = QTime::currentTime();
    QRandomGenerator qrand ((uint) time.msec());

    int r = qrand() % s.GetInstance()->rand_pos()-5;
    apple3_x = (r * s.GetInstance()->size_dot());

    r = qrand() % s.GetInstance()->rand_pos()-6;
    apple3_y = (r * s.GetInstance()->size_dot());

}

void Snake::newlocateApple3() {

    QTime time = QTime::currentTime();
    QRandomGenerator qrand ((uint) time.msec());

    int r = qrand() % s.GetInstance()->rand_pos()+6;
    apple4_x = (r * s.GetInstance()->size_dot());

    r = qrand() % s.GetInstance()->rand_pos()+4;
    apple4_y = (r * s.GetInstance()->size_dot());
}

//установка мячей на игровом поле
void Snake::locateBall() {
    ball_x = (10 * s.GetInstance()->size_dot());
    ball_y = (10 * s.GetInstance()->size_dot());
}

void Snake::locateBall2() {
    ball2_x = (10 * s.GetInstance()->size_dot());
    ball2_y = (20 * s.GetInstance()->size_dot());
}

void Snake::locateBall3() {
    ball3_x = (9 * s.GetInstance()->size_dot());
    ball3_y = (10 * s.GetInstance()->size_dot());
}

void Snake::locateBall4() {
    ball4_x = (18 * s.GetInstance()->size_dot());
    ball4_y = (10 * s.GetInstance()->size_dot());
}

void Snake::timerEvent(QTimerEvent *e) {

    Q_UNUSED(e);

    if (inGame) { //пока игра не окончена

        //проверка на съеденные яблоки
        checkApple();
        checkBall();
        checkCollision();

        //движения мячей
        move();
        move_ball();
        move_ball2();
        move_ball3();
        move_ball4();

        //проверка на попадание в норку
        Nora();
    }

    repaint(); //перерисовка объектов при движении
}

void Snake::keyPressEvent(QKeyEvent *e) {

    int key = e->key();

    //движение влево, если змеюка не движется вправо по нажатию на клаве <-
    if ((key == Qt::Key_Left) && (!rightDirection) ) {
        leftDirection = true;
        upDirection = false;
        downDirection = false;
    }

    //движение вправо, если змеюка не движется влево по нажатию на клаве ->
    if ((key == Qt::Key_Right) && (!leftDirection)) {
        rightDirection = true;
        upDirection = false;
        downDirection = false;
    }

    //движение вверх, если змеюка не движется вниз
    if ((key == Qt::Key_Up) && (!downDirection)) {
        upDirection = true;
        rightDirection = false;
        leftDirection = false;

        /*img.head = img.head.transformed([](QPoint center) {
               QMatrix matrix;
               matrix.translate(center.x(), center.y());
               matrix.rotate(-180);
               return matrix;
        }(img.head.rect().center()));*/
    }

    //движение вниз, если змеюка не движется вверх
    if ((key == Qt::Key_Down) && (!upDirection)) {
        downDirection = true;
        rightDirection = false;
        leftDirection = false;
    }

    QWidget::keyPressEvent(e);
}

