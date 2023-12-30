#ifndef MODEL_FACADE_H_
#define MODEL_FACADE_H_

#include "AffineTransformations.h"
#include "Figure.h"
#include "FileParser.h"
#include "Vertex.h"

namespace s21 {

class Facade {
    public:
        // Facade(AffineTransformations affineTransformations, 
        //         Figure figure, 
        //         FileParser fileParser, 
        //         Vertex vertex) {

        Facade(){};
        ~Facade(){};

        // std::vector<s21::Vertex> GetVertex() {return vertex_;};
        // void SetX_Max(double x) {x_max_ = x;};

        // std::vector<s21::Vertex> GetFigure_() {return figure_;};

        void SetAffineTransformations(AffineTransformations aff_tran);
        void SetPathToObject(std::string path);

        void TrasformateFigure();

    private:
        AffineTransformations affineTransformations_;
        Figure figure_;
        FileParser fileParser_;
        Vertex vertex_;

};

} //namespace s21

#endif //MODEL_FACADE_H_
