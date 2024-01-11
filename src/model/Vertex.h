#ifndef MODEL_VERTEX_H_
#define MODEL_VERTEX_H_

// #include "AffineTransformations.h"
// #include "Figure.h"

namespace s21 {

class Vertex {
 public:
  Vertex(){};
  Vertex(double x, double y, double z) {
    x_ = x;
    y_ = y;
    z_ = z;
  };
  ~Vertex(){};

  double GetX() { return x_; };
  double GetY() { return y_; };
  double GetZ() { return z_; };
  void SetX(double x) { x_ = x; };
  void SetY(double y) { y_ = y; };
  void SetZ(double z) { z_ = z; };

//  void TransformVertex(s21::Figure* figure_draw_) {
//   unsigned vector_size =  vertices_.size();
//   for (unsigned i = 0; i < vector_size; i++) {
//     vertices_.at(i).TransformVertex(figure_draw_);
//   }

//    AffineTransformations::Trasformate(&x_, &y_, &z_, figure_draw_);
//  };

//  static void TransformVertices(s21::Figure* figure_def_, s21::Figure* figure_draw_) {
//   unsigned vector_size =  figure_def_->GetVerticesVectorRef().size();
//   for (unsigned i = 0; i < vector_size; i++) {
//     AffineTransformations::Trasformate(figure_def_->GetEdgesVectorRef()->at(i), figure_draw_->GetEdgesVectorRef()->at(i));
//   }
//  };

 private:
  double x_{};
  double y_{};
  double z_{};
};

}  // namespace s21

#endif  // MODEL_VERTEX_H_
