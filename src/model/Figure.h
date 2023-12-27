#ifndef MODEL_FIGURE_H_
#define MODEL_FIGURE_H_

#include <vector>

#include "Vertex.h"

namespace s21 {

class Figure {
    public:
        Figure(){};
        ~Figure(){};

        std::vector<s21::Vertex> GetVertexesVector() {return vertexes_;};
        std::vector<unsigned> GetEdgesVector() {return edges_;};
        std::vector<unsigned> GetPoligonsSizesVector() {return polygon_sizes_;};

        double GetX(int index) {return vertexes_[index].GetX();};
        double GetY(int index) {return vertexes_[index].GetY();};
        double GetZ(int index) {return vertexes_[index].GetZ();};
        void SetX(double x, int index) {vertexes_[index].SetX(x);};
        void SetY(double y, int index) {vertexes_[index].SetY(y);};
        void SetZ(double z, int index) {vertexes_[index].SetZ(z);};

        void AddVertex(double x, double y, double z);
        void AddVertexToEdgesVector(unsigned num);
        void AddPolygonsSize(unsigned num);
        void MutateFigure();

    private:
        std::vector<s21::Vertex> vertexes_;
        std::vector<unsigned> edges_;
        std::vector<unsigned> polygon_sizes_; //сколько взять вершин из edges_ для одного полигона
};

} //namespace s21

#endif //MODEL_FIGURE_H_
