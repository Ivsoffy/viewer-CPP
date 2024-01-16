macx: {
QT += core gui openglwidgets
}
unix:!macx {
QT += core gui opengl widgets
LIBS += -lglut -lGLU # только для линукс
}
include(QtGifImage/src/gifimage/qtgifimage.pri)

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

TARGET = 3d_viewer_v2

OBJECTS_DIR = $$PWD/../build/obj/3d_viewer_v2

SOURCES +=         \
    ../controller/controller.cc \
    ../controller/controller_dto.cc \
    ../model/affine_transformations.cc \
    ../model/facade.cc \
    ../model/figure.cc \
    ../model/file_parser.cc \
#    ../model/snapshot.cc \
    main.cpp       \
    mainwindow.cpp \
    oglwidget.cpp

HEADERS +=       \
    ../controller/controller.h \
    ../controller/controller_dto.h \
    ../model/ snapshot.h \
    ../model/affine_transformations.h \
    ../model/facade.h \
    ../model/figure.h \
    ../model/snapshot.h \
    ../model/vertex.h \
    mainwindow.h \
    oglwidget.h

FORMS += mainwindow.ui \

DISTFILES += \

SUBDIRS += \

qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
