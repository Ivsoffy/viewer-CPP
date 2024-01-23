//#include "mainwindow.h"

//#include "ui_mainwindow.h"

//MainWindow::MainWindow(s21::Controller *controller, QWidget *parent)
//    : QMainWindow(parent), ui(new Ui::MainWindow) {
//  controller_ = controller;
//  file_dialog.setFileMode(QFileDialog::ExistingFile);
//  file_dialog.setNameFilter(tr("Object Files (*.obj)"));
//  QString std_path =
//      QCoreApplication::applicationDirPath() + PATH_STD_OPEN_FINDER;
//  file_dialog.setDirectory(std_path);
//  //  user_settings_setup(&user_settings);
//  ui->setupUi(this);
//  //  init_settings();
//  Connects();
//}

//MainWindow::~MainWindow() { delete ui; }

//// void MainWindow::closeEvent(QCloseEvent *event) {
////   if (event) pass();
//// //  user_settings_save_file(&user_settings);
////  close();
//// }

//void MainWindow::Connects() {
//  connect(ui->pushButton_file_select, SIGNAL(clicked()), this,
//          SLOT(ChooseFile()));

//  connect(ui->comboBox_settings_view_projection_type,
//          SIGNAL(currentIndexChanged(int)), this, SLOT(ComboboxChange()));
//  connect(ui->comboBox_settings_view_polygon_type,
//          SIGNAL(currentIndexChanged(int)), this, SLOT(ComboboxChange()));
//  connect(ui->comboBox_settings_view_vertex_type,
//          SIGNAL(currentIndexChanged(int)), this, SLOT(ComboboxChange()));

//  connect(ui->spinbox_move_x, SIGNAL(valueChanged(int)), ui->slider_move_x,
//          SLOT(setValue(int)));
//  connect(ui->slider_move_x, SIGNAL(valueChanged(int)), ui->spinbox_move_x,
//          SLOT(setValue(int)));
//  connect(ui->spinbox_move_x, SIGNAL(valueChanged(int)), this,
//          SLOT(SpinboxChange()));

//  connect(ui->spinbox_move_y, SIGNAL(valueChanged(int)), ui->slider_move_y,
//          SLOT(setValue(int)));
//  connect(ui->slider_move_y, SIGNAL(valueChanged(int)), ui->spinbox_move_y,
//          SLOT(setValue(int)));
//  connect(ui->spinbox_move_y, SIGNAL(valueChanged(int)), this,
//          SLOT(SpinboxChange()));

//  connect(ui->spinbox_move_z, SIGNAL(valueChanged(int)), ui->slider_move_z,
//          SLOT(setValue(int)));
//  connect(ui->slider_move_z, SIGNAL(valueChanged(int)), ui->spinbox_move_z,
//          SLOT(setValue(int)));
//  connect(ui->spinbox_move_z, SIGNAL(valueChanged(int)), this,
//          SLOT(SpinboxChange()));

//  connect(ui->spinbox_rot_x, SIGNAL(valueChanged(int)), ui->slider_rot_x,
//          SLOT(setValue(int)));
//  connect(ui->slider_rot_x, SIGNAL(valueChanged(int)), ui->spinbox_rot_x,
//          SLOT(setValue(int)));
//  connect(ui->spinbox_rot_x, SIGNAL(valueChanged(int)), this,
//          SLOT(SpinboxChange()));

//  connect(ui->spinbox_rot_y, SIGNAL(valueChanged(int)), ui->slider_rot_y,
//          SLOT(setValue(int)));
//  connect(ui->slider_rot_y, SIGNAL(valueChanged(int)), ui->spinbox_rot_y,
//          SLOT(setValue(int)));
//  connect(ui->spinbox_rot_y, SIGNAL(valueChanged(int)), this,
//          SLOT(SpinboxChange()));

//  connect(ui->spinbox_rot_z, SIGNAL(valueChanged(int)), ui->slider_rot_z,
//          SLOT(setValue(int)));
//  connect(ui->slider_rot_z, SIGNAL(valueChanged(int)), ui->spinbox_rot_z,
//          SLOT(setValue(int)));
//  connect(ui->spinbox_rot_z, SIGNAL(valueChanged(int)), this,
//          SLOT(SpinboxChange()));

//  connect(ui->slider_scale, SIGNAL(valueChanged(int)), this,
//          SLOT(ScaleSliderChange(int)));

