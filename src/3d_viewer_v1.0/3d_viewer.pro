TEMPLATE = app
TARGET = 3d_viewer_v1.0

include(QtGifImage/src/gifimage/qtgifimage.pri)

DESTDIR = $$PWD/../build
INCLUDEPATH += .
UI_DIR += $$PWD
MOC_DIR = $$PWD/tmp
OBJECTS_DIR = $$PWD/../obj/3d_viewer_v1.0

CONFIG += c++17
QMAKE_CC = gcc

QT += core gui
QT += opengl
QT += openglwidgets
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

SOURCES +=         \
    ../3d_viewer_lib/object_to_object_data.c \
    ../3d_viewer_lib/object_to_object_data_sup.c \
    gl_model.cpp \
    main.cpp       \
    mainwindow.cpp \
    oglwidget.cpp

HEADERS +=       \
    ../3d_viewer_lib/3d_viewer.h \
    ../3d_viewer_lib/3d_viewer_sup.h \
    gl_model.h \
    mainwindow.h \
    oglwidget.h

FORMS += \
    mainwindow.ui

LIBS += "../lib3d_viewer.a"
