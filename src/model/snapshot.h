#ifndef MODEL_SNAPSHOT_H_
#define MODEL_SNAPSHOT_H_

#include "figure.h"
#include "../dto/dto.h"
#include "affine_transformations.h"

namespace s21 {

class Snapshot {
public:
    Snapshot& operator=(const Snapshot& snapshot) {
        if(&snapshot != this) {
            figure_def_ = snapshot.figure_def_;
            figure_draw_ = snapshot.figure_draw_;
            dto_old_for_view_ = snapshot.dto_old_for_view_;
            dto_old_for_afffin_tran_ = snapshot.dto_old_for_afffin_tran_;
            dto_ptr_ = snapshot.dto_ptr_;
        }
        return *this;
    }

    Snapshot(s21::Figure *figure_def, s21::Figure *figure_draw, s21::ParamDTO *dto) {
        dto_old_for_afffin_tran_ = s21::AffineTransformations::GetOldFielde();
        dto_old_for_view_ = *dto;
        dto_ptr_ = dto;
        figure_def_ = *figure_def;
        figure_draw_ = *figure_draw;
    };
    ~Snapshot(){};
    void Restore(Figure *figure_def, Figure *figure_draw) {
        s21::AffineTransformations::SetOldFielde(dto_old_for_afffin_tran_);
        *dto_ptr_ = dto_old_for_view_;
        *figure_def = figure_def_;
        *figure_draw = figure_draw_;
    };

private:
    s21::Figure figure_def_;
    s21::Figure figure_draw_;
    s21::ParamDTO dto_old_for_afffin_tran_;
    s21::ParamDTO dto_old_for_view_;
    s21::ParamDTO *dto_ptr_;
};

}  // namespace s21

#endif  // MODEL_SNAPSHOT_H_
