#include "Controller.h"

void s21::Controller::TransferFigureParams() {////////////
  // call func from fasad
  facade_->TrasformateFigure(*paramDTO_);
}

void s21::Controller::TransferObject(std::string file_name) {
  // call func from fasad
  facade_->SetPathToObject(file_name);
}

s21::GLBufferDTO s21::Controller::TransferGLBuffer() {/////////////////////////

    s21::GLBufferDTO glBufferDTO = s21::GLBufferDTO(facade_->GetVertecisRef(),
                                                    facade_->GetEdges());
    return glBufferDTO;
}
