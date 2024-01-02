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

void s21::AffineTransformations::SetAngleX(double angle) {
    angle_x_ = angle;
}

void s21::AffineTransformations::SetAngleY(double angle) {
    angle_y_ = angle;
}

void s21::AffineTransformations::SetAngleZ(double angle) {
    angle_z_ = angle;
}

void s21::AffineTransformations::SetScale(int scale) {
    scale_ = scale;
}

void s21::AffineTransformations::TrasformateVertex(s21::Vertex* vertex) {
    double x = vertex->GetX();
    double y = vertex->GetY();
    double z = vertex->GetZ();
    double angle_x = angle_x_ * M_PI / 180;
    double angle_y = angle_y_ * M_PI / 180;
    double angle_z = angle_z_ * M_PI / 180;
    if (move_x_ != 0) {
        vertex->SetX(x + move_x_);
    }
    if (move_y_ != 0) {
        vertex->SetY(y + move_y_);
    }
    if (move_z_ != 0) {
        vertex->SetZ(z + move_z_);
    }

    if (angle_x_ != 0) {
        vertex->SetY(y * cos(angle_x) + z * sin(angle_x));
        vertex->SetZ(-y * sin(angle_x) + z * cos(angle_x));
    }
    if (angle_y_ != 0) {
        vertex->SetX(x * cos(angle_y) - z * sin(angle_y));
        vertex->SetZ(x * sin(angle_y) + z * cos(angle_y));
    }
    if (angle_z_ != 0) {
        vertex->SetX(x * cos(angle_z) + y * sin(angle_z));
        vertex->SetY(-x * sin(angle_z) + y * cos(angle_z));
    }
    if (scale_ != 0) {
        vertex->SetX(x * scale_);
        vertex->SetY(y * scale_);
        vertex->SetZ(z * scale_);
    }
}

void s21::AffineTransformations::TrasformateVectorOfVerteces(s21::Figure *figure) {
    unsigned vector_size = figure->GetVertexesVector().size();
    for (unsigned i = 0; i < vector_size; ++i) {
        s21::AffineTransformations::TrasformateVertex(&figure->GetVertexesVector().at(i));
    }
}

//void s21::AffineTransformations::Trasformate(s21::Figure *figure) {
//    s21::AffineTransformations::TrasformateVectorOfVerteces(&figure->GetVertexesVector());
//}
