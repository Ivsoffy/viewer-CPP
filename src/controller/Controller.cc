#include "controller.h"

void s21::Controller::TransferFigureParams() {
  facade_->TrasformateFigure();
}

void s21::Controller::TransferObject(std::string file_name) {
  facade_->SetPathToObject(file_name);
}

s21::GLBufferDTO s21::Controller::TransferGLBuffer() {
    s21::GLBufferDTO glBufferDTO = s21::GLBufferDTO(facade_->GetDrawVertecisRef(),
                                                    facade_->GetDrawEdgesRef());
    return glBufferDTO;
}

std::vector<s21::Vertex> *s21::Controller::GetVertecisRef() {
    return facade_->GetDrawVertecisRef();
}

std::vector<unsigned> *s21::Controller::GetEdgesRef() {
    return facade_->GetDrawEdgesRef();
}

s21::AffineTransformations* s21::Controller::GetAffineTransformationsRef() {
    return facade_->GetAffineTransformationsRef();
}

double s21::Controller::GetMax() { return facade_->GetMax(); }
