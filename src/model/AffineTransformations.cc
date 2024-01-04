#include "AffineTransformations.h"

void s21::AffineTransformations::SetMoveX(double distance) {
  move_x_ = distance;
}

void s21::AffineTransformations::SetMoveY(double distance) {
  move_y_ = distance;
}

void s21::AffineTransformations::SetMoveZ(double distance) {
  move_z_ = distance;
}

void s21::AffineTransformations::SetAngleX(double angle) { angle_x_ = angle; }

void s21::AffineTransformations::SetAngleY(double angle) { angle_y_ = angle; }

void s21::AffineTransformations::SetAngleZ(double angle) { angle_z_ = angle; }

void s21::AffineTransformations::SetScale(int scale) { scale_ = scale; }

void s21::AffineTransformations::TrasformateVertex(s21::Vertex* vertex) {
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
    vertex->SetY(vertex->GetY() * cos(angle_x) + vertex->GetZ() * sin(angle_x));
    vertex->SetZ(-vertex->GetY() * sin(angle_x) +
                 vertex->GetZ() * cos(angle_x));
  }
  if (angle_y_ != 0) {
    vertex->SetX(vertex->GetX() * cos(angle_y) - vertex->GetZ() * sin(angle_y));
    vertex->SetZ(vertex->GetX() * sin(angle_y) + vertex->GetZ() * cos(angle_y));
  }
  if (angle_z_ != 0) {
    vertex->SetX(vertex->GetX() * cos(angle_z) + vertex->GetY() * sin(angle_z));
    vertex->SetY(-vertex->GetX() * sin(angle_z) +
                 vertex->GetY() * cos(angle_z));
  }
  if (scale_ > 1) {
    vertex->SetX(vertex->GetX() * scale_);
    vertex->SetY(vertex->GetY() * scale_);
    vertex->SetZ(vertex->GetZ() * scale_);
  }
  else if (scale_ < -1) {
      vertex->SetX(vertex->GetX() / -scale_);
      vertex->SetY(vertex->GetY() / -scale_);
      vertex->SetZ(vertex->GetZ() / -scale_);
}
}

void s21::AffineTransformations::TrasformateVectorOfVerteces(
    s21::Figure* figure_draw) {
  unsigned vector_size = figure_draw->GetVertexesVector().size();
  for (unsigned i = 0; i < vector_size; ++i) {
    s21::AffineTransformations::TrasformateVertex(
        &figure_draw->GetVertexesVectorRef()->at(i));
  }

  old_move_x_ = move_x_;
  old_move_y_ = move_y_;
  old_move_z_ = move_z_;
  old_angle_x_ = angle_x_;
  old_angle_y_ = angle_y_;
  old_angle_z_ = angle_z_;
  old_scale_ = scale_;

  //    std::vector<s21::Vertex>::iterator it;
  //    it = figure->GetVertexesVector().begin();
  //  //    unsigned vector_size = figure->GetVertexesVector().size();
  //      for (it; it != figure->GetVertexesVector().end(); ++it) {
  //          s21::AffineTransformations::TrasformateVertex(it.base());
  //      }
}

// void s21::AffineTransformations::Trasformate(s21::Figure *figure) {
//     s21::AffineTransformations::TrasformateVectorOfVerteces(&figure->GetVertexesVector());
// }
