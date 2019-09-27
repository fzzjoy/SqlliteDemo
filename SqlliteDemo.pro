#-------------------------------------------------
#
# Project created by QtCreator 2019-09-26T01:42:42
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SqlliteDemo
TEMPLATE = app

win32:CONFIG(release, debug|release): DESTDIR += $$PWD/release/win32
else:win32:CONFIG(debug, debug|release): DESTDIR += $$PWD/debug/win32
else:unix:!macx:CONFIG(release, debug|release): DESTDIR += $$PWD/release/linux_x86_64
else:unix:!macx:CONFIG(debug, debug|release): DESTDIR += $$PWD/debug/linux_x86_64

CONFIG += c++14

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    login_register_widget.cpp \
    search_dialog.cpp \
    utils.cpp

HEADERS += \
        mainwindow.h \
    login_register_widget.h \
    search_dialog.h \
    utils.h

FORMS += \
        mainwindow.ui \
    login_register_widget.ui \
    search_dialog.ui
