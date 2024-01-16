#ifndef MODEL_FIGURE_H_
#define MODEL_FIGURE_H_

#include <cmath>
#include <cstdio>
#include <vector>
#include <exception>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

#include "AffineTransformations.h"

namespace s21 {

class Vertex;

class Figure {
 public:
  class FileParser {
    public:
      FileParser(){};
      ~FileParser(){};

      void Parser(s21::Figure *figure, std::string file_name);

    private:
      void ParsVLine(std::string strstr, s21::Figure *figure);
      void ParsFLine(std::string strstr, s21::Figure *figure);
    };

  Figure(){
    vertices_.reserve(10000010);
    edges_.reserve(1000010);
  };
  ~Figure(){};

  void copy_figure(Figure *other) {
    this->SetVertexesVector(other->GetVerticesVector());
    this->SetEdgesVector(other->GetEdgesVector());
    this->Set_Max(other->Get_Max());
  };

  void TransformFigure(s21::Figure* figure_draw_) {
      unsigned vector_size =  this->GetVerticesVectorRef()->size();
      for (unsigned i = 0; i < vector_size; i++) {
        AffineTransformations::TrasformateVertex(&(this->GetVerticesVectorRef()->at(i)),
                                                &(figure_draw_->GetVerticesVectorRef()->at(i)));
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

  void AddVertex(double x, double y, double z);
  void AddVertexToEdgesVector(unsigned num);

 private:
  std::vector<s21::Vertex> vertices_{};
  std::vector<unsigned> edges_{};
  double max_ = 0;
};

}  // namespace s21

#endif  // MODEL_FIGURE_H_
