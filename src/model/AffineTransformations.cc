#include "AffineTransformations.h"

#include <iostream>////////////////////////////TODO

void s21::AffineTransformations::SetMoveX(double value) {
  CleanData();
  move_x_ = value - old_move_x_;
  old_move_x_ = value;
  // move_x_ = value;
}

void s21::AffineTransformations::SetMoveY(double value) {
  CleanData();
  move_y_ = value - old_move_y_;
  old_move_y_ = value;
  // move_y_ = value;
}

void s21::AffineTransformations::SetMoveZ(double value) {
  CleanData();
  move_z_ = value - old_move_z_;
  old_move_z_ = value;
  // move_z_ = value;
}

void s21::AffineTransformations::SetAngleX(double angle) { 
  CleanData();
  angle_x_ = angle - old_angle_x_;
  old_angle_x_ = angle;
  // angle_x_ = angle;
}

void s21::AffineTransformations::SetAngleY(double angle) {
  CleanData();
  angle_y_ = angle - old_angle_y_;
  old_angle_y_ = angle;
  // angle_y_ = angle;
}

void s21::AffineTransformations::SetAngleZ(double angle) {
  CleanData();
  angle_z_ = angle - old_angle_z_;
  old_angle_z_ = angle;
  // angle_z_ = angle;
}

void s21::AffineTransformations::SetScale(double scale) {
  CleanData();
  // std::cerr << std::endl;/////////////////////TODO
  // std::cerr << "scale= " << scale << std::endl;/////////////////////TODO
  // std::cerr <<"old_scale_= " << old_scale_ << std::endl;/////////////////////TODO

  // std::cerr << "(double)(scale - old_scale_) / 100.0= " << (double)(scale - old_scale_) / 100.0 << std::endl;/////////////////////TODO
  // scale_ = scale - old_scale_;
  scale_ = pow(5, (double)(scale - old_scale_) / 100.0);
  old_scale_ = scale;

  // std::cerr << "scale_= " << scale_ << std::endl;/////////////////////TODO
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
    // double real_scale = (scale_ + 1000000) / 1000000.0;
    double real_scale = scale_;
    // std::cerr << "real_scale= " << real_scale << std::endl;/////////////////////TODO
    vertex_draw->SetX(vertex_draw->GetX() * real_scale);
    vertex_draw->SetY(vertex_draw->GetY() * real_scale);
    vertex_draw->SetZ(vertex_draw->GetZ() * real_scale);
  }


  //2
  // if (scale_ != 0 ) {
  //   double real_scale = (scale_ + 1000) / 1000.0;
  //   std::cerr << "real_scale= " << real_scale << std::endl;/////////////////////TODO
  //   vertex_draw->SetX(vertex_draw->GetX() * real_scale);
  //   vertex_draw->SetY(vertex_draw->GetY() * real_scale);
  //   vertex_draw->SetZ(vertex_draw->GetZ() * real_scale);
  // }



  //old 1
  // if (scale_ != 0 ) {
  //   // int scale_temp = 0;
  //   // if (scale_ < 0) {
  //   //   scale_temp = -1 / scale_; 
  //   // } else {
  //   //   scale_temp = scale_ + 1;
  //   // }
  //   std::cerr << "scale_temp= " << scale_temp << std::endl;/////////////////////TODO
  //   vertex_draw->SetX(vertex_draw->GetX() * scale_temp);
  //   vertex_draw->SetY(vertex_draw->GetY() * scale_temp);
  //   vertex_draw->SetZ(vertex_draw->GetZ() * scale_temp);
  // }







  ///last version slow
  // double angle_x = angle_x_ * M_PI / 180;
  // double angle_y = angle_y_ * M_PI / 180;
  // double angle_z = angle_z_ * M_PI / 180;

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
  //   vertex_draw->SetX(vertex_draw->GetX() * scale_ / 100);
  //   vertex_draw->SetY(vertex_draw->GetY() * scale_ / 100);
  //   vertex_draw->SetZ(vertex_draw->GetZ() * scale_ / 100);
  // }


  /////old version
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


}
