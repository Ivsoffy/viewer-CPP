#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(s21::Controller *controller, QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  controller_ = controller;
//  controller_->paramDTO_ = new s21::ParamDTO(0, 0, 0, 0, 0, 0, 1);
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

    connect(this->ui->slider_scale, SIGNAL(valueChanged(int)), this,
            SLOT(valueChanged_to_Slider_scale(int)));

//  connect(ui->lineEdit_file_input, SIGNAL(returnPressed()), this,
//          SLOT(open_file()));
  connect(ui->comboBox_settings_view_projection_type,
          SIGNAL(currentIndexChanged(int)), this, SLOT(combo_box_change()));
  connect(ui->comboBox_settings_view_polygon_type,
          SIGNAL(currentIndexChanged(int)), this,
          SLOT(combo_box_change()));
  connect(ui->comboBox_settings_view_vertex_type,
          SIGNAL(currentIndexChanged(int)), this,
          SLOT(combo_box_change()));

  connect(ui->pushButton_file_select, SIGNAL(clicked()), this,
          SLOT(choose_file()));

  connect(ui->pushButton_screen_start, SIGNAL(clicked()), this,
          SLOT(take_screenshot()));
  connect(ui->pushButton_screen_gif_start, SIGNAL(clicked()), this,
          SLOT(record_gif()));

  ////////////////////////////////////////
  ////////////////////////////////////////
  ////////////////////////////////////////
  connect(ui->pushButton_CreateSnapshot, SIGNAL(clicked()), this, SLOT(CreateSnapshot()));
  connect(ui->pushButton_Restore, SIGNAL(clicked()), this, SLOT(Restore()));
}


void MainWindow::choose_file() {
  ui->openGLWidget->need_paint = false;
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
    ui->openGLWidget->scale = controller_->GetMax() * 2;

    ui->openGLWidget->SetVertices(controller_->GetVertecisRef());
    ui->openGLWidget->SetEdges(controller_->GetEdgesRef());
    ui->openGLWidget->update();
    ui->openGLWidget->need_paint = true;
    ui->lineEdit_file_input->setText(filename);
  }
}

void MainWindow::redraw() {
  if (ui->openGLWidget->need_paint) {
      controller_->TransferFigureParams();
      ui->openGLWidget->update();
  }
}

void MainWindow::valueChanged_to_Slider_move_x(int value) {
  ui->spinbox_move_x->setValue(value);
}

void MainWindow::valueChanged_to_Spinbox_move_x(int value) {
  ui->slider_move_x->setValue(value);
  controller_->GetAffineTransformationsRef()->SetMoveX(ui->openGLWidget->scale * value / 100);
  redraw();
}

void MainWindow::valueChanged_to_Slider_move_y(int value) {
  ui->spinbox_move_y->setValue(value);
}

void MainWindow::valueChanged_to_Spinbox_move_y(int value) {
  ui->slider_move_y->setValue(value);
  controller_->GetAffineTransformationsRef()->SetMoveY(ui->openGLWidget->scale * value / 100);
  redraw();
}

void MainWindow::valueChanged_to_Slider_move_z(int value) {
  ui->spinbox_move_z->setValue(value);
}

void MainWindow::valueChanged_to_Spinbox_move_z(int value) {
  ui->slider_move_z->setValue(value);
  controller_->GetAffineTransformationsRef()->SetMoveZ(ui->openGLWidget->scale * value / 100);
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
    controller_->GetAffineTransformationsRef()->SetScale(value);
    ui->scale_lable->setText(QString::number(pow(3, value / 100.0) * 100, 'f', 2));
    redraw();
}

void MainWindow::take_screenshot() {
  //
}

void MainWindow::record_gif() {
  //
}

void MainWindow::combo_box_change() {
  QComboBox *worked = (QComboBox *)sender();

  if (worked == ui->comboBox_settings_view_projection_type) {
    ui->openGLWidget->view_type = worked->currentIndex();
  } else if (worked == ui->comboBox_settings_view_vertex_type) {
    ui->openGLWidget->vertex_type = worked->currentIndex();
  } else if (worked == ui->comboBox_settings_view_polygon_type) {
    ui->openGLWidget->line_type = worked->currentIndex();
  }
  ui->openGLWidget->repaint();
}

void MainWindow::on_doubleSpinBox_settings_view_polygon_width_valueChanged(
    double arg1) {
  ui->openGLWidget->line_size = arg1;
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

void MainWindow::CreateSnapshot() {
    dto_ = new s21::ParamDTO(ui->spinbox_move_x->value(),
                              ui->spinbox_move_y->value(),
                              ui->spinbox_move_z->value(),
                              ui->spinbox_rot_x->value(),
                              ui->spinbox_rot_y->value(),
                              ui->spinbox_rot_z->value(),
                              ui->slider_scale->value());
    controller_->CreateSnapshot(dto_);
    // controller_->CreateSnapshot(ui->spinbox_move_x->value(),
    //                             ui->spinbox_move_y->value(),
    //                             ui->spinbox_move_z->value(),
    //                             ui->spinbox_rot_x->value(),
    //                             ui->spinbox_rot_y->value(),
    //                             ui->spinbox_rot_z->value(),
    //                             ui->slider_scale->value());
}

void MainWindow::Restore() {
    controller_->Restore(dto_);
    ui->spinbox_move_x->setValue(dto_->move_x_);
    ui->spinbox_move_y->setValue(dto_->move_y_);
    ui->spinbox_move_z->setValue(dto_->move_z_);
    ui->spinbox_rot_x->setValue(dto_->angle_x_);
    ui->spinbox_rot_y->setValue(dto_->angle_y_);
    ui->spinbox_rot_z->setValue(dto_->angle_z_);
    ui->slider_scale->setValue(dto_->scale_);
    ui->openGLWidget->update(); 
    };
