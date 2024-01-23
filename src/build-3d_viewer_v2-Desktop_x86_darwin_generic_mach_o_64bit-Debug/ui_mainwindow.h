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
#include <QtWidgets/QCheckBox>
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
    QPushButton *pushButton_screen_gif_start;
    QPushButton *pushButton_CreateSnapshot;
    QLineEdit *lineEdit_file_input;
    QPushButton *pushButton_file_select;
    QPushButton *pushButton_screen_start;
    QPushButton *pushButton_Restore;
    QComboBox *comboBox_screen_unit;
    QPushButton *pushButton_Reset;
    QFrame *frame_settings_move;
    QSlider *slider_scale;
    QLabel *scale_lable;
    QLabel *label_settings_move_scale;
    QLabel *label_settings_move_rotate_info;
    QLabel *label_settings_move_rotate_x;
    QSlider *slider_rot_x;
    QSpinBox *spinbox_rot_x;
    QLabel *label_settings_move_rotate_y;
    QSpinBox *spinbox_rot_y;
    QSlider *slider_rot_y;
    QLabel *label_settings_move_rotate_z;
    QSlider *slider_rot_z;
    QSpinBox *spinbox_rot_z;
    QLabel *label_settings_move_move_info;
    QLabel *label_settings_move_move_x;
    QSpinBox *spinbox_move_x;
    QSlider *slider_move_x;
    QLabel *label_settings_move_move_y;
    QSpinBox *spinbox_move_y;
    QSlider *slider_move_y;
    QLabel *label_settings_move_move_z;
    QSpinBox *spinbox_move_z;
    QSlider *slider_move_z;
    QLabel *label_info;
    OGLwidget *openGLWidget;
    QFrame *frame_screen_2;
    QLabel *label_file_input;
    QLabel *label_info_object_info_file_name_2;
    QLabel *label_info_object_info_file_name_ans_2;
    QLabel *label_info_object_info_vertex_count_2;
    QLabel *label_info_object_info_polygon_count_2;
    QLabel *label_info_object_info_vertex_count_ans_2;
    QLabel *label_info_object_info_polygon_count_ans_2;
    QFrame *frame_settings_view;
    QFrame *frame_settings_view_polygon;
    QComboBox *comboBox_settings_view_polygon_type;
    QLabel *label_settings_view_polygon_type;
    QLabel *label_settings_view_polygon_width;
    QDoubleSpinBox *doubleSpinBox_settings_view_polygon_width;
    QLabel *label_settings_view_polygon_color;
    QPushButton *pushButton_settings_view_polygon_color;
    QFrame *frame_settings_view_vertex;
    QLabel *label_settings_view_vertex_size;
    QLabel *label_settings_view_vertex_color;
    QDoubleSpinBox *doubleSpinBox_settings_view_vertex_size;
    QComboBox *comboBox_settings_view_vertex_type;
    QLabel *label_settings_view_polygon_display;
    QPushButton *pushButton_settings_view_vertex_color;
    QFrame *frame_settings_view_other;
    QComboBox *comboBox_settings_view_projection_type;
    QPushButton *pushButton_settings_view_other_color;
    QLabel *label_settings_view_other_color;
    QLabel *label_settings_view_other_type;
    QLabel *label_file_input_2;
    QFrame *frame;
    QCheckBox *checkBox_vertex;
    QCheckBox *checkBox_projection;
    QCheckBox *checkBox_edges;
    QLabel *label_saving;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1349, 617);
        MainWindow->setMinimumSize(QSize(1349, 617));
        MainWindow->setMaximumSize(QSize(1349, 617));
        MainWindow->setStyleSheet(QString::fromUtf8("QMainWindow {\n"
"	background: #10151C;\n"
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
        frame_settings_file->setGeometry(QRect(10, 420, 371, 141));
        frame_settings_file->setStyleSheet(QString::fromUtf8("border-style: outset;\n"
"border-width: 2px;\n"
"border-radius: 10px;\n"
"border-color: #697E9C;\n"
"background-color : #0E1115;"));
        frame_settings_file->setFrameShape(QFrame::StyledPanel);
        frame_settings_file->setFrameShadow(QFrame::Raised);
        pushButton_screen_gif_start = new QPushButton(frame_settings_file);
        pushButton_screen_gif_start->setObjectName(QString::fromUtf8("pushButton_screen_gif_start"));
        pushButton_screen_gif_start->setGeometry(QRect(130, 60, 121, 31));
        pushButton_screen_gif_start->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color:  #61738E;\n"
"     border-style: outset;\n"
"     border-width: 2px;\n"
"     border-radius: 10px;\n"
"     font: bold 14px;\n"
"     padding: 6px;\n"
"}\n"
"\n"
" QPushButton:pressed {\n"
"	background-color: #6D7A8E;\n"
" }\n"
""));
        pushButton_CreateSnapshot = new QPushButton(frame_settings_file);
        pushButton_CreateSnapshot->setObjectName(QString::fromUtf8("pushButton_CreateSnapshot"));
        pushButton_CreateSnapshot->setGeometry(QRect(0, 100, 121, 31));
        pushButton_CreateSnapshot->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color:  #61738E;\n"
