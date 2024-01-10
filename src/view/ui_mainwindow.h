/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>
#include <oglwidget.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QFrame *frame_settings_file;
    QPushButton *pushButton_file_open;
    QLineEdit *lineEdit_file_input;
    QLabel *label_file_input;
    QPushButton *pushButton_file_select;
    QFrame *frame_settings_move;
    QFrame *frame_settings_move_rotate;
    QLabel *label_settings_move_rotate_info;
    QLabel *label_settings_move_rotate_x;
    QLabel *label_settings_move_rotate_y;
    QLabel *label_settings_move_rotate_z;
    QSlider *slider_rot_x;
    QSlider *slider_rot_y;
    QSpinBox *spinbox_rot_y;
    QSpinBox *spinbox_rot_z;
    QSpinBox *spinbox_rot_x;
    QSlider *slider_rot_z;
    QFrame *frame_settings_move_move;
    QLabel *label_settings_move_move_info;
    QLabel *label_settings_move_move_x;
    QLabel *label_settings_move_move_y;
    QLabel *label_settings_move_move_z;
    QSpinBox *spinbox_move_x;
    QSlider *slider_move_x;
    QSlider *slider_move_y;
    QSpinBox *spinbox_move_y;
    QSpinBox *spinbox_move_z;
    QSlider *slider_move_z;
    QFrame *frame_settings_move_scale;
    QLabel *label_settings_move_scale;
    QFrame *frame_screen;
    QFrame *frame_screen_2;
    QLabel *label_screen;
    QLabel *label_screen_gif;
    QComboBox *comboBox_screen_unit;
    QPushButton *pushButton_screen_start;
    QPushButton *pushButton_screen_gif_start;
    QFrame *frame_open_gl;
    OGLwidget *openGLWidget;
    QFrame *frame_settings_view;
    QFrame *frame_settings_view_polygon;
    QComboBox *comboBox_settings_view_polygon_type;
    QLabel *label_settings_view_polygon_type;
    QLabel *label_settings_view_polygon_width;
    QDoubleSpinBox *doubleSpinBox_settings_view_polygon_width;
    QPushButton *pushButton_settings_view_polygon_color;
    QLabel *label_settings_view_polygon_color;
    QFrame *frame_settings_view_vertex;
    QLabel *label_settings_view_vertex_size;
    QLabel *label_settings_view_vertex_color;
    QDoubleSpinBox *doubleSpinBox_settings_view_vertex_size;
    QPushButton *pushButton_settings_view_vertex_color;
    QComboBox *comboBox_settings_view_vertex_type;
    QLabel *label_settings_view_polygon_display;
    QFrame *frame_settings_view_other;
    QComboBox *comboBox_settings_view_projection_type;
    QPushButton *pushButton_settings_view_other_color;
    QLabel *label_settings_view_other_type;
    QLabel *label_settings_view_other_color;
    QLabel *label_info;
    QFrame *frame_info;
    QFrame *frame_info_object_info_2;
    QLabel *label_info_object_info_file_name_2;
    QLabel *label_info_object_info_vertex_count_2;
    QLabel *label_info_object_info_polygon_count_2;
    QLabel *label_info_object_info_file_name_ans_2;
    QLabel *label_info_object_info_vertex_count_ans_2;
    QLabel *label_info_object_info_polygon_count_ans_2;
    QSlider *slider_scale;
    QDoubleSpinBox *double_spinbox_scale;
    QSlider *slider_scale_2;
    QSpinBox *spinbox_scale_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1070, 570);
        MainWindow->setMinimumSize(QSize(1070, 570));
        MainWindow->setMaximumSize(QSize(1130, 570));
        MainWindow->setStyleSheet(QString::fromUtf8("QMainWindow {\n"
"	background: rgb(60, 60, 60);\n"
"}\n"
"QPushButton {\n"
"	color: rgb(204, 204, 204);\n"
"}\n"
"QLabel {\n"
"	color: rgb(204, 204, 204);\n"
" }\n"
"QLineEdit {\n"
"	color: rgb(204, 204, 204);\n"
" }\n"
"QComboBox {\n"
"	color: rgb(204, 204, 204);\n"
" }\n"
"QDoubleSpinBox {\n"
"	color: rgb(204, 204, 204);\n"
" }"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        frame_settings_file = new QFrame(centralwidget);
        frame_settings_file->setObjectName(QString::fromUtf8("frame_settings_file"));
        frame_settings_file->setGeometry(QRect(255, 10, 303, 52));
        frame_settings_file->setStyleSheet(QString::fromUtf8("border: 2px  solid rgb(150, 150, 150) ;\n"
"background-color: rgb(50, 50, 50);"));
        frame_settings_file->setFrameShape(QFrame::StyledPanel);
        frame_settings_file->setFrameShadow(QFrame::Raised);
        pushButton_file_open = new QPushButton(frame_settings_file);
        pushButton_file_open->setObjectName(QString::fromUtf8("pushButton_file_open"));
        pushButton_file_open->setGeometry(QRect(1, 1, 301, 21));
        pushButton_file_open->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"     border: 1px  solid rgb(150, 150, 150) ;\n"
"	background-color: rgb(64, 140, 191);\n"
" }\n"
"\n"
" QPushButton:pressed {\n"
"	border: 1px solid rgb(150, 150, 150) ;\n"
"     background-color:  rgb(84, 160, 211);\n"
" }\n"
"\n"
"\n"
""));
        lineEdit_file_input = new QLineEdit(frame_settings_file);
        lineEdit_file_input->setObjectName(QString::fromUtf8("lineEdit_file_input"));
        lineEdit_file_input->setGeometry(QRect(60, 20, 201, 31));
        lineEdit_file_input->setStyleSheet(QString::fromUtf8("\n"
"border: 1px  solid rgb(150, 150, 150) ;\n"
"background-color: rgb(50, 50, 50);\n"
" \n"
"\n"
"\n"
"\n"
""));
        lineEdit_file_input->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_file_input = new QLabel(frame_settings_file);
        label_file_input->setObjectName(QString::fromUtf8("label_file_input"));
        label_file_input->setGeometry(QRect(1, 20, 61, 31));
        label_file_input->setStyleSheet(QString::fromUtf8("border: 1px  solid rgb(150, 150, 150) ;\n"
"background-color: rgb(50, 50, 50);\n"
" \n"
"\n"
"\n"
"\n"
""));
        label_file_input->setAlignment(Qt::AlignCenter);
        pushButton_file_select = new QPushButton(frame_settings_file);
        pushButton_file_select->setObjectName(QString::fromUtf8("pushButton_file_select"));
        pushButton_file_select->setGeometry(QRect(260, 20, 42, 31));
        pushButton_file_select->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"     border: 1px  solid rgb(150, 150, 150) ;\n"
