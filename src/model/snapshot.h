#ifndef MODEL_SNAPSHOT_H_
#define MODEL_SNAPSHOT_H_

#include "figure.h"

namespace s21 {

class Snapshot {
public:
    Snapshot(s21::Figure *figure_def,
            s21::Figure *figure_draw,
            double move_x,
            double move_y,
            double move_z,
            double angle_x,
            double angle_y,
            double angle_z,
            double scale)
            :
            move_x_(move_x),
            move_y_(move_y),
            move_z_(move_z),
            angle_x_(angle_x),
            angle_y_(angle_y),
            angle_z_(angle_z),
            scale_(scale)
            { figure_def_.CopyFigure(figure_def);
              figure_draw_.CopyFigure(figure_draw); };
    ~Snapshot(){};
    void Restore(Figure *figure_def, Figure *figure_draw) {
        figure_def->CopyFigure(&figure_def_);
        figure_draw->CopyFigure(&figure_draw_);
    };

private:
    s21::Figure figure_def_;
    s21::Figure figure_draw_;
    double move_x_{0};
    double move_y_{0};
    double move_z_{0};
    double angle_x_{0};
    double angle_y_{0};
    double angle_z_{0};
    double scale_{0};
};

}  // namespace s21

#endif  // MODEL_SNAPSHOT_H_
