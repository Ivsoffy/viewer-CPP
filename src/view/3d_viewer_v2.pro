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
ICON = ../../misc/3d_viewer_logo.icns

TARGET = 3d_viewer_v2

OBJECTS_DIR = $$PWD/../build/obj/3d_viewer_v2

SOURCES +=         \
    ../controller/Controller.cc \
    ../controller/ControllerDTO.cc \
    ../model/AffineTransformations.cc \
    ../model/Facade.cc \
    ../model/Figure.cc \
    ../model/FileParser.cc \
    main.cpp       \
    mainwindow.cpp \
    oglwidget.cpp

HEADERS +=       \
    ../controller/Controller.h \
    ../controller/ControllerDTO.h \
    ../model/AffineTransformations.h \
    ../model/Facade.h \
    ../model/Figure.h \
    ../model/Vertex.h \
    mainwindow.h \
    oglwidget.h

FORMS += mainwindow.ui \

DISTFILES += \

SUBDIRS += \

qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
