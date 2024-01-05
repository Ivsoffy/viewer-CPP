#ifndef CONTROLLERDTO_H
#define CONTROLLERDTO_H

#include <QOpenGLFunctions>
namespace s21 {
class ParamDTO {
 public:
  ParamDTO(double move_x, double move_y, double move_z, double angle_x,
           double angle_y, double angle_z, double scale);
  double move_x_{};
  double move_y_{};
  double move_z_{};
  double angle_x_{};
  double angle_y_{};
  double angle_z_{};
  double scale_ = 1;
};

class GLBufferDTO {
 public:
  GLBufferDTO(GLuint vertex_buffer, GLuint index_buffer, GLuint indices_size,
              GLuint vertices_size);
  GLuint vertex_buffer_{};
  GLuint index_buffer_{};
  GLuint indices_size_{};
  GLuint vertices_size_{};
};
}  // namespace s21

#endif // CONTROLLERDTO_H
