#ifndef CONTROLLER_CONTROLLER_H_
#define CONTROLLER_CONTROLLER_H_

#include <QOpenGLFunctions>
#include <string>

#include "../model/facade.h"
#include "../dto/dto.h"

namespace s21 {
class Controller {
 public:
  Controller(Facade *facade) {
    facade_ = facade;
  }

  /// @brief Retern figureDataDTO
  /// @return dto object
  s21::FigureDataDTO TransferFigureData();

  /// @brief Call TrasformateFigure function on facade object
  void TransferFigureParams();

  /// @brief Transfer the name of the file to open
  /// @param file_name Name of the file to open
  /// @return Status messege
  std::string TransferObject(std::string file_name);

  std::vector<s21::Vertex> *GetVertecisRef();
  std::vector<unsigned> *GetEdgesRef();

  double GetMax();

  void CreateSnapshot(ParamDTO *dto) {
      facade_->CreateSnapshot(dto);
  };

  void Restore() {
    facade_->Restore();
  };

  s21::AffineTransformations *GetAffineTransformationsRef();

  /// @brief Returns the maximum overall size
  /// @return Returns value of maximum overall size
  Facade* GetFacadeRef() {return facade_; };

 private:
  Facade *facade_;
};

}  // namespace s21

#endif  // CONTROLLER_CONTROLLER_H_
