#ifndef CONTROLLERDTO_H
#define CONTROLLERDTO_H

#include <QOpenGLFunctions>
#include "../model/vertex.h"
#include <vector>

namespace s21 {
class ParamDTO {
public:
 ParamDTO(double move_x, double move_y, double move_z, double angle_x,
          double angle_y, double angle_z, double scale);
 double move_x_{};
 double move_y_{};
 double move_z_{};
 double angle_x_{};
 double angle_y_{};
 double angle_z_{};
 double scale_ = 1;

 ParamDTO(){};

// ParamDTO& operator=(const ParamDTO& paramDTO) {
//     if(&paramDTO != this) {
//         move_x_ = paramDTO.move_x_;
//         move_y_ = paramDTO.move_y_;
//         move_z_ = paramDTO.move_z_;
//         angle_x_ = paramDTO.angle_x_;
//         angle_y_ = paramDTO.angle_y_;
//         angle_z_ = paramDTO.angle_z_;
//         scale_ = paramDTO.scale_;
//     }
//     return *this;
// }
};

class GLBufferDTO {
 public:
  GLBufferDTO(std::vector<s21::Vertex>* vertices, std::vector<unsigned>* edges);

  std::vector<s21::Vertex>* vertices_;
  std::vector<unsigned>* edges_;
};
}  // namespace s21

#endif // CONTROLLERDTO_H
