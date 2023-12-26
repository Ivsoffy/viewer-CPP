#ifndef MODEL_FIGURE_H_
#define MODEL_FIGURE_H_

#include <vector>

#include "Vertex.h"

namespace s21 {

class Figure {
    public:
        Figure(){};
        ~Figure(){};
    private:
        std::vector<s21::Vertex> vertexes_;
        std::vector<int> edges_;
};

} //namespace s21

#endif //MODEL_FIGURE_H_
