#include "oglwidget.h"

#include <ctime>/////////////////////////////TODO
#include <chrono>/////////////////////TODO
using std::chrono::duration_cast;////////////////////////////TODO
using std::chrono::milliseconds;////////////////////////////TODO
using std::chrono::system_clock;////////////////////////////TODO
#include <iostream>////////////////////////////TODO

//OGLwidget::OGLwidget(QWidget *parent) : QOpenGLWidget{parent} {}

void OGLwidget::initializeGL() {
//    setlocale(LC_ALL, "en_US.UTF-8");
    initializeOpenGLFunctions();
//    glEnable(GL_DEPTH_TEST);
//    glDepthFunc(GL_LEQUAL);
//    glDisable(GL_CULL_FACE);
//    glCullFace(GL_BACK);
}

void OGLwidget::init_setttings() {
  //  init_set = &main_window->user_settings;
  //  view_type = (int)init_set->projection_type;

  //  line_type = (int)init_set->polygon_type;
  //  line_size = init_set->polygon_width;
  //  line_color_r = init_set->polygon_color.red;
  //  line_color_g = init_set->polygon_color.green;
  //  line_color_b = init_set->polygon_color.blue;

  //  vertex_type = (int)init_set->vertex_type;
  //  vertex_size = init_set->vertex_size;
  //  vertex_color_r = init_set->vertex_color.red;
  //  vertex_color_g = init_set->vertex_color.green;
  //  vertex_color_b = init_set->vertex_color.blue;

  //  background_color_r = init_set->background_color.red;
  //  background_color_g = init_set->background_color.green;
  //  background_color_b = init_set->background_color.blue;
}

void OGLwidget::SetVertices(std::vector<s21::Vertex>* vertices) {//////////
  vertices_ = vertices;
}

void OGLwidget::SetEdges(std::vector<unsigned>* edges) {//////////
  edges_ = edges;
}

std::vector<s21::Vertex>* OGLwidget::GetVerticesRef() {
    return vertices_;
}

std::vector<unsigned>* OGLwidget::GetEdgesRef() {
    return edges_;
}
//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////
void OGLwidget::paintGL() {

  if (need_paint) {
  glClearColor(background_color_r / 255.0, background_color_g / 255.0,
               background_color_b / 255.0, 0);

  //очистка экрана и буфера глубины
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();


  glRotatef(-30.0f, 1.0f, 0.0f, 0.0f); // Наклон оси X на 60 градусов вперед
  glRotatef(30.0f, 0.0f, 1.0f, 0.0f); // Наклон оси Y на 60 градусов влево

  // Отрисовка осей
  glBegin(GL_LINES);

  // Ось X (красный цвет)
  glColor3f(1.0f, 0.0f, 0.0f);
  glVertex3f(-100.0f, 0.0f, 0.0f);
  glVertex3f(100.0f, 0.0f, 0.0f);

  // Ось Y (зеленый цвет)
  glColor3f(0.0f, 100.0f, 0.0f);
  glVertex3f(0.0f, -100.0f, 0.0f);
  glVertex3f(0.0f, 100.0f, 0.0f);

  // Ось Z (синий цвет)
  glColor3f(0.0f, 0.0f, 100.0f);
  glVertex3f(0.0f, 0.0f, -100.0f);
  glVertex3f(0.0f, 0.0f, 100.0f);

  glEnd();

  if (view_type) {
    double fov = frustum_fov * M_PI / 180;
    double frustum_near = frustum_hight / (2 * tan(fov / 2));
    frustum_near *= fabs(scale);
    glFrustum(-frustum_widht, frustum_widht, -frustum_hight, frustum_hight,
              frustum_near, frustum_far);
  } else {
    glOrtho(-scale, scale, -scale, scale, -scale, scale);
  }

  if (line_type) {
    glLineStipple(1, 0x3333);
    glEnable(GL_LINE_STIPPLE);
  }

  // Включение атрибута вершин
  glEnableClientState(GL_VERTEX_ARRAY);
//   glVertexPointer(3, GL_DOUBLE, 0, 0);
   glVertexPointer(3, GL_DOUBLE, 0, vertices_->data());

  if (vertex_type != NONE) {
    // size and color of vertex
    glPointSize(vertex_size);
    glColor3d(vertex_color_r / 255.0, vertex_color_g / 255.0,
              vertex_color_b / 255.0);

    if (vertex_type == CIRCLE) glEnable(GL_POINT_SMOOTH);

  
    // paint vertex
    glDrawArrays(GL_POINTS, 0, vertices_->size());
    if (vertex_type == CIRCLE) glDisable(GL_POINT_SMOOTH);
  }

  glLineWidth(1);
  glColor3d(line_color_r / 255.0, line_color_g / 255.0,
            line_color_b / 255.0);

   std::cerr << ">>>>>>>paintGL<<<<<<<" << std::endl;/////////////////////TODO
   auto millisec_start = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();/////////////////////TODO

  // Отрисовка куба
  glDrawElements(GL_LINES, edges_->size(), GL_UNSIGNED_INT, edges_->data());

   auto millisec_end = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();/////////////////////TODO
   std::cerr << millisec_end - millisec_start << "<<<<<<<<paintGL>>>>>>>" << std::endl;/////////////////////TODO

  // Отключение атрибута вершин
  glDisableClientState(GL_VERTEX_ARRAY);
  }
}
// //////////////////////////////////////////////////////////////
// //////////////////////////////////////////////////////////////
// //////////////////////////////////////////////////////////////
// void OGLwidget::paintGL() {

