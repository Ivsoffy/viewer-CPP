#ifndef MODEL_FACADE_H_
#define MODEL_FACADE_H_

#include "../controller/ControllerDTO.h"
#include "Figure.h"
#include "Vertex.h"
#include "AffineTransformations.h"

namespace s21 {

class Facade {
 public:
  Facade();
  ~Facade(){};

  void SetPathToObject(std::string path);
  void TrasformateFigure() { figure_def_->TransformFigure(figure_draw_); }

  std::vector<s21::Vertex>* GetDrawVertecisRef() { return figure_draw_->GetVerticesVectorRef(); }/////////
  std::vector<unsigned>* GetDrawEdgesRef() { return  figure_draw_->GetEdgesVectorRef(); }////////

  std::vector<s21::Vertex>* GetDefVertecisRef() { return figure_def_->GetVerticesVectorRef(); }////////
  std::vector<unsigned>* GetDefEdgesRef() { return  figure_def_->GetEdgesVectorRef(); }//////////

  AffineTransformations GetAffineTransformations() {
    return *affineTransformations_;
  }

  AffineTransformations *GetAffineTransformationsRef() {
    return affineTransformations_;
  }

  Figure::FileParser GetFileParser() { return *fileParser_; }

  Figure* GetFigureDef() { return figure_def_; }
  Figure* GetFigureDraw() { return figure_draw_; }

 private:
  AffineTransformations *affineTransformations_;
  Figure *figure_def_;
  Figure *figure_draw_;
  Figure::FileParser *fileParser_;
};

}  // namespace s21

#endif  // MODEL_FACADE_H_
