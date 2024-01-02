#ifndef CONTROLLER_CONTROLLER_H_
#define CONTROLLER_CONTROLLER_H_

#include <QOpenGLFunctions>
#include <string>

#include "../model/Facade.h"
#include "ControllerDTO.h"

namespace s21 {
class Controller {
 public:
  Controller(Facade facade) {
    facade_ = &facade;
  }

  ParamDTO* paramDTO_;
  GLBufferDTO TransferGLBuffer();

  void TransferFigureParams(ParamDTO param);
  void TransferObject(std::string file_name);


 private:
  Facade *facade_;
};

}  // namespace s21

#endif  // CONTROLLER_CONTROLLER_H_
