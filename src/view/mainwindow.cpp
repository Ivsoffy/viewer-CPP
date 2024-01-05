#include "mainwindow.h"

#include "ui_mainwindow.h"

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

// void MainWindow::init_settings() {
//   QString finder_path =
//       QCoreApplication::applicationDirPath() + ICON_FINDER_PATH;
//   QPixmap pixmap(finder_path);
//   QIcon ButtonIcon(pixmap);
//   ui->pushButton_file_select->setIcon(ButtonIcon);
//   ui->pushButton_file_select->setIconSize(QSize(50, 50));

//  QString style_sheet;
//  style_sheet = take_style_sheet_color_button(user_settings.background_color);
//  ui->pushButton_settings_view_other_color->setStyleSheet(style_sheet);
//  style_sheet = take_style_sheet_color_button(user_settings.polygon_color);
//  ui->pushButton_settings_view_polygon_color->setStyleSheet(style_sheet);
//  style_sheet = take_style_sheet_color_button(user_settings.vertex_color);
//  ui->pushButton_settings_view_vertex_color->setStyleSheet(style_sheet);

//  ui->comboBox_settings_view_polygon_type->setCurrentIndex(
//      (int)user_settings.polygon_type);
//  ui->comboBox_settings_view_vertex_type->setCurrentIndex(
//      (int)user_settings.vertex_type);
//  ui->comboBox_settings_view_projection_type->setCurrentIndex(
//      (int)user_settings.projection_type);

//  ui->doubleSpinBox_settings_view_polygon_width->setValue(
//      user_settings.polygon_width);
//  ui->doubleSpinBox_settings_view_vertex_size->setValue(
//      user_settings.vertex_size);
//}

// QString MainWindow::take_style_sheet_color_button(struct rgb_color color) {
//   char str[BUFF_SIZE] =
//       "border: 5px  solid rgb(150, 150, 150) ; background-color: ";
//   char str_2[BUFF_SIZE];
//   snprintf(str_2, BUFF_SIZE, "rgb(%" PRIu8 ", %" PRIu8 ", %" PRIu8 ");",
//            color.red, color.green, color.blue);
//   strcat(str, str_2);

//  QString style_sheet = str;

//  return style_sheet;
//}

void MainWindow::connects() {
//  connect(ui->pushButton_file_open, SIGNAL(clicked()), this, SLOT(open_file()));
//  connect(ui->lineEdit_file_input, SIGNAL(returnPressed()), this,
//          SLOT(open_file()));
  connect(ui->pushButton_file_select, SIGNAL(clicked()), this,
          SLOT(choose_file()));

  connect(ui->pushButton_screen_start, SIGNAL(clicked()), this,
          SLOT(take_screenshot()));
  connect(ui->pushButton_screen_gif_start, SIGNAL(clicked()), this,
          SLOT(record_gif()));

//  connect(ui->comboBox_settings_view_projection_type,
//          SIGNAL(currentIndexChanged(int)), this,
//          SLOT(user_settings_combo_box_change()));
//  connect(ui->comboBox_settings_view_vertex_type,
//          SIGNAL(currentIndexChanged(int)), this,
//          SLOT(user_settings_combo_box_change()));
//  connect(ui->comboBox_settings_view_polygon_type,
//          SIGNAL(currentIndexChanged(int)), this,
//          SLOT(user_settings_combo_box_change()));

//  connect(ui->doubleSpinBox_settings_view_polygon_width,
//          SIGNAL(valueChanged(double)), this,
//          SLOT(user_settings_double_spin_box_change()));
//  connect(ui->doubleSpinBox_settings_view_vertex_size,
//          SIGNAL(valueChanged(double)), this,
//          SLOT(user_settings_double_spin_box_change()));

//  connect(ui->pushButton_settings_view_other_color, SIGNAL(clicked()), this,
//          SLOT(user_settings_color_change()));
//  connect(ui->pushButton_settings_view_polygon_color, SIGNAL(clicked()), this,
//          SLOT(user_settings_color_change()));
//  connect(ui->pushButton_settings_view_vertex_color, SIGNAL(clicked()), this,
//          SLOT(user_settings_color_change()));
}