//  connect(ui->doubleSpinBox_settings_view_polygon_width,
//          SIGNAL(valueChanged(double)), this, SLOT(DoubleSpinboxChange()));
//  connect(ui->doubleSpinBox_settings_view_vertex_size,
//          SIGNAL(valueChanged(double)), this, SLOT(DoubleSpinboxChange()));

//  connect(ui->pushButton_CreateSnapshot, SIGNAL(clicked()), this,
//          SLOT(CreateSnapshot()));
//  connect(ui->pushButton_Restore, SIGNAL(clicked()), this, SLOT(Restore()));
//  connect(ui->pushButton_Reset, SIGNAL(clicked()), this, SLOT(Reset()));
//}

//void MainWindow::ChooseFile() {
//  if (file_dialog.exec()) {
//    ui->openGLWidget->need_paint_ = false;
//    QStringList fileNames = file_dialog.selectedFiles();
//    QString filename = fileNames[0];

//    SliderReset();
//    ui->label_info->clear();

//    std::string err_msg = controller_->TransferObject(filename.toStdString());
//    if (err_msg == "OK") {
//      ui->openGLWidget->scale_ = controller_->GetMax() * 2;

//      ui->openGLWidget->SetVertices(controller_->GetVertecisRef());
//      ui->openGLWidget->SetEdges(controller_->GetEdgesRef());
//      ui->openGLWidget->update();
//      ui->lineEdit_file_input->setText(filename);
//      ui->label_info_object_info_vertex_count_ans_2->setText(
//          QString::number(ui->openGLWidget->GetVerticesRef()->size()));
//      ui->label_info_object_info_polygon_count_ans_2->setText(
//          QString::number(ui->openGLWidget->GetEdgesRef()->size()));
//      QFileInfo fi(filename);
//      ui->label_info_object_info_file_name_ans_2->setText(fi.baseName());
//      ui->openGLWidget->need_paint_ = true;
//    } else
//      ui->label_info->setText(QString::fromStdString(err_msg));
//  }
//}

//void MainWindow::Redraw() {
//  if (ui->openGLWidget->need_paint_) {
//    controller_->TransferFigureParams();
//    ui->openGLWidget->update();
//  }
//}

//void MainWindow::ComboboxChange() {
//  QComboBox *worked = (QComboBox *)sender();

//  if (worked == ui->comboBox_settings_view_projection_type) {
//    ui->openGLWidget->view_type_ = worked->currentIndex();
//  } else if (worked == ui->comboBox_settings_view_vertex_type) {
//    ui->openGLWidget->vertex_type_ = worked->currentIndex();
//  } else if (worked == ui->comboBox_settings_view_polygon_type) {
//    ui->openGLWidget->line_type_ = worked->currentIndex();
//  }
//  ui->openGLWidget->update();
//}

//void MainWindow::SpinboxChange() {
//  if (from_snapshot_) {
//    return;
//  }
//  QSpinBox *worked = (QSpinBox *)sender();
//  if (worked == ui->spinbox_move_x)
//    controller_->GetAffineTransformationsRef()->SetMoveX(
//        worked->value() * ui->openGLWidget->axis_scale_ / 100);
//  else if (worked == ui->spinbox_move_y)
//    controller_->GetAffineTransformationsRef()->SetMoveY(
//        worked->value() * ui->openGLWidget->axis_scale_ / 100);
//  else if (worked == ui->spinbox_move_z)
//    controller_->GetAffineTransformationsRef()->SetMoveZ(
//        worked->value() * ui->openGLWidget->axis_scale_ / 100);
//  else if (worked == ui->spinbox_rot_x)
//    controller_->GetAffineTransformationsRef()->SetAngleX(worked->value());
//  else if (worked == ui->spinbox_rot_y)
//    controller_->GetAffineTransformationsRef()->SetAngleY(worked->value());
//  else if (worked == ui->spinbox_rot_z)
//    controller_->GetAffineTransformationsRef()->SetAngleZ(worked->value());
//  Redraw();
//}

//void MainWindow::ScaleSliderChange(int value) {
//  ui->scale_lable->setText(
//      QString::number(pow(3, value / 100.0) * 100, 'f', 2));
//  if (from_snapshot_) {
//    return;
//  }
//  controller_->GetAffineTransformationsRef()->SetScale(value);
//  //  ui->scale_lable->setText(
//  //      QString::number(pow(3, value / 100.0) * 100, 'f', 2));
//  Redraw();
//}