"     border-style: outset;\n"
"     border-width: 2px;\n"
"     border-radius: 10px;\n"
"     font: bold 14px;\n"
"     padding: 6px;\n"
"}\n"
"\n"
" QPushButton:pressed {\n"
"	background-color: #6D7A8E;\n"
" }\n"
""));
        lineEdit_file_input = new QLineEdit(frame_settings_file);
        lineEdit_file_input->setObjectName(QString::fromUtf8("lineEdit_file_input"));
        lineEdit_file_input->setGeometry(QRect(100, 10, 271, 41));
        lineEdit_file_input->setStyleSheet(QString::fromUtf8("background-color: #0E1115;"));
        lineEdit_file_input->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        pushButton_file_select = new QPushButton(frame_settings_file);
        pushButton_file_select->setObjectName(QString::fromUtf8("pushButton_file_select"));
        pushButton_file_select->setGeometry(QRect(0, 10, 101, 41));
        pushButton_file_select->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: #93266D;\n"
" }\n"
"\n"
" QPushButton:pressed {\n"
"     background-color:  #600C42;\n"
" }\n"
"\n"
"\n"
""));
        pushButton_screen_start = new QPushButton(frame_settings_file);
        pushButton_screen_start->setObjectName(QString::fromUtf8("pushButton_screen_start"));
        pushButton_screen_start->setGeometry(QRect(0, 60, 121, 31));
        pushButton_screen_start->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color:  #61738E;\n"
"     border-style: outset;\n"
"     border-width: 2px;\n"
"     border-radius: 10px;\n"
"     font: bold 14px;\n"
"     padding: 6px;\n"
"}\n"
"\n"
" QPushButton:pressed {\n"
"	background-color: #6D7A8E;\n"
" }\n"
""));
        pushButton_Restore = new QPushButton(frame_settings_file);
        pushButton_Restore->setObjectName(QString::fromUtf8("pushButton_Restore"));
        pushButton_Restore->setGeometry(QRect(130, 100, 121, 31));
        pushButton_Restore->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color:  #61738E;\n"
"     border-style: outset;\n"
"     border-width: 2px;\n"
"     border-radius: 10px;\n"
"     font: bold 14px;\n"
"     padding: 6px;\n"
"}\n"
"\n"
" QPushButton:pressed {\n"
"	background-color: #6D7A8E;\n"
" }\n"
""));
        comboBox_screen_unit = new QComboBox(frame_settings_file);
        comboBox_screen_unit->addItem(QString());
        comboBox_screen_unit->addItem(QString());
        comboBox_screen_unit->setObjectName(QString::fromUtf8("comboBox_screen_unit"));
        comboBox_screen_unit->setGeometry(QRect(260, 60, 111, 31));
        comboBox_screen_unit->setStyleSheet(QString::fromUtf8("background-color: #202A38;\n"
"\n"
"\n"
""));
        pushButton_Reset = new QPushButton(frame_settings_file);
        pushButton_Reset->setObjectName(QString::fromUtf8("pushButton_Reset"));
        pushButton_Reset->setGeometry(QRect(260, 100, 111, 31));
        pushButton_Reset->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color:  #61738E;\n"
