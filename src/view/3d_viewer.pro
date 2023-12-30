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
    ../model/gl_model.cpp \
    ../model/AffineTransformations.cc \
    ../model/Figure.cc \
    ../model/FileParser.cc \
    ../controller/Controller.cc \
    main.cpp       \
    mainwindow.cpp \
    oglwidget.cpp

HEADERS +=       \
    ../model/gl_model.h \
    ../model/AffineTransformations.h \
    ../model/Figure.h \
    ../model/FileParser.h \
    ../model/Vertex.h \
    ../controller/Controller.h \
    mainwindow.h \
    oglwidget.h

FORMS += \
    mainwindow.ui
