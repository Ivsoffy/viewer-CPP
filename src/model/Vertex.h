#ifndef MODEL_VERTEX_H_
#define MODEL_VERTEX_H_

#include "AffineTransformations.h"

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

 void TransformVertex() {
   AffineTransformations::Trasformate(&x_, &y_, &z_);
 };

 private:
  double x_{};
  double y_{};
  double z_{};
};

}  // namespace s21

#endif  // MODEL_VERTEX_H_
