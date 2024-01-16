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

#include "../controller/controller.h"
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

  void take_screenshot();
  void record_gif();

  void CreateSnapshot(double move_x,
                      double move_y,
                      double move_z,
                      double angle_x,
                      double angle_y,
                      double angle_z,
                      double scale);

//  void user_settings_combo_box_change();
//  void user_settings_double_spin_box_change();
//  void user_settings_color_change();

 private slots:  
  void valueChanged_to_Slider_rot_x(int value);
  void valueChanged_to_Spinbox_rot_x(int value);
  void valueChanged_to_Slider_rot_y(int value);
  void valueChanged_to_Spinbox_rot_y(int value);
  void valueChanged_to_Slider_rot_z(int value);
  void valueChanged_to_Spinbox_rot_z(int value);

  void valueChanged_to_Slider_move_x(int value);
  void valueChanged_to_Spinbox_move_x(int value);
  void valueChanged_to_Slider_move_y(int value);
  void valueChanged_to_Spinbox_move_y(int value);
  void valueChanged_to_Slider_move_z(int value);
  void valueChanged_to_Spinbox_move_z(int value);

  void valueChanged_to_Slider_scale(int value);

  void combo_box_change();

  void on_doubleSpinBox_settings_view_polygon_width_valueChanged(double arg1);

  void on_doubleSpinBox_settings_view_vertex_size_valueChanged(double arg1);

  void on_pushButton_screen_start_clicked();
  void on_pushButton_screen_gif_start_clicked();
  void recording_gif();
  void recording_stop();

 private:
  s21::Controller *controller_;
  Ui::MainWindow *ui;
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
