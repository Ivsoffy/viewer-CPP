#ifndef MODEL_AFFINETRANSFORMATIONS_H_
#define MODEL_AFFINETRANSFORMATIONS_H_

#include <cmath>
#include <iostream>///////////////////////////////////////////////////

#include "Vertex.h"

namespace s21 {

    class Vertex;

class AffineTransformations {

    public:
        AffineTransformations(){};
        ~AffineTransformations(){};

        void SetMoveX(double distance);
        void SetMoveY(double distance);
        void SetMoveZ(double distance);
        void SetAngleX(double angle);
        void SetAngleY(double angle);
        void SetAngleZ(double angle);
        void SetScale(int scale);

        void Trasformate(s21::Vertex *vertex);
        
    private:
        double move_x_{};
        double move_y_{};
        double move_z_{};
        double angle_x_{};
        double angle_y_{};
        double angle_z_{};
        double scale_{};
};

} //namespace s21

#endif //MODEL_AFFINETRANSFORMATIONS_H_