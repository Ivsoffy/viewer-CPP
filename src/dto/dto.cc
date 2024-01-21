#include "../dto/dto.h"

s21::ParamDTO::ParamDTO(double move_x, double move_y, double move_z,
                        double angle_x, double angle_y, double angle_z,
                        double scale) {
  move_x_ = move_x;
  move_y_ = move_y;
  move_z_ = move_z;
  angle_x_ = angle_x;
  angle_y_ = angle_y;
  angle_z_ = angle_z;
  scale_ = scale;
}

s21::ObjectInfoDTO::ObjectInfoDTO(std::string object_info_file_path,
                                  std::string object_info_file_name,
                                  std::string object_info_vertex_count,
                                  std::string object_info_polygon_count) {
  object_info_file_path_ = object_info_file_path;
  object_info_file_name_ = object_info_file_name;
  object_info_vertex_count_ = object_info_vertex_count;
  object_info_polygon_count_ = object_info_polygon_count;
}
s21::FigureDataDTO::FigureDataDTO(std::vector<s21::Vertex>* vertices,
                                  std::vector<unsigned>* edges) {
  vertices_ = vertices;
  edges_ = edges;
}
