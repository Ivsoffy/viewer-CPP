#ifndef CONTROLLERDTO_H
#define CONTROLLERDTO_H

// #include <QOpenGLFunctions>
#include "../model/vertex.h"
#include <vector>
#include <string>

namespace s21 {
class ParamDTO {
public:
  /// @brief DTO for transferring geometric parameters of 3d object
 ParamDTO(){};

 /// @brief DTO for transferring geometric parameters of 3d object
 /// @param move_x x-axis movement
 /// @param move_y y-axis movement
 /// @param move_z z-axis movement
 /// @param angle_x rotation around x axis
 /// @param angle_y rotation around y axis
 /// @param angle_z rotation around z axis
 /// @param scale 3d object scaling
 ParamDTO(double move_x, double move_y, double move_z, double angle_x,
          double angle_y, double angle_z, double scale);

  ~ParamDTO(){};

 double move_x_{0};
 double move_y_{0};
 double move_z_{0};
 double angle_x_{0};
 double angle_y_{0};
 double angle_z_{0};
 double scale_{1};
};

class ObjectInfoDTO {
public:
      /// @brief DTO for save infomation about 3d object
     ObjectInfoDTO(){};

     /// @brief DTO for save infomation about 3d object 
     ObjectInfoDTO(std::string object_info_file_path,
                     std::string object_info_file_name,
                     std::string object_info_vertex_count,
                     std::string object_info_polygon_count
                     );

    ~ObjectInfoDTO(){};

    std::string object_info_file_path_;
    std::string object_info_file_name_;
    std::string object_info_vertex_count_;
    std::string object_info_polygon_count_;
};

class FigureDataDTO {
 public:
  /// @brief DTO for transferring references to vertices and edges vecters
  /// @param vertices array of virtex
  /// @param edges edges array
  FigureDataDTO(std::vector<s21::Vertex>* vertices, std::vector<unsigned>* edges);

  ~FigureDataDTO(){};

  std::vector<s21::Vertex>* vertices_;
  std::vector<unsigned>* edges_;
};

}  // namespace s21

#endif // CONTROLLERDTO_H
