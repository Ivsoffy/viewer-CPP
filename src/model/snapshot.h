#ifndef MODEL_SNAPSHOT_H_
#define MODEL_SNAPSHOT_H_

#include "figure.h"
#include "../dto/dto.h"
#include "affine_transformations.h"

namespace s21 {

class Snapshot {
public:

    Snapshot(s21::Figure *figure_def, s21::Figure *figure_draw, s21::ParamDTO *dto);
    ~Snapshot(){};

    Snapshot& operator=(const Snapshot& snapshot);

    void Restore(Figure *figure_def, Figure *figure_draw);

private:
    s21::Figure figure_def_;
    s21::Figure figure_draw_;
    s21::ParamDTO dto_old_for_afffin_tran_;
    s21::ParamDTO dto_old_for_view_;
    s21::ParamDTO *dto_ptr_;
};

}  // namespace s21

#endif  // MODEL_SNAPSHOT_H_
