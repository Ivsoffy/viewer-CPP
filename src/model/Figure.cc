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

// std::vector<double> s21::Figure::PrepareVertecesToOGL(s21::Figure *figure) {
//     std::vector<double> result;
//     std::vector<s21::Vertex> vertexes_vector = figure->GetVertexesVector();
//     unsigned vector_size = vertexes_vector.size();
//     for (unsigned i = 0; i < vector_size; ++i) {
//         result.push_back(vertexes_vector[i].GetX());
//         result.push_back(vertexes_vector[i].GetY());
//         result.push_back(vertexes_vector[i].GetZ());
//     }
//     return result;
// }
