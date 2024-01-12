#ifndef MODEL_AFFINETRANSFORMATIONS_H_
#define MODEL_AFFINETRANSFORMATIONS_H_

#include <cmath>
#include <vector>
#include "Vertex.h"

namespace s21 {

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
        void CleanData();
        
    private:
        static inline double move_x_{0};
        static inline double move_y_{0};
        static inline double move_z_{0};
        static inline double angle_x_{0};
        static inline double angle_y_{0};
        static inline double angle_z_{0};
        static inline double scale_{0};

        static inline double old_move_x_{0};
        static inline double old_move_y_{0};
        static inline double old_move_z_{0};
        static inline double old_angle_x_{0};
        static inline double old_angle_y_{0};
        static inline double old_angle_z_{0};
        static inline double old_scale_{0};
};

} //namespace s21

#endif //MODEL_AFFINETRANSFORMATIONS_H_
