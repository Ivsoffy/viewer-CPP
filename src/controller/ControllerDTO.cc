#include "ControllerDTO.h"

s21::ParamDTO::ParamDTO(double move_x, double move_y, double move_z,
                                    double angle_x, double angle_y,
                                    double angle_z, double scale) {
  move_x_ = move_x;
  move_y_ = move_y;
  move_z_ = move_z;
  angle_x_ = angle_x;
  angle_y_ = angle_y;
  angle_z_ = angle_z;
  scale_ = scale;
}

s21::GLBufferDTO::GLBufferDTO(GLuint vertex_buffer, GLuint index_buffer,
                             GLuint indices_size, GLuint vertices_size,
                            std::vector<unsigned> edges,/////
//                             std::vector<double> vertices) {/////
                            std::vector<s21::Vertex> vertices) {/////
  vertex_buffer_ = vertex_buffer;
  index_buffer_ = index_buffer;
  indices_size_ = indices_size;
  vertices_size_ = vertices_size;

  edges_ = edges;///////////
  vertices_ = vertices;///////////
}
