#include "figure.h"

void s21::Figure::AddVertex(double x, double y, double z) {
  s21::Vertex vertex(s21::Vertex(x, y, z));
  vertices_.push_back(vertex);
}

void s21::Figure::AddVertexToEdgesVector(unsigned num) {
  edges_.push_back(num);
}

void s21::Figure::copy_figure(Figure *other) {
  this->SetVertexesVector(other->GetVerticesVector());
  this->SetEdgesVector(other->GetEdgesVector());
  this->Set_Max(other->Get_Max());
};
