#include "Controller.h"

s21::Controller::ParamDTO::ParamDTO(double move_x, double move_y,
                                        double move_z, double angle_x,
                                        double angle_y, double angle_z,
                                        double scale) {
  move_x_ = move_x;
  move_y_ = move_y;
  move_z_ = move_z;
  angle_x_ = angle_x;
  angle_y_ = angle_y;
  angle_z_ = angle_z;
  scale_ = scale;
}

void s21::Controller::TransferFigureParams(ParamDTO param) {
  // call func from fasad
  facade_.SetAffineTransformations(param);
}

void s21::Controller::TransferObject(std::string file_name) {
  // call func from fasad
  facade_.SetPathToObject(file_name);
}

void s21::Controller::TransferGLBuffer(GLuint VertexBuffer,
                                           GLuint IndexBuffer, uint IndecesSize,
                                           uint VerticesSize) {
  // call func from fasad
}
