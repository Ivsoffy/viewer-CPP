#include "oglwidget.h"

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

void OGLwidget::paintGL() {
  if (need_paint) {
  glClearColor(background_color_r / 255.0, background_color_g / 255.0,
               background_color_b / 255.0, 0);

  //очистка экрана и буфера глубины
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();


  if (view_type) {
    gluPerspective(frustum_fov, this->width()/ this->height(), 0.1, scale * 3);
  } else {
    glOrtho(-scale * this->width()/ this->height(), scale *  this->width()/ this->height(), -scale, scale, -scale * 10, scale * 10);
  }

  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  double look_scale = scale*0.4;
  gluLookAt(look_scale*1.2,look_scale,look_scale*2, 0,0,0,0,1,0);

  glLineWidth(1);
  // Отрисовка осей
  glBegin(GL_LINES);

  // Ось X (красный цвет)
  glColor3f(1.0f, 0.0f, 0.0f);
  glVertex3f(-scale * 1.3, 0.0f, 0.0f);
  glVertex3f(scale * 1.3, 0.0f, 0.0f);

  // Ось Y (зеленый цвет)
  glColor3f(0.0f, 100.0f, 0.0f);
  glVertex3f(0.0f, -scale * 1.3, 0.0f);
  glVertex3f(0.0f, scale * 1.3, 0.0f);

  // Ось Z (синий цвет)
  glColor3f(0.0f, 0.0f, 100.0f);
  glVertex3f(0.0f, 0.0f, -scale * 1.3);
  glVertex3f(0.0f, 0.0f, scale * 1.3);

  glEnd();

  if (line_type) {
    glLineStipple(1, 0x3333);
  }

  // Включение атрибута вершин
  glEnableClientState(GL_VERTEX_ARRAY);

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

  glLineWidth(line_size);
  glColor3d(line_color_r / 255.0, line_color_g / 255.0,
            line_color_b / 255.0);

   if (line_type) glEnable(GL_LINE_STIPPLE);

  // Отрисовка
  glDrawElements(GL_LINES, edges_->size(), GL_UNSIGNED_INT, edges_->data());

  if (line_type) glDisable(GL_LINE_STIPPLE);

  // Отключение атрибута вершин
  glDisableClientState(GL_VERTEX_ARRAY);
  }
}