//void MainWindow::DoubleSpinboxChange() {
//  QDoubleSpinBox *worked = (QDoubleSpinBox *)sender();
//  if (worked == ui->doubleSpinBox_settings_view_polygon_width)
//    ui->openGLWidget->line_size_ = worked->value();
//  else if (worked == ui->doubleSpinBox_settings_view_vertex_size)
//    ui->openGLWidget->vertex_size_ = worked->value();
//  ui->openGLWidget->update();
//}

//void MainWindow::on_pushButton_screen_start_clicked() {
//  QImage screenshot = ui->openGLWidget->grabFramebuffer();
//  QString name = QDate::currentDate().toString("yyMMdd") + "_" +
//                 QTime::currentTime().toString("hhmmss");
//  QString extention = ui->comboBox_screen_unit->currentText();
//  QString path = QApplication::applicationDirPath() + "/../../../" + name +
//                 "." + extention;
//  screenshot.save(path);
//}

////void MainWindow::on_pushButton_screen_gif_start_clicked() {
////  if (!gif_recording) {
////    ui->pushButton_screen_gif_start->setText("Остановить запись");

////    gif = new QGifImage;
////    timer = new QTimer(this);
////    timer_2 = new QTimer(this);
////    connect(timer, SIGNAL(timeout()), this, SLOT(recording_gif()));
////    connect(timer_2, SIGNAL(timeout()), ui->openGLWidget, SLOT(repaint()));
////    timer->start(100);
////    timer_2->start(1);
////    QTimer::singleShot(5000, this, SLOT(recording_stop()));
////    gif_recording = 1;
////  } else {
////    recording_stop();
////  }
////}

////void MainWindow::recording_gif() {
////  QImage frameImage = ui->openGLWidget->grabFramebuffer();
////  gif->addFrame(frameImage, 100);
////}

////void MainWindow::recording_stop() {
////  if (gif_recording) {
////    gif_recording = 0;
////    ui->pushButton_screen_gif_start->setText("GIF");
////    timer->stop();
////    timer_2->stop();
////    delete timer;
////    delete timer_2;

////    QString name = QDate::currentDate().toString("yyMMdd") + "_" +
////                   QTime::currentTime().toString("hhmmss") + ".gif";
////    //  QString gifFileName =
////    //      QApplication::applicationDirPath() + "/../../../" + name;
////    QString gif_filename = QFileDialog::getSaveFileName(NULL, "Save to ...", "",
////                                                        "GIF image (*.gif)");
////    //  QString gif_filename = "/Users/errokele/projects/gifka.gif";
////    gif->save(gif_filename);
////    delete gif;
////    repaint();
////  }
////}
/////// ///////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
////void MainWindow::on_pushButton_screen_gif_start_clicked() {
////  gif = new QGifImage(QSize(640, 480));
////  gif->setDefaultDelay(100);
////  timer = new QTimer(this);
////  timer->start(100);
////  connect(timer, SIGNAL(timeout()), this, SLOT(recording_gif()));
////}

////void MainWindow::recording_gif() {
////  if (gif->frameCount() < 50) {
////    QImage image = ui->openGLWidget->grabFramebuffer();
////    image = image.scaled(640, 480, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
////    gif->addFrame(image);
////  } else {
////      QString gif_filename = QFileDialog::getSaveFileName(NULL, "Save to ...", "",
////                                                          "GIF image (*.gif)");
////      gif->save(gif_filename);
////      timer->stop();
////      delete gif;
////  }
////}
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
///// /// ///////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////
//void MainWindow::on_pushButton_screen_gif_start_clicked() {
//  gif = new QGifImage(QSize(640, 480));
//  gif-> setDefaultDelay(100);
//  timer = new QTimer(this);
//  QTimer::singleShot(5000, this, SLOT(recording_stop()));
//  timer->start(100);
//  connect(timer, SIGNAL(timeout()), this, SLOT(recording_gif()));
//}

//void MainWindow::recording_gif() {
//    std::cerr << "-gif->frameCount()-" << gif->frameCount() << std::endl;
//    QImage image = ui->openGLWidget->grabFramebuffer();
//    image = image.scaled(640, 480, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
//    gif->addFrame(image);
//}

