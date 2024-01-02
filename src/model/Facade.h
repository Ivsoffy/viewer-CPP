#ifndef MODEL_FACADE_H_
#define MODEL_FACADE_H_

#include "../controller/ControllerDTO.h"
#include "AffineTransformations.h"
#include "Figure.h"
#include "FileParser.h"
#include "GLmodel.h"
#include "Vertex.h"

namespace s21 {

class Facade {
 public:
  Facade();
  ~Facade(){};

  void SetPathToObject(std::string path);
  void SetAffineTransformations(ParamDTO paramDTO);
  void GetBuffer();
  GLuint GetVertexBuffer() { return glmodel_->GetVertexBuffer(); }
  GLuint GetIndexBuffer() { return glmodel_->GetIndexBuffer(); }
  GLuint GetIndicesSize() { return glmodel_->GetIndicesSize(); }
  GLuint GetVerticesSize() { return glmodel_->GetVerticesSize(); }

  AffineTransformations GetAffineTransformations() {
    return *affineTransformations_;
  }

  FileParser GetFileParser() { return *fileParser_; }

  Figure* GetFigure() { return figure_; }

 private:
  AffineTransformations *affineTransformations_;
  Figure *figure_;
  FileParser *fileParser_;
  Vertex *vertex_;
  GLmodel *glmodel_;

  void TrasformateFigure();
};

}  // namespace s21

#endif  // MODEL_FACADE_H_
