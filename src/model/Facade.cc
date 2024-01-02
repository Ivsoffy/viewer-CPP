#include "Facade.h"

s21::Facade::Facade() {
  affineTransformations_ = new AffineTransformations();
  figure_ = new Figure();
  fileParser_ = new FileParser();
  vertex_ = new Vertex();
  glmodel_ = new GLmodel();
}

void s21::Facade::SetPathToObject(std::string path) {
  path = "/Users/rosmertt/CPP4_3DViewer_v2.0-1/src/3d_objects/cube.obj";
  fileParser_->Parser(this->GetFigure(), path);
}

void s21::Facade::SetAffineTransformations(s21::ParamDTO paramDTO) {
  affineTransformations_->SetMoveX(paramDTO.move_x_);
  affineTransformations_->SetMoveY(paramDTO.move_y_);
  affineTransformations_->SetMoveZ(paramDTO.move_z_);
  affineTransformations_->SetAngleX(paramDTO.angle_x_);
  affineTransformations_->SetAngleY(paramDTO.angle_y_);
  affineTransformations_->SetAngleZ(paramDTO.angle_z_);
  affineTransformations_->SetScale(paramDTO.scale_);
}

void s21::Facade::TrasformateFigure() {
  affineTransformations_->TrasformateVectorOfVerteces(figure_);
}

void s21::Facade::GetBuffer() {
  glmodel_->FillBufferData(figure_->GetDoubleVector(),
                           figure_->GetEdgesVector());
}