//void MainWindow::recording_stop() {
//      QString gif_filename = QFileDialog::getSaveFileName(NULL, "Save to ...", "",
//                                                          "GIF image (*.gif)");
//      timer->stop();
//      gif->save(gif_filename);
//      delete gif;
//      delete timer;
//}
////void MainWindow::recording_gif() {
////  if (gif->frameCount() < 50) {
////    std::cerr << "-gif->frameCount()-" << gif->frameCount() << std::endl;
////    QImage image = ui->openGLWidget->grabFramebuffer();
////    image = image.scaled(640, 480, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
////    gif->addFrame(image);
////  } else {
////      QString gif_filename = QFileDialog::getSaveFileName(NULL, "Save to ...", "",
////                                                          "GIF image (*.gif)");
////      timer->stop();
////      gif->save(gif_filename);
////      delete gif;
////      delete timer;
////  }
////}
/////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////

//void MainWindow::CreateSnapshot() {
//  if (controller_->GetFacadeRef()->GetFigureDraw() == nullptr) {
//    return;
//  }
//  dto_ = new s21::ParamDTO(
//      ui->spinbox_move_x->value(), ui->spinbox_move_y->value(),
//      ui->spinbox_move_z->value(), ui->spinbox_rot_x->value(),
//      ui->spinbox_rot_y->value(), ui->spinbox_rot_z->value(),
//      ui->slider_scale->value());
//  controller_->CreateSnapshot(dto_);

//  objectInfoDTO_ = s21::ObjectInfoDTO(
//      ui->lineEdit_file_input->text().toStdString(),
//      ui->label_info_object_info_file_name_ans_2->text().toStdString(),
//      ui->label_info_object_info_vertex_count_ans_2->text().toStdString(),
//      ui->label_info_object_info_polygon_count_ans_2->text().toStdString());
//}

//void MainWindow::Restore() {
//  if (controller_->GetFacadeRef()->GetSnapshot() == nullptr) {
//    return;
//  }
//  controller_->Restore();

//  from_snapshot_ = true;
//  ui->openGLWidget->scale_ = controller_->GetMax() * 2;
//  ui->spinbox_move_x->setValue(dto_->move_x_);
//  ui->spinbox_move_y->setValue(dto_->move_y_);
//  ui->spinbox_move_z->setValue(dto_->move_z_);
//  ui->spinbox_rot_x->setValue(dto_->angle_x_);
//  ui->spinbox_rot_y->setValue(dto_->angle_y_);
//  ui->spinbox_rot_z->setValue(dto_->angle_z_);
//  ui->slider_scale->setValue(dto_->scale_);

//  ui->lineEdit_file_input->setText(
//      QString::fromStdString(objectInfoDTO_.object_info_file_path_));
//  ui->label_info_object_info_file_name_ans_2->setText(
//      QString::fromStdString(objectInfoDTO_.object_info_file_name_));
//  ui->label_info_object_info_vertex_count_ans_2->setText(
//      QString::fromStdString(objectInfoDTO_.object_info_vertex_count_));
//  ui->label_info_object_info_polygon_count_ans_2->setText(
//      QString::fromStdString(objectInfoDTO_.object_info_polygon_count_));

//  ui->openGLWidget->update();
//  from_snapshot_ = false;
//};

//void MainWindow::Reset() {
//  SliderReset();
//  controller_->Reset();
//  ui->openGLWidget->SetVertices(controller_->GetVertecisRef());
//  ui->openGLWidget->SetEdges(controller_->GetEdgesRef());
//  ui->openGLWidget->update();
//}

//void MainWindow::SliderReset() {
//  ui->slider_move_x->setValue(0);
//  ui->slider_move_y->setValue(0);
//  ui->slider_move_z->setValue(0);
//  ui->slider_rot_x->setValue(0);
//  ui->slider_rot_y->setValue(0);
//  ui->slider_rot_z->setValue(0);
//  ui->slider_scale->setValue(0);

//  ui->spinbox_move_x->setValue(0);
//  ui->spinbox_move_y->setValue(0);
//  ui->spinbox_move_z->setValue(0);
//  ui->spinbox_rot_x->setValue(0);
//  ui->spinbox_rot_y->setValue(0);
//  ui->spinbox_rot_z->setValue(0);
//}


#include "mainwindow.h"

#include "ui_mainwindow.h"
#include <iostream>

