#include "controller.h"

void s21::Controller::TransferFigureParams() { facade_->TrasformateFigure(); }

std::string s21::Controller::TransferObject(std::string file_name) {
  std::string err_msg = "OK";
  try {
    facade_->SetPathToObject(file_name);
  } catch (const std::exception& e) {
    err_msg = e.what();
  }
  return err_msg;
}

s21::FigureDataDTO s21::Controller::TransferFigureData() {
  s21::FigureDataDTO figureDataDTO = s21::FigureDataDTO(
      facade_->GetDrawVertecisRef(), facade_->GetDrawEdgesRef());
  return figureDataDTO;
}

std::vector<s21::Vertex>* s21::Controller::GetVertecisRef() {
  return facade_->GetDrawVertecisRef();
}

std::vector<unsigned>* s21::Controller::GetEdgesRef() {
  return facade_->GetDrawEdgesRef();
}

s21::AffineTransformations* s21::Controller::GetAffineTransformationsRef() {
  return facade_->GetAffineTransformationsRef();
}

double s21::Controller::GetMax() { return facade_->GetMax(); }