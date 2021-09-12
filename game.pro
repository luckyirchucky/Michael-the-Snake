QT       += core gui
QT       += multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    aboutwindow.cpp \
    controlwindow.cpp \
    gameoverwindow.cpp \
    images.cpp \
    levelwindow.cpp \
    loading.cpp \
    main.cpp \
    mainwindow.cpp \
    music.cpp \
    singleton.cpp \
    snake.cpp \
    winwindow.cpp

HEADERS += \
    aboutwindow.h \
    controlwindow.h \
    gameoverwindow.h \
    images.h \
    levelwindow.h \
    loading.h \
    mainwindow.h \
    music.h \
    singleton.h \
    snake.h \
    winwindow.h

FORMS += \
    aboutwindow.ui \
    controlwindow.ui \
    gameoverwindow.ui \
    levelwindow.ui \
    mainwindow.ui \
    snake.ui \
    winwindow.ui

win32: RC_ICONS = $$PWD/head.ico

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
