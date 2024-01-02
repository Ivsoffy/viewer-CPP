#include "Controller.h"

void s21::Controller::TransferFigureParams(ParamDTO param) {
  // call func from fasad
  facade_->SetAffineTransformations(param);
}

void s21::Controller::TransferObject(std::string file_name) {
  // call func from fasad
  facade_->SetPathToObject(file_name);
}

s21::GLBufferDTO s21::Controller::TransferGLBuffer() {
  // call func from fasad
  facade_->GetBuffer();
  s21::GLBufferDTO GLBuffDTO = s21::GLBufferDTO(
      facade_->GetVertexBuffer(), facade_->GetIndexBuffer(),
      facade_->GetIndicesSize(), facade_->GetVerticesSize());
  return GLBuffDTO;
}