//   if (need_paint) {
//   glClearColor(background_color_r / 255.0, background_color_g / 255.0,
//                background_color_b / 255.0, 0);

//   //очистка экрана и буфера глубины
//   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

//   glMatrixMode(GL_MODELVIEW);
//   glLoadIdentity();


//   glRotatef(-30.0f, 1.0f, 0.0f, 0.0f); // Наклон оси X на 60 градусов вперед
//   glRotatef(30.0f, 0.0f, 1.0f, 0.0f); // Наклон оси Y на 60 градусов влево

//   // Отрисовка осей
//   glBegin(GL_LINES);

//   // Ось X (красный цвет)
//   glColor3f(1.0f, 0.0f, 0.0f);
//   glVertex3f(-100.0f, 0.0f, 0.0f);
//   glVertex3f(100.0f, 0.0f, 0.0f);

//   // Ось Y (зеленый цвет)
//   glColor3f(0.0f, 100.0f, 0.0f);
//   glVertex3f(0.0f, -100.0f, 0.0f);
//   glVertex3f(0.0f, 100.0f, 0.0f);

//   // Ось Z (синий цвет)
//   glColor3f(0.0f, 0.0f, 100.0f);
//   glVertex3f(0.0f, 0.0f, -100.0f);
//   glVertex3f(0.0f, 0.0f, 100.0f);

//   glEnd();

//   if (view_type) {
//     double fov = frustum_fov * M_PI / 180;
//     double frustum_near = frustum_hight / (2 * tan(fov / 2));
//     frustum_near *= fabs(scale);
//     glFrustum(-frustum_widht, frustum_widht, -frustum_hight, frustum_hight,
//               frustum_near, frustum_far);
//   } else {
//     glOrtho(-scale, scale, -scale, scale, -scale, scale);
//   }

//   if (line_type) {
//     glLineStipple(1, 0x3333);
//     glEnable(GL_LINE_STIPPLE);
//   }

//   // Включение атрибута вершин
//   glEnableClientState(GL_VERTEX_ARRAY);
// //   glVertexPointer(3, GL_DOUBLE, 0, 0);
//    glVertexPointer(3, GL_DOUBLE, 0, vertices_->data());

//   if (vertex_type != NONE) {
//     // size and color of vertex
//     glPointSize(vertex_size);
//     glColor3d(vertex_color_r / 255.0, vertex_color_g / 255.0,
//               vertex_color_b / 255.0);

//     if (vertex_type == CIRCLE) glEnable(GL_POINT_SMOOTH);

  
//     // paint vertex
//     glDrawArrays(GL_POINTS, 0, vertices_->size());
//     if (vertex_type == CIRCLE) glDisable(GL_POINT_SMOOTH);
//   }

//   glLineWidth(1);
//   glColor3d(line_color_r / 255.0, line_color_g / 255.0,
//             line_color_b / 255.0);

//   std::cerr << ">>>>>>>paintGL<<<<<<<" << std::endl;/////////////////////TODO
//   auto millisec_start = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();/////////////////////TODO

//   // Отрисовка куба
//   glDrawElements(GL_LINES, edges_->size(), GL_UNSIGNED_INT, edges_->data());
//   std::cerr << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << std::endl;

//   auto millisec_end = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();/////////////////////TODO
//   std::cerr << millisec_end - millisec_start << "<<<<<<<<paintGL>>>>>>>" << std::endl;/////////////////////TODO

//   // Отключение атрибута вершин
//   glDisableClientState(GL_VERTEX_ARRAY);
//   }
// }
