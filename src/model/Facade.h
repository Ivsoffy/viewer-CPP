#ifndef MODEL_FACADE_H_
#define MODEL_FACADE_H_

#include "../controller/controller_dto.h"
#include "figure.h"
#include "vertex.h"
#include "snapshot.h"
#include "affine_transformations.h"

namespace s21 {

class Facade {
 public:
  Facade();
  ~Facade(){};

  void SetPathToObject(std::string path);
  void TrasformateFigure() { figure_def_->TransformFigure(figure_draw_); }

  std::vector<s21::Vertex>* GetDrawVertecisRef() { return figure_draw_->GetVerticesVectorRef(); }
  std::vector<unsigned>* GetDrawEdgesRef() { return  figure_draw_->GetEdgesVectorRef(); }

  std::vector<s21::Vertex>* GetDefVertecisRef() { return figure_def_->GetVerticesVectorRef(); }
  std::vector<unsigned>* GetDefEdgesRef() { return  figure_def_->GetEdgesVectorRef(); }

  AffineTransformations GetAffineTransformations() {
    return *affineTransformations_;
  }

  AffineTransformations *GetAffineTransformationsRef() {
    return affineTransformations_;
  }

  void CreateSnapshot(ParamDTO *dto) { snapshot_ = new Snapshot(figure_def_, figure_draw_, dto); }

//  void CreateSnapshot(double move_x,
//                      double move_y,
//                      double move_z,
//                      double angle_x,
//                      double angle_y,
//                      double angle_z,
//                      double scale) {
//    snapshot_ = new Snapshot(figure_def_,
//                            figure_draw_,
//                            move_x,
//                            move_y,
//                            move_z,
//                            angle_x,
//                            angle_y,
//                            angle_z,
//                            scale);
//  }

  void Restore(ParamDTO *dto) {
      snapshot_->Restore(figure_def_, figure_draw_, dto);
  }

  Figure::FileParser GetFileParser() { return *fileParser_; }
  Figure* GetFigureDef() { return figure_def_; }
  Figure* GetFigureDraw() { return figure_draw_; }
  Snapshot* GetSnapshot() { return snapshot_; }

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
