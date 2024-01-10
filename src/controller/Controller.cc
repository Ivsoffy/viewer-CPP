#include "Controller.h"

void s21::Controller::TransferFigureParams() {  ////////////
  // call func from fasad
  // facade_->TrasformateFigure(*paramDTO_);
  facade_->TrasformateFigure();
}

void s21::Controller::TransferObject(std::string file_name) {
  // call func from fasad
  facade_->SetPathToObject(file_name);
}

s21::GLBufferDTO
s21::Controller::TransferGLBuffer() {  /////////////////////////

  s21::GLBufferDTO glBufferDTO =
      s21::GLBufferDTO(facade_->GetVertecisRef(), facade_->GetEdgesRef());
  return glBufferDTO;
}

std::vector<s21::Vertex> *s21::Controller::GetVertecisRef() {
  return facade_->GetVertecisRef();
}

std::vector<unsigned> *s21::Controller::GetEdgesRef() {
  return facade_->GetEdgesRef();
}

s21::AffineTransformations *s21::Controller::GetAffineTransformationsRef() {
  return facade_->GetAffineTransformationsRef();
}

double s21::Controller::GetMax() { return facade_->GetMax(); }