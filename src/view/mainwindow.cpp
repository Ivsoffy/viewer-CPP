#include "mainwindow.h"

#include "ui_mainwindow.h"

#include <ctime>/////////////////////////////TODO
#include <chrono>/////////////////////TODO
#include <iostream>////////////////////////////TODO
using std::chrono::duration_cast;////////////////////////////TODO
using std::chrono::milliseconds;////////////////////////////TODO
using std::chrono::system_clock;////////////////////////////TODO

MainWindow::MainWindow(s21::Controller *controller, QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  controller_ = controller;
  controller_->paramDTO_ = new s21::ParamDTO(0, 0, 0, 0, 0, 0, 1);
//  file_dialog.setParent(parent);
  file_dialog.setFileMode(QFileDialog::ExistingFile);
  file_dialog.setNameFilter(tr("Object Files (*.obj)"));
  QString std_path =
      QCoreApplication::applicationDirPath() + PATH_STD_OPEN_FINDER;
  file_dialog.setDirectory(std_path);
  //  user_settings_setup(&user_settings);
  ui->setupUi(this);
  //  ui->openGLWidget->main_window = this;
//  init_settings();
  connects();
}

MainWindow::~MainWindow() { delete ui; }

// void MainWindow::closeEvent(QCloseEvent *event) {
//   if (event) pass();
////  user_settings_save_file(&user_settings);
//  close();
//}


void MainWindow::connects() {
  connect(ui->pushButton_file_select, SIGNAL(clicked()), this,
          SLOT(choose_file()));

  connect(ui->comboBox_settings_view_projection_type,
          SIGNAL(currentIndexChanged(int)), this, SLOT(combo_box_change()));
  connect(ui->comboBox_settings_view_polygon_type,
          SIGNAL(currentIndexChanged(int)), this,
          SLOT(combo_box_change()));
  connect(ui->comboBox_settings_view_vertex_type,
          SIGNAL(currentIndexChanged(int)), this,
          SLOT(combo_box_change()));

  connect (ui->spinbox_move_x, SIGNAL(valueChanged(int)),ui->slider_move_x, SLOT(setValue(int)));
  connect (ui->slider_move_x, SIGNAL(valueChanged(int)),ui->spinbox_move_x, SLOT(setValue(int)));
  connect(ui->spinbox_move_x, SIGNAL(valueChanged(int)), this,
          SLOT(spinbox_change()));

  connect (ui->spinbox_move_y, SIGNAL(valueChanged(int)),ui->slider_move_y, SLOT(setValue(int)));
  connect (ui->slider_move_y, SIGNAL(valueChanged(int)),ui->spinbox_move_y, SLOT(setValue(int)));
  connect(ui->spinbox_move_y, SIGNAL(valueChanged(int)), this,
          SLOT(spinbox_change()));

  connect (ui->spinbox_move_z, SIGNAL(valueChanged(int)),ui->slider_move_z, SLOT(setValue(int)));
  connect (ui->slider_move_z, SIGNAL(valueChanged(int)),ui->spinbox_move_z, SLOT(setValue(int)));
  connect(ui->spinbox_move_z, SIGNAL(valueChanged(int)), this,
          SLOT(spinbox_change()));

  connect (ui->spinbox_rot_x, SIGNAL(valueChanged(int)),ui->slider_rot_x, SLOT(setValue(int)));
  connect (ui->slider_rot_x, SIGNAL(valueChanged(int)),ui->spinbox_rot_x, SLOT(setValue(int)));
  connect(ui->spinbox_rot_x, SIGNAL(valueChanged(int)), this,
          SLOT(spinbox_change()));

  connect (ui->spinbox_rot_y, SIGNAL(valueChanged(int)),ui->slider_rot_y, SLOT(setValue(int)));
  connect (ui->slider_rot_y, SIGNAL(valueChanged(int)),ui->spinbox_rot_y, SLOT(setValue(int)));
  connect(ui->spinbox_rot_y, SIGNAL(valueChanged(int)), this,
          SLOT(spinbox_change()));

  connect (ui->spinbox_rot_z, SIGNAL(valueChanged(int)),ui->slider_rot_z, SLOT(setValue(int)));
  connect (ui->slider_rot_z, SIGNAL(valueChanged(int)),ui->spinbox_rot_z, SLOT(setValue(int)));
  connect(ui->spinbox_rot_z, SIGNAL(valueChanged(int)), this,
          SLOT(spinbox_change()));

  connect(ui->slider_scale, SIGNAL(valueChanged(int)), this,
          SLOT(valueChanged_to_Slider_scale(int)));

  connect(ui->doubleSpinBox_settings_view_polygon_width, SIGNAL(valueChanged(double)), this,
          SLOT(double_spinbox_change()));
  connect(ui->doubleSpinBox_settings_view_vertex_size, SIGNAL(valueChanged(double)), this,
          SLOT(double_spinbox_change()));

  connect(ui->pushButton_screen_start, SIGNAL(clicked()), this,
          SLOT(take_screenshot()));
  connect(ui->pushButton_screen_gif_start, SIGNAL(clicked()), this,
          SLOT(record_gif()));
}

