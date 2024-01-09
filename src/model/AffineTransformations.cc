#include "AffineTransformations.h"

void s21::AffineTransformations::SetMoveX(double distance) {
  CleanData();
  move_x_ = distance;
}

void s21::AffineTransformations::SetMoveY(double distance) {
  CleanData();
  move_y_ = distance;
}

void s21::AffineTransformations::SetMoveZ(double distance) {
  CleanData();
  move_z_ = distance;
}

void s21::AffineTransformations::SetAngleX(double angle) { 
  CleanData();
  angle_x_ = angle - old_angle_x_;
  old_angle_x_ = angle;
}

void s21::AffineTransformations::SetAngleY(double angle) {
  CleanData();
  angle_y_ = angle;
}

void s21::AffineTransformations::SetAngleZ(double angle) {
  CleanData();
  angle_z_ = angle;
}

void s21::AffineTransformations::SetScale(double scale) {
  CleanData();
  scale_ = scale;
}

void s21::AffineTransformations::CleanData() {
  move_x_ = 0;
  move_y_ = 0;
  move_z_ = 0;
  angle_x_ = 0;
  angle_y_ = 0;
  angle_z_ = 0;
  scale_ = 1;
}

void s21::AffineTransformations::Trasformate(double *x_, double *y_, double *z_) {
  double angle_x = angle_x_ * M_PI / 180;
  double angle_y = angle_y_ * M_PI / 180;
  double angle_z = angle_z_ * M_PI / 180;

  if (move_x_ != 0) {
    *x_ = *x_ + move_x_;
  }
  if (move_y_ != 0) {
    *y_ = *y_ + move_y_;
  }
  if (move_z_ != 0) {
    *z_ = *z_ + move_z_;
  }

  if (angle_x_ != 0) {
    double y = *y_;
    double z = *z_;
    *y_ = (*y_ * cos(angle_x) - *z_ * sin(angle_x));
    *z_ = (y * sin(angle_x) + z * cos(angle_x));
  }
  if (angle_y_ != 0) {
    double x = *x_;
    double z = *z_;
    *x_ = (*x_ * cos(angle_y) + *z_ * sin(angle_y));
    *z_ = (x * -sin(angle_y) + z * cos(angle_y));
  }
  if (angle_z_ != 0) {
    double x = *x_;
    double y = *y_;
    *x_ = (*x_ * cos(angle_z) - *y_ * sin(angle_z));
    *y_ = (x * sin(angle_z) + y * cos(angle_z));
  }

  if (scale_ != 1) {
    *x_ = (*x_ * scale_);
    *y_ = (*y_ * scale_);
    *z_ = (*z_ * scale_);
  }
}

// void s21::AffineTransformations::TrasformateVectorOfVerteces(
//     s21::Figure* figure_draw) {
//   unsigned vector_size = figure_draw->GetVertexesVector().size();
//   for (unsigned i = 0; i < vector_size; ++i) {
//     s21::AffineTransformations::TrasformateVertex(&figure_draw->GetVertexesVectorRef()->at(i));
//   }

//   old_move_x_ = move_x_;
//   old_move_y_ = move_y_;
//   old_move_z_ = move_z_;
//   old_angle_x_ = angle_x_;
//   old_angle_y_ = angle_y_;
//   old_angle_z_ = angle_z_;
//   old_scale_ = scale_;
// }

// void s21::AffineTransformations::TrasformateVertex(s21::Vertex* vertex) {
//   double angle_x = angle_x_ * M_PI / 180;
//   double angle_y = angle_y_ * M_PI / 180;
//   double angle_z = angle_z_ * M_PI / 180;

//   if (move_x_ != 0) {
//     vertex->SetX(vertex->GetX() + move_x_);
//   }
//   if (move_y_ != 0) {
//     vertex->SetY(vertex->GetY() + move_y_);
//   }
//   if (move_z_ != 0) {
//     vertex->SetZ(vertex->GetZ() + move_z_);
//   }

//   // if (angle_x_ != 0) {
//   //   vertex->SetY(y * cos(angle_x) - z * sin(angle_x));
//   //   vertex->SetZ(y * sin(angle_x) + z * cos(angle_x));
//   // }
//   // if (angle_y_ != 0) {
//   //   vertex->SetX(x * cos(angle_y) + z * sin(angle_y));
//   //   vertex->SetZ(x * -sin(angle_y) + z * cos(angle_y));
//   // }
//   // if (angle_z_ != 0) {
//   //   vertex->SetX(x * cos(angle_z) - y * sin(angle_z));
//   //   vertex->SetY(x * sin(angle_z) + y * cos(angle_z));
//   // }
//   // if (angle_x_ != 0) {
//   //   vertex->SetY(vertex->GetY() * cos(angle_x) - vertex->GetZ() * sin(angle_x));
//   //   vertex->SetZ(vertex->GetY() * sin(angle_x) + vertex->GetZ() * cos(angle_x));
//   // }
//   // if (angle_y_ != 0) {
//   //   vertex->SetX(vertex->GetX() * cos(angle_y) + vertex->GetZ() * sin(angle_y));
//   //   vertex->SetZ(vertex->GetX() * -sin(angle_y) + vertex->GetZ() * cos(angle_y));
//   // }
//   // if (angle_z_ != 0) {
//   //   vertex->SetX(vertex->GetX() * cos(angle_z) - vertex->GetY() * sin(angle_z));
//   //   vertex->SetY(vertex->GetX() * sin(angle_z) + vertex->GetY() * cos(angle_z));
//   // }
//   if (angle_x_ != 0) {
//     double y = vertex->GetY();
//     double z = vertex->GetZ();
//     vertex->SetY(vertex->GetY() * cos(angle_x) - vertex->GetZ() * sin(angle_x));
//     vertex->SetZ(y * sin(angle_x) + z * cos(angle_x));
//   }
//   if (angle_y_ != 0) {
//     double x = vertex->GetX();
//     double z = vertex->GetZ();
//     vertex->SetX(vertex->GetX() * cos(angle_y) + vertex->GetZ() * sin(angle_y));
//     vertex->SetZ(x * -sin(angle_y) + z * cos(angle_y));
//   }
//   if (angle_z_ != 0) {
//     double x = vertex->GetX();
//     double y = vertex->GetY();
//     vertex->SetX(vertex->GetX() * cos(angle_z) - vertex->GetY() * sin(angle_z));
//     vertex->SetY(x * sin(angle_z) + y * cos(angle_z));
//   }

//   if (scale_ != 1) {
//     vertex->SetX(vertex->GetX() * scale_);
//     vertex->SetY(vertex->GetY() * scale_);
//     vertex->SetZ(vertex->GetZ() * scale_);
//   }
// }

// void s21::AffineTransformations::TrasformateVectorOfVerteces(
//     s21::Figure* figure_draw) {
//   unsigned vector_size = figure_draw->GetVertexesVector().size();
//   for (unsigned i = 0; i < vector_size; ++i) {
//     s21::AffineTransformations::TrasformateVertex(
//         &figure_draw->GetVertexesVectorRef()->at(i));
//   }

//   old_move_x_ = move_x_;
//   old_move_y_ = move_y_;
//   old_move_z_ = move_z_;
//   old_angle_x_ = angle_x_;
//   old_angle_y_ = angle_y_;
//   old_angle_z_ = angle_z_;
//   old_scale_ = scale_;
// }