MainWindow::MainWindow(s21::Controller *controller, QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  controller_ = controller;
  file_dialog.setFileMode(QFileDialog::ExistingFile);
  file_dialog.setNameFilter(tr("Object Files (*.obj)"));
  QString std_path =
      QCoreApplication::applicationDirPath() + PATH_STD_OPEN_FINDER;
  file_dialog.setDirectory(std_path);
  //  user_settings_setup(&user_settings);
  ui->setupUi(this);
  readSettings();
  //  init_settings();
  Connects();
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::Connects() {
  connect(ui->pushButton_file_select, SIGNAL(clicked()), this,
          SLOT(ChooseFile()));

  connect(ui->comboBox_settings_view_projection_type,
          SIGNAL(currentIndexChanged(int)), this, SLOT(ComboboxChange()));
  connect(ui->comboBox_settings_view_polygon_type,
          SIGNAL(currentIndexChanged(int)), this, SLOT(ComboboxChange()));
  connect(ui->comboBox_settings_view_vertex_type,
          SIGNAL(currentIndexChanged(int)), this, SLOT(ComboboxChange()));

  connect(ui->spinbox_move_x, SIGNAL(valueChanged(int)), ui->slider_move_x,
          SLOT(setValue(int)));
  connect(ui->slider_move_x, SIGNAL(valueChanged(int)), ui->spinbox_move_x,
          SLOT(setValue(int)));
  connect(ui->spinbox_move_x, SIGNAL(valueChanged(int)), this,
          SLOT(SpinboxChange()));

  connect(ui->spinbox_move_y, SIGNAL(valueChanged(int)), ui->slider_move_y,
          SLOT(setValue(int)));
  connect(ui->slider_move_y, SIGNAL(valueChanged(int)), ui->spinbox_move_y,
          SLOT(setValue(int)));
  connect(ui->spinbox_move_y, SIGNAL(valueChanged(int)), this,
          SLOT(SpinboxChange()));

  connect(ui->spinbox_move_z, SIGNAL(valueChanged(int)), ui->slider_move_z,
          SLOT(setValue(int)));
  connect(ui->slider_move_z, SIGNAL(valueChanged(int)), ui->spinbox_move_z,
          SLOT(setValue(int)));
  connect(ui->spinbox_move_z, SIGNAL(valueChanged(int)), this,
          SLOT(SpinboxChange()));

  connect(ui->spinbox_rot_x, SIGNAL(valueChanged(int)), ui->slider_rot_x,
          SLOT(setValue(int)));
  connect(ui->slider_rot_x, SIGNAL(valueChanged(int)), ui->spinbox_rot_x,
          SLOT(setValue(int)));
  connect(ui->spinbox_rot_x, SIGNAL(valueChanged(int)), this,
          SLOT(SpinboxChange()));

  connect(ui->spinbox_rot_y, SIGNAL(valueChanged(int)), ui->slider_rot_y,
          SLOT(setValue(int)));
  connect(ui->slider_rot_y, SIGNAL(valueChanged(int)), ui->spinbox_rot_y,
          SLOT(setValue(int)));
  connect(ui->spinbox_rot_y, SIGNAL(valueChanged(int)), this,
          SLOT(SpinboxChange()));

  connect(ui->spinbox_rot_z, SIGNAL(valueChanged(int)), ui->slider_rot_z,
          SLOT(setValue(int)));
  connect(ui->slider_rot_z, SIGNAL(valueChanged(int)), ui->spinbox_rot_z,
          SLOT(setValue(int)));
  connect(ui->spinbox_rot_z, SIGNAL(valueChanged(int)), this,
          SLOT(SpinboxChange()));

  connect(ui->slider_scale, SIGNAL(valueChanged(int)), this,
          SLOT(ScaleSliderChange(int)));

  connect(ui->doubleSpinBox_settings_view_polygon_width,
          SIGNAL(valueChanged(double)), this, SLOT(DoubleSpinboxChange()));
  connect(ui->doubleSpinBox_settings_view_vertex_size,
          SIGNAL(valueChanged(double)), this, SLOT(DoubleSpinboxChange()));

  connect(ui->pushButton_CreateSnapshot, SIGNAL(clicked()), this,
          SLOT(CreateSnapshot()));
  connect(ui->pushButton_Restore, SIGNAL(clicked()), this, SLOT(Restore()));
  connect(ui->pushButton_Reset, SIGNAL(clicked()), this, SLOT(Reset()));
}

void MainWindow::ChooseFile() {
  if (file_dialog.exec()) {
    ui->openGLWidget->need_paint_ = false;
    QStringList fileNames = file_dialog.selectedFiles();
    QString filename = fileNames[0];
    SliderReset();
    ui->label_info->clear();
    std::string err_msg = controller_->TransferObject(filename.toStdString());
    if (err_msg == "OK") {
      ui->openGLWidget->scale_ = controller_->GetMax() * 2;

      ui->openGLWidget->SetVertices(controller_->GetVertecisRef());
      ui->openGLWidget->SetEdges(controller_->GetEdgesRef());
      ui->openGLWidget->update();
      ui->lineEdit_file_input->setText(filename);
      ui->label_info_object_info_vertex_count_ans_2->setText(
          QString::number(ui->openGLWidget->GetVerticesRef()->size()));
      ui->label_info_object_info_polygon_count_ans_2->setText(
          QString::number(ui->openGLWidget->GetEdgesRef()->size()));
      QFileInfo fi(filename);
      ui->label_info_object_info_file_name_ans_2->setText(fi.baseName());
      ui->openGLWidget->need_paint_ = true;
    } else
      ui->label_info->setText(QString::fromStdString(err_msg));
  }
}

void MainWindow::Redraw() {
  if (ui->openGLWidget->need_paint_) {
    controller_->TransferFigureParams();
    ui->openGLWidget->update();
  }
}

void MainWindow::ComboboxChange() {
  QComboBox *worked = (QComboBox *)sender();

  if (worked == ui->comboBox_settings_view_projection_type) {
    ui->openGLWidget->view_type_ = worked->currentIndex();
  } else if (worked == ui->comboBox_settings_view_vertex_type) {
    ui->openGLWidget->vertex_type_ = worked->currentIndex();
  } else if (worked == ui->comboBox_settings_view_polygon_type) {
    ui->openGLWidget->line_type_ = worked->currentIndex();
  }
  ui->openGLWidget->update();
}

void MainWindow::SpinboxChange() {
  if (from_snapshot_) {
    return;
  }
  QSpinBox *worked = (QSpinBox *)sender();
  if (worked == ui->spinbox_move_x)
    controller_->GetAffineTransformationsRef()->SetMoveX(
        worked->value() * ui->openGLWidget->axis_scale_ / 100);
  else if (worked == ui->spinbox_move_y)
    controller_->GetAffineTransformationsRef()->SetMoveY(
        worked->value() * ui->openGLWidget->axis_scale_ / 100);
  else if (worked == ui->spinbox_move_z)
    controller_->GetAffineTransformationsRef()->SetMoveZ(
        worked->value() * ui->openGLWidget->axis_scale_ / 100);
  else if (worked == ui->spinbox_rot_x)
    controller_->GetAffineTransformationsRef()->SetAngleX(worked->value());
  else if (worked == ui->spinbox_rot_y)
    controller_->GetAffineTransformationsRef()->SetAngleY(worked->value());
  else if (worked == ui->spinbox_rot_z)
    controller_->GetAffineTransformationsRef()->SetAngleZ(worked->value());
  Redraw();
}

void MainWindow::ScaleSliderChange(int value) {
  ui->scale_lable->setText(
      QString::number(pow(3, value / 100.0) * 100, 'f', 2));
  if (from_snapshot_) {
    return;
  }
  controller_->GetAffineTransformationsRef()->SetScale(value);
  //  ui->scale_lable->setText(
  //      QString::number(pow(3, value / 100.0) * 100, 'f', 2));
  Redraw();
}

void MainWindow::DoubleSpinboxChange() {
  QDoubleSpinBox *worked = (QDoubleSpinBox *)sender();
  if (worked == ui->doubleSpinBox_settings_view_polygon_width)
    ui->openGLWidget->line_size_ = worked->value();
  else if (worked == ui->doubleSpinBox_settings_view_vertex_size)
    ui->openGLWidget->vertex_size_ = worked->value();
  ui->openGLWidget->update();
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
  if (!gif_recording) {
    ui->pushButton_screen_gif_start->setText("Остановить запись");

    gif = new QGifImage;
    timer = new QTimer(this);
    timer_2 = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(recording_gif()));
    connect(timer_2, SIGNAL(timeout()), ui->openGLWidget, SLOT(repaint()));
    timer->start(100);
    timer_2->start(1);
    QTimer::singleShot(5000, this, SLOT(recording_stop()));
    gif_recording = 1;
  } else {
    recording_stop();
  }
}

