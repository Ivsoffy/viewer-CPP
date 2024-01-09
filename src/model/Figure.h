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

#include "Vertex.h"
//#include "AffineTransformations.h"

namespace s21 {

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
    vertices_.reserve(1000000);
    edges_.reserve(1000000);
  };
  ~Figure(){};

  void copy_figure(Figure *other) {
    this->SetVertexesVector(other->GetVertexesVector());
    this->SetEdgesVector(other->GetEdgesVector());
    // this->SetPoligonsSizesVector(other->GetPoligonsSizesVector());
  };

  void TransformFigure();//////////////////
  s21::Figure TransformFigure2(s21::Figure figure);//////////////////

  std::vector<s21::Vertex> GetVertexesVector() { return vertices_; };
  std::vector<s21::Vertex>* GetVertexesVectorRef() { return &vertices_; };
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
  void AddPolygonsSize(unsigned num);

 private:
  std::vector<s21::Vertex> vertices_{};
  std::vector<unsigned> edges_{};
  double max_ = 0;
};

}  // namespace s21

#endif  // MODEL_FIGURE_H_
