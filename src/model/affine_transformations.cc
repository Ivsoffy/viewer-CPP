#include "affine_transformations.h"

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

void s21::AffineTransformations::TrasformateVertex(s21::Vertex *vertex_def, s21::Vertex *vertex_draw) {
  double angle_x = angle_x_ * M_PI / 180;
  double angle_y = angle_y_ * M_PI / 180;
  double angle_z = angle_z_ * M_PI / 180;

  if (move_x_ != 0) {
    vertex_draw->SetX(vertex_draw->GetX() + move_x_);
  }
  if (move_y_ != 0) {
    vertex_draw->SetY(vertex_draw->GetY() + move_y_);
  }
  if (move_z_ != 0) {
    vertex_draw->SetZ(vertex_draw->GetZ() + move_z_);
  }

  if (angle_x_ != 0) {
    double y = vertex_draw->GetY();
    double z = vertex_draw->GetZ();
    vertex_draw->SetY(vertex_draw->GetY() * cos(angle_x) - vertex_draw->GetZ() * sin(angle_x));
    vertex_draw->SetZ(y * sin(angle_x) + z * cos(angle_x));
  }
  if (angle_y_ != 0) {
    double x = vertex_draw->GetX();
    double z = vertex_draw->GetZ();
    vertex_draw->SetX(vertex_draw->GetX() * cos(angle_y) + vertex_draw->GetZ() * sin(angle_y));
    vertex_draw->SetZ(x * -sin(angle_y) + z * cos(angle_y));
  }
  if (angle_z_ != 0) {
    double x = vertex_draw->GetX();
    double y = vertex_draw->GetY();
    vertex_draw->SetX(vertex_draw->GetX() * cos(angle_z) - vertex_draw->GetY() * sin(angle_z));
    vertex_draw->SetY(x * sin(angle_z) + y * cos(angle_z));
  }

  if (scale_ != 0 ) {
    vertex_draw->SetX(vertex_draw->GetX() * scale_);
    vertex_draw->SetY(vertex_draw->GetY() * scale_);
    vertex_draw->SetZ(vertex_draw->GetZ() * scale_);
  }
}
