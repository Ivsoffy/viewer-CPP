#include "Figure.h"

void s21::Figure::AddVertex(double x, double y, double z) {
  s21::Vertex vertex(s21::Vertex(x, y, z));
  vertices_.push_back(vertex);
}

void s21::Figure::AddVertexToEdgesVector(unsigned num) {
  edges_.push_back(num);
}

void s21::Figure::TransformFigure() {
  unsigned vector_size =  vertices_.size();
  for (unsigned i = 0; i < vector_size; i++) {
    vertices_.at(i).TransformVertex();
  }
}

s21::Figure s21::Figure::TransformFigure2(s21::Figure figure) {
  unsigned vector_size =  vertices_.size();
  for (unsigned i = 0; i < vector_size; i++) {
    vertices_.at(i).TransformVertex();
  }
  return figure;
}