void MainWindow::recording_gif() {
  QImage frameImage = ui->openGLWidget->grabFramebuffer();
  gif->addFrame(frameImage, 100);
}

void MainWindow::recording_stop() {
  if (gif_recording) {
    gif_recording = 0;
    ui->pushButton_screen_gif_start->setText("GIF");
    timer->stop();
    timer_2->stop();
    delete timer;
    delete timer_2;

    QString name = QDate::currentDate().toString("yyMMdd") + "_" +
                   QTime::currentTime().toString("hhmmss") + ".gif";
    //  QString gifFileName =
    //      QApplication::applicationDirPath() + "/../../../" + name;
    QString gif_filename = QFileDialog::getSaveFileName(NULL, "Save to ...", "",
                                                        "GIF image (*.gif)");
    //  QString gif_filename = "/Users/errokele/projects/gifka.gif";
    gif->save(gif_filename);
    delete gif;
    repaint();
  }
}

void MainWindow::CreateSnapshot() {
  if (controller_->GetFacadeRef()->GetFigureDraw() == nullptr) {
    return;
  }
  dto_ = new s21::ParamDTO(
      ui->spinbox_move_x->value(), ui->spinbox_move_y->value(),
      ui->spinbox_move_z->value(), ui->spinbox_rot_x->value(),
      ui->spinbox_rot_y->value(), ui->spinbox_rot_z->value(),
      ui->slider_scale->value());
  controller_->CreateSnapshot(dto_);

  objectInfoDTO_ = s21::ObjectInfoDTO(
      ui->lineEdit_file_input->text().toStdString(),
      ui->label_info_object_info_file_name_ans_2->text().toStdString(),
      ui->label_info_object_info_vertex_count_ans_2->text().toStdString(),
      ui->label_info_object_info_polygon_count_ans_2->text().toStdString());
}

