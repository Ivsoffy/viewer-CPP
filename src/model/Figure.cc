#include "Figure.h"

void s21::Figure::AddVertex(double x, double y, double z) {
    s21::Vertex vertex(s21::Vertex(x, y, z));
    vertexes_.push_back(vertex);
}

void s21::Figure::AddEdge(unsigned a, unsigned b) {
    edge_.push_back(a);
    edge_.push_back(b);
}

void s21::Figure::AddPolygons(unsigned num) {
    polygons_.push_back(num);
}
