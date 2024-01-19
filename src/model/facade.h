#ifndef MODEL_FACADE_H_
#define MODEL_FACADE_H_

#include "../dto/dto.h"
#include "affine_transformations.h"
#include "figure.h"
#include "snapshot.h"
#include "vertex.h"

namespace s21 {

class Facade {
 public:
  Facade();
  ~Facade(){};

  /// @brief Set the path of the file to open
  void SetPathToObject(std::string path);

  /// @brief transform from first figure to another figure
  void TrasformateFigure() { figure_def_->TransformFigure(figure_draw_); }

  std::vector<s21::Vertex> *GetDrawVertecisRef() {
    return figure_draw_->GetVerticesVectorRef();
  }
  std::vector<unsigned> *GetDrawEdgesRef() {
    return figure_draw_->GetEdgesVectorRef();
  }

  std::vector<s21::Vertex> *GetDefVertecisRef() {
    return figure_def_->GetVerticesVectorRef();
  }
  std::vector<unsigned> *GetDefEdgesRef() {
    return figure_def_->GetEdgesVectorRef();
  }

  AffineTransformations GetAffineTransformations() {
    return *affineTransformations_;
  }

  AffineTransformations *GetAffineTransformationsRef() {
    return affineTransformations_;
  }

  /// @brief Save 3d object parameters
  /// @param dto reference to dto
  void CreateSnapshot(ParamDTO *dto) {
    snapshot_ = new Snapshot(figure_def_, figure_draw_, dto);
  }
  
  /// @brief Restore 3d object parameters
  void Restore() {
    snapshot_->Restore(figure_def_, figure_draw_);
  }

  void Reset();

  Figure::FileParser GetFileParser() { return *fileParser_; }
  Figure *GetFigureDef() { return figure_def_; }
  Figure *GetFigureDraw() { return figure_draw_; }
  Snapshot *GetSnapshot() { return snapshot_; }


  double GetMax() { return figure_draw_->Get_Max(); }

 private:
  AffineTransformations *affineTransformations_;
  Figure *figure_def_ = nullptr;
  Figure *figure_draw_ = nullptr;
  Figure::FileParser *fileParser_;
  Snapshot *snapshot_ = nullptr;
};

}  // namespace s21

#endif  // MODEL_FACADE_H_