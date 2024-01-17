#include "facade.h"

s21::Facade::Facade() {
  affineTransformations_ = new AffineTransformations();
  fileParser_ = new Figure::FileParser();
}

void s21::Facade::SetPathToObject(std::string path) {
   if (figure_def_ != nullptr && figure_draw_ != nullptr) {
       delete figure_def_;
       delete figure_draw_;
   }
  figure_draw_ = new Figure();
  figure_def_ = new Figure();
  fileParser_->Parser(figure_def_, path);
  figure_draw_ = figure_def_;
}