"     border-style: outset;\n"
"     border-width: 2px;\n"
"     border-radius: 10px;\n"
"     font: bold 14px;\n"
"     padding: 6px;\n"
"}\n"
"\n"
" QPushButton:pressed {\n"
"	background-color: #6D7A8E;\n"
" }\n"
""));
        frame_settings_move = new QFrame(centralwidget);
        frame_settings_move->setObjectName(QString::fromUtf8("frame_settings_move"));
        frame_settings_move->setGeometry(QRect(10, 10, 371, 391));
        frame_settings_move->setStyleSheet(QString::fromUtf8("border-style: outset;\n"
"border-width: 2px;\n"
"border-radius: 10px;\n"
"border-color: #697E9C;\n"
"background-color : #0E1115;"));
        frame_settings_move->setFrameShape(QFrame::StyledPanel);
        frame_settings_move->setFrameShadow(QFrame::Raised);
        slider_scale = new QSlider(frame_settings_move);
        slider_scale->setObjectName(QString::fromUtf8("slider_scale"));
        slider_scale->setGeometry(QRect(0, 330, 241, 31));
        slider_scale->setMinimum(-300);
        slider_scale->setMaximum(300);
        slider_scale->setSingleStep(1);
        slider_scale->setPageStep(1);
        slider_scale->setValue(0);
        slider_scale->setSliderPosition(0);
        slider_scale->setOrientation(Qt::Horizontal);
        scale_lable = new QLabel(frame_settings_move);
        scale_lable->setObjectName(QString::fromUtf8("scale_lable"));
        scale_lable->setGeometry(QRect(250, 330, 121, 31));
        scale_lable->setStyleSheet(QString::fromUtf8("background-color: #202A38;\n"
"\n"
"\n"
""));
        scale_lable->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_settings_move_scale = new QLabel(frame_settings_move);
        label_settings_move_scale->setObjectName(QString::fromUtf8("label_settings_move_scale"));
        label_settings_move_scale->setGeometry(QRect(0, 290, 371, 31));
        label_settings_move_scale->setStyleSheet(QString::fromUtf8("color: #6D7A8E;"));
        label_settings_move_scale->setAlignment(Qt::AlignCenter);
        label_settings_move_rotate_info = new QLabel(frame_settings_move);
        label_settings_move_rotate_info->setObjectName(QString::fromUtf8("label_settings_move_rotate_info"));
        label_settings_move_rotate_info->setGeometry(QRect(190, 0, 181, 31));
        label_settings_move_rotate_info->setStyleSheet(QString::fromUtf8("color: #6D7A8E;"));
        label_settings_move_rotate_info->setAlignment(Qt::AlignCenter);
        label_settings_move_rotate_x = new QLabel(frame_settings_move);
        label_settings_move_rotate_x->setObjectName(QString::fromUtf8("label_settings_move_rotate_x"));
        label_settings_move_rotate_x->setGeometry(QRect(190, 60, 51, 61));
        label_settings_move_rotate_x->setStyleSheet(QString::fromUtf8("color: #6D7A8E;"));
        label_settings_move_rotate_x->setAlignment(Qt::AlignCenter);
        slider_rot_x = new QSlider(frame_settings_move);
        slider_rot_x->setObjectName(QString::fromUtf8("slider_rot_x"));
        slider_rot_x->setGeometry(QRect(250, 90, 111, 31));
        slider_rot_x->setMinimum(-180);
        slider_rot_x->setMaximum(180);
        slider_rot_x->setOrientation(Qt::Horizontal);
        spinbox_rot_x = new QSpinBox(frame_settings_move);
        spinbox_rot_x->setObjectName(QString::fromUtf8("spinbox_rot_x"));
        spinbox_rot_x->setGeometry(QRect(250, 60, 111, 31));
        QFont font;
        font.setKerning(true);
        spinbox_rot_x->setFont(font);
        spinbox_rot_x->setStyleSheet(QString::fromUtf8("background-color: #202A38;"));
        spinbox_rot_x->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        spinbox_rot_x->setMinimum(-180);
        spinbox_rot_x->setMaximum(180);
        label_settings_move_rotate_y = new QLabel(frame_settings_move);
        label_settings_move_rotate_y->setObjectName(QString::fromUtf8("label_settings_move_rotate_y"));
        label_settings_move_rotate_y->setGeometry(QRect(190, 130, 51, 61));
        label_settings_move_rotate_y->setStyleSheet(QString::fromUtf8("color: #6D7A8E;"));
        label_settings_move_rotate_y->setAlignment(Qt::AlignCenter);
        spinbox_rot_y = new QSpinBox(frame_settings_move);
        spinbox_rot_y->setObjectName(QString::fromUtf8("spinbox_rot_y"));
        spinbox_rot_y->setGeometry(QRect(250, 130, 111, 31));
        spinbox_rot_y->setFont(font);
        spinbox_rot_y->setStyleSheet(QString::fromUtf8("background-color: #202A38;"));
        spinbox_rot_y->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        spinbox_rot_y->setMinimum(-180);
        spinbox_rot_y->setMaximum(180);
        slider_rot_y = new QSlider(frame_settings_move);
        slider_rot_y->setObjectName(QString::fromUtf8("slider_rot_y"));
        slider_rot_y->setGeometry(QRect(250, 160, 111, 31));
        slider_rot_y->setMinimum(-180);
        slider_rot_y->setMaximum(180);
        slider_rot_y->setOrientation(Qt::Horizontal);
        label_settings_move_rotate_z = new QLabel(frame_settings_move);
        label_settings_move_rotate_z->setObjectName(QString::fromUtf8("label_settings_move_rotate_z"));
        label_settings_move_rotate_z->setGeometry(QRect(190, 200, 51, 61));
        label_settings_move_rotate_z->setStyleSheet(QString::fromUtf8("color: #6D7A8E;"));
        label_settings_move_rotate_z->setAlignment(Qt::AlignCenter);
        slider_rot_z = new QSlider(frame_settings_move);
        slider_rot_z->setObjectName(QString::fromUtf8("slider_rot_z"));
        slider_rot_z->setGeometry(QRect(250, 230, 111, 31));
        slider_rot_z->setMinimum(-180);
        slider_rot_z->setMaximum(180);
        slider_rot_z->setOrientation(Qt::Horizontal);
        spinbox_rot_z = new QSpinBox(frame_settings_move);
        spinbox_rot_z->setObjectName(QString::fromUtf8("spinbox_rot_z"));
        spinbox_rot_z->setGeometry(QRect(250, 200, 111, 31));
        spinbox_rot_z->setFont(font);
        spinbox_rot_z->setStyleSheet(QString::fromUtf8("background-color: #202A38;"));
        spinbox_rot_z->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        spinbox_rot_z->setMinimum(-180);
        spinbox_rot_z->setMaximum(180);
        label_settings_move_move_info = new QLabel(frame_settings_move);
        label_settings_move_move_info->setObjectName(QString::fromUtf8("label_settings_move_move_info"));
        label_settings_move_move_info->setGeometry(QRect(0, 0, 181, 31));
        label_settings_move_move_info->setStyleSheet(QString::fromUtf8("color: #6D7A8E;"));
        label_settings_move_move_info->setAlignment(Qt::AlignCenter);
        label_settings_move_move_x = new QLabel(frame_settings_move);
        label_settings_move_move_x->setObjectName(QString::fromUtf8("label_settings_move_move_x"));
        label_settings_move_move_x->setGeometry(QRect(10, 60, 51, 61));
        label_settings_move_move_x->setStyleSheet(QString::fromUtf8("color: #6D7A8E;"));
        label_settings_move_move_x->setAlignment(Qt::AlignCenter);
        spinbox_move_x = new QSpinBox(frame_settings_move);
        spinbox_move_x->setObjectName(QString::fromUtf8("spinbox_move_x"));
        spinbox_move_x->setGeometry(QRect(70, 60, 111, 31));
        spinbox_move_x->setFont(font);
        spinbox_move_x->setStyleSheet(QString::fromUtf8("background-color: #202A38;"));
        spinbox_move_x->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        spinbox_move_x->setMinimum(-100);
        spinbox_move_x->setMaximum(100);
        slider_move_x = new QSlider(frame_settings_move);
        slider_move_x->setObjectName(QString::fromUtf8("slider_move_x"));
        slider_move_x->setGeometry(QRect(70, 90, 111, 31));
        slider_move_x->setStyleSheet(QString::fromUtf8(""));
        slider_move_x->setMinimum(-100);
        slider_move_x->setMaximum(100);
        slider_move_x->setOrientation(Qt::Horizontal);
        label_settings_move_move_y = new QLabel(frame_settings_move);
        label_settings_move_move_y->setObjectName(QString::fromUtf8("label_settings_move_move_y"));
        label_settings_move_move_y->setGeometry(QRect(10, 130, 51, 61));
        label_settings_move_move_y->setStyleSheet(QString::fromUtf8("color: #6D7A8E;"));
        label_settings_move_move_y->setAlignment(Qt::AlignCenter);
        spinbox_move_y = new QSpinBox(frame_settings_move);
        spinbox_move_y->setObjectName(QString::fromUtf8("spinbox_move_y"));
        spinbox_move_y->setGeometry(QRect(70, 130, 111, 31));
        spinbox_move_y->setFont(font);
        spinbox_move_y->setStyleSheet(QString::fromUtf8("background-color: #202A38;"));
        spinbox_move_y->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        spinbox_move_y->setMinimum(-100);
        spinbox_move_y->setMaximum(100);
        slider_move_y = new QSlider(frame_settings_move);
        slider_move_y->setObjectName(QString::fromUtf8("slider_move_y"));
        slider_move_y->setGeometry(QRect(70, 160, 111, 31));
        slider_move_y->setMinimum(-100);
        slider_move_y->setMaximum(100);
        slider_move_y->setOrientation(Qt::Horizontal);
        label_settings_move_move_z = new QLabel(frame_settings_move);
        label_settings_move_move_z->setObjectName(QString::fromUtf8("label_settings_move_move_z"));
        label_settings_move_move_z->setGeometry(QRect(10, 200, 51, 61));
        label_settings_move_move_z->setStyleSheet(QString::fromUtf8("color: #6D7A8E;"));
        label_settings_move_move_z->setAlignment(Qt::AlignCenter);
        spinbox_move_z = new QSpinBox(frame_settings_move);
        spinbox_move_z->setObjectName(QString::fromUtf8("spinbox_move_z"));
        spinbox_move_z->setGeometry(QRect(70, 200, 111, 31));
        spinbox_move_z->setFont(font);
        spinbox_move_z->setStyleSheet(QString::fromUtf8("background-color: #202A38;"));
        spinbox_move_z->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        spinbox_move_z->setMinimum(-100);
        spinbox_move_z->setMaximum(100);
        slider_move_z = new QSlider(frame_settings_move);
        slider_move_z->setObjectName(QString::fromUtf8("slider_move_z"));
        slider_move_z->setGeometry(QRect(70, 230, 111, 31));
        slider_move_z->setMinimum(-100);
        slider_move_z->setMaximum(100);
        slider_move_z->setOrientation(Qt::Horizontal);
        label_info = new QLabel(centralwidget);
        label_info->setObjectName(QString::fromUtf8("label_info"));
        label_info->setGeometry(QRect(390, 530, 681, 33));
        label_info->setStyleSheet(QString::fromUtf8("border-style: outset;\n"
"border-width: 2px;\n"
"border-radius: 10px;\n"
"border-color: #697E9C;"));
        label_info->setAlignment(Qt::AlignCenter);
        openGLWidget = new OGLwidget(centralwidget);
        openGLWidget->setObjectName(QString::fromUtf8("openGLWidget"));
        openGLWidget->setGeometry(QRect(390, 10, 680, 510));
        openGLWidget->setMinimumSize(QSize(4, 0));
        openGLWidget->setStyleSheet(QString::fromUtf8("border: 3px  solid rgb(150, 150, 150) ;"));
        frame_screen_2 = new QFrame(centralwidget);
        frame_screen_2->setObjectName(QString::fromUtf8("frame_screen_2"));
        frame_screen_2->setGeometry(QRect(1080, 310, 261, 121));
        frame_screen_2->setStyleSheet(QString::fromUtf8("border-style: outset;\n"
"border-width: 2px;\n"
"border-radius: 10px;\n"
"border-color: #697E9C;\n"
"background-color : #0E1115;"));
        frame_screen_2->setFrameShape(QFrame::StyledPanel);
        frame_screen_2->setFrameShadow(QFrame::Raised);
        label_file_input = new QLabel(frame_screen_2);
        label_file_input->setObjectName(QString::fromUtf8("label_file_input"));
        label_file_input->setGeometry(QRect(0, 0, 261, 31));
        label_file_input->setStyleSheet(QString::fromUtf8("color: #6D7A8E;"));
        label_file_input->setAlignment(Qt::AlignCenter);
        label_info_object_info_file_name_2 = new QLabel(frame_screen_2);
        label_info_object_info_file_name_2->setObjectName(QString::fromUtf8("label_info_object_info_file_name_2"));
        label_info_object_info_file_name_2->setGeometry(QRect(0, 30, 131, 31));
        label_info_object_info_file_name_2->setStyleSheet(QString::fromUtf8("color: #6D7A8E;"));
        label_info_object_info_file_name_2->setAlignment(Qt::AlignCenter);
        label_info_object_info_file_name_ans_2 = new QLabel(frame_screen_2);
        label_info_object_info_file_name_ans_2->setObjectName(QString::fromUtf8("label_info_object_info_file_name_ans_2"));
        label_info_object_info_file_name_ans_2->setGeometry(QRect(140, 30, 121, 31));
        label_info_object_info_file_name_ans_2->setStyleSheet(QString::fromUtf8("background-color: #202A38;\n"
"\n"
"\n"
""));
        label_info_object_info_file_name_ans_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_info_object_info_vertex_count_2 = new QLabel(frame_screen_2);
        label_info_object_info_vertex_count_2->setObjectName(QString::fromUtf8("label_info_object_info_vertex_count_2"));
        label_info_object_info_vertex_count_2->setGeometry(QRect(0, 60, 131, 31));
        QFont font1;
        font1.setPointSize(12);
        label_info_object_info_vertex_count_2->setFont(font1);
        label_info_object_info_vertex_count_2->setStyleSheet(QString::fromUtf8("color: #6D7A8E;"));
        label_info_object_info_vertex_count_2->setAlignment(Qt::AlignCenter);
        label_info_object_info_polygon_count_2 = new QLabel(frame_screen_2);
        label_info_object_info_polygon_count_2->setObjectName(QString::fromUtf8("label_info_object_info_polygon_count_2"));
        label_info_object_info_polygon_count_2->setGeometry(QRect(0, 90, 131, 31));
        label_info_object_info_polygon_count_2->setStyleSheet(QString::fromUtf8("color: #6D7A8E;"));
        label_info_object_info_polygon_count_2->setAlignment(Qt::AlignCenter);
        label_info_object_info_vertex_count_ans_2 = new QLabel(frame_screen_2);
        label_info_object_info_vertex_count_ans_2->setObjectName(QString::fromUtf8("label_info_object_info_vertex_count_ans_2"));
        label_info_object_info_vertex_count_ans_2->setGeometry(QRect(140, 60, 121, 31));
        label_info_object_info_vertex_count_ans_2->setStyleSheet(QString::fromUtf8("background-color: #202A38;\n"
"\n"
"\n"
""));
        label_info_object_info_vertex_count_ans_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_info_object_info_polygon_count_ans_2 = new QLabel(frame_screen_2);
        label_info_object_info_polygon_count_ans_2->setObjectName(QString::fromUtf8("label_info_object_info_polygon_count_ans_2"));
        label_info_object_info_polygon_count_ans_2->setGeometry(QRect(140, 90, 121, 31));
        label_info_object_info_polygon_count_ans_2->setStyleSheet(QString::fromUtf8("background-color: #202A38;\n"
"\n"
"\n"
""));
        label_info_object_info_polygon_count_ans_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        frame_settings_view = new QFrame(centralwidget);
        frame_settings_view->setObjectName(QString::fromUtf8("frame_settings_view"));
        frame_settings_view->setGeometry(QRect(1080, 10, 261, 291));
        frame_settings_view->setStyleSheet(QString::fromUtf8("border-style: outset;\n"
"border-width: 2px;\n"
"border-radius: 10px;\n"
"border-color: #697E9C;\n"
"background-color : #0E1115;"));
        frame_settings_view->setFrameShape(QFrame::StyledPanel);
        frame_settings_view->setFrameShadow(QFrame::Raised);
        frame_settings_view_polygon = new QFrame(frame_settings_view);
        frame_settings_view_polygon->setObjectName(QString::fromUtf8("frame_settings_view_polygon"));
        frame_settings_view_polygon->setGeometry(QRect(0, 100, 261, 91));
        frame_settings_view_polygon->setStyleSheet(QString::fromUtf8(""));
        frame_settings_view_polygon->setFrameShape(QFrame::StyledPanel);
        frame_settings_view_polygon->setFrameShadow(QFrame::Raised);
        comboBox_settings_view_polygon_type = new QComboBox(frame_settings_view_polygon);
        comboBox_settings_view_polygon_type->addItem(QString());
        comboBox_settings_view_polygon_type->addItem(QString());
        comboBox_settings_view_polygon_type->setObjectName(QString::fromUtf8("comboBox_settings_view_polygon_type"));
        comboBox_settings_view_polygon_type->setGeometry(QRect(140, 0, 120, 31));
        comboBox_settings_view_polygon_type->setStyleSheet(QString::fromUtf8("background-color: #202A38;\n"
"\n"
"\n"
""));
        label_settings_view_polygon_type = new QLabel(frame_settings_view_polygon);
        label_settings_view_polygon_type->setObjectName(QString::fromUtf8("label_settings_view_polygon_type"));
        label_settings_view_polygon_type->setGeometry(QRect(0, 0, 120, 31));
        label_settings_view_polygon_type->setStyleSheet(QString::fromUtf8("color: #6D7A8E;"));
        label_settings_view_polygon_type->setAlignment(Qt::AlignCenter);
        label_settings_view_polygon_width = new QLabel(frame_settings_view_polygon);
        label_settings_view_polygon_width->setObjectName(QString::fromUtf8("label_settings_view_polygon_width"));
        label_settings_view_polygon_width->setGeometry(QRect(0, 30, 120, 31));
        QFont font2;
        font2.setPointSize(13);
        label_settings_view_polygon_width->setFont(font2);
        label_settings_view_polygon_width->setStyleSheet(QString::fromUtf8("color: #6D7A8E;"));
        label_settings_view_polygon_width->setAlignment(Qt::AlignCenter);
        doubleSpinBox_settings_view_polygon_width = new QDoubleSpinBox(frame_settings_view_polygon);
        doubleSpinBox_settings_view_polygon_width->setObjectName(QString::fromUtf8("doubleSpinBox_settings_view_polygon_width"));
        doubleSpinBox_settings_view_polygon_width->setGeometry(QRect(140, 30, 119, 31));
        doubleSpinBox_settings_view_polygon_width->setStyleSheet(QString::fromUtf8("background-color: #202A38;\n"
"\n"
"\n"
""));
        doubleSpinBox_settings_view_polygon_width->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        doubleSpinBox_settings_view_polygon_width->setMaximum(100.000000000000000);
        doubleSpinBox_settings_view_polygon_width->setSingleStep(0.100000000000000);
        label_settings_view_polygon_color = new QLabel(frame_settings_view_polygon);
        label_settings_view_polygon_color->setObjectName(QString::fromUtf8("label_settings_view_polygon_color"));
        label_settings_view_polygon_color->setGeometry(QRect(0, 60, 120, 31));
        label_settings_view_polygon_color->setStyleSheet(QString::fromUtf8("color: #6D7A8E;"));
        label_settings_view_polygon_color->setAlignment(Qt::AlignCenter);
        pushButton_settings_view_polygon_color = new QPushButton(frame_settings_view_polygon);
        pushButton_settings_view_polygon_color->setObjectName(QString::fromUtf8("pushButton_settings_view_polygon_color"));
        pushButton_settings_view_polygon_color->setGeometry(QRect(140, 60, 120, 31));
        pushButton_settings_view_polygon_color->setStyleSheet(QString::fromUtf8("background-color: #202A38;\n"
"\n"
"\n"
""));
        frame_settings_view_vertex = new QFrame(frame_settings_view);
        frame_settings_view_vertex->setObjectName(QString::fromUtf8("frame_settings_view_vertex"));
        frame_settings_view_vertex->setGeometry(QRect(0, 200, 261, 91));
        frame_settings_view_vertex->setStyleSheet(QString::fromUtf8(""));
        frame_settings_view_vertex->setFrameShape(QFrame::StyledPanel);
        frame_settings_view_vertex->setFrameShadow(QFrame::Raised);
        label_settings_view_vertex_size = new QLabel(frame_settings_view_vertex);
        label_settings_view_vertex_size->setObjectName(QString::fromUtf8("label_settings_view_vertex_size"));
        label_settings_view_vertex_size->setGeometry(QRect(1, 30, 120, 31));
        label_settings_view_vertex_size->setStyleSheet(QString::fromUtf8("color: #6D7A8E;"));
        label_settings_view_vertex_size->setAlignment(Qt::AlignCenter);
        label_settings_view_vertex_color = new QLabel(frame_settings_view_vertex);
        label_settings_view_vertex_color->setObjectName(QString::fromUtf8("label_settings_view_vertex_color"));
        label_settings_view_vertex_color->setGeometry(QRect(1, 60, 120, 31));
        label_settings_view_vertex_color->setStyleSheet(QString::fromUtf8("color: #6D7A8E;"));
        label_settings_view_vertex_color->setAlignment(Qt::AlignCenter);
        doubleSpinBox_settings_view_vertex_size = new QDoubleSpinBox(frame_settings_view_vertex);
        doubleSpinBox_settings_view_vertex_size->setObjectName(QString::fromUtf8("doubleSpinBox_settings_view_vertex_size"));
        doubleSpinBox_settings_view_vertex_size->setGeometry(QRect(140, 30, 119, 31));
        doubleSpinBox_settings_view_vertex_size->setStyleSheet(QString::fromUtf8("background-color: #202A38;\n"
"\n"
"\n"
""));
        doubleSpinBox_settings_view_vertex_size->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        doubleSpinBox_settings_view_vertex_size->setSingleStep(0.100000000000000);
        comboBox_settings_view_vertex_type = new QComboBox(frame_settings_view_vertex);
        comboBox_settings_view_vertex_type->addItem(QString());
        comboBox_settings_view_vertex_type->addItem(QString());
        comboBox_settings_view_vertex_type->addItem(QString());
        comboBox_settings_view_vertex_type->setObjectName(QString::fromUtf8("comboBox_settings_view_vertex_type"));
        comboBox_settings_view_vertex_type->setGeometry(QRect(140, 0, 120, 31));
        comboBox_settings_view_vertex_type->setStyleSheet(QString::fromUtf8("background-color: #202A38;\n"
"\n"
"\n"
""));
        comboBox_settings_view_vertex_type->setFrame(true);
        label_settings_view_polygon_display = new QLabel(frame_settings_view_vertex);
        label_settings_view_polygon_display->setObjectName(QString::fromUtf8("label_settings_view_polygon_display"));
        label_settings_view_polygon_display->setGeometry(QRect(1, 0, 120, 31));
        QFont font3;
        label_settings_view_polygon_display->setFont(font3);
        label_settings_view_polygon_display->setStyleSheet(QString::fromUtf8("color: #6D7A8E;"));
        label_settings_view_polygon_display->setAlignment(Qt::AlignCenter);
        pushButton_settings_view_vertex_color = new QPushButton(frame_settings_view_vertex);
        pushButton_settings_view_vertex_color->setObjectName(QString::fromUtf8("pushButton_settings_view_vertex_color"));
        pushButton_settings_view_vertex_color->setGeometry(QRect(140, 60, 120, 31));
        pushButton_settings_view_vertex_color->setStyleSheet(QString::fromUtf8("background-color: #202A38;\n"
"\n"
"\n"
""));
        frame_settings_view_other = new QFrame(frame_settings_view);
        frame_settings_view_other->setObjectName(QString::fromUtf8("frame_settings_view_other"));
        frame_settings_view_other->setGeometry(QRect(0, 30, 261, 61));
        frame_settings_view_other->setStyleSheet(QString::fromUtf8(""));
        frame_settings_view_other->setFrameShape(QFrame::StyledPanel);
        frame_settings_view_other->setFrameShadow(QFrame::Raised);
        comboBox_settings_view_projection_type = new QComboBox(frame_settings_view_other);
        comboBox_settings_view_projection_type->addItem(QString());
        comboBox_settings_view_projection_type->addItem(QString());
        comboBox_settings_view_projection_type->setObjectName(QString::fromUtf8("comboBox_settings_view_projection_type"));
        comboBox_settings_view_projection_type->setGeometry(QRect(140, 0, 120, 31));
        comboBox_settings_view_projection_type->setStyleSheet(QString::fromUtf8("background-color: #202A38;\n"
"\n"
"\n"
""));
        pushButton_settings_view_other_color = new QPushButton(frame_settings_view_other);
        pushButton_settings_view_other_color->setObjectName(QString::fromUtf8("pushButton_settings_view_other_color"));
        pushButton_settings_view_other_color->setGeometry(QRect(140, 30, 120, 31));
        pushButton_settings_view_other_color->setStyleSheet(QString::fromUtf8("background-color: #202A38;\n"
"\n"
"\n"
""));
        label_settings_view_other_color = new QLabel(frame_settings_view_other);
        label_settings_view_other_color->setObjectName(QString::fromUtf8("label_settings_view_other_color"));
        label_settings_view_other_color->setGeometry(QRect(0, 30, 120, 31));
        label_settings_view_other_color->setStyleSheet(QString::fromUtf8("color: #6D7A8E;"));
        label_settings_view_other_color->setAlignment(Qt::AlignCenter);
        label_settings_view_other_type = new QLabel(frame_settings_view_other);
        label_settings_view_other_type->setObjectName(QString::fromUtf8("label_settings_view_other_type"));
        label_settings_view_other_type->setGeometry(QRect(0, 0, 120, 31));
        label_settings_view_other_type->setStyleSheet(QString::fromUtf8("color: #6D7A8E;"));
        label_settings_view_other_type->setAlignment(Qt::AlignCenter);
        label_file_input_2 = new QLabel(frame_settings_view);
        label_file_input_2->setObjectName(QString::fromUtf8("label_file_input_2"));
        label_file_input_2->setGeometry(QRect(0, 0, 261, 31));
        label_file_input_2->setStyleSheet(QString::fromUtf8("color: #6D7A8E;"));
        label_file_input_2->setAlignment(Qt::AlignCenter);
        frame = new QFrame(centralwidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(1080, 440, 261, 121));
        frame->setStyleSheet(QString::fromUtf8("border-style: outset;\n"
"border-width: 2px;\n"
"border-radius: 10px;\n"
"border-color: #697E9C;\n"
"background-color : #0E1115;"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        checkBox_vertex = new QCheckBox(frame);
        checkBox_vertex->setObjectName(QString::fromUtf8("checkBox_vertex"));
        checkBox_vertex->setGeometry(QRect(0, 30, 261, 31));
        checkBox_projection = new QCheckBox(frame);
        checkBox_projection->setObjectName(QString::fromUtf8("checkBox_projection"));
        checkBox_projection->setGeometry(QRect(0, 90, 261, 31));
        checkBox_edges = new QCheckBox(frame);
        checkBox_edges->setObjectName(QString::fromUtf8("checkBox_edges"));
        checkBox_edges->setGeometry(QRect(0, 60, 261, 31));
        label_saving = new QLabel(frame);
        label_saving->setObjectName(QString::fromUtf8("label_saving"));
        label_saving->setGeometry(QRect(0, 0, 261, 31));
        label_saving->setStyleSheet(QString::fromUtf8("color: #6D7A8E;"));
        label_saving->setAlignment(Qt::AlignCenter);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1349, 24));
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
        pushButton_screen_gif_start->setText(QCoreApplication::translate("MainWindow", "GIF", nullptr));
        pushButton_CreateSnapshot->setText(QCoreApplication::translate("MainWindow", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214", nullptr));
        lineEdit_file_input->setText(QCoreApplication::translate("MainWindow", "3d_objects/cube.obj", nullptr));
        pushButton_file_select->setText(QCoreApplication::translate("MainWindow", "\320\222\321\213\320\261\320\276\321\200 \321\204\320\260\320\271\320\273\320\260", nullptr));
        pushButton_screen_start->setText(QCoreApplication::translate("MainWindow", "\320\241\320\272\321\200\320\270\320\275\321\210\320\276\321\202", nullptr));
        pushButton_Restore->setText(QCoreApplication::translate("MainWindow", "\320\222\320\276\321\201\321\201\321\202\320\260\320\275\320\276\320\262\320\270\321\202\321\214", nullptr));
        comboBox_screen_unit->setItemText(0, QCoreApplication::translate("MainWindow", "bmp", nullptr));
        comboBox_screen_unit->setItemText(1, QCoreApplication::translate("MainWindow", "jpeg", nullptr));

        pushButton_Reset->setText(QCoreApplication::translate("MainWindow", "\320\241\320\261\321\200\320\276\321\201\320\270\321\202\321\214", nullptr));
        scale_lable->setText(QCoreApplication::translate("MainWindow", "100", nullptr));
        label_settings_move_scale->setText(QCoreApplication::translate("MainWindow", "\320\234\320\260\321\201\321\210\321\202\320\260\320\261", nullptr));
        label_settings_move_rotate_info->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\320\262\320\276\321\200\320\276\321\202", nullptr));
        label_settings_move_rotate_x->setText(QCoreApplication::translate("MainWindow", "X", nullptr));
        label_settings_move_rotate_y->setText(QCoreApplication::translate("MainWindow", "Y", nullptr));
        label_settings_move_rotate_z->setText(QCoreApplication::translate("MainWindow", "Z", nullptr));
        label_settings_move_move_info->setText(QCoreApplication::translate("MainWindow", "\320\237\320\265\321\200\320\265\320\274\320\265\321\211\320\265\320\275\320\270\320\265", nullptr));
        label_settings_move_move_x->setText(QCoreApplication::translate("MainWindow", "X", nullptr));
        label_settings_move_move_y->setText(QCoreApplication::translate("MainWindow", "Y", nullptr));
        label_settings_move_move_z->setText(QCoreApplication::translate("MainWindow", "Z", nullptr));
        label_info->setText(QCoreApplication::translate("MainWindow", "\320\230\320\275\321\204\320\276 \321\201\321\202\321\200\320\276\320\272\320\260", nullptr));
        label_file_input->setText(QCoreApplication::translate("MainWindow", "\320\244\320\260\320\271\320\273", nullptr));
        label_info_object_info_file_name_2->setText(QCoreApplication::translate("MainWindow", "\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265 \321\204\320\260\320\271\320\273\320\260", nullptr));
        label_info_object_info_file_name_ans_2->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_info_object_info_vertex_count_2->setText(QCoreApplication::translate("MainWindow", "\320\232\320\276\320\273\320\270\321\207\320\265\321\201\321\202\320\262\320\276 \320\262\320\265\321\200\321\210\320\270\320\275", nullptr));
        label_info_object_info_polygon_count_2->setText(QCoreApplication::translate("MainWindow", "\320\232\320\276\320\273\320\270\321\207\320\265\321\201\321\202\320\262\320\276 \321\200\320\265\320\261\320\265\321\200", nullptr));
        label_info_object_info_vertex_count_ans_2->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_info_object_info_polygon_count_ans_2->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        comboBox_settings_view_polygon_type->setItemText(0, QCoreApplication::translate("MainWindow", "\320\241\320\277\320\273\320\276\321\210\320\275\320\260\321\217", nullptr));
        comboBox_settings_view_polygon_type->setItemText(1, QCoreApplication::translate("MainWindow", "\320\237\321\203\320\275\320\272\321\202\320\270\321\200\320\275\320\260\321\217", nullptr));

        label_settings_view_polygon_type->setText(QCoreApplication::translate("MainWindow", "\320\242\320\270\320\277 \320\240\320\265\320\261\320\265\321\200", nullptr));
        label_settings_view_polygon_width->setText(QCoreApplication::translate("MainWindow", "\320\242\320\276\320\273\321\211\320\270\320\275\320\260 \321\200\320\265\320\261\321\200\320\260", nullptr));
        label_settings_view_polygon_color->setText(QCoreApplication::translate("MainWindow", "\320\246\320\262\320\265\321\202 \320\240\320\265\320\261\320\265\321\200", nullptr));
        pushButton_settings_view_polygon_color->setText(QString());
        label_settings_view_vertex_size->setText(QCoreApplication::translate("MainWindow", "\320\240\320\260\320\267\320\274\320\265\321\200 \320\262\320\265\321\200\321\210\320\270\320\275", nullptr));
        label_settings_view_vertex_color->setText(QCoreApplication::translate("MainWindow", "\320\246\320\262\320\265\321\202 \320\222\320\265\321\200\321\210\320\270\320\275", nullptr));
        comboBox_settings_view_vertex_type->setItemText(0, QCoreApplication::translate("MainWindow", "\320\236\321\202\321\201\321\203\321\202\321\201\320\262\321\203\320\265\321\202", nullptr));
        comboBox_settings_view_vertex_type->setItemText(1, QCoreApplication::translate("MainWindow", "\320\232\321\200\321\203\320\263", nullptr));
        comboBox_settings_view_vertex_type->setItemText(2, QCoreApplication::translate("MainWindow", "\320\232\320\262\320\260\320\264\321\200\320\260\321\202", nullptr));

        label_settings_view_polygon_display->setText(QCoreApplication::translate("MainWindow", "\320\242\320\270\320\277 \320\262\320\265\321\200\321\210\320\270\320\275", nullptr));
        pushButton_settings_view_vertex_color->setText(QString());
        comboBox_settings_view_projection_type->setItemText(0, QCoreApplication::translate("MainWindow", "\320\237\320\260\321\200\320\260\320\273\320\273\320\265\320\273\321\214\320\275\320\260\321\217", nullptr));
        comboBox_settings_view_projection_type->setItemText(1, QCoreApplication::translate("MainWindow", "\320\246\320\265\320\275\321\202\321\200\320\260\320\273\321\214\320\275\320\260\321\217", nullptr));

        pushButton_settings_view_other_color->setText(QString());
        label_settings_view_other_color->setText(QCoreApplication::translate("MainWindow", "\320\246\320\262\320\265\321\202 \321\204\320\276\320\275\320\260", nullptr));
        label_settings_view_other_type->setText(QCoreApplication::translate("MainWindow", "\320\242\320\270\320\277 \320\277\321\200\320\276\320\265\320\272\321\206\320\270\320\270", nullptr));
        label_file_input_2->setText(QCoreApplication::translate("MainWindow", "\320\237\321\200\320\276\320\265\320\272\321\206\320\270\321\217", nullptr));
        checkBox_vertex->setText(QCoreApplication::translate("MainWindow", "\320\222\320\265\321\200\321\210\320\270\320\275\321\213", nullptr));
        checkBox_projection->setText(QCoreApplication::translate("MainWindow", "\320\237\321\200\320\276\320\265\320\272\321\206\320\270\321\217", nullptr));
        checkBox_edges->setText(QCoreApplication::translate("MainWindow", "\320\233\320\270\320\275\320\270\320\270", nullptr));
        label_saving->setText(QCoreApplication::translate("MainWindow", "\320\241\320\276\321\205\321\200\320\260\320\275\320\265\320\275\320\270\320\265", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
