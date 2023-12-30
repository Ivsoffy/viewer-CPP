#ifndef CONTROLLER_CONTROLLER_H_
#define CONTROLLER_CONTROLLER_H_

#include <QOpenGLFunctions>
#include <string>

namespace s21 {
class CalcController {
 public:
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
    double scale_{};
  };

  void TransferFigureParams(ParamDTO *param);
  void TransferObject(std::string file_name);
  void TransferGLBuffer(GLuint VertexBuffer, GLuint IndexBuffer,
                        uint IndecesSize, uint VerticesSize);
};

}  // namespace s21

#endif  // CONTROLLER_CONTROLLER_H_