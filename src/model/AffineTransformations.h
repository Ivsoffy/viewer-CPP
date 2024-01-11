#ifndef MODEL_AFFINETRANSFORMATIONS_H_
#define MODEL_AFFINETRANSFORMATIONS_H_

#include <cmath>
#include <vector>
#include "Vertex.h"

namespace s21 {

//class Vertex;

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
        void SetScale(double scale);

        static void TrasformateVertex(s21::Vertex *vertex_def, s21::Vertex *vertex_draw);
        // static void Trasformate(double *x_, double *y_, double *z_, Figure *figure_draw_);
        // void TrasformateVectorOfVerteces(s21::Figure *figure_draw);
        // void CleanData();
        
    private:
        static inline double move_x_{};
        static inline double move_y_{};
        static inline double move_z_{};
        static inline double angle_x_{};
        static inline double angle_y_{};
        static inline double angle_z_{};
        static inline double scale_{};

        static inline double old_move_x_{};
        static inline double old_move_y_{};
        static inline double old_move_z_{};
        static inline double old_angle_x_{};
        static inline double old_angle_y_{};
        static inline double old_angle_z_{};
        static inline double old_scale_{};
};

} //namespace s21

#endif //MODEL_AFFINETRANSFORMATIONS_H_