void MainWindow::Restore() {
  if (controller_->GetFacadeRef()->GetSnapshot() == nullptr) {
    return;
  }
  controller_->Restore();

  from_snapshot_ = true;
  ui->openGLWidget->scale_ = controller_->GetMax() * 2;
  ui->spinbox_move_x->setValue(dto_->move_x_);
  ui->spinbox_move_y->setValue(dto_->move_y_);
  ui->spinbox_move_z->setValue(dto_->move_z_);
  ui->spinbox_rot_x->setValue(dto_->angle_x_);
  ui->spinbox_rot_y->setValue(dto_->angle_y_);
  ui->spinbox_rot_z->setValue(dto_->angle_z_);
  ui->slider_scale->setValue(dto_->scale_);

  ui->lineEdit_file_input->setText(
      QString::fromStdString(objectInfoDTO_.object_info_file_path_));
  ui->label_info_object_info_file_name_ans_2->setText(
      QString::fromStdString(objectInfoDTO_.object_info_file_name_));
  ui->label_info_object_info_vertex_count_ans_2->setText(
      QString::fromStdString(objectInfoDTO_.object_info_vertex_count_));
  ui->label_info_object_info_polygon_count_ans_2->setText(
      QString::fromStdString(objectInfoDTO_.object_info_polygon_count_));

  ui->openGLWidget->update();
  from_snapshot_ = false;
};

void MainWindow::Reset() {
  SliderReset();
  controller_->Reset();
  ui->openGLWidget->SetVertices(controller_->GetVertecisRef());
  ui->openGLWidget->SetEdges(controller_->GetEdgesRef());
  ui->openGLWidget->update();
}

void MainWindow::SliderReset() {
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
}

void MainWindow::on_pushButton_settings_view_other_color_clicked()
{
    QColor color = QColorDialog::getColor(QColor("white"), this);
    if (color.isValid()) {
      changeBackground(color);
    }
}

void MainWindow::changeBackground(QColor color){
    ui->openGLWidget->background_color_b_ = color.blue();
    ui->openGLWidget->background_color_r_ = color.red();
    ui->openGLWidget->background_color_g_ = color.green();
}

void MainWindow::on_pushButton_settings_view_polygon_color_clicked()
{
    QColor color = QColorDialog::getColor(QColor("white"), this);
    if (color.isValid()) {
      changeEdges(color);
    }
}

void MainWindow::changeEdges(QColor color){
    ui->openGLWidget->line_color_b_ = color.blue();
    ui->openGLWidget->line_color_r_ = color.red();
    ui->openGLWidget->line_color_g_ = color.green();
}

void MainWindow::on_pushButton_settings_view_vertex_color_clicked()
{
    QColor color = QColorDialog::getColor(QColor("white"), this);
    if (color.isValid()) {
      changeVertex(color);
    }
}

