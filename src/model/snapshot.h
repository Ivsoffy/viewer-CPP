#ifndef MODEL_SNAPSHOT_H_
#define MODEL_SNAPSHOT_H_

#include "figure.h"
#include "../dto/dto.h"
#include <iostream>////////////////////

namespace s21 {

class Snapshot {
public:
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
                figure_def_ = *figure_def;
                figure_draw_ = *figure_draw;
    };
    ~Snapshot(){};
    void Restore(Figure *figure_def, Figure *figure_draw, ParamDTO *dto) {
        std::cerr << "===Restore===" << std::endl;/////////////////////
        *dto = *dto_old_;
        figure_def = &figure_def_;
        figure_draw = &figure_draw_;
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
