#include "Facade.h"

void s21::Facade::SetPathToObject(std::string path) {
    figure_ = fileParser_.Parser(path);
}

void s21::Facade::SetAffineTransformations(s21::AffineTransformations aff_tran) {
    affineTransformations_ = aff_tran;
}

void s21::Facade::TrasformateFigure() {
    affineTransformations_.Trasformate(&figure_);
}