// void MainWindow::user_settings_combo_box_change() {
//   QComboBox *worked = (QComboBox *)sender();
//   int index = worked->currentIndex();

//  if (worked == ui->comboBox_settings_view_polygon_type) {
//    user_settings.polygon_type = (enum polygon_types)index;
//  } else if (worked == ui->comboBox_settings_view_vertex_type) {
//    user_settings.vertex_type = (enum vertex_types)index;
//  } else {
//    user_settings.projection_type = (enum projection_types)index;
//  }
//}

// void MainWindow::user_settings_double_spin_box_change() {
//   QDoubleSpinBox *worked = (QDoubleSpinBox *)sender();

//  double value = worked->value();

//  if (worked == ui->doubleSpinBox_settings_view_polygon_width) {
//    user_settings.polygon_width = value;
//  } else {
//    user_settings.vertex_size = value;
//  }
//}

// void MainWindow::user_settings_color_change() {
//   QPushButton *worked = (QPushButton *)sender();

//  QColorDialog color_dialog(this);
//  color_dialog.setOptions(QColorDialog::DontUseNativeDialog);

//  if (color_dialog.exec()) {
//    QColor q_color = color_dialog.selectedColor();
//    struct rgb_color color;
//    color.red = q_color.red();
//    color.green = q_color.green();
//    color.blue = q_color.blue();

//    QString style_sheet;
//    if (worked == ui->pushButton_settings_view_vertex_color) {
//      user_settings.vertex_color = color;
//      style_sheet = take_style_sheet_color_button(user_settings.vertex_color);
//      ui->pushButton_settings_view_vertex_color->setStyleSheet(style_sheet);
//      ui->openGLWidget->vertex_color_r = color.red;
//      ui->openGLWidget->vertex_color_g = color.green;
//      ui->openGLWidget->vertex_color_b = color.blue;

//    } else if (worked == ui->pushButton_settings_view_polygon_color) {
//      user_settings.polygon_color = color;
//      style_sheet =
//      take_style_sheet_color_button(user_settings.polygon_color);
//      ui->pushButton_settings_view_polygon_color->setStyleSheet(style_sheet);
//      ui->openGLWidget->line_color_r = color.red;
//      ui->openGLWidget->line_color_g = color.green;
//      ui->openGLWidget->line_color_b = color.blue;

//    } else {
//      user_settings.background_color = color;
//      style_sheet =
//          take_style_sheet_color_button(user_settings.background_color);
//      ui->pushButton_settings_view_other_color->setStyleSheet(style_sheet);
//      ui->openGLWidget->background_color_r = color.red;
//      ui->openGLWidget->background_color_g = color.green;
//      ui->openGLWidget->background_color_b = color.blue;
//    }
//    ui->openGLWidget->repaint();
//  }
//}

void MainWindow::choose_file() {
  ui->openGLWidget->need_paint = false;
  if (file_dialog.exec()) {
    QStringList fileNames = file_dialog.selectedFiles();
    QString filename = fileNames[0];
    controller_->TransferObject(filename.toStdString());
//    std::cerr << filename.toStdString() << std::endl;
    rebuff();
    ui->lineEdit_file_input->setText(filename);
  }

}

void MainWindow::rebuff() {

  s21::GLBufferDTO GLBuffDTO = controller_->TransferGLBuffer();
  ui->openGLWidget->SetVertexBuffer(GLBuffDTO.vertex_buffer_);
  ui->openGLWidget->SetIndexBuffer(GLBuffDTO.index_buffer_);
  ui->openGLWidget->SetIndicesSize(GLBuffDTO.indices_size_);
  ui->openGLWidget->SetVerticesSize(GLBuffDTO.vertices_size_);
  ui->openGLWidget->need_paint = true;
  ui->openGLWidget->repaint();
}

void MainWindow::redraw() {
  controller_->TransferFigureParams();/////////////////////
  rebuff();/////////////////////
}

// void MainWindow::open_file() {
//   controller.TransferObject()

