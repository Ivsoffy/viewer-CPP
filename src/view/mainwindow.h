#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <qgifimage.h>
#include <stdio.h>

#include <QColorDialog>
#include <QFileDialog>
#include <QFileInfo>
#include <QImage>
#include <QMainWindow>
#include <QCloseEvent>
#include <QSettings>
#include <QTimer>
#include <iostream>

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

class MainWindow : public QMainWindow {
  Q_OBJECT


 public:
  MainWindow(s21::Controller *controller, QWidget *parent = nullptr);
  ~MainWindow();
public slots:
  void changeBackground(QColor color);
  void changeEdges(QColor color);
  void changeVertex(QColor color);

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

  void on_pushButton_settings_view_other_color_clicked();
  void on_pushButton_settings_view_polygon_color_clicked();
  void on_pushButton_settings_view_vertex_color_clicked();

  void closeEvent(QCloseEvent *event);

public:
  Ui::MainWindow *ui;
private:
  s21::Controller *controller_;

  s21::ParamDTO *dto_;
  s21::ObjectInfoDTO objectInfoDTO_;
  bool from_snapshot_ = false;

  /// @brief Contain all connects
  void Connects();

  QFileDialog file_dialog;

  QColor vertex_color, edges_color, back_color;

  int gif_recording = 0;
  QTimer *timer;
  QTimer *timer_2;
  QGifImage *gif;

  class InterfaceDecorator {
  public:
      virtual ~InterfaceDecorator() = default;
      virtual void writeSettings() = 0;
  };

  class BaseSetting : public InterfaceDecorator{
    public:
      BaseSetting(Ui::MainWindow *ui) : ui_(ui) {}
      BaseSetting(Ui::MainWindow *ui, MainWindow *mv) : ui_(ui), mw_(mv){}
      ~BaseSetting() = default;
      void writeSettings() override;
      void readSettings();
     private:
      Ui::MainWindow *ui_;
      MainWindow *mw_;
  };

  class Decorator : public InterfaceDecorator{
    public:
      InterfaceDecorator *common_;
      Decorator(InterfaceDecorator *id) : common_(id) {}

      void writeSettings();
  };

    friend MainWindow::BaseSetting;

  class DecoratorVertexes : public Decorator{
  public:
      DecoratorVertexes(InterfaceDecorator *id, Ui::MainWindow *ui): Decorator(id), ui_(ui) {}

      void writeSettings();
      void writeVertexes();

      Ui::MainWindow *ui_;
  };

  class DecoratorEdges : public Decorator{
  public:
      DecoratorEdges(InterfaceDecorator *id, Ui::MainWindow *ui): Decorator(id), ui_(ui) {}

      void writeSettings();
      void writeEdges();

      Ui::MainWindow *ui_;
  };

  class DecoratorProjection : public Decorator{
  public:
      DecoratorProjection(InterfaceDecorator *id, Ui::MainWindow *ui): Decorator(id), ui_(ui) {}

      void writeSettings();
      void writeProjection();

      Ui::MainWindow *ui_;
  };

  InterfaceDecorator  *bs;
  BaseSetting *bs_read_;

};

#endif  // MAINWINDOW_H
