#ifndef MODEL_SNAPSHOT_H_
#define MODEL_SNAPSHOT_H_

#include "figure.h"
#include "../dto/dto.h"
#include "affine_transformations.h"
#include <iostream>////////////////////

namespace s21 {

class Snapshot {
public:
    Snapshot& operator=(const Snapshot& snapshot) {
        if(&snapshot != this) {
            dto_old_ = snapshot.dto_old_;
        }
        return *this;
    }

    Snapshot(s21::Figure *figure_def, s21::Figure *figure_draw, s21::ParamDTO *dto) {
        std::cerr << "===Snapshot===" << std::endl;/////////////////////
        dto_old_ = s21::AffineTransformations::GetOldFielde();
        dto_ptr_ = dto;
        figure_def_ = *figure_def;
        figure_draw_ = *figure_draw;
    };
    ~Snapshot(){};
    void Restore(Figure *figure_def, Figure *figure_draw) {
        std::cerr << "===Restore===" << std::endl;/////////////////////
        *dto_ptr_ = dto_old_;
        *figure_def = figure_def_;
        *figure_draw = figure_draw_;
    };

private:
    s21::Figure figure_def_;
    s21::Figure figure_draw_;
    s21::ParamDTO dto_old_;
    s21::ParamDTO *dto_ptr_;
};

}  // namespace s21

#endif  // MODEL_SNAPSHOT_H_