void MainWindow::choose_file() {
  ui->openGLWidget->need_paint_ = false;
  if (file_dialog.exec()) {
    QStringList fileNames = file_dialog.selectedFiles();
    QString filename = fileNames[0];

    ui->slider_move_x->setValue(0);
    ui->slider_move_y->setValue(0);
    ui->slider_move_z->setValue(0);
    ui->slider_rot_x->setValue(0);
    ui->slider_rot_y->setValue(0);
    ui->slider_rot_z->setValue(0);
     ui->slider_scale->setValue(0);

    ui->spinbox_move_x->setValue(0);
    ui->spinbox_move_y->setValue(0);
    ui->spinbox_move_z->setValue(0);
    ui->spinbox_rot_x->setValue(0);
    ui->spinbox_rot_y->setValue(0);
    ui->spinbox_rot_z->setValue(0);

    controller_->TransferObject(filename.toStdString());
    ui->openGLWidget->scale_ = controller_->GetMax()*2;

    ui->openGLWidget->SetVertices(controller_->GetVertecisRef());
    ui->openGLWidget->SetEdges(controller_->GetEdgesRef());
    ui->openGLWidget->update();
    ui->openGLWidget->need_paint_ = true;
    ui->lineEdit_file_input->setText(filename);
  }
}

void MainWindow::redraw() {
  if (ui->openGLWidget->need_paint_) {
//      auto millisec_start = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();/////////////////////TODO
      controller_->TransferFigureParams();
//      auto millisec_end = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();/////////////////////TODO
//      std::cerr << millisec_end - millisec_start << "<<<<<<<<TransferFigureParams>>>>>>>" << std::endl;/////////////////////TODO
      ui->openGLWidget->update();
  }
}

void MainWindow::combo_box_change() {
  QComboBox *worked = (QComboBox *)sender();

  if (worked == ui->comboBox_settings_view_projection_type) {
    ui->openGLWidget->view_type_ = worked->currentIndex();
  } else if (worked == ui->comboBox_settings_view_vertex_type) {
    ui->openGLWidget->vertex_type_ = worked->currentIndex();
  } else if (worked == ui->comboBox_settings_view_polygon_type) {
    ui->openGLWidget->line_type_ = worked->currentIndex();
  }
  ui->openGLWidget->repaint();
}

void MainWindow::spinbox_change() {
  QSpinBox *worked = (QSpinBox *)sender();
  if (worked == ui->spinbox_move_x)
    controller_->GetAffineTransformationsRef()->SetMoveX(worked->value() * ui->openGLWidget->axis_scale_ / 100);
  else if (worked == ui->spinbox_move_y)
    controller_->GetAffineTransformationsRef()->SetMoveY(worked->value() * ui->openGLWidget->axis_scale_ / 100);
  else if (worked == ui->spinbox_move_z)
    controller_->GetAffineTransformationsRef()->SetMoveZ(worked->value() * ui->openGLWidget->axis_scale_ / 100);
  else if (worked == ui->spinbox_rot_x)
    controller_->GetAffineTransformationsRef()->SetAngleX(worked->value());
  else if (worked == ui->spinbox_rot_y)
    controller_->GetAffineTransformationsRef()->SetAngleY(worked->value());
  else if (worked == ui->spinbox_rot_z)
    controller_->GetAffineTransformationsRef()->SetAngleZ(worked->value());
  redraw();
}

void MainWindow::valueChanged_to_Slider_scale(int value) {
    controller_->GetAffineTransformationsRef()->SetScale(value);
    ui->scale_lable->setText(QString::number(pow(3, value / 100.0) * 100, 'f', 2));
    redraw();
}

void MainWindow::double_spinbox_change() {
  QDoubleSpinBox *worked = (QDoubleSpinBox *)sender();
  if (worked == ui->doubleSpinBox_settings_view_polygon_width)
    ui->openGLWidget->line_size_ = worked->value();
  else if (worked == ui->doubleSpinBox_settings_view_vertex_size)
    ui->openGLWidget->vertex_size_ = worked->value();
  redraw();
}

void MainWindow::on_pushButton_screen_start_clicked() {
  QImage screenshot = ui->openGLWidget->grabFramebuffer();
  QString name = QDate::currentDate().toString("yyMMdd") + "_" +
                 QTime::currentTime().toString("hhmmss");
  QString extention = ui->comboBox_screen_unit->currentText();
  QString path = QApplication::applicationDirPath() + "/../../../" + name +
                 "." + extention;
  screenshot.save(path);
}

void MainWindow::on_pushButton_screen_gif_start_clicked() {
  if (!flag) {
    ui->pushButton_screen_gif_start->setText("Остановить запись");

    gif = new QGifImage;
    timer = new QTimer(this);
    timer_2 = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(recording_gif()));
    connect(timer_2, SIGNAL(timeout()), ui->openGLWidget, SLOT(repaint()));
    timer->start(100);
    timer_2->start(1);
    QTimer::singleShot(5000, this, SLOT(recording_stop()));
    flag = 1;
  } else {
    recording_stop();
  }
}

void MainWindow::recording_gif() {
  QImage frameImage = ui->openGLWidget->grabFramebuffer();
  gif->addFrame(frameImage, 100);
}

void MainWindow::recording_stop() {
  flag = 0;
  ui->pushButton_screen_gif_start->setText("Запись");
  timer->stop();
  timer_2->stop();
  delete timer;
  delete timer_2;

  QString name = QDate::currentDate().toString("yyMMdd") + "_" +
                 QTime::currentTime().toString("hhmmss") + ".gif";
  QString gifFileName =
      QApplication::applicationDirPath() + "/../../../" + name;
  gif->save(gifFileName);
  delete gif;
  repaint();
}