void MainWindow::changeVertex(QColor color){
    ui->openGLWidget->vertex_color_b_ = color.blue();
    ui->openGLWidget->vertex_color_r_ = color.red();
    ui->openGLWidget->vertex_color_g_ = color.green();
}

void MainWindow::closeEvent(QCloseEvent *event) {
    writeSettings();
    event->accept();
}

void MainWindow::writeSettings() {
  QSettings settings("Cabbage.conf", "AAA");
//  QSettings settings("/Users/vanesabo/Cabbage.conf", "AAA");
//  std::cerr << QDir::homePath().toStdString() << std::endl;
  int indexTypeProjection = ui->comboBox_settings_view_projection_type->currentIndex();
  int indexEdges = ui->comboBox_settings_view_polygon_type->currentIndex();
  int indexVertex = ui->comboBox_settings_view_vertex_type->currentIndex();


  double sizeVertex = ui->doubleSpinBox_settings_view_vertex_size->value();
  double sizeEdges = ui->doubleSpinBox_settings_view_polygon_width->value();

  settings.beginGroup("MainWindow_UI");
  settings.setValue("alredySave", true);
  settings.setValue("vertexSettenings/indexVertex", indexVertex);
  settings.setValue("edgesSettenings/indexEdges", indexEdges);
  settings.setValue("vertexSettenings/sizeVertex", sizeVertex);
  settings.setValue("edgesSettenings/sizeEdges", sizeEdges);
  settings.setValue("projection/indexTypeProjection", indexTypeProjection);

  settings.setValue("vertexRgb/r", ui->openGLWidget->vertex_color_r_);
  settings.setValue("vertexRgb/g", ui->openGLWidget->vertex_color_g_);
  settings.setValue("vertexRgb/b", ui->openGLWidget->vertex_color_b_);

  settings.setValue("edgesRgb/r", ui->openGLWidget->line_color_r_);
  settings.setValue("edgesRgb/g", ui->openGLWidget->line_color_g_);
  settings.setValue("edgesRgb/b", ui->openGLWidget->line_color_b_);

  settings.setValue("backRgb/r", ui->openGLWidget->background_color_r_);
  settings.setValue("backRgb/g", ui->openGLWidget->background_color_g_);
  settings.setValue("backRgb/b", ui->openGLWidget->background_color_b_);

  settings.endGroup();
}

void MainWindow::readSettings() {
  QSettings settings("Cabbage.conf", "AAA");
//  QSettings settings("/Users/vanesabo/Cabbage.conf", "AAA");
  settings.beginGroup("MainWindow_UI");
  if (settings.contains("alredySave")) {
      ui->comboBox_settings_view_projection_type->setCurrentIndex(settings.value("projection/indexTypeProjection").toInt());
      ui->openGLWidget->view_type_ = settings.value("projection/indexTypeProjection").toInt();
      ui->comboBox_settings_view_polygon_type->setCurrentIndex(settings.value("edgesSettenings/indexEdges").toInt());
      ui->openGLWidget->line_type_ = settings.value("edgesSettenings/indexEdges").toInt();
      ui->comboBox_settings_view_vertex_type->setCurrentIndex(settings.value("vertexSettenings/indexVertex").toInt());
      ui->openGLWidget->vertex_type_ = settings.value("vertexSettenings/indexVertex").toInt();
      ui->doubleSpinBox_settings_view_polygon_width->setValue(settings.value("edgesSettenings/sizeEdges").toDouble());
      ui->openGLWidget->line_size_ = settings.value("edgesSettenings/sizeEdges").toDouble();
      ui->doubleSpinBox_settings_view_vertex_size->setValue(settings.value("vertexSettenings/sizeVertex").toDouble());
      ui->openGLWidget->vertex_size_ = settings.value("vertexSettenings/sizeVertex").toDouble();

      QColor color1(settings.value("backRgb/r").toInt(),settings.value("backRgb/g").toInt(),settings.value("backRgb/b").toInt());
      changeBackground(color1);
      QColor color2(settings.value("vertexRgb/r").toInt(),settings.value("vertexRgb/g").toInt(),settings.value("vertexRgb/b").toInt());
      changeVertex(color2);
      QColor color3(settings.value("edgesRgb/r").toInt(),settings.value("edgesRgb/g").toInt(),settings.value("edgesRgb/b").toInt());
      changeEdges(color3);
  }
  settings.endGroup();
}
