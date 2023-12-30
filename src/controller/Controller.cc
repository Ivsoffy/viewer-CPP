#include "Controller.h"

s21::CalcController::ParamDTO::ParamDTO(double move_x, double move_y,
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

void s21::CalcController::TransferFigureParams(ParamDTO *param) {
  // call func from fasad
}

void s21::CalcController::TransferObject(std::string file_name) {
  // call func from fasad
}

void s21::CalcController::TransferGLBuffer(GLuint VertexBuffer,
                                           GLuint IndexBuffer, uint IndecesSize,
                                           uint VerticesSize) {
  // call func from fasad
}
