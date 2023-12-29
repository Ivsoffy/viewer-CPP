#ifndef MODEL_FIGURE_H_
#define MODEL_FIGURE_H_

#include <vector>
#include <cmath>
#include <cstdio>

#include "Vertex.h"

namespace s21 {

class Figure {
    public:
        Figure(){};
        ~Figure(){};

        std::vector<s21::Vertex> GetVertexesVector() {return vertexes_;};
        std::vector<unsigned> GetEdgesVector() {return edges_;};
        std::vector<unsigned> GetPoligonsSizesVector() {return polygons_sizes_;};
        double GetX_Max() {return x_max_;};
        double GetY_Max() {return y_max_;};
        double GetZ_Max() {return z_max_;};
        double Get_Max() {return z_max_;};
        void SetX_Max(double x) {x_max_ = x;};
        void SetY_Max(double y) {y_max_ = y;};
        void SetZ_Max(double z) {z_max_ = z;};
        void Set_Max(double z) {z_max_ = z;};

        double GetX(int index) {return vertexes_[index].GetX();};
        double GetY(int index) {return vertexes_[index].GetY();};
        double GetZ(int index) {return vertexes_[index].GetZ();};
        void SetX(double x, int index) {vertexes_[index].SetX(x);};
        void SetY(double y, int index) {vertexes_[index].SetY(y);};
        void SetZ(double z, int index) {vertexes_[index].SetZ(z);};

        void AddVertex(double x, double y, double z);
        void AddVertexToEdgesVector(unsigned num);
        void AddPolygonsSize(unsigned num);

    private:
        std::vector<s21::Vertex> vertexes_;
        std::vector<unsigned> edges_;
        std::vector<unsigned> polygons_sizes_; //сколько взять вершин из edges_ для одного полигона
        double x_max_, y_max_, z_max_;
        double max_;
};

} //namespace s21

#endif //MODEL_FIGURE_H_
