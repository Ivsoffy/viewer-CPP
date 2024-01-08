#include "Facade.h"

s21::Facade::Facade() {
  affineTransformations_ = new AffineTransformations();
  figure_def_ = new Figure();
  figure_draw_ = new Figure();
  fileParser_ = new Figure::FileParser();
  vertex_ = new Vertex();
  glmodel_ = new GLmodel();
}

void s21::Facade::SetPathToObject(std::string path) {
  fileParser_->Parser(GetFigureDef(), path);
  figure_draw_->copy_figure(figure_def_);
}

void s21::Facade::TrasformateFigure(s21::ParamDTO paramDTO) {
  affineTransformations_->SetMoveX(paramDTO.move_x_);
  affineTransformations_->SetMoveY(paramDTO.move_y_);
  affineTransformations_->SetMoveZ(paramDTO.move_z_);
  affineTransformations_->SetAngleX(paramDTO.angle_x_);
  affineTransformations_->SetAngleY(paramDTO.angle_y_);
  affineTransformations_->SetAngleZ(paramDTO.angle_z_);
  affineTransformations_->SetScale(paramDTO.scale_);
  figure_draw_->copy_figure(figure_def_);
  affineTransformations_->TrasformateVectorOfVerteces(figure_draw_);
}

void s21::Facade::GetBuffer() {
  glmodel_->FillBufferData(figure_draw_->GetDoubleVector(),
                           figure_draw_->GetVertexesVector(),
                           figure_draw_->GetEdgesVector());
}
