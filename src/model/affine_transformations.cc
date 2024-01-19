#include "affine_transformations.h"

#include "../dto/dto.h"

void s21::AffineTransformations::SetMoveX(double value) {
  CleanData();
  move_x_ = value - old_move_x_;
  old_move_x_ = value;
}

void s21::AffineTransformations::SetMoveY(double value) {
  CleanData();
  move_y_ = value - old_move_y_;
  old_move_y_ = value;
}

void s21::AffineTransformations::SetMoveZ(double value) {
  CleanData();
  move_z_ = value - old_move_z_;
  old_move_z_ = value;
}

void s21::AffineTransformations::SetAngleX(double angle) { 
  CleanData();
  angle_x_ = angle - old_angle_x_;
  old_angle_x_ = angle;
}

void s21::AffineTransformations::SetAngleY(double angle) {
  CleanData();
  angle_y_ = angle - old_angle_y_;
  old_angle_y_ = angle;
}

void s21::AffineTransformations::SetAngleZ(double angle) {
  CleanData();
  angle_z_ = angle - old_angle_z_;
  old_angle_z_ = angle;
}

void s21::AffineTransformations::SetScale(double scale) {
  CleanData();
  scale_ = scale - old_scale_;
  old_scale_ = scale;
  scale_ = pow(3, scale_ / 100.0);
}

void s21::AffineTransformations::CleanData() {
  move_x_ = 0;
  move_y_ = 0;
  move_z_ = 0;
  angle_x_ = 0;
  angle_y_ = 0;
  angle_z_ = 0;
  scale_ = 0;
}

s21::ParamDTO s21::AffineTransformations::GetOldFielde() {
  return ParamDTO(old_move_x_,
                  old_move_y_, 
                  old_move_z_, 
                  old_angle_x_, 
                  old_angle_y_, 
                  old_angle_z_, 
                  old_scale_);
}

void s21::AffineTransformations::SetOldFielde(s21::ParamDTO dto) {
  old_move_x_ = dto.move_x_;
  old_move_y_ = dto.move_y_;
  old_move_z_ = dto.move_z_;
  old_angle_x_ = dto.angle_x_;
  old_angle_y_ = dto.angle_y_;
  old_angle_z_ = dto.angle_z_;
  old_scale_ = dto.scale_;
};

void s21::AffineTransformations::TrasformateVertex(s21::Vertex *vertex) {
  double angle_x = angle_x_ * M_PI / 180;
  double angle_y = angle_y_ * M_PI / 180;
  double angle_z = angle_z_ * M_PI / 180;

  if (move_x_ != 0) {
    vertex->SetX(vertex->GetX() + move_x_);
  }
  if (move_y_ != 0) {
    vertex->SetY(vertex->GetY() + move_y_);
  }
  if (move_z_ != 0) {
    vertex->SetZ(vertex->GetZ() + move_z_);
  }

  if (angle_x_ != 0) {
    double y = vertex->GetY();
    double z = vertex->GetZ();
    vertex->SetY(vertex->GetY() * cos(angle_x) - vertex->GetZ() * sin(angle_x));
    vertex->SetZ(y * sin(angle_x) + z * cos(angle_x));
  }
  if (angle_y_ != 0) {
    double x = vertex->GetX();
    double z = vertex->GetZ();
    vertex->SetX(vertex->GetX() * cos(angle_y) + vertex->GetZ() * sin(angle_y));
    vertex->SetZ(x * -sin(angle_y) + z * cos(angle_y));
  }
  if (angle_z_ != 0) {
    double x = vertex->GetX();
    double y = vertex->GetY();
    vertex->SetX(vertex->GetX() * cos(angle_z) - vertex->GetY() * sin(angle_z));
    vertex->SetY(x * sin(angle_z) + y * cos(angle_z));
  }

  if (scale_ != 0 ) {
    vertex->SetX(vertex->GetX() * scale_);
    vertex->SetY(vertex->GetY() * scale_);
    vertex->SetZ(vertex->GetZ() * scale_);
  }
}
