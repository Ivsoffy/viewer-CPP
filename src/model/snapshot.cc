#include "snapshot.h"

s21::Snapshot::Snapshot(s21::Figure *figure_def, s21::Figure *figure_draw,
                        s21::ParamDTO *dto) {
  dto_old_for_afffin_tran_ = s21::AffineTransformations::GetOldFielde();
  dto_old_for_view_ = *dto;
  dto_ptr_ = dto;
  figure_def_ = *figure_def;
  figure_draw_ = *figure_draw;
};

s21::Snapshot &s21::Snapshot::operator=(const Snapshot &snapshot) {
  if (&snapshot != this) {
    figure_def_ = snapshot.figure_def_;
    figure_draw_ = snapshot.figure_draw_;
    dto_old_for_view_ = snapshot.dto_old_for_view_;
    dto_old_for_afffin_tran_ = snapshot.dto_old_for_afffin_tran_;
    dto_ptr_ = snapshot.dto_ptr_;
  }
  return *this;
}

void s21::Snapshot::Restore(Figure *figure_def, Figure *figure_draw) {
  s21::AffineTransformations::SetOldFielde(dto_old_for_afffin_tran_);
  *dto_ptr_ = dto_old_for_view_;
  *figure_def = figure_def_;
  *figure_draw = figure_draw_;
};