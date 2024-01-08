#include "oglwidget.h"

#include <chrono>                  /////////////////////TODO
#include <ctime>                   /////////////////////////////TODO
#include <iostream>                ////////////////////////////TODO
using std::chrono::duration_cast;  ////////////////////////////TODO
using std::chrono::milliseconds;   ////////////////////////////TODO
using std::chrono::system_clock;   ////////////////////////////TODO

void OGLwidget::initializeGL() {
  // Загрузка и компиляция шейдеров
  const char* vertexShaderSource =
      "#version 330 core\n"
      "layout (location = 0) in vec3 aPos;\n"
      "void main()\n"
      "{\n"
      "    gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
      "}\n";
  const char* fragmentShaderSource =
      "#version 330 core\n"
      "out vec4 FragColor;\n"
      "void main()\n"
      "{\n"
      "    FragColor = vec4(1.0, 0.5, 0.2, 1.0);\n"
      "}\n";

  GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
  glShaderSource(vertexShader, 1, &vertexShaderSource, nullptr);
  glCompileShader(vertexShader);

  GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
  glShaderSource(fragmentShader, 1, &fragmentShaderSource, nullptr);
  glCompileShader(fragmentShader);

  shaderProgram = glCreateProgram();
  glAttachShader(shaderProgram, vertexShader);
  glAttachShader(shaderProgram, fragmentShader);
  glLinkProgram(shaderProgram);

  // glDeleteShader(vertexShader);
  // glDeleteShader(fragmentShader);

  // Установка текущей шейдерной программы
  glUseProgram(shaderProgram);
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

void OGLwidget::SetVertexBuffer(GLuint vertex_buffer) {
  VertexBuffer_ = vertex_buffer;
}
void OGLwidget::SetIndexBuffer(GLuint index_buffer) {
  IndexBuffer_ = index_buffer;
}
void OGLwidget::SetIndicesSize(GLuint indices_size) {
  IndecesSize_ = indices_size;
}
void OGLwidget::SetVerticesSize(GLuint vertices_size) {
  VerticesSize_ = vertices_size;
}

void OGLwidget::paintGL() {
  if (need_paint) {
    glClearColor(background_color_r / 255.0, background_color_g / 255.0,
                 background_color_b / 255.0, 0);

    // очистка экрана и буфера глубины
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glRotatef(-30.0f, 1.0f, 0.0f, 0.0f);  // Наклон оси X на 45 градусов вперед
    glRotatef(30.0f, 0.0f, 1.0f, 0.0f);  // Наклон оси Z на 45 градусов влево

    float scalef = 1.0f / sqrt(2.0f);
    glScalef(scalef, scalef, scalef);

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

    glBindBuffer(GL_ARRAY_BUFFER, VertexBuffer_);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IndexBuffer_);

    // Установка атрибута вершин в шейдерной программе
    GLint posAttrib = glGetAttribLocation(shaderProgram, "position");
    glEnableVertexAttribArray(posAttrib);
    glVertexAttribPointer(posAttrib, 3, GL_DOUBLE, GL_FALSE, 0, 0);

    // Включение атрибута вершин
    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(3, GL_DOUBLE, 0, 0);

    if (vertex_type != NONE) {
      // size and color of vertex
      glPointSize(vertex_size);
      glColor3d(vertex_color_r / 255.0, vertex_color_g / 255.0,
                vertex_color_b / 255.0);

      if (vertex_type == CIRCLE) glEnable(GL_POINT_SMOOTH);

      // paint vertex
      glDrawArrays(GL_POINTS, 0, VerticesSize_);
      if (vertex_type == CIRCLE) glDisable(GL_POINT_SMOOTH);
    }

    //  glLineWidth(line_size);
    glLineWidth(1);
    glColor3d(1.0 * line_color_r / 255, 1.0 * line_color_g / 255,
              1.0 * line_color_b / 255);

    std::cerr << ">>>>>>>paintGL<<<<<<<"
              << std::endl;  /////////////////////TODO
    auto millisec_start =
        duration_cast<milliseconds>(system_clock::now().time_since_epoch())
            .count();  /////////////////////TODO

    // Отрисовка куба
    glDrawElements(GL_LINES, IndecesSize_, GL_UNSIGNED_INT, 0);

    std::cerr << "<<<<<<<<paintGL>>>>>>>"
              << std::endl;  /////////////////////TODO
    auto millisec_end =
        duration_cast<milliseconds>(system_clock::now().time_since_epoch())
            .count();  /////////////////////TODO
    std::cerr << millisec_end - millisec_start
              << std::endl;  /////////////////////TODO

    // Отключение атрибута вершин
    glDisableClientState(GL_VERTEX_ARRAY);

    // Освобождение буфера вершин
    glDeleteBuffers(1, &VertexBuffer_);

    // Освобождение буфера полигонов
    glDeleteBuffers(1, &IndexBuffer_);
  }
}
