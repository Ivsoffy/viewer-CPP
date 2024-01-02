#include "Figure.h"

void s21::Figure::AddVertex(double x, double y, double z) {
  s21::Vertex vertex(s21::Vertex(x, y, z));
  vertexes_.push_back(vertex);
}

void s21::Figure::AddVertexToEdgesVector(unsigned num) {
  edges_.push_back(num);
}

void s21::Figure::AddPolygonsSize(unsigned num) {
  polygons_sizes_.push_back(num);
}

std::vector<double> s21::Figure::GetDoubleVector() {
  std::vector<double> double_vector;
  for (size_t i = 0; i < vertexes_.size(); i++) {
    double_vector.push_back(vertexes_[i].GetX());
    double_vector.push_back(vertexes_[i].GetY());
    double_vector.push_back(vertexes_[i].GetZ());
  }
  return double_vector;
}