//      if (error) {
//    //    struct error_mes_str er_mes[3] = {ERROR_MES};
//    //    ui->label_info->setText(er_mes[error - 1].error);
//  }
//  else {
//    ui->openGLWidget->need_paint = true;
//    if (ui->openGLWidget->vertex_array) {
//      opengl_array_destroy(ui->openGLWidget->polygons_array,
//                           ui->openGLWidget->edges_counter);
//      ui->openGLWidget->vertex_array = NULL;
//      ui->openGLWidget->polygons_array = NULL;
//      ui->openGLWidget->edges_counter = NULL;
//      ui->openGLWidget->total_edges = 0;
//    }

//    ui->openGLWidget->vertex_array =
//        (struct vertex *)calloc(sizeof(struct vertex *), data.vertex_count);

//    object_data_for_opengl(
//        data, ui->openGLWidget->vertex_array,
//        &ui->openGLWidget->polygons_array, &ui->openGLWidget->edges_counter,
//        &ui->openGLWidget->total_edges);

//    fprintf(stderr, "\n");
//    fprintf(stderr, "\n");
//    for (int i = 0; i < data.vertex_count; i++) {
//      fprintf(stderr, "%lf ", ui->openGLWidget->vertex_array[i].x);
//      fprintf(stderr, "%lf ", ui->openGLWidget->vertex_array[i].y);
//      fprintf(stderr, "%lf ", ui->openGLWidget->vertex_array[i].z);
//      fprintf(stderr, "\n");
//    }

//    ui->openGLWidget->polygon_count = data.polygon_count;
//    ui->openGLWidget->vertex_count = data.vertex_count;

//    max_coord = fabs(data.x_max);
//    if (fabs(data.x_min) > max_coord) max_coord = fabs(data.x_min);
//    if (fabs(data.y_max) > max_coord) max_coord = fabs(data.y_max);
//    if (fabs(data.y_min) > max_coord) max_coord = fabs(data.y_min);
//    if (fabs(data.z_max) > max_coord) max_coord = fabs(data.z_max);
//    if (fabs(data.z_min) > max_coord) max_coord = fabs(data.z_min);

//    projection_settings();

//    ui->doubleSpinBox_settings_move_move_x->setValue(0);
//    ui->horizontalSlider_settings_move_move_x->setValue(0);
//    ui->doubleSpinBox_settings_move_move_x->setMaximum(max_coord * 2);
//    ui->doubleSpinBox_settings_move_move_x->setMinimum(-max_coord * 2);
//    ui->horizontalSlider_settings_move_move_x->setMaximum(max_coord * 2);
//    ui->horizontalSlider_settings_move_move_x->setMinimum(-max_coord * 2);

//    ui->doubleSpinBox_settings_move_move_y->setValue(0);
//    ui->horizontalSlider_settings_move_move_y->setValue(0);
//    ui->doubleSpinBox_settings_move_move_y->setMaximum(max_coord * 2);
//    ui->doubleSpinBox_settings_move_move_y->setMinimum(-max_coord * 2);
//    ui->horizontalSlider_settings_move_move_y->setMaximum(max_coord * 2);
//    ui->horizontalSlider_settings_move_move_y->setMinimum(-max_coord * 2);
//    ui->openGLWidget->vertex_type =
//        ui->comboBox_settings_view_vertex_type->currentIndex();

//    ui->label_info_object_info_file_name_ans_2->setText(
//        ui->lineEdit_file_input->text().toLocal8Bit().data());

//    char vertex_tmp[10];
//    sprintf(vertex_tmp, "%d", data.vertex_count);
//    ui->label_info_object_info_vertex_count_ans_2->setText(vertex_tmp);

//    char edge_tmp[10];
//    sprintf(edge_tmp, "%d", (int)(ui->openGLWidget->total_edges / 4));
//    ui->label_info_object_info_polygon_count_ans_2->setText(edge_tmp);
//    ui->openGLWidget->repaint();
//  }
//  object_data_destroy(&data);
//}

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
  changeYcoord(arg);
}

void MainWindow::on_horizontalSlider_settings_move_move_z_sliderMoved(
    int position) {
//  ui->openGLWidget->shift_z = position;// --
  ui->doubleSpinBox_settings_move_move_z->setValue((double)position);
changeYcoord((double)position);
}

