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
    connect(this->ui->slider_move_x, SIGNAL(valueChanged(int)), this,
            SLOT(valueChanged_to_Slider_move_x(int)));
    connect(this->ui->spinbox_move_x, SIGNAL(valueChanged(int)), this,
            SLOT(valueChanged_to_Spinbox_move_x(int)));
    connect(this->ui->slider_move_y, SIGNAL(valueChanged(int)), this,
            SLOT(valueChanged_to_Slider_move_y(int)));
    connect(this->ui->spinbox_move_y, SIGNAL(valueChanged(int)), this,
            SLOT(valueChanged_to_Spinbox_move_y(int)));
    connect(this->ui->slider_move_z, SIGNAL(valueChanged(int)), this,
            SLOT(valueChanged_to_Slider_move_z(int)));
    connect(this->ui->spinbox_move_z, SIGNAL(valueChanged(int)), this,
            SLOT(valueChanged_to_Spinbox_move_z(int)));

    connect(this->ui->slider_rot_x, SIGNAL(valueChanged(int)), this,
            SLOT(valueChanged_to_Slider_rot_x(int)));
    connect(this->ui->spinbox_rot_x, SIGNAL(valueChanged(int)), this,
            SLOT(valueChanged_to_Spinbox_rot_x(int)));
    connect(this->ui->slider_rot_y, SIGNAL(valueChanged(int)), this,
            SLOT(valueChanged_to_Slider_rot_y(int)));
    connect(this->ui->spinbox_rot_y, SIGNAL(valueChanged(int)), this,
            SLOT(valueChanged_to_Spinbox_rot_y(int)));
    connect(this->ui->slider_rot_z, SIGNAL(valueChanged(int)), this,
            SLOT(valueChanged_to_Slider_rot_z(int)));
    connect(this->ui->spinbox_rot_z, SIGNAL(valueChanged(int)), this,
            SLOT(valueChanged_to_Spinbox_rot_z(int)));



    ///////////////////////////////////////////////////////////////
    connect(this->ui->slider_scale, SIGNAL(valueChanged(int)), this,
            SLOT(valueChanged_to_Slider_scale(int)));
    connect(this->ui->spinbox_scale, SIGNAL(valueChanged(double)), this,
            SLOT(valueChanged_to_Spinbox_scale(double)));

    connect(this->ui->slider_scale_2, SIGNAL(valueChanged(int)), this,
            SLOT(valueChanged_to_Slider_scale_2(int)));
    connect(this->ui->spinbox_scale_2, SIGNAL(valueChanged(int)), this,
            SLOT(valueChanged_to_Spinbox_scale_2(int)));

//  connect(ui->lineEdit_file_input, SIGNAL(returnPressed()), this,
//          SLOT(open_file()));
  connect(ui->pushButton_file_select, SIGNAL(clicked()), this,
          SLOT(choose_file()));

  connect(ui->pushButton_screen_start, SIGNAL(clicked()), this,
          SLOT(take_screenshot()));
  connect(ui->pushButton_screen_gif_start, SIGNAL(clicked()), this,
          SLOT(record_gif()));
}


void MainWindow::choose_file() {
  ui->openGLWidget->need_paint = false;
  if (file_dialog.exec()) {
    QStringList fileNames = file_dialog.selectedFiles();
    QString filename = fileNames[0];
    controller_->TransferObject(filename.toStdString());
    ui->openGLWidget->SetVertices(controller_->GetVertecisRef());
    ui->openGLWidget->SetEdges(controller_->GetEdgesRef());
    ui->openGLWidget->update();
    ui->openGLWidget->need_paint = true;
    ui->lineEdit_file_input->setText(filename);
  }
}

void MainWindow::redraw() {
  if (ui->openGLWidget->need_paint) {

//      auto millisec_start = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();/////////////////////TODO

      controller_->TransferFigureParams();

//      auto millisec_end = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();/////////////////////TODO
//      std::cerr << millisec_end - millisec_start << "<<<<<<<<TransferFigureParams>>>>>>>" << std::endl;/////////////////////TODO

      ui->openGLWidget->update();
  }
}

void MainWindow::valueChanged_to_Slider_move_x(int value) {
  ui->spinbox_move_x->setValue(value);
}

