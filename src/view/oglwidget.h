#ifndef OGLWIDGET_H
#define OGLWIDGET_H

#define GL_SILENCE_DEPRECATION

#include <QOpenGLFunctions>
#include <QOpenGLWidget>
#include <QWindow>
#include <OpenGL/glu.h>

#include "../model/vertex.h"

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

  int init_key = 0;

  bool need_paint = false;

  //  uint vertex_count = 0;
  //  uint polygon_count = 0;

  //  struct vertex *vertex_array = NULL;
  //  uint *polygons_array = NULL;
  //  uint *edges_counter = NULL;

  //  MainWindow *main_window;
  //  struct user_settings *init_set;

  double eyeX=2;
  double eyeY=1;
  double eyeZ=3;

  int line_type = 0;
  int vertex_type = 1;
  uint total_edges = 0;

  int view_type = 0;         // 0 - parallel, 1 - central
  double frustum_widht = 1;  // Central projection: vertical clipping planes
  double frustum_hight = 1;  // Central projection: horizontal clipping planes
  double frustum_far = 200;  // Central projection: depth clipping planes
  double frustum_fov = 120;  // Central projection: angle of view in degrese

  double shift_x = 0;
  double shift_y = 0;
  double shift_z = 0;

  double rot_x = 0;
  double rot_y = 0;
  double rot_z = 0;

  double scale = 1;

  int line_color_r = 0;
  int line_color_g = 0;
  int line_color_b = 0;

  float line_size = 2;

  int vertex_color_r = 255;
  int vertex_color_g = 0;
  int vertex_color_b = 0;

  int background_color_r = 255;
  int background_color_g = 253;
  int background_color_b = 239;

  float vertex_size = 5;

 private:
    enum vertex_type { NONE, CIRCLE, SQUARE };
    std::vector<s21::Vertex>* vertices_;
    std::vector<unsigned>* edges_;
};

#endif  // OGLWIDGET_H
