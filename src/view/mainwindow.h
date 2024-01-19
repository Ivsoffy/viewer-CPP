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
#include <QFileInfo>

#include "../controller/controller.h"
#include "../dto/dto.h"
#include "oglwidget.h"

#ifdef __APPLE__
#define PATH_FROM_EXE_TO_SRC "../../../.."
#else
#define PATH_FROM_EXE_TO_SRC ".."
#endif

#define PATH_STD_OPEN_FINDER "/" PATH_FROM_EXE_TO_SRC "/3d_objects"

enum screenshot_formats { SCREENSHOT_FORMAT_BMP, SCREENSHOT_FORMAT_JPEG };

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

// class Controller;

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  MainWindow(s21::Controller *controller, QWidget *parent = nullptr);
  ~MainWindow();

  //  void closeEvent(QCloseEvent *event);

  //  struct user_settings user_settings;

  //  void user_settings_combo_box_change();
  //  void user_settings_double_spin_box_change();
  //  void user_settings_color_change();

 private slots:
  /// @brief Choose .obj file and transfer him to model

  void ChooseFile();
  /// @brief Update figure param and repaint

  void Redraw();
  /**
   * @brief Slot for change figure scale
   *
   * @param value New figure scale
   */
  void ScaleSliderChange(int value);

  /// @brief Slot for change all combobox
  void ComboboxChange();

  /// @brief Slot for change all spinbox
  void SpinboxChange();

  /// @brief Slot for change all double spinbox
  void DoubleSpinboxChange();

  void CreateSnapshot();
  void Restore();

  void Reset();
  void SliderReset();

  void on_pushButton_screen_start_clicked();
  void on_pushButton_screen_gif_start_clicked();
  void recording_gif();
  void recording_stop();

 private:
  s21::Controller *controller_;
  Ui::MainWindow *ui;
  s21::ParamDTO *dto_;
  bool from_snapshot_ = false;

  /// @brief Contain all connects
  void Connects();

  //  void init_settings();
  //  void user_settings_set();
  //  void user_settings_save();
  //  void projection_settings();

  QFileDialog file_dialog;

  int gif_recording = 0;
  QTimer *timer;
  QTimer *timer_2;
  QGifImage *gif;
};

#endif  // MAINWINDOW_H