"	background-color: rgb(30, 35, 45);\n"
" }\n"
"\n"
" QPushButton:pressed {\n"
"	border: 1px solid rgb(150, 150, 150) ;\n"
"     background-color:  rgb(50, 55, 65);\n"
" }\n"
"\n"
"\n"
""));
        frame_settings_move = new QFrame(centralwidget);
        frame_settings_move->setObjectName(QString::fromUtf8("frame_settings_move"));
        frame_settings_move->setGeometry(QRect(255, 65, 303, 263));
        frame_settings_move->setStyleSheet(QString::fromUtf8("border: 2px  solid rgb(150, 150, 150) ;\n"
"background-color: rgb(50, 50, 50);"));
        frame_settings_move->setFrameShape(QFrame::StyledPanel);
        frame_settings_move->setFrameShadow(QFrame::Raised);
        frame_settings_move_rotate = new QFrame(frame_settings_move);
        frame_settings_move_rotate->setObjectName(QString::fromUtf8("frame_settings_move_rotate"));
        frame_settings_move_rotate->setGeometry(QRect(150, 0, 151, 213));
        frame_settings_move_rotate->setStyleSheet(QString::fromUtf8("border: 2px  solid rgb(150, 150, 150) ;\n"
"background-color: rgb(50, 50, 50);"));
        frame_settings_move_rotate->setFrameShape(QFrame::StyledPanel);
        frame_settings_move_rotate->setFrameShadow(QFrame::Raised);
        label_settings_move_rotate_info = new QLabel(frame_settings_move_rotate);
        label_settings_move_rotate_info->setObjectName(QString::fromUtf8("label_settings_move_rotate_info"));
        label_settings_move_rotate_info->setGeometry(QRect(1, 1, 151, 31));
        label_settings_move_rotate_info->setStyleSheet(QString::fromUtf8("border: 1px  solid rgb(150, 150, 150) ;\n"
"background-color: rgb(50, 50, 50);\n"
" \n"
"\n"
"\n"
"\n"
""));
        label_settings_move_rotate_info->setAlignment(Qt::AlignCenter);
        label_settings_move_rotate_x = new QLabel(frame_settings_move_rotate);
        label_settings_move_rotate_x->setObjectName(QString::fromUtf8("label_settings_move_rotate_x"));
        label_settings_move_rotate_x->setGeometry(QRect(1, 31, 41, 61));
        label_settings_move_rotate_x->setStyleSheet(QString::fromUtf8("border: 1px  solid rgb(150, 150, 150) ;\n"
"background-color: rgb(50, 50, 50);\n"
" \n"
"\n"
"\n"
"\n"
""));
        label_settings_move_rotate_x->setAlignment(Qt::AlignCenter);
        label_settings_move_rotate_y = new QLabel(frame_settings_move_rotate);
        label_settings_move_rotate_y->setObjectName(QString::fromUtf8("label_settings_move_rotate_y"));
        label_settings_move_rotate_y->setGeometry(QRect(1, 91, 41, 61));
        label_settings_move_rotate_y->setStyleSheet(QString::fromUtf8("border: 1px  solid rgb(150, 150, 150) ;\n"
"background-color: rgb(50, 50, 50);\n"
" \n"
"\n"
"\n"
"\n"
""));
        label_settings_move_rotate_y->setAlignment(Qt::AlignCenter);
        label_settings_move_rotate_z = new QLabel(frame_settings_move_rotate);
        label_settings_move_rotate_z->setObjectName(QString::fromUtf8("label_settings_move_rotate_z"));
        label_settings_move_rotate_z->setGeometry(QRect(1, 151, 41, 61));
        label_settings_move_rotate_z->setStyleSheet(QString::fromUtf8("border: 1px  solid rgb(150, 150, 150) ;\n"
"background-color: rgb(50, 50, 50);\n"
" \n"
"\n"
"\n"
"\n"
""));
        label_settings_move_rotate_z->setAlignment(Qt::AlignCenter);
        slider_rot_x = new QSlider(frame_settings_move_rotate);
        slider_rot_x->setObjectName(QString::fromUtf8("slider_rot_x"));
        slider_rot_x->setGeometry(QRect(39, 64, 111, 31));
        slider_rot_x->setMinimum(-180);
        slider_rot_x->setMaximum(180);
        slider_rot_x->setOrientation(Qt::Horizontal);
        slider_rot_y = new QSlider(frame_settings_move_rotate);
        slider_rot_y->setObjectName(QString::fromUtf8("slider_rot_y"));
        slider_rot_y->setGeometry(QRect(40, 120, 111, 31));
        slider_rot_y->setMinimum(-180);
        slider_rot_y->setMaximum(180);
        slider_rot_y->setOrientation(Qt::Horizontal);
        spinbox_rot_y = new QSpinBox(frame_settings_move_rotate);
        spinbox_rot_y->setObjectName(QString::fromUtf8("spinbox_rot_y"));
        spinbox_rot_y->setGeometry(QRect(40, 90, 111, 31));
        QFont font;
        font.setKerning(true);
        spinbox_rot_y->setFont(font);
        spinbox_rot_y->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        spinbox_rot_y->setMinimum(-180);
        spinbox_rot_y->setMaximum(180);
        spinbox_rot_z = new QSpinBox(frame_settings_move_rotate);
        spinbox_rot_z->setObjectName(QString::fromUtf8("spinbox_rot_z"));
        spinbox_rot_z->setGeometry(QRect(40, 150, 111, 31));
        spinbox_rot_z->setFont(font);
        spinbox_rot_z->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        spinbox_rot_z->setMinimum(-180);
        spinbox_rot_z->setMaximum(180);
        spinbox_rot_x = new QSpinBox(frame_settings_move_rotate);
        spinbox_rot_x->setObjectName(QString::fromUtf8("spinbox_rot_x"));
        spinbox_rot_x->setGeometry(QRect(40, 30, 111, 31));
        spinbox_rot_x->setFont(font);
        spinbox_rot_x->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        spinbox_rot_x->setMinimum(-180);
        spinbox_rot_x->setMaximum(180);
        slider_rot_z = new QSlider(frame_settings_move_rotate);
        slider_rot_z->setObjectName(QString::fromUtf8("slider_rot_z"));
        slider_rot_z->setGeometry(QRect(40, 180, 111, 31));
        slider_rot_z->setMinimum(-180);
        slider_rot_z->setMaximum(180);
        slider_rot_z->setOrientation(Qt::Horizontal);
        frame_settings_move_move = new QFrame(frame_settings_move);
        frame_settings_move_move->setObjectName(QString::fromUtf8("frame_settings_move_move"));
        frame_settings_move_move->setGeometry(QRect(0, 0, 151, 213));
        frame_settings_move_move->setStyleSheet(QString::fromUtf8("border: 2px  solid rgb(150, 150, 150) ;\n"
"background-color: rgb(50, 50, 50);"));
        frame_settings_move_move->setFrameShape(QFrame::StyledPanel);
        frame_settings_move_move->setFrameShadow(QFrame::Raised);
        label_settings_move_move_info = new QLabel(frame_settings_move_move);
        label_settings_move_move_info->setObjectName(QString::fromUtf8("label_settings_move_move_info"));
        label_settings_move_move_info->setGeometry(QRect(1, 1, 150, 31));
        label_settings_move_move_info->setStyleSheet(QString::fromUtf8("border: 1px  solid rgb(150, 150, 150) ;\n"
"background-color: rgb(50, 50, 50);\n"
" \n"
"\n"
"\n"
"\n"
""));
        label_settings_move_move_info->setAlignment(Qt::AlignCenter);
        label_settings_move_move_x = new QLabel(frame_settings_move_move);
        label_settings_move_move_x->setObjectName(QString::fromUtf8("label_settings_move_move_x"));
        label_settings_move_move_x->setGeometry(QRect(1, 31, 41, 61));
        label_settings_move_move_x->setStyleSheet(QString::fromUtf8("border: 1px  solid rgb(150, 150, 150) ;\n"
"background-color: rgb(50, 50, 50);\n"
" \n"
"\n"
"\n"
"\n"
""));
        label_settings_move_move_x->setAlignment(Qt::AlignCenter);
        label_settings_move_move_y = new QLabel(frame_settings_move_move);
        label_settings_move_move_y->setObjectName(QString::fromUtf8("label_settings_move_move_y"));
        label_settings_move_move_y->setGeometry(QRect(1, 91, 41, 61));
        label_settings_move_move_y->setStyleSheet(QString::fromUtf8("border: 1px  solid rgb(150, 150, 150) ;\n"
"background-color: rgb(50, 50, 50);\n"
" \n"
"\n"
"\n"
"\n"
""));
        label_settings_move_move_y->setAlignment(Qt::AlignCenter);
        label_settings_move_move_z = new QLabel(frame_settings_move_move);
        label_settings_move_move_z->setObjectName(QString::fromUtf8("label_settings_move_move_z"));
        label_settings_move_move_z->setGeometry(QRect(1, 151, 41, 61));
        label_settings_move_move_z->setStyleSheet(QString::fromUtf8("border: 1px  solid rgb(150, 150, 150) ;\n"
"background-color: rgb(50, 50, 50);\n"
" \n"
"\n"
"\n"
"\n"
""));
        label_settings_move_move_z->setAlignment(Qt::AlignCenter);
        spinbox_move_x = new QSpinBox(frame_settings_move_move);
        spinbox_move_x->setObjectName(QString::fromUtf8("spinbox_move_x"));
        spinbox_move_x->setGeometry(QRect(40, 30, 111, 31));
        spinbox_move_x->setFont(font);
        spinbox_move_x->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        spinbox_move_x->setMinimum(-100);
        spinbox_move_x->setMaximum(100);
        slider_move_x = new QSlider(frame_settings_move_move);
        slider_move_x->setObjectName(QString::fromUtf8("slider_move_x"));
        slider_move_x->setGeometry(QRect(40, 60, 111, 31));
        slider_move_x->setMinimum(-1000);
        slider_move_x->setMaximum(1000);
        slider_move_x->setOrientation(Qt::Horizontal);
        slider_move_y = new QSlider(frame_settings_move_move);
        slider_move_y->setObjectName(QString::fromUtf8("slider_move_y"));
        slider_move_y->setGeometry(QRect(40, 120, 111, 31));
        slider_move_y->setMinimum(-100);
        slider_move_y->setMaximum(100);
        slider_move_y->setOrientation(Qt::Horizontal);
        spinbox_move_y = new QSpinBox(frame_settings_move_move);
        spinbox_move_y->setObjectName(QString::fromUtf8("spinbox_move_y"));
        spinbox_move_y->setGeometry(QRect(40, 90, 111, 31));
        spinbox_move_y->setFont(font);
        spinbox_move_y->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        spinbox_move_y->setMinimum(-100);
        spinbox_move_y->setMaximum(100);
        spinbox_move_z = new QSpinBox(frame_settings_move_move);
        spinbox_move_z->setObjectName(QString::fromUtf8("spinbox_move_z"));
        spinbox_move_z->setGeometry(QRect(40, 150, 111, 31));
        spinbox_move_z->setFont(font);
        spinbox_move_z->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        spinbox_move_z->setMinimum(-100);
        spinbox_move_z->setMaximum(100);
        slider_move_z = new QSlider(frame_settings_move_move);
        slider_move_z->setObjectName(QString::fromUtf8("slider_move_z"));
        slider_move_z->setGeometry(QRect(40, 180, 111, 31));
        slider_move_z->setMinimum(-100);
        slider_move_z->setMaximum(100);
        slider_move_z->setOrientation(Qt::Horizontal);
        frame_settings_move_scale = new QFrame(frame_settings_move);
        frame_settings_move_scale->setObjectName(QString::fromUtf8("frame_settings_move_scale"));
        frame_settings_move_scale->setGeometry(QRect(0, 210, 303, 53));
        frame_settings_move_scale->setStyleSheet(QString::fromUtf8("border: 2px  solid rgb(150, 150, 150) ;\n"
"background-color: rgb(50, 50, 50);"));
        frame_settings_move_scale->setFrameShape(QFrame::StyledPanel);
        frame_settings_move_scale->setFrameShadow(QFrame::Raised);
        label_settings_move_scale = new QLabel(frame_settings_move_scale);
        label_settings_move_scale->setObjectName(QString::fromUtf8("label_settings_move_scale"));
        label_settings_move_scale->setGeometry(QRect(1, 1, 151, 51));
        label_settings_move_scale->setStyleSheet(QString::fromUtf8("border: 1px  solid rgb(150, 150, 150) ;\n"
"background-color: rgb(50, 50, 50);\n"
" \n"
"\n"
"\n"
"\n"
""));
        label_settings_move_scale->setAlignment(Qt::AlignCenter);
        frame_screen = new QFrame(centralwidget);
        frame_screen->setObjectName(QString::fromUtf8("frame_screen"));
        frame_screen->setGeometry(QRect(255, 330, 303, 63));
        frame_screen->setStyleSheet(QString::fromUtf8("border: 2px  solid rgb(150, 150, 150) ;\n"
"background-color: rgb(50, 50, 50);"));
        frame_screen->setFrameShape(QFrame::StyledPanel);
        frame_screen->setFrameShadow(QFrame::Raised);
        frame_screen_2 = new QFrame(frame_screen);
        frame_screen_2->setObjectName(QString::fromUtf8("frame_screen_2"));
        frame_screen_2->setGeometry(QRect(0, 0, 303, 63));
        frame_screen_2->setStyleSheet(QString::fromUtf8("border: 2px  solid rgb(150, 150, 150) ;\n"
"background-color: rgb(50, 50, 50);"));
        frame_screen_2->setFrameShape(QFrame::StyledPanel);
        frame_screen_2->setFrameShadow(QFrame::Raised);
        label_screen = new QLabel(frame_screen_2);
        label_screen->setObjectName(QString::fromUtf8("label_screen"));
        label_screen->setGeometry(QRect(1, 1, 150, 31));
        label_screen->setStyleSheet(QString::fromUtf8("border: 1px  solid rgb(150, 150, 150) ;\n"
"background-color: rgb(50, 50, 50);\n"
" \n"
"\n"
"\n"
"\n"
""));
        label_screen->setAlignment(Qt::AlignCenter);
        label_screen_gif = new QLabel(frame_screen_2);
        label_screen_gif->setObjectName(QString::fromUtf8("label_screen_gif"));
        label_screen_gif->setGeometry(QRect(1, 31, 150, 31));
        label_screen_gif->setStyleSheet(QString::fromUtf8("border: 1px  solid rgb(150, 150, 150) ;\n"
"background-color: rgb(50, 50, 50);\n"
" \n"
"\n"
"\n"
"\n"
""));
        label_screen_gif->setAlignment(Qt::AlignCenter);
        comboBox_screen_unit = new QComboBox(frame_screen_2);
        comboBox_screen_unit->addItem(QString());
        comboBox_screen_unit->addItem(QString());
        comboBox_screen_unit->setObjectName(QString::fromUtf8("comboBox_screen_unit"));
        comboBox_screen_unit->setGeometry(QRect(150, 1, 81, 31));
        comboBox_screen_unit->setStyleSheet(QString::fromUtf8("border: 1px  solid rgb(150, 150, 150) ;\n"
"background-color: rgb(50, 50, 50);"));
        pushButton_screen_start = new QPushButton(frame_screen_2);
        pushButton_screen_start->setObjectName(QString::fromUtf8("pushButton_screen_start"));
        pushButton_screen_start->setGeometry(QRect(230, 1, 72, 31));
        pushButton_screen_start->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"     border: 1px  solid rgb(150, 150, 150) ;\n"
