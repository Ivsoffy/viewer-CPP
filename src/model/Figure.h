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

namespace s21 {

class Figure {
 public:
  class FileParser {
    public:
      FileParser(){};
      ~FileParser(){};

      void Parser(s21::Figure *figure, std::string file_name);

      // std::vector<double> PrepareVertecesToOGL(s21::Figure *figure);

    private:
      void ParsVLine(std::string strstr, s21::Figure *figure);
      void ParsFLine(std::string strstr, s21::Figure *figure);
    };

  Figure(){
    vertexes_.reserve(1000000);
    edges_.reserve(1000000);
  };
  ~Figure(){};

    void copy_figure(Figure *other) {
      this->SetVertexesVector(other->GetVertexesVector());
      this->SetEdgesVector(other->GetEdgesVector());
      // this->SetPoligonsSizesVector(other->GetPoligonsSizesVector());
    };

  std::vector<s21::Vertex> GetVertexesVector() { return vertexes_; };
  std::vector<s21::Vertex>* GetVertexesVectorRef() { return &vertexes_; };
  std::vector<double> GetDoubleVector();
  std::vector<unsigned> GetEdgesVector() { return edges_; };

  void SetVertexesVector(std::vector<s21::Vertex> vert) { vertexes_ = vert; };
  void SetEdgesVector(std::vector<unsigned> vect) { edges_ = vect; };

  double Get_Max() { return max_; };
  void Set_Max(double m) { max_ = m; };

  double GetX(int index) { return vertexes_[index].GetX(); };
  double GetY(int index) { return vertexes_[index].GetY(); };
  double GetZ(int index) { return vertexes_[index].GetZ(); };
  void SetX(double x, int index) { vertexes_[index].SetX(x); };
  void SetY(double y, int index) { vertexes_[index].SetY(y); };
  void SetZ(double z, int index) { vertexes_[index].SetZ(z); };

  void AddVertex(double x, double y, double z);
  void AddVertexToEdgesVector(unsigned num);
  void AddPolygonsSize(unsigned num);

 private:
  std::vector<s21::Vertex> vertexes_;
  std::vector<unsigned> edges_;
  double max_ = 0;
};

}  // namespace s21

#endif  // MODEL_FIGURE_H_
