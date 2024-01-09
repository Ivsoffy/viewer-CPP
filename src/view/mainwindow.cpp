#include "mainwindow.h"

#include "ui_mainwindow.h"

#include <ctime>/////////////////////////////TODO
#include <chrono>/////////////////////TODO
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
  connect(this->ui->slide_rot_x, SIGNAL(valueChanged(int)), this,
          SLOT(valueChanged_to_Rot_X(int)));

//  connect(ui->pushButton_file_open, SIGNAL(clicked()), this, SLOT(open_file()));
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
    rebuff();
    // ui->openGLWidget->update();//////
    // ui->openGLWidget->need_paint = true;////

    ui->lineEdit_file_input->setText(filename);

  }

}

void MainWindow::rebuff() {

//  s21::GLBufferDTO GLBuffDTO = controller_->TransferGLBuffer();//

//  ui->openGLWidget->SetVertices(GLBuffDTO.vertices_);
//  ui->openGLWidget->SetEdges(GLBuffDTO.edges_);


  ui->openGLWidget->SetVertices(controller_->GetVertecisRef());
  ui->openGLWidget->SetEdges(controller_->GetEdgesRef());

  // std::cerr << "((((((((((((((((((((repaint))))))))))))))))))))" << std::endl;/////////////////////TODO
  // auto millisec_start = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();/////////////////////TODO

  // ui->openGLWidget->repaint();
  ui->openGLWidget->update();
  ui->openGLWidget->need_paint = true;//

  // auto millisec_end = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();/////////////////////TODO
  // std::cerr << millisec_end - millisec_start << ")))))))))repaint(((((((((" << std::endl;/////////////////////TODO
}

void MainWindow::redraw() {
  controller_->TransferFigureParams();
  rebuff();
}

////////////////////////////////////////////
////////////////////////////////////////////
void MainWindow::on_spinBox_settings_move_rotate_x_valueChanged(
    int arg) {
  ui->horizontalSlider_settings_move_rotate_x->setValue(arg);
  changeXangle(arg);
}

void MainWindow::on_horizontalSlider_settings_move_rotate_x_sliderMoved(
    int position) {
  ui->spinBox_settings_move_rotate_x->setValue(position);
  changeXangle(position);
}

void MainWindow::changeXangle(int arg){
      controller_->paramDTO_->angle_x_ = (double) arg;
  redraw();
}

//////////////////////////////////////////////////
void MainWindow::valueChanged_to_Rot_X(int value) {
  controller_->GetAffineTransformationsRef()->SetAngleX(value);

//  controller_->GetAffineTransformationsRef()->SetMoveX(0);
//  controller_->GetAffineTransformationsRef()->SetMoveY(0);
//  controller_->GetAffineTransformationsRef()->SetMoveZ(0);
//  controller_->GetAffineTransformationsRef()->SetAngleY(0);
//  controller_->GetAffineTransformationsRef()->SetAngleZ(0);
//  controller_->GetAffineTransformationsRef()->SetScale(1);

  auto millisec_start = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();/////////////////////TODO

  controller_->TransferFigureParams();//150

  auto millisec_end = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();/////////////////////TODO
  std::cerr << millisec_end - millisec_start << ")))TransferFigureParams(((" << "\n" << std::endl;/////////////////////TODO

  // rebuff();
  ui->openGLWidget->update();

}
////////////////////////////////////////////
////////////////////////////////////////////


void MainWindow::take_screenshot() {
  //
}

void MainWindow::record_gif() {
  //
}

void MainWindow::on_doubleSpinBox_settings_move_move_x_valueChanged(
    double arg) {
//  ui->openGLWidget->shift_x = arg;// --
  ui->horizontalSlider_settings_move_move_x->setValue(arg);
  changeXcoord(arg);///////////////////
}

void MainWindow::on_horizontalSlider_settings_move_move_x_sliderMoved(
    int position) {
//  ui->openGLWidget->shift_x = (double)position;// --
  ui->doubleSpinBox_settings_move_move_x->setValue((double)position);
  changeXcoord((double)position);
}

void MainWindow::changeXcoord(double arg){
//  controller_->paramDTO_->move_x_ = ui->openGLWidget->shift_x;// --
  controller_->paramDTO_->move_x_ = arg;// --
  redraw();/////////////////////
}

void MainWindow::on_doubleSpinBox_settings_move_move_y_valueChanged(
    double arg) {
//  ui->openGLWidget->shift_y = ar1;// --
  ui->horizontalSlider_settings_move_move_y->setValue(arg);
  changeYcoord(arg);
}

