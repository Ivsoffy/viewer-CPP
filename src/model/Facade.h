#ifndef MODEL_FACADE_H_
#define MODEL_FACADE_H_

#include "../controller/ControllerDTO.h"
#include "AffineTransformations.h"
#include "Figure.h"
#include "GLmodel.h"
#include "Vertex.h"

namespace s21 {

class Facade {
 public:
  Facade();
  ~Facade(){};

  void SetPathToObject(std::string path);
  void TrasformateFigure(ParamDTO paramDTO);
  void GetBuffer();
  GLuint GetVertexBuffer() { return glmodel_->GetVertexBuffer(); }
  GLuint GetIndexBuffer() { return glmodel_->GetIndexBuffer(); }
  GLuint GetIndicesSize() { return glmodel_->GetIndicesSize(); }
  GLuint GetVerticesSize() { return glmodel_->GetVerticesSize(); }

  std::vector<unsigned> GetEdges() { return glmodel_->GetEdges(); }
//  std::vector<double> GetVertices() { return glmodel_->GetVertices(); }
  std::vector<s21::Vertex> GetVertices() { return glmodel_->GetVertices(); }

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
  Vertex *vertex_;
  GLmodel *glmodel_;
};

}  // namespace s21

#endif  // MODEL_FACADE_H_
