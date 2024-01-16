#ifndef MODEL_SNAPSHOT_H_
#define MODEL_SNAPSHOT_H_

#include "figure.h"
#include <iostream>////////////////////

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
            {
                std::cerr << "===Snapshot===" << std::endl;/////////////////////
                figure_def_.CopyFigure(figure_def);
                figure_draw_.CopyFigure(figure_draw);
                // ////////////////////////////////////////////////////////////////////////////////////////
                 std::cerr << std::endl;/////////////////////
                 for (unsigned i = 0; i < figure_draw_.GetVerticesVectorRef()->size(); ++i) {
                   std::cerr << figure_draw_.GetVerticesVectorRef()->at(i).GetX() << " "
                             << figure_draw_.GetVerticesVectorRef()->at(i).GetY() << " "
                             << figure_draw_.GetVerticesVectorRef()->at(i).GetZ() << std::endl;/////////////////////
                 }
                 std::cerr << std::endl;/////////////////////
                // //////////////////////////////////////////////////////////////////////////////////////

    };
    ~Snapshot(){};
    void Restore(Figure *figure_def, Figure *figure_draw) {
        std::cerr << "===Restore===" << std::endl;/////////////////////
        figure_def->CopyFigure(&figure_def_);
        figure_draw->CopyFigure(&figure_draw_);
        // ////////////////////////////////////////////////////////////////////////////////////////
         std::cerr << std::endl;/////////////////////
         for (unsigned i = 0; i < figure_draw_.GetVerticesVectorRef()->size(); ++i) {
           std::cerr << figure_draw_.GetVerticesVectorRef()->at(i).GetX() << " "
                     << figure_draw_.GetVerticesVectorRef()->at(i).GetY() << " "
                     << figure_draw_.GetVerticesVectorRef()->at(i).GetZ() << std::endl;/////////////////////
         }
         std::cerr << std::endl;/////////////////////
        // //////////////////////////////////////////////////////////////////////////////////////
        // figure_draw_ = new Figure();
        // figure_draw_->CopyFigure(figure_def_);
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
