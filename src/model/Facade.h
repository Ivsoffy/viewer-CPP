#ifndef MODEL_FACADE_H_
#define MODEL_FACADE_H_

#include "AffineTransformations.h"
#include "Figure.h"
#include "FileParser.h"
#include "Vertex.h"
#include "../controller/Controller.h"

namespace s21 {

class Facade {
    public:
        Facade(){};
        ~Facade(){};

        void SetPathToObject(std::string path);
        void SetAffineTransformations(Controller::ParamDTO paramDTO);
        // getBuffer

    private:
        AffineTransformations affineTransformations_;
        Figure figure_;
        FileParser fileParser_;
        Vertex vertex_;
        Controller controller_;

        void TrasformateFigure();
};

} //namespace s21

#endif //MODEL_FACADE_H_