void MainWindow::valueChanged_to_Spinbox_move_x(int value) {
  ui->slider_move_x->setValue(value);
  controller_->GetAffineTransformationsRef()->SetMoveX(value);
  redraw();
}

void MainWindow::valueChanged_to_Slider_move_y(int value) {
  ui->spinbox_move_y->setValue(value);
}

void MainWindow::valueChanged_to_Spinbox_move_y(int value) {
  ui->slider_move_y->setValue(value);
  controller_->GetAffineTransformationsRef()->SetMoveY(value);
  redraw();
}

void MainWindow::valueChanged_to_Slider_move_z(int value) {
  ui->spinbox_move_z->setValue(value);
}

void MainWindow::valueChanged_to_Spinbox_move_z(int value) {
  ui->slider_move_z->setValue(value);
  controller_->GetAffineTransformationsRef()->SetMoveZ(value);
  redraw();
}

void MainWindow::valueChanged_to_Slider_rot_x(int value) {
  ui->spinbox_rot_x->setValue(value);
}

void MainWindow::valueChanged_to_Spinbox_rot_x(int value) {
  ui->slider_rot_x->setValue(value);
  controller_->GetAffineTransformationsRef()->SetAngleX(value);
  redraw();
}

void MainWindow::valueChanged_to_Slider_rot_y(int value) {
  ui->spinbox_rot_y->setValue(value);
}

void MainWindow::valueChanged_to_Spinbox_rot_y(int value) {
  ui->slider_rot_y->setValue(value);
  controller_->GetAffineTransformationsRef()->SetAngleY(value);
  redraw();
}

void MainWindow::valueChanged_to_Slider_rot_z(int value) {
  ui->spinbox_rot_z->setValue(value);
}

void MainWindow::valueChanged_to_Spinbox_rot_z(int value) {
  ui->slider_rot_z->setValue(value);
  controller_->GetAffineTransformationsRef()->SetAngleZ(value);
  redraw();
}

void MainWindow::valueChanged_to_Slider_scale(int value) {
  ui->spinbox_scale->setValue(value);
}
void MainWindow::valueChanged_to_Spinbox_scale(double value) {
  ui->slider_scale->setValue(value);
  controller_->GetAffineTransformationsRef()->SetScale(value);
  redraw();
}
////////////////////////////////////////////////////////////////////
//void MainWindow::valueChanged_to_Slider_scale_2(int value) {
//  if (value == 0) {
//      value = -2;
//  } else if (value == -1) {
//      value = 1;
//  }
//  ui->spinbox_scale_2->setValue(value);
//}
//void MainWindow::valueChanged_to_Spinbox_scale_2(int value) {
//  if (value == 0) {
//     value = -2;
//     ui->spinbox_scale_2->setValue(value);
//  } else if (value == -1) {
//      value = 1;
//  }
//  ui->slider_scale_2->setValue(value);
//  controller_->GetAffineTransformationsRef()->SetScale(value);
//  redraw();
//}
////////////////////////////////////////////////////////////////////
void MainWindow::valueChanged_to_Slider_scale_2(int value) {
  ui->spinbox_scale_2->setValue(value);
}
void MainWindow::valueChanged_to_Spinbox_scale_2(int value) {
  ui->slider_scale_2->setValue(value);
  controller_->GetAffineTransformationsRef()->SetScale(value);
  redraw();
}


void MainWindow::take_screenshot() {
  //
}

void MainWindow::record_gif() {
  //
}

void MainWindow::on_comboBox_settings_view_polygon_type_currentIndexChanged(
    int index) {
  ui->openGLWidget->line_type = index;
  ui->openGLWidget->repaint();
}

void MainWindow::on_doubleSpinBox_settings_view_polygon_width_valueChanged(
    double arg1) {
  ui->openGLWidget->line_size = arg1;
  ui->openGLWidget->repaint();
}


void MainWindow::on_comboBox_settings_view_vertex_type_currentIndexChanged(
    int index) {
  ui->openGLWidget->vertex_type = index;
  ui->openGLWidget->repaint();
}

void MainWindow::on_doubleSpinBox_settings_view_vertex_size_valueChanged(
    double arg1) {
  ui->openGLWidget->vertex_size = arg1;
  ui->openGLWidget->repaint();
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
