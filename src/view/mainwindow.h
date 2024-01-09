#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <qgifimage.h>
#include <stdio.h>

#include <QColorDialog>
#include <QFileDialog>
#include <QImage>
#include <QMainWindow>
#include <QTimer>
#include <iostream>

#include "../controller/Controller.h"
#include "oglwidget.h"

#ifdef __APPLE__
#define PATH_FROM_EXE_TO_SRC "../../../.."
#else
#define PATH_FROM_EXE_TO_SRC ".."
#endif

#define ICON_FINDER_PATH \
  "/" PATH_FROM_EXE_TO_SRC "/../misc/images/mac_os_finder_icon.png"

#define PATH_STD_OPEN_FINDER "/" PATH_FROM_EXE_TO_SRC "/3d_objects"

enum screenshot_formats { SCREENSHOT_FORMAT_BMP, SCREENSHOT_FORMAT_JPEG };

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

//class Controller;

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  MainWindow(s21::Controller *controller, QWidget *parent = nullptr);
  ~MainWindow();

//  void closeEvent(QCloseEvent *event);

  //  struct user_settings user_settings;

 public slots:
  void choose_file();

  void redraw();
  void rebuff();

//  void changeXcoord(double arg);
//  void changeYcoord(double arg);
//  void changeZcoord(double arg);

//  void changeXangle(int arg);
//  void changeYangle(double arg);
//  void changeZangle(double arg);

//  void changeScale();
//  void open_file();

  void take_screenshot();
  void record_gif();

//  void user_settings_combo_box_change();
//  void user_settings_double_spin_box_change();
//  void user_settings_color_change();

 private slots:  
  void valueChanged_to_Rot_X(int value);
  void valueChanged_to_Rot_Y(int value);
  void valueChanged_to_Rot_Z(int value);

  void valueChanged_to_Move_X(int value);
  void valueChanged_to_Move_Y(int value);
  void valueChanged_to_Move_Z(int value);




//  void on_doubleSpinBox_settings_move_move_x_valueChanged(double arg1);
//  void on_doubleSpinBox_settings_move_move_y_valueChanged(double arg1);
//  void on_doubleSpinBox_settings_move_move_z_valueChanged(double arg1);
//  void on_horizontalSlider_settings_move_move_x_sliderMoved(int position);
//  void on_horizontalSlider_settings_move_move_y_sliderMoved(int position);
//  void on_horizontalSlider_settings_move_move_z_sliderMoved(int position);

//  void on_spinBox_settings_move_rotate_x_valueChanged(int arg1);
//  void on_doubleSpinBox_settings_move_rotate_y_valueChanged(double arg1);
//  void on_doubleSpinBox_settings_move_rotate_z_valueChanged(double arg1);
//  void on_horizontalSlider_settings_move_rotate_x_sliderMoved(int position);
//  void on_horizontalSlider_settings_move_rotate_y_sliderMoved(int position);
//  void on_horizontalSlider_settings_move_rotate_z_sliderMoved(int position);

//  void on_doubleSpinBox_settings_move_scale_valueChanged(double arg1);
//  void on_horizontalSlider_settings_move_scale_sliderMoved(int position);

//  void on_comboBox_settings_view_projection_type_currentIndexChanged(int index);

  void on_comboBox_settings_view_polygon_type_currentIndexChanged(int index);
  void on_doubleSpinBox_settings_view_polygon_width_valueChanged(double arg1);

  void on_comboBox_settings_view_vertex_type_currentIndexChanged(int index);
  void on_doubleSpinBox_settings_view_vertex_size_valueChanged(double arg1);

  void on_pushButton_screen_start_clicked();
  void on_pushButton_screen_gif_start_clicked();
  void recording_gif();
  void recording_stop();

 private:
  s21::Controller *controller_;
//  s21::ParamDTO * paramDTO_;

  Ui::MainWindow *ui;

  //  struct object_data data = {0, NULL, 0, NULL, 0, 0, 0, 0, 0, 0};
  double max_coord;

//  void init_settings();
  QString take_style_sheet_color_button(struct rgb_color color);
  void connects();

//  void user_settings_set();
//  void user_settings_save();
//  void projection_settings();

  QFileDialog file_dialog;

  int flag = 0;
  QTimer *timer;
  QTimer *timer_2;
  QGifImage *gif;
};

#endif  // MAINWINDOW_H
