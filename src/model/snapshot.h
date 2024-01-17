#ifndef MODEL_SNAPSHOT_H_
#define MODEL_SNAPSHOT_H_

#include "figure.h"
#include "../controller/controller_dto.h"
#include <iostream>////////////////////

namespace s21 {

class Snapshot {
public:
//    Snapshot(s21::Figure *figure_def,
//            s21::Figure *figure_draw,
//            double move_x,
//            double move_y,
//            double move_z,
//            double angle_x,
//            double angle_y,
//            double angle_z,
//            double scale)
//            :
//            move_x_(move_x),
//            move_y_(move_y),
//            move_z_(move_z),
//            angle_x_(angle_x),
//            angle_y_(angle_y),
//            angle_z_(angle_z),
//            scale_(scale)
//            {
    Snapshot(s21::Figure *figure_def,
            s21::Figure *figure_draw,
            s21::ParamDTO *dto)
            :
            move_x_(dto->move_x_),
            move_y_(dto->move_y_),
            move_z_(dto->move_z_),
            angle_x_(dto->angle_x_),
            angle_y_(dto->angle_y_),
            angle_z_(dto->angle_z_),
            scale_(dto->scale_)
            {
                std::cerr << "===Snapshot===" << std::endl;/////////////////////
                dto_old_ = dto;
                figure_def_.CopyFigure(figure_def);
                figure_draw_.CopyFigure(figure_draw);
                // ////////////////////////////////////////////////////////////////////////////////////////
//                 std::cerr << std::endl;/////////////////////
//                 for (unsigned i = 0; i < figure_draw_.GetVerticesVectorRef()->size(); ++i) {
//                   std::cerr << figure_draw_.GetVerticesVectorRef()->at(i).GetX() << " "
//                             << figure_draw_.GetVerticesVectorRef()->at(i).GetY() << " "
//                             << figure_draw_.GetVerticesVectorRef()->at(i).GetZ() << std::endl;/////////////////////
//                 }
//                 std::cerr << std::endl;/////////////////////
                // //////////////////////////////////////////////////////////////////////////////////////

    };
    ~Snapshot(){};
    void Restore(Figure *figure_def, Figure *figure_draw, ParamDTO *dto) {
        std::cerr << "===Restore===" << std::endl;/////////////////////
        *dto = *dto_old_;
        figure_def->CopyFigure(&figure_def_);
        figure_draw->CopyFigure(&figure_draw_);
        // ////////////////////////////////////////////////////////////////////////////////////////
//         std::cerr << std::endl;/////////////////////
//         for (unsigned i = 0; i < figure_draw_.GetVerticesVectorRef()->size(); ++i) {
//           std::cerr << figure_draw_.GetVerticesVectorRef()->at(i).GetX() << " "
//                     << figure_draw_.GetVerticesVectorRef()->at(i).GetY() << " "
//                     << figure_draw_.GetVerticesVectorRef()->at(i).GetZ() << std::endl;/////////////////////
//         }
//         std::cerr << std::endl;/////////////////////
        // //////////////////////////////////////////////////////////////////////////////////////
    };

    Snapshot& operator=(const Snapshot& snapshot) {
        if(&snapshot != this) {
            move_x_ = snapshot.move_x_;
            move_y_ = snapshot.move_y_;
            move_z_ = snapshot.move_z_;
            angle_x_ = snapshot.angle_x_;
            angle_y_ = snapshot.angle_y_;
            angle_z_ = snapshot.angle_z_;
            scale_ = snapshot.scale_;
            dto_old_ = snapshot.dto_old_;
        }
        return *this;
    }

private:
    s21::Figure figure_def_;
    s21::Figure figure_draw_;
    s21::ParamDTO *dto_old_;
//    s21::ParamDTO *dto_current_;
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
