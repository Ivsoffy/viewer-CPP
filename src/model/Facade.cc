#include "Facade.h"

void s21::Facade::SetPathToObject(std::string path) {
    figure_ = fileParser_.Parser(path);
}

void s21::Facade::SetAffineTransformations(s21::Controller::ParamDTO paramDTO) {
    affineTransformations_.SetMoveX(paramDTO.move_x_);
    affineTransformations_.SetMoveY(paramDTO.move_y_);
    affineTransformations_.SetMoveZ(paramDTO.move_z_);
    affineTransformations_.SetAngleX(paramDTO.angle_x_);
    affineTransformations_.SetAngleY(paramDTO.angle_y_);
    affineTransformations_.SetAngleZ(paramDTO.angle_z_);
    affineTransformations_.SetScale(paramDTO.scale_);
}

void s21::Facade::TrasformateFigure() {
    affineTransformations_.Trasformate(&figure_);
}
