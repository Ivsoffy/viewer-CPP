#include "Facade.h"

s21::Facade::Facade() {
  affineTransformations_ = new AffineTransformations();
  figure_def_ = new Figure();
  figure_draw_ = new Figure();
  fileParser_ = new Figure::FileParser();
}

void s21::Facade::SetPathToObject(std::string path) {
  fileParser_->Parser(figure_def_, path);
  figure_draw_->copy_figure(figure_def_);
}
