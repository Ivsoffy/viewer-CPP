#include "Figure.h"

void s21::Figure::AddVertex(double x, double y, double z) {
    s21::Vertex vertex(s21::Vertex(x, y, z));
    vertexes_.push_back(vertex);
}

void s21::Figure::AddVertexToEdgesVector(unsigned num) {
    edges_.push_back(num);
}

void s21::Figure::AddPolygonsSize(unsigned num) {
    polygon_sizes_.push_back(num);
}

void s21::Figure::MutateFigure() {
    // for (auto vertex : vertexes_) {
    //     vertex.
    // }
}