void MainWindow::changeZcoord(double arg){
//  controller_->paramDTO_->move_z_ = ui->openGLWidget->shift_z;// --
  controller_->paramDTO_->move_z_ = arg;// --
  redraw();
}

void MainWindow::on_doubleSpinBox_settings_move_rotate_x_valueChanged(
    double arg1) {
  ui->openGLWidget->rot_x = arg1;
  ui->horizontalSlider_settings_move_rotate_x->setValue(arg1);
  changeXangle();
}

void MainWindow::on_horizontalSlider_settings_move_rotate_x_sliderMoved(
    int position) {
  ui->openGLWidget->rot_x = position;
  ui->doubleSpinBox_settings_move_rotate_x->setValue(position);
  changeXangle();
}

void MainWindow::changeXangle(){
  controller_->paramDTO_->angle_x_ = ui->openGLWidget->rot_x;
  redraw();

}

void MainWindow::on_doubleSpinBox_settings_move_rotate_y_valueChanged(
    double arg1) {
  ui->openGLWidget->rot_y = arg1;
  ui->horizontalSlider_settings_move_rotate_y->setValue(arg1);
  changeYangle();
}

void MainWindow::on_horizontalSlider_settings_move_rotate_y_sliderMoved(
    int position) {
  ui->openGLWidget->rot_y = position;
  ui->doubleSpinBox_settings_move_rotate_y->setValue(position);
  changeYangle();
}

void MainWindow::changeYangle(){
  controller_->paramDTO_->angle_y_ = ui->openGLWidget->rot_y;
  redraw();

}


void MainWindow::on_doubleSpinBox_settings_move_rotate_z_valueChanged(
    double arg1) {
  ui->openGLWidget->rot_z = arg1;
  ui->horizontalSlider_settings_move_rotate_z->setValue(arg1);
  changeZangle();
}

void MainWindow::on_horizontalSlider_settings_move_rotate_z_sliderMoved(
    int position) {
  ui->openGLWidget->rot_z = position;
  ui->doubleSpinBox_settings_move_rotate_z->setValue(position);
  changeZangle();
}

void MainWindow::changeZangle(){
  controller_->paramDTO_->angle_z_ = ui->openGLWidget->rot_z;
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

//void MainWindow::projection_settings() {
//  ui->doubleSpinBox_settings_move_move_z->setMaximum(max_coord * 4);
//  ui->doubleSpinBox_settings_move_move_z->setMinimum(-max_coord * 4);
//  ui->horizontalSlider_settings_move_move_z->setMaximum(max_coord * 4);
//  ui->horizontalSlider_settings_move_move_z->setMinimum(-max_coord * 4);
//  if (ui->comboBox_settings_view_projection_type->currentIndex()) {
//    ui->openGLWidget->shift_z = -max_coord * 1.2;
//    ui->openGLWidget->frustum_far = max_coord * 4;
//    ui->openGLWidget->scale = 1;
//    ui->doubleSpinBox_settings_move_scale->setMaximum(10);
//    ui->doubleSpinBox_settings_move_scale->setValue(1);
//    ui->horizontalSlider_settings_move_scale->setMaximum(10);
//    ui->horizontalSlider_settings_move_scale->setValue(1);
//    ui->doubleSpinBox_settings_move_move_z->setValue(-max_coord * 1.2);
//    ui->horizontalSlider_settings_move_move_z->setValue(-max_coord * 1.2);
//  } else {
//    ui->doubleSpinBox_settings_move_scale->setMaximum(max_coord * 2);
//    ui->doubleSpinBox_settings_move_scale->setValue(max_coord * 1.5);
//    ui->horizontalSlider_settings_move_scale->setMaximum(max_coord * 2);
//    ui->horizontalSlider_settings_move_scale->setValue(max_coord * 1.5);
//    ui->openGLWidget->scale = max_coord * 1.5;
//    ui->doubleSpinBox_settings_move_move_z->setValue(0);
//    ui->horizontalSlider_settings_move_move_z->setValue(0);
//  }
//}

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
