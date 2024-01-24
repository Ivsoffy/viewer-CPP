#include "oglwidget.h"

// OGLwidget::OGLwidget(QWidget *parent) : QOpenGLWidget{parent} {}

void OGLwidget::initializeGL() {
  initializeOpenGLFunctions();
  window_ratio_ = 1.0 * this->width() / this->height();
}

void OGLwidget::SetVertices(std::vector<s21::Vertex>* vertices) {
  vertices_ = vertices;
}

void OGLwidget::SetEdges(std::vector<unsigned>* edges) { edges_ = edges; }

std::vector<s21::Vertex>* OGLwidget::GetVerticesRef() { return vertices_; }

std::vector<unsigned>* OGLwidget::GetEdgesRef() { return edges_; }

void OGLwidget::paintGL() {
  glClearColor(background_color_r_ / 255.0, background_color_g_ / 255.0,
               background_color_b_ / 255.0, 0);

  // очистка экрана и буфера глубины
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  if (need_paint_) {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    if (view_type_) {
      gluPerspective(perspective_fov_, window_ratio_, 0.1, scale_ * 5);
    } else {
      glOrtho(-scale_ * window_ratio_, scale_ * window_ratio_, -scale_, scale_,
              -scale_ * 5, scale_ * 5);
    }

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    double look_scale_ = scale_ * 0.4;
    gluLookAt(look_scale_ * 1.2, look_scale_, look_scale_ * 2, 0, 0, 0, 0, 1,
              0);

    glLineWidth(1);
    /// Отрисовка осей
    glBegin(GL_LINES);
    axis_scale_ = scale_ * 1.3 * window_ratio_;

    // Ось X (красный цвет)
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex3f(-axis_scale_, 0.0f, 0.0f);
    glVertex3f(axis_scale_, 0.0f, 0.0f);

    // Ось Y (зеленый цвет)
    glColor3f(0.0f, 100.0f, 0.0f);
    glVertex3f(0.0f, -axis_scale_, 0.0f);
    glVertex3f(0.0f, axis_scale_, 0.0f);

    // Ось Z (синий цвет)
    glColor3f(0.0f, 0.0f, 100.0f);
    glVertex3f(0.0f, 0.0f, -axis_scale_);
    glVertex3f(0.0f, 0.0f, axis_scale_);

    glEnd();

    if (line_type_) {
      glLineStipple(1, 0x3333);
    }

    // Включение атрибута вершин
    glEnableClientState(GL_VERTEX_ARRAY);

    glVertexPointer(3, GL_DOUBLE, 0, vertices_->data());

    if (vertex_type_ != NONE) {
      // size and color of vertex
      glPointSize(vertex_size_);
      glColor3d(vertex_color_r_ / 255.0, vertex_color_g_ / 255.0,
                vertex_color_b_ / 255.0);

      if (vertex_type_ == CIRCLE) glEnable(GL_POINT_SMOOTH);

      // paint vertex
      glDrawArrays(GL_POINTS, 0, vertices_->size());
      if (vertex_type_ == CIRCLE) glDisable(GL_POINT_SMOOTH);
    }

    glLineWidth(line_size_);
    glColor3d(line_color_r_ / 255.0, line_color_g_ / 255.0,
              line_color_b_ / 255.0);

    if (line_type_) glEnable(GL_LINE_STIPPLE);

    // Отрисовка
    glDrawElements(GL_LINES, edges_->size(), GL_UNSIGNED_INT, edges_->data());

    if (line_type_) glDisable(GL_LINE_STIPPLE);

    // Отключение атрибута вершин
    glDisableClientState(GL_VERTEX_ARRAY);
  }
}
