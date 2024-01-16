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
  void ChooseFile();
  void Redraw();

//  void user_settings_combo_box_change();
//  void user_settings_double_spin_box_change();
//  void user_settings_color_change();

 private slots:  
  void ScaleSliderChange(int value);

  void ComboboxChange();
  void SpinboxChange();
  void DoubleSpinboxChange();

  void on_pushButton_screen_start_clicked();
  void on_pushButton_screen_gif_start_clicked();
  void recording_gif();
  void recording_stop();

 private:
  s21::Controller *controller_;

  Ui::MainWindow *ui;

  double max_coord;

//  void init_settings();
  void Connects();

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
