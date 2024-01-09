#ifndef CONTROLLER_CONTROLLER_H_
#define CONTROLLER_CONTROLLER_H_

#include <QOpenGLFunctions>
#include <string>

#include "../model/Facade.h"
#include "ControllerDTO.h"

namespace s21 {
class Controller {
 public:
  Controller(Facade *facade) {
    facade_ = facade;
  }

  ParamDTO* paramDTO_;
  s21::GLBufferDTO TransferGLBuffer();

  void TransferFigureParams();
  void TransferObject(std::string file_name);

  std::vector<s21::Vertex> *GetVertecisRef();
  std::vector<unsigned> *GetEdgesRef();

  s21::AffineTransformations GetAffineTransformations();
  s21::AffineTransformations *GetAffineTransformationsRef();////////

 private:
  Facade *facade_;
};

}  // namespace s21

#endif  // CONTROLLER_CONTROLLER_H_
