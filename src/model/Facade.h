#ifndef MODEL_FACADE_H_
#define MODEL_FACADE_H_

#include "../controller/ControllerDTO.h"
#include "AffineTransformations.h"
#include "Figure.h"
#include "GLmodelh.txt"
#include "Vertex.h"

namespace s21 {

class Facade {
 public:
  Facade();
  ~Facade(){};

  void SetPathToObject(std::string path);
  void TrasformateFigure(ParamDTO paramDTO);
  void GetBuffer();
//  GLuint GetVertexBuffer() { return glmodel_->GetVertexBuffer(); }
  std::vector<s21::Vertex>* GetVertecisRef() { return figure_draw_->GetVertexesVectorRef(); }
  std::vector<unsigned>* GetEdges() { return  figure_draw_->GetEdgesVectorRef(); }

  AffineTransformations GetAffineTransformations() {
    return *affineTransformations_;
  }

  Figure::FileParser GetFileParser() { return *fileParser_; }

  Figure* GetFigureDef() { return figure_def_; }
  Figure* GetFigureDraw() { return figure_draw_; }

 private:
  AffineTransformations *affineTransformations_;
  Figure *figure_def_;
  Figure *figure_draw_;
  Figure::FileParser *fileParser_;

//  std::vector<double> vertices_;
//  std::vector<unsigned> edges_;
//  GLmodel *glmodel_;
};

}  // namespace s21

#endif  // MODEL_FACADE_H_
