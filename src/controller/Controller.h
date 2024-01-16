#ifndef CONTROLLER_CONTROLLER_H_
#define CONTROLLER_CONTROLLER_H_

#include <QOpenGLFunctions>
#include <string>

#include "../model/facade.h"
#include "controller_dto.h"

namespace s21 {
class Controller {
 public:
  Controller(Facade *facade) {
    facade_ = facade;
  }

//  ParamDTO* paramDTO_;
  s21::GLBufferDTO TransferGLBuffer();

  void TransferFigureParams();
  void TransferObject(std::string file_name);

  std::vector<s21::Vertex> *GetVertecisRef();
  std::vector<unsigned> *GetEdgesRef();

  double GetMax();

  void CreateSnapshot(double move_x,
                      double move_y,
                      double move_z,
                      double angle_x,
                      double angle_y,
                      double angle_z,
                      double scale
                      ) {
    facade_->CreateSnapshot(move_x,
                            move_y,
                            move_z,
                            angle_x,
                            angle_y,
                            angle_z,
                            scale);
                      };

  void Restore() {
    facade_->Restore();
  };

  s21::AffineTransformations *GetAffineTransformationsRef();

  Facade* GetFacadeRef() {return facade_; };

 private:
  Facade *facade_;
};

}  // namespace s21

#endif  // CONTROLLER_CONTROLLER_H_
