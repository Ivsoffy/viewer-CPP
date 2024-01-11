#include "AffineTransformations.h"

#include <iostream>////////////////////////////TODO

void s21::AffineTransformations::SetMoveX(double value) {
  move_x_ = value;

}

void s21::AffineTransformations::SetMoveY(double value) {
  move_y_ = value;
}

void s21::AffineTransformations::SetMoveZ(double value) {
  move_z_ = value;
}

void s21::AffineTransformations::SetAngleX(double angle) { 
  angle_x_ = angle;
}

void s21::AffineTransformations::SetAngleY(double angle) {
  angle_y_ = angle;
}

void s21::AffineTransformations::SetAngleZ(double angle) {
  angle_z_ = angle;
}

void s21::AffineTransformations::SetScale(double scale) {
  // scale_ = scale;
  old_scale_ = scale;
  scale_ = scale / 100;
}

// void s21::AffineTransformations::CleanData() {
//   move_x_ = 0;
//   move_y_ = 0;
//   move_z_ = 0;
//   angle_x_ = 0;
//   angle_y_ = 0;
//   angle_z_ = 0;
//   scale_ = 0;
// }


void s21::AffineTransformations::TrasformateVertex(s21::Vertex *vertex_def, s21::Vertex *vertex_draw) {
  double angle_x = angle_x_ * M_PI / 180;
  double angle_y = angle_y_ * M_PI / 180;
  double angle_z = angle_z_ * M_PI / 180;

  vertex_draw->SetX(vertex_def->GetX());
  vertex_draw->SetY(vertex_def->GetY());
  vertex_draw->SetZ(vertex_def->GetZ());

  double y = vertex_draw->GetY();
  double z = vertex_draw->GetZ();
  vertex_draw->SetY(vertex_draw->GetY() * cos(angle_x) - vertex_draw->GetZ() * sin(angle_x));
  vertex_draw->SetZ(y * sin(angle_x) + z * cos(angle_x));

  double x = vertex_draw->GetX();
  z = vertex_draw->GetZ();
  vertex_draw->SetX(vertex_draw->GetX() * cos(angle_y) + vertex_draw->GetZ() * sin(angle_y));
  vertex_draw->SetZ(x * -sin(angle_y) + z * cos(angle_y));

  x = vertex_draw->GetX();
  y = vertex_draw->GetY();
  vertex_draw->SetX(vertex_draw->GetX() * cos(angle_z) - vertex_draw->GetY() * sin(angle_z));
  vertex_draw->SetY(x * sin(angle_z) + y * cos(angle_z));

  vertex_draw->SetX(vertex_draw->GetX() + move_x_);
  vertex_draw->SetY(vertex_draw->GetY() + move_y_);
  vertex_draw->SetZ(vertex_draw->GetZ() + move_z_);




  // vertex_draw->SetX(vertex_def->GetX());
  // vertex_draw->SetY(vertex_def->GetY());
  // vertex_draw->SetZ(vertex_def->GetZ());

  // double y = vertex_draw->GetY();
  // double z = vertex_draw->GetZ();
  // vertex_draw->SetY(vertex_draw->GetY() * cos(angle_x) - vertex_draw->GetZ() * sin(angle_x));
  // vertex_draw->SetZ(y * sin(angle_x) + z * cos(angle_x));

  // double x = vertex_draw->GetX();
  // z = vertex_draw->GetZ();
  // vertex_draw->SetX(vertex_draw->GetX() * cos(angle_y) + vertex_draw->GetZ() * sin(angle_y));
  // vertex_draw->SetZ(x * -sin(angle_y) + z * cos(angle_y));

  // x = vertex_draw->GetX();
  // y = vertex_draw->GetY();
  // vertex_draw->SetX(vertex_draw->GetX() * cos(angle_z) - vertex_draw->GetY() * sin(angle_z));
  // vertex_draw->SetY(x * sin(angle_z) + y * cos(angle_z));

  // vertex_draw->SetX(vertex_draw->GetX() + move_x_);
  // vertex_draw->SetY(vertex_draw->GetY() + move_y_);
  // vertex_draw->SetZ(vertex_draw->GetZ() + move_z_);

  // if (scale_ != 1 ) {
  //   vertex_draw->SetX(vertex_def->GetX() * scale_);
  //   vertex_draw->SetY(vertex_def->GetY() * scale_);
  //   vertex_draw->SetZ(vertex_def->GetZ() * scale_);
  // }
}
