#ifndef MODEL_FIGURE_H_
#define MODEL_FIGURE_H_

#include <cmath>
#include <cstdio>
#include <exception>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "affine_transformations.h"

namespace s21 {

class Vertex;

class Figure {
 public:
  class FileParser {
   public:
    FileParser(){};
    ~FileParser(){};

    /// @brief Reads the file line by line
    /// @param figure Referrence to a figure in which the collected values will be written
    /// @param file_name Name of the file to open
    void Parser(s21::Figure* figure, std::string file_name);

   private:
    /// @brief Parsing a string with vertex coordinates
    /// @param strstr Line read from the file
    /// @param figure Referrence to a figure in which the collected values will be written
    void ParsVLine(std::string strstr, s21::Figure* figure);
    
    /// @brief Parsing strings with polygon descriptions
    /// @param strstr Line read from the file
    /// @param figure Referrence to a figure in which the collected values will be written
    void ParsFLine(std::string strstr, s21::Figure* figure);
  };

  Figure() {
    vertices_.reserve(10000000);
    edges_.reserve(1000000);
  };
  ~Figure(){};

 Figure& operator=(const Figure& figure) {
   if (&figure != this) {
     vertices_ = figure.vertices_;
     edges_ = figure.edges_;
     max_ = figure.max_;
   }
   return *this;
 }

  /// @brief Apply affine transformations to all vertices of the figureJ
  /// @param figure_draw_ Referrence to a figure
  void TransformFigure(s21::Figure* figure_draw_) {
    unsigned vector_size = this->GetVerticesVectorRef()->size();
    for (unsigned i = 0; i < vector_size; i++) {
        AffineTransformations::TrasformateVertex(&(figure_draw_->GetVerticesVectorRef()->at(i)));
    }
  };

  std::vector<s21::Vertex> GetVerticesVector() { return vertices_; };
  std::vector<s21::Vertex>* GetVerticesVectorRef() { return &vertices_; };
  std::vector<unsigned> GetEdgesVector() { return edges_; };
  std::vector<unsigned>* GetEdgesVectorRef() { return &edges_; };

  void SetVertexesVector(std::vector<s21::Vertex> vert) { vertices_ = vert; };
  void SetEdgesVector(std::vector<unsigned> edge) { edges_ = edge; };

  double Get_Max() { return max_; };
  void Set_Max(double m) { max_ = m; };

  double GetX(int index) { return vertices_[index].GetX(); };
  double GetY(int index) { return vertices_[index].GetY(); };
  double GetZ(int index) { return vertices_[index].GetZ(); };
  void SetX(double x, int index) { vertices_[index].SetX(x); };
  void SetY(double y, int index) { vertices_[index].SetY(y); };
  void SetZ(double z, int index) { vertices_[index].SetZ(z); };

  /// @brief Creating and adding a vertex to a vertex array
  void AddVertex(double x, double y, double z);

  /// @brief Adding a vertex number to a edges array
  /// @param num vertex number
  void AddVertexToEdgesVector(unsigned num);

 private:
  std::vector<s21::Vertex> vertices_{};

  /// @brief Array of vertex numbers. The vertices are connected in two and form a face
  std::vector<unsigned> edges_{};

  /// @brief Overall size of the figure
  double max_ = 0;
};

}  // namespace s21

#endif  // MODEL_FIGURE_H_