"	background-color: rgb(64, 140, 191);\n"
" }\n"
"\n"
" QPushButton:pressed {\n"
"	border: 1px solid rgb(150, 150, 150) ;\n"
"     background-color:  rgb(84, 160, 211);\n"
" }\n"
"\n"
"\n"
""));
        pushButton_screen_gif_start = new QPushButton(frame_screen_2);
        pushButton_screen_gif_start->setObjectName(QString::fromUtf8("pushButton_screen_gif_start"));
        pushButton_screen_gif_start->setGeometry(QRect(150, 31, 152, 31));
        pushButton_screen_gif_start->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"     border: 1px  solid rgb(150, 150, 150) ;\n"
"	background-color: rgb(64, 140, 191);\n"
" }\n"
"\n"
" QPushButton:pressed {\n"
"	border: 1px solid rgb(150, 150, 150) ;\n"
"     background-color:  rgb(84, 160, 211);\n"
" }\n"
"\n"
"\n"
""));
        frame_open_gl = new QFrame(centralwidget);
        frame_open_gl->setObjectName(QString::fromUtf8("frame_open_gl"));
        frame_open_gl->setGeometry(QRect(560, 10, 502, 502));
        frame_open_gl->setStyleSheet(QString::fromUtf8("border: 2px  solid rgb(150, 150, 150) ;\n"
"background-color: rgb(50, 50, 50);"));
        frame_open_gl->setFrameShape(QFrame::StyledPanel);
        frame_open_gl->setFrameShadow(QFrame::Raised);
        openGLWidget = new OGLwidget(frame_open_gl);
        openGLWidget->setObjectName(QString::fromUtf8("openGLWidget"));
        openGLWidget->setGeometry(QRect(1, 1, 500, 500));
        openGLWidget->setMinimumSize(QSize(4, 0));
        openGLWidget->setStyleSheet(QString::fromUtf8("border: 3px  solid rgb(150, 150, 150) ;"));
        frame_settings_view = new QFrame(centralwidget);
        frame_settings_view->setObjectName(QString::fromUtf8("frame_settings_view"));
        frame_settings_view->setGeometry(QRect(10, 10, 241, 243));
        frame_settings_view->setStyleSheet(QString::fromUtf8("border: 2px  solid rgb(150, 150, 150) ;\n"
"background-color: rgb(50, 50, 50);"));
        frame_settings_view->setFrameShape(QFrame::StyledPanel);
        frame_settings_view->setFrameShadow(QFrame::Raised);
        frame_settings_view_polygon = new QFrame(frame_settings_view);
        frame_settings_view_polygon->setObjectName(QString::fromUtf8("frame_settings_view_polygon"));
        frame_settings_view_polygon->setGeometry(QRect(0, 60, 241, 91));
        frame_settings_view_polygon->setStyleSheet(QString::fromUtf8("border: 2px  solid rgb(150, 150, 150) ;\n"
"background-color: rgb(50, 50, 50);"));
        frame_settings_view_polygon->setFrameShape(QFrame::StyledPanel);
        frame_settings_view_polygon->setFrameShadow(QFrame::Raised);
        comboBox_settings_view_polygon_type = new QComboBox(frame_settings_view_polygon);
        comboBox_settings_view_polygon_type->addItem(QString());
        comboBox_settings_view_polygon_type->addItem(QString());
        comboBox_settings_view_polygon_type->setObjectName(QString::fromUtf8("comboBox_settings_view_polygon_type"));
        comboBox_settings_view_polygon_type->setGeometry(QRect(120, 0, 120, 31));
        comboBox_settings_view_polygon_type->setStyleSheet(QString::fromUtf8("border: 1px  solid rgb(150, 150, 150) ;\n"
"background-color: rgb(50, 50, 50);\n"
""));
        label_settings_view_polygon_type = new QLabel(frame_settings_view_polygon);
        label_settings_view_polygon_type->setObjectName(QString::fromUtf8("label_settings_view_polygon_type"));
        label_settings_view_polygon_type->setGeometry(QRect(1, 0, 120, 31));
        label_settings_view_polygon_type->setStyleSheet(QString::fromUtf8("border: 1px  solid rgb(150, 150, 150) ;\n"
"background-color: rgb(50, 50, 50);\n"
"\n"
" \n"
"\n"
"\n"
"\n"
""));
        label_settings_view_polygon_type->setAlignment(Qt::AlignCenter);
        label_settings_view_polygon_width = new QLabel(frame_settings_view_polygon);
        label_settings_view_polygon_width->setObjectName(QString::fromUtf8("label_settings_view_polygon_width"));
        label_settings_view_polygon_width->setGeometry(QRect(1, 30, 120, 31));
        QFont font1;
        font1.setPointSize(13);
        label_settings_view_polygon_width->setFont(font1);
        label_settings_view_polygon_width->setStyleSheet(QString::fromUtf8("border: 1px  solid rgb(150, 150, 150) ;\n"
"background-color: rgb(50, 50, 50);\n"
"\n"
" \n"
"\n"
"\n"
"\n"
""));
        label_settings_view_polygon_width->setAlignment(Qt::AlignCenter);
        doubleSpinBox_settings_view_polygon_width = new QDoubleSpinBox(frame_settings_view_polygon);
        doubleSpinBox_settings_view_polygon_width->setObjectName(QString::fromUtf8("doubleSpinBox_settings_view_polygon_width"));
        doubleSpinBox_settings_view_polygon_width->setGeometry(QRect(120, 30, 119, 31));
        doubleSpinBox_settings_view_polygon_width->setStyleSheet(QString::fromUtf8("border: 1px  solid rgb(150, 150, 150) ;\n"
"background-color: rgb(50, 50, 50);\n"
" \n"
"\n"
"\n"
"\n"
""));
        doubleSpinBox_settings_view_polygon_width->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        pushButton_settings_view_polygon_color = new QPushButton(frame_settings_view_polygon);
        pushButton_settings_view_polygon_color->setObjectName(QString::fromUtf8("pushButton_settings_view_polygon_color"));
        pushButton_settings_view_polygon_color->setGeometry(QRect(120, 60, 120, 31));
        pushButton_settings_view_polygon_color->setStyleSheet(QString::fromUtf8("border: 1px  solid rgb(150, 150, 150) ;\n"
"background-color: rgb(50, 50, 50);\n"
" \n"
"\n"
"\n"
"\n"
""));
        label_settings_view_polygon_color = new QLabel(frame_settings_view_polygon);
        label_settings_view_polygon_color->setObjectName(QString::fromUtf8("label_settings_view_polygon_color"));
        label_settings_view_polygon_color->setGeometry(QRect(1, 60, 120, 31));
        label_settings_view_polygon_color->setStyleSheet(QString::fromUtf8("border: 1px  solid rgb(150, 150, 150) ;\n"
"background-color: rgb(50, 50, 50);\n"
"\n"
" \n"
"\n"
"\n"
"\n"
""));
        label_settings_view_polygon_color->setAlignment(Qt::AlignCenter);
        frame_settings_view_vertex = new QFrame(frame_settings_view);
        frame_settings_view_vertex->setObjectName(QString::fromUtf8("frame_settings_view_vertex"));
        frame_settings_view_vertex->setGeometry(QRect(0, 150, 241, 91));
        frame_settings_view_vertex->setStyleSheet(QString::fromUtf8("border: 2px  solid rgb(150, 150, 150) ;\n"
"background-color: rgb(50, 50, 50);"));
        frame_settings_view_vertex->setFrameShape(QFrame::StyledPanel);
        frame_settings_view_vertex->setFrameShadow(QFrame::Raised);
        label_settings_view_vertex_size = new QLabel(frame_settings_view_vertex);
        label_settings_view_vertex_size->setObjectName(QString::fromUtf8("label_settings_view_vertex_size"));
        label_settings_view_vertex_size->setGeometry(QRect(1, 30, 120, 31));
        label_settings_view_vertex_size->setStyleSheet(QString::fromUtf8("border: 1px  solid rgb(150, 150, 150) ;\n"
"background-color: rgb(50, 50, 50);\n"
"\n"
"\n"
"\n"
""));
        label_settings_view_vertex_size->setAlignment(Qt::AlignCenter);
        label_settings_view_vertex_color = new QLabel(frame_settings_view_vertex);
        label_settings_view_vertex_color->setObjectName(QString::fromUtf8("label_settings_view_vertex_color"));
        label_settings_view_vertex_color->setGeometry(QRect(1, 60, 120, 31));
        label_settings_view_vertex_color->setStyleSheet(QString::fromUtf8("border: 1px  solid rgb(150, 150, 150) ;\n"
"background-color: rgb(50, 50, 50);\n"
"\n"
"\n"
"\n"
""));
        label_settings_view_vertex_color->setAlignment(Qt::AlignCenter);
        doubleSpinBox_settings_view_vertex_size = new QDoubleSpinBox(frame_settings_view_vertex);
        doubleSpinBox_settings_view_vertex_size->setObjectName(QString::fromUtf8("doubleSpinBox_settings_view_vertex_size"));
        doubleSpinBox_settings_view_vertex_size->setGeometry(QRect(120, 30, 119, 31));
        doubleSpinBox_settings_view_vertex_size->setStyleSheet(QString::fromUtf8("border: 1px  solid rgb(150, 150, 150) ;\n"
"background-color: rgb(50, 50, 50);\n"
" \n"
"\n"
"\n"
"\n"
""));
        doubleSpinBox_settings_view_vertex_size->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        pushButton_settings_view_vertex_color = new QPushButton(frame_settings_view_vertex);
        pushButton_settings_view_vertex_color->setObjectName(QString::fromUtf8("pushButton_settings_view_vertex_color"));
        pushButton_settings_view_vertex_color->setGeometry(QRect(120, 60, 120, 31));
        pushButton_settings_view_vertex_color->setStyleSheet(QString::fromUtf8("border: 1px  solid rgb(150, 150, 150) ;\n"
"background-color: rgb(50, 50, 50);\n"
" \n"
"\n"
"\n"
"\n"
""));
        comboBox_settings_view_vertex_type = new QComboBox(frame_settings_view_vertex);
        comboBox_settings_view_vertex_type->addItem(QString());
        comboBox_settings_view_vertex_type->addItem(QString());
        comboBox_settings_view_vertex_type->addItem(QString());
        comboBox_settings_view_vertex_type->setObjectName(QString::fromUtf8("comboBox_settings_view_vertex_type"));
        comboBox_settings_view_vertex_type->setGeometry(QRect(120, 0, 120, 31));
        comboBox_settings_view_vertex_type->setStyleSheet(QString::fromUtf8("border: 1px  solid rgb(150, 150, 150) ;\n"
"background-color: rgb(50, 50, 50);\n"
"font-size: 12px;"));
        comboBox_settings_view_vertex_type->setFrame(true);
        label_settings_view_polygon_display = new QLabel(frame_settings_view_vertex);
        label_settings_view_polygon_display->setObjectName(QString::fromUtf8("label_settings_view_polygon_display"));
        label_settings_view_polygon_display->setGeometry(QRect(1, 0, 120, 31));
        QFont font2;
        label_settings_view_polygon_display->setFont(font2);
        label_settings_view_polygon_display->setStyleSheet(QString::fromUtf8("border: 1px  solid rgb(150, 150, 150) ;\n"
"background-color: rgb(50, 50, 50);\n"
"font-size: 13px;"));
        label_settings_view_polygon_display->setAlignment(Qt::AlignCenter);
        frame_settings_view_other = new QFrame(frame_settings_view);
        frame_settings_view_other->setObjectName(QString::fromUtf8("frame_settings_view_other"));
        frame_settings_view_other->setGeometry(QRect(0, 0, 241, 61));
        frame_settings_view_other->setStyleSheet(QString::fromUtf8("border: 2px  solid rgb(150, 150, 150) ;\n"
"background-color: rgb(50, 50, 50);"));
        frame_settings_view_other->setFrameShape(QFrame::StyledPanel);
        frame_settings_view_other->setFrameShadow(QFrame::Raised);
        comboBox_settings_view_projection_type = new QComboBox(frame_settings_view_other);
        comboBox_settings_view_projection_type->addItem(QString());
        comboBox_settings_view_projection_type->addItem(QString());
        comboBox_settings_view_projection_type->setObjectName(QString::fromUtf8("comboBox_settings_view_projection_type"));
        comboBox_settings_view_projection_type->setGeometry(QRect(120, 0, 120, 31));
        comboBox_settings_view_projection_type->setStyleSheet(QString::fromUtf8("border: 1px  solid rgb(150, 150, 150) ;\n"
"background-color: rgb(50, 50, 50);\n"
"font-size: 10px;"));
        pushButton_settings_view_other_color = new QPushButton(frame_settings_view_other);
        pushButton_settings_view_other_color->setObjectName(QString::fromUtf8("pushButton_settings_view_other_color"));
        pushButton_settings_view_other_color->setGeometry(QRect(120, 30, 120, 31));
        pushButton_settings_view_other_color->setStyleSheet(QString::fromUtf8("border: 1px  solid rgb(150, 150, 150) ;\n"
"background-color: rgb(50, 50, 50);\n"
" \n"
"\n"
"\n"
"\n"
""));
        label_settings_view_other_type = new QLabel(frame_settings_view_other);
        label_settings_view_other_type->setObjectName(QString::fromUtf8("label_settings_view_other_type"));
        label_settings_view_other_type->setGeometry(QRect(1, 0, 120, 31));
        label_settings_view_other_type->setStyleSheet(QString::fromUtf8("border: 1px  solid rgb(150, 150, 150) ;\n"
"background-color: rgb(50, 50, 50);\n"
"\n"
"\n"
"\n"
""));
        label_settings_view_other_type->setAlignment(Qt::AlignCenter);
        label_settings_view_other_color = new QLabel(frame_settings_view_other);
        label_settings_view_other_color->setObjectName(QString::fromUtf8("label_settings_view_other_color"));
        label_settings_view_other_color->setGeometry(QRect(1, 30, 120, 31));
        label_settings_view_other_color->setStyleSheet(QString::fromUtf8("border: 1px  solid rgb(150, 150, 150) ;\n"
"background-color: rgb(50, 50, 50);\n"
"\n"
"\n"
"\n"
""));
        label_settings_view_other_color->setAlignment(Qt::AlignCenter);
        label_info = new QLabel(centralwidget);
        label_info->setObjectName(QString::fromUtf8("label_info"));
        label_info->setGeometry(QRect(10, 400, 549, 33));
        label_info->setStyleSheet(QString::fromUtf8("border: 2px  solid rgb(150, 150, 150) ;\n"
"background-color: rgb(50, 50, 50);\n"
" \n"
"\n"
"\n"
"\n"
""));
        label_info->setAlignment(Qt::AlignCenter);
        frame_info = new QFrame(centralwidget);
        frame_info->setObjectName(QString::fromUtf8("frame_info"));
        frame_info->setGeometry(QRect(10, 255, 241, 92));
        frame_info->setStyleSheet(QString::fromUtf8("border: 2px  solid rgb(150, 150, 150) ;\n"
"background-color: rgb(50, 50, 50);"));
        frame_info->setFrameShape(QFrame::StyledPanel);
        frame_info->setFrameShadow(QFrame::Raised);
        frame_info_object_info_2 = new QFrame(frame_info);
        frame_info_object_info_2->setObjectName(QString::fromUtf8("frame_info_object_info_2"));
        frame_info_object_info_2->setGeometry(QRect(0, 0, 241, 92));
        frame_info_object_info_2->setStyleSheet(QString::fromUtf8("border: 2px  solid rgb(150, 150, 150) ;\n"
"background-color: rgb(50, 50, 50);"));
        frame_info_object_info_2->setFrameShape(QFrame::StyledPanel);
        frame_info_object_info_2->setFrameShadow(QFrame::Raised);
        label_info_object_info_file_name_2 = new QLabel(frame_info_object_info_2);
        label_info_object_info_file_name_2->setObjectName(QString::fromUtf8("label_info_object_info_file_name_2"));
        label_info_object_info_file_name_2->setGeometry(QRect(1, 1, 120, 31));
        label_info_object_info_file_name_2->setStyleSheet(QString::fromUtf8("border: 1px  solid rgb(150, 150, 150) ;\n"
"background-color: rgb(50, 50, 50);\n"
" \n"
"\n"
"\n"
"\n"
""));
        label_info_object_info_file_name_2->setAlignment(Qt::AlignCenter);
        label_info_object_info_vertex_count_2 = new QLabel(frame_info_object_info_2);
        label_info_object_info_vertex_count_2->setObjectName(QString::fromUtf8("label_info_object_info_vertex_count_2"));
        label_info_object_info_vertex_count_2->setGeometry(QRect(1, 30, 120, 31));
        QFont font3;
        font3.setPointSize(12);
        label_info_object_info_vertex_count_2->setFont(font3);
        label_info_object_info_vertex_count_2->setStyleSheet(QString::fromUtf8("border: 1px  solid rgb(150, 150, 150) ;\n"
"background-color: rgb(50, 50, 50);\n"
" \n"
"\n"
"\n"
"\n"
""));
        label_info_object_info_vertex_count_2->setAlignment(Qt::AlignCenter);
        label_info_object_info_polygon_count_2 = new QLabel(frame_info_object_info_2);
        label_info_object_info_polygon_count_2->setObjectName(QString::fromUtf8("label_info_object_info_polygon_count_2"));
        label_info_object_info_polygon_count_2->setGeometry(QRect(1, 60, 120, 31));
        label_info_object_info_polygon_count_2->setStyleSheet(QString::fromUtf8("border: 1px  solid rgb(150, 150, 150) ;\n"
"background-color: rgb(50, 50, 50);\n"
"color: rgb(204, 204, 204);\n"
" \n"
"\n"
"\n"
"\n"
""));
        label_info_object_info_polygon_count_2->setAlignment(Qt::AlignCenter);
        label_info_object_info_file_name_ans_2 = new QLabel(frame_info_object_info_2);
        label_info_object_info_file_name_ans_2->setObjectName(QString::fromUtf8("label_info_object_info_file_name_ans_2"));
        label_info_object_info_file_name_ans_2->setGeometry(QRect(120, 1, 120, 31));
        label_info_object_info_file_name_ans_2->setStyleSheet(QString::fromUtf8("border: 1px  solid rgb(150, 150, 150) ;\n"
"background-color: rgb(50, 50, 50);\n"
" \n"
"\n"
"\n"
"\n"
""));
        label_info_object_info_file_name_ans_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_info_object_info_vertex_count_ans_2 = new QLabel(frame_info_object_info_2);
        label_info_object_info_vertex_count_ans_2->setObjectName(QString::fromUtf8("label_info_object_info_vertex_count_ans_2"));
        label_info_object_info_vertex_count_ans_2->setGeometry(QRect(120, 30, 120, 31));
        label_info_object_info_vertex_count_ans_2->setStyleSheet(QString::fromUtf8("border: 1px  solid rgb(150, 150, 150) ;\n"
"background-color: rgb(50, 50, 50);\n"
" \n"
"\n"
"\n"
"\n"
""));
        label_info_object_info_vertex_count_ans_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_info_object_info_polygon_count_ans_2 = new QLabel(frame_info_object_info_2);
        label_info_object_info_polygon_count_ans_2->setObjectName(QString::fromUtf8("label_info_object_info_polygon_count_ans_2"));
        label_info_object_info_polygon_count_ans_2->setGeometry(QRect(120, 60, 120, 31));
        label_info_object_info_polygon_count_ans_2->setStyleSheet(QString::fromUtf8("border: 1px  solid rgb(150, 150, 150) ;\n"
"background-color: rgb(50, 50, 50);\n"
" \n"
"\n"
"\n"
"\n"
""));
        label_info_object_info_polygon_count_ans_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        slider_scale = new QSlider(centralwidget);
        slider_scale->setObjectName(QString::fromUtf8("slider_scale"));
        slider_scale->setGeometry(QRect(410, 480, 111, 31));
        slider_scale->setMinimum(0);
        slider_scale->setMaximum(20);
        slider_scale->setValue(1);
        slider_scale->setOrientation(Qt::Horizontal);
        double_spinbox_scale = new QDoubleSpinBox(centralwidget);
        double_spinbox_scale->setObjectName(QString::fromUtf8("double_spinbox_scale"));
        double_spinbox_scale->setGeometry(QRect(420, 440, 91, 22));
        double_spinbox_scale->setDecimals(1);
        double_spinbox_scale->setMinimum(0.100000000000000);
        double_spinbox_scale->setMaximum(20.000000000000000);
        double_spinbox_scale->setSingleStep(0.100000000000000);
        double_spinbox_scale->setValue(1.000000000000000);
        slider_scale_2 = new QSlider(centralwidget);
        slider_scale_2->setObjectName(QString::fromUtf8("slider_scale_2"));
        slider_scale_2->setGeometry(QRect(260, 480, 111, 31));
        slider_scale_2->setMinimum(-100);
        slider_scale_2->setMaximum(300);
        slider_scale_2->setSingleStep(10);
        slider_scale_2->setValue(0);
        slider_scale_2->setSliderPosition(0);
        slider_scale_2->setOrientation(Qt::Horizontal);
        spinbox_scale_2 = new QSpinBox(centralwidget);
        spinbox_scale_2->setObjectName(QString::fromUtf8("spinbox_scale_2"));
        spinbox_scale_2->setGeometry(QRect(270, 440, 101, 22));
        spinbox_scale_2->setMinimum(-100);
        spinbox_scale_2->setMaximum(300);
        spinbox_scale_2->setSingleStep(10);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1070, 24));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        pushButton_file_open->setText(QCoreApplication::translate("MainWindow", "\320\236\321\202\320\272\321\200\321\213\321\202\321\214", nullptr));
        lineEdit_file_input->setText(QCoreApplication::translate("MainWindow", "3d_objects/cube.obj", nullptr));
        label_file_input->setText(QCoreApplication::translate("MainWindow", "\320\244\320\260\320\271\320\273", nullptr));
        pushButton_file_select->setText(QString());
        label_settings_move_rotate_info->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\320\262\320\276\321\200\320\276\321\202", nullptr));
        label_settings_move_rotate_x->setText(QCoreApplication::translate("MainWindow", "X", nullptr));
        label_settings_move_rotate_y->setText(QCoreApplication::translate("MainWindow", "Y", nullptr));
        label_settings_move_rotate_z->setText(QCoreApplication::translate("MainWindow", "Z", nullptr));
        label_settings_move_move_info->setText(QCoreApplication::translate("MainWindow", "\320\237\320\265\321\200\320\265\320\274\320\265\321\211\320\265\320\275\320\270\320\265", nullptr));
        label_settings_move_move_x->setText(QCoreApplication::translate("MainWindow", "X", nullptr));
        label_settings_move_move_y->setText(QCoreApplication::translate("MainWindow", "Y", nullptr));
        label_settings_move_move_z->setText(QCoreApplication::translate("MainWindow", "Z", nullptr));
        label_settings_move_scale->setText(QCoreApplication::translate("MainWindow", "\320\234\320\260\321\201\321\210\321\202\320\260\320\261", nullptr));
        label_screen->setText(QCoreApplication::translate("MainWindow", "\320\241\320\272\321\200\320\270\320\275\321\210\320\276\321\202 \320\262 \321\204\320\276\321\200\320\274\320\260\321\202\320\265", nullptr));
        label_screen_gif->setText(QCoreApplication::translate("MainWindow", "\320\227\320\260\320\277\320\270\321\201\321\214 \320\223\320\270\321\204", nullptr));
        comboBox_screen_unit->setItemText(0, QCoreApplication::translate("MainWindow", "bmp", nullptr));
        comboBox_screen_unit->setItemText(1, QCoreApplication::translate("MainWindow", "jpeg", nullptr));

        pushButton_screen_start->setText(QCoreApplication::translate("MainWindow", "\320\241\320\272\321\200\320\270\320\275\321\210\320\276\321\202", nullptr));
        pushButton_screen_gif_start->setText(QCoreApplication::translate("MainWindow", "\320\227\320\260\320\277\320\270\321\201\321\214", nullptr));
        comboBox_settings_view_polygon_type->setItemText(0, QCoreApplication::translate("MainWindow", "\320\241\320\277\320\273\320\276\321\210\320\275\320\260\321\217", nullptr));
        comboBox_settings_view_polygon_type->setItemText(1, QCoreApplication::translate("MainWindow", "\320\237\321\203\320\275\320\272\321\202\320\270\321\200\320\275\320\260\321\217", nullptr));

        label_settings_view_polygon_type->setText(QCoreApplication::translate("MainWindow", "\320\242\320\270\320\277 \320\240\320\265\320\261\320\265\321\200", nullptr));
        label_settings_view_polygon_width->setText(QCoreApplication::translate("MainWindow", "\320\242\320\276\320\273\321\211\320\270\320\275\320\260 \321\200\320\265\320\261\321\200\320\260", nullptr));
        pushButton_settings_view_polygon_color->setText(QString());
        label_settings_view_polygon_color->setText(QCoreApplication::translate("MainWindow", "\320\246\320\262\320\265\321\202 \320\240\320\265\320\261\320\265\321\200", nullptr));
        label_settings_view_vertex_size->setText(QCoreApplication::translate("MainWindow", "\320\240\320\260\320\267\320\274\320\265\321\200 \320\262\320\265\321\200\321\210\320\270\320\275", nullptr));
        label_settings_view_vertex_color->setText(QCoreApplication::translate("MainWindow", "\320\246\320\262\320\265\321\202 \320\222\320\265\321\200\321\210\320\270\320\275", nullptr));
        pushButton_settings_view_vertex_color->setText(QString());
        comboBox_settings_view_vertex_type->setItemText(0, QCoreApplication::translate("MainWindow", "\320\236\321\202\321\201\321\203\321\202\321\201\320\262\321\203\320\265\321\202", nullptr));
        comboBox_settings_view_vertex_type->setItemText(1, QCoreApplication::translate("MainWindow", "\320\232\321\200\321\203\320\263", nullptr));
        comboBox_settings_view_vertex_type->setItemText(2, QCoreApplication::translate("MainWindow", "\320\232\320\262\320\260\320\264\321\200\320\260\321\202", nullptr));

        label_settings_view_polygon_display->setText(QCoreApplication::translate("MainWindow", "\320\242\320\270\320\277 \320\262\320\265\321\200\321\210\320\270\320\275", nullptr));
        comboBox_settings_view_projection_type->setItemText(0, QCoreApplication::translate("MainWindow", "\320\237\320\260\321\200\320\260\320\273\320\273\320\265\320\273\321\214\320\275\320\260\321\217", nullptr));
        comboBox_settings_view_projection_type->setItemText(1, QCoreApplication::translate("MainWindow", "\320\246\320\265\320\275\321\202\321\200\320\260\320\273\321\214\320\275\320\260\321\217", nullptr));

        pushButton_settings_view_other_color->setText(QString());
        label_settings_view_other_type->setText(QCoreApplication::translate("MainWindow", "\320\242\320\270\320\277 \320\277\321\200\320\276\320\265\320\272\321\206\320\270\320\270", nullptr));
        label_settings_view_other_color->setText(QCoreApplication::translate("MainWindow", "\320\246\320\262\320\265\321\202 \321\204\320\276\320\275\320\260", nullptr));
        label_info->setText(QCoreApplication::translate("MainWindow", "\320\230\320\275\321\204\320\276 \321\201\321\202\321\200\320\276\320\272\320\260", nullptr));
        label_info_object_info_file_name_2->setText(QCoreApplication::translate("MainWindow", "\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265 \321\204\320\260\320\271\320\273\320\260", nullptr));
        label_info_object_info_vertex_count_2->setText(QCoreApplication::translate("MainWindow", "\320\232\320\276\320\273\320\270\321\207\320\265\321\201\321\202\320\262\320\276 \320\262\320\265\321\200\321\210\320\270\320\275", nullptr));
        label_info_object_info_polygon_count_2->setText(QCoreApplication::translate("MainWindow", "\320\232\320\276\320\273\320\270\321\207\320\265\321\201\321\202\320\262\320\276 \321\200\320\265\320\261\320\265\321\200", nullptr));
        label_info_object_info_file_name_ans_2->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_info_object_info_vertex_count_ans_2->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_info_object_info_polygon_count_ans_2->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
