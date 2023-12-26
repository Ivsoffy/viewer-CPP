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
        std::vector<unsigned> GetEges() {return edge_;};
        std::vector<unsigned> GetPoligonsVector() {return polygon_sizes_;};

        double GetX(int index) {return vertexes_[index].GetX();};
        double GetY(int index) {return vertexes_[index].GetY();};
        double GetZ(int index) {return vertexes_[index].GetZ();};
        void SetX(double x, int index) {vertexes_[index].SetX(x);};
        void SetY(double y, int index) {vertexes_[index].SetY(y);};
        void SetZ(double z, int index) {vertexes_[index].SetZ(z);};

        void AddVertex(double x, double y, double z);
        void AddEdge(unsigned a, unsigned b);
        void AddPolygonsSize(unsigned num);
        void MutateFigure();

    private:
        std::vector<s21::Vertex> vertexes_;
        std::vector<unsigned> edge_;
        std::vector<unsigned> polygon_sizes_; //сколько взять вершин из edge_ для одного полигона
};

} //namespace s21

#endif //MODEL_FIGURE_H_
