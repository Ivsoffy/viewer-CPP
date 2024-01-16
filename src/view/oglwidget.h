#ifndef OGLWIDGET_H
#define OGLWIDGET_H

#define GL_SILENCE_DEPRECATION

#include <QOpenGLFunctions>
#include <QOpenGLWidget>
#include <QWindow>
#include <OpenGL/glu.h>

#include "../model/Vertex.h"

//class OGLwidget : public QOpenGLWidget, public QOpenGLFunctions {
//  Q_OBJECT

class OGLwidget : public QOpenGLWidget, public QOpenGLFunctions {
  Q_OBJECT
  
 public:
  OGLwidget(QWidget *parent = NULL) : QOpenGLWidget(parent)  {}
  ~OGLwidget() {
    //    if (vertex_array) {
    //      opengl_array_destroy(polygons_array, edges_counter);
    //    }
  }

  /// @brief Standart method in OpenGL. Start when OpenGLwidget open.
  void initializeGL() override;

  /// @brief Standart method in OpenGL. All painting doing there.
  void paintGL() override;

  void init_setttings();

  void SetVertices(std::vector<s21::Vertex>* vertices);
  void SetEdges(std::vector<unsigned>* edges);

  std::vector<s21::Vertex>* GetVerticesRef();
  std::vector<unsigned>* GetEdgesRef();

  double window_ratio_;
  int perspective_fov_ = 80;

  bool need_paint_ = false;

  int line_type_ = 0;
  int vertex_type_ = 1;
  uint total_edges_ = 0;

  int view_type_ = 0;         // 0 - parallel, 1 - central

  double scale_ = 1;
  double axis_scale_;

  int line_color_r_ = 0;
  int line_color_g_ = 0;
  int line_color_b_ = 0;

  float line_size_ = 2;

  int vertex_color_r_ = 255;
  int vertex_color_g_ = 0;
  int vertex_color_b_ = 0;

  int background_color_r_ = 255;
  int background_color_g_ = 253;
  int background_color_b_ = 239;

  float vertex_size_ = 5;

 private:
    enum vertex_type { NONE, CIRCLE, SQUARE };
    std::vector<s21::Vertex>* vertices_;
    std::vector<unsigned>* edges_;
};

#endif  // OGLWIDGET_H