void MainWindow::on_horizontalSlider_settings_move_move_y_sliderMoved(
    int position) {
//  ui->openGLWidget->shift_y = position;// --
  ui->doubleSpinBox_settings_move_move_y->setValue((double)position);
changeYcoord((double)position);
}

void MainWindow::changeYcoord(double arg){
//  controller_->paramDTO_->move_y_ = ui->openGLWidget->shift_y;// --
  controller_->paramDTO_->move_y_ = arg;// --
  redraw();
}

void MainWindow::on_doubleSpinBox_settings_move_move_z_valueChanged(
    double arg) {
//  ui->openGLWidget->shift_z = ar1;// --
  ui->horizontalSlider_settings_move_move_z->setValue(arg);
  changeZcoord(arg);
}

void MainWindow::on_horizontalSlider_settings_move_move_z_sliderMoved(
    int position) {
//  ui->openGLWidget->shift_z = position;// --
    ui->doubleSpinBox_settings_move_move_z->setValue((double)position);
    changeZcoord((double)position);
}

void MainWindow::changeZcoord(double arg){
//  controller_->paramDTO_->move_z_ = ui->openGLWidget->shift_z;// --
  controller_->paramDTO_->move_z_ = arg;// --
  redraw();
}

//void MainWindow::on_doubleSpinBox_settings_move_rotate_x_valueChanged(
//    double arg) {
////  ui->openGLWidget->rot_x = arg;// --
//  ui->horizontalSlider_settings_move_rotate_x->setValue(arg);
//  changeXangle(arg);
//}

//void MainWindow::on_horizontalSlider_settings_move_rotate_x_sliderMoved(
//    int position) {
////  ui->openGLWidget->rot_x = position;// --
//  ui->doubleSpinBox_settings_move_rotate_x->setValue((double)position);
//  changeXangle((double)position);
//}

//void MainWindow::changeXangle(double arg){
////  controller_->paramDTO_->angle_x_ = ui->openGLWidget->rot_x;// --
//      controller_->paramDTO_->angle_x_ = arg;
//  redraw();

//}

void MainWindow::on_doubleSpinBox_settings_move_rotate_y_valueChanged(
    double arg) {
  ui->horizontalSlider_settings_move_rotate_y->setValue(arg);
  changeYangle(arg);
}

void MainWindow::on_horizontalSlider_settings_move_rotate_y_sliderMoved(
    int position) {
  ui->doubleSpinBox_settings_move_rotate_y->setValue((double)position);
  changeYangle((double)position);
}

void MainWindow::changeYangle(double arg){
  controller_->paramDTO_->angle_y_ = arg;
  redraw();
}
void MainWindow::on_doubleSpinBox_settings_move_rotate_z_valueChanged(
    double arg) {
//  ui->openGLWidget->rot_z = arg;// --
  ui->horizontalSlider_settings_move_rotate_z->setValue(arg);
  changeZangle(arg);
}

void MainWindow::on_horizontalSlider_settings_move_rotate_z_sliderMoved(
    int position) {
//  ui->openGLWidget->rot_z = position;// --
  ui->doubleSpinBox_settings_move_rotate_z->setValue((double)position);
  changeZangle((double)position);
}

void MainWindow::changeZangle(double arg){
//  controller_->paramDTO_->angle_z_ = ui->openGLWidget->rot_z;// --
  controller_->paramDTO_->angle_z_ = arg;
  redraw();

}

void MainWindow::on_doubleSpinBox_settings_move_scale_valueChanged(
    double arg1) {
//  ui->openGLWidget->scale = arg1;// --
  controller_->paramDTO_->scale_ = arg1;
  ui->horizontalSlider_settings_move_scale->setValue(arg1);
  changeScale();
}

void MainWindow::on_horizontalSlider_settings_move_scale_sliderMoved(
    int position) {
//  ui->openGLWidget->scale = position;// --
  ui->doubleSpinBox_settings_move_scale->setValue(position);
  changeScale();
}

void MainWindow::changeScale(){
//  controller_->paramDTO_->scale_ = ui->openGLWidget->scale;// --
  redraw();

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

//void MainWindow::on_comboBox_settings_view_projection_type_currentIndexChanged(
//    int index) {
//  ui->openGLWidget->view_type = index;
//  ui->openGLWidget->repaint();
//  projection_settings();
//}

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
