#include "Figure.h"

#include <ctime>/////////////////////////////TODO
#include <chrono>/////////////////////TODO
using std::chrono::duration_cast;////////////////////////////TODO
using std::chrono::milliseconds;////////////////////////////TODO
using std::chrono::seconds;////////////////////////////TODO
using std::chrono::system_clock;////////////////////////////TODO

void s21::Figure::FileParser::Parser(s21::Figure *figure, std::string file_name) {
  std::cerr << "(((((((((((((((((((())))))))))))))))))))" << std::endl;/////////////////////TODO
  auto millisec_start = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();/////////////////////TODO

  std::ifstream file;
  file.open(file_name);
  if (file.is_open()) {
    std::string line;
    while (std::getline(file, line)) {
      if (line[0] == 'v' && line[1] == ' ') {
        s21::Figure::FileParser::ParsVLine(line, figure);
      } else if (line[0] == 'f' && line[1] == ' ') {
        s21::Figure::FileParser::ParsFLine(line, figure);
      }
    }
  }
  file.close();
//////////////////////////////////////////////////////////////////////////////////////////
  // std::cerr << std::endl;/////////////////////
  // for (unsigned i = 0; i < figure->GetEdgesVector().size(); ++i) {
  //   std::cerr << figure->GetEdgesVector().at(i) + 1 << "|";/////////////////////
  // }
  // std::cerr << std::endl;/////////////////////
//////////////////////////////////////////////////////////////////////////////////////////

  std::cerr << "))))))))))))))))))))((((((((((((((((((((" << std::endl;/////////////////////TODO
  auto millisec_end = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();/////////////////////TODO
  std::cerr << millisec_end - millisec_start << std::endl;/////////////////////TODO
}

void s21::Figure::FileParser::ParsVLine(std::string line, s21::Figure* figure) {
  double num_double = 0;
  double temp_vertex_arr[3];
  unsigned space_1 = 0;
  unsigned space_2 = 0;
  unsigned space_couter = 0;
  unsigned length = line.size();
  try {
    unsigned j = 0;
    for (unsigned index = 0; index < length; ++index) {
      if (line[index] == '\r' || line[index] == '\n') {
        break;
      }
      if (line[index] == ' ') {
        if (line[index + 1] == ' ') {
          continue;
        }
        if (space_couter == 0) {
          ++space_couter;
          space_1 = index;
        } else {
          space_2 = index;
          num_double = std::stod(line.substr(space_1 + 1, space_2 - (space_1 + 1)));
          temp_vertex_arr[j++] = num_double;
          if (figure->Get_Max() < std::fabs(num_double)) {
            figure->Set_Max(std::fabs(num_double));
          }
          space_couter = 1;
          space_1 = index;
        }
        continue;
      }
    }
    num_double = std::stod(line.substr(space_1 + 1, space_2 - (space_1 + 1)));
    temp_vertex_arr[j] = num_double;
    if (figure->Get_Max() < std::fabs(num_double)) {
      figure->Set_Max(std::fabs(num_double));
    }
  } catch(const std::exception& e) {
    throw std::invalid_argument("ERROR: Invalid data in 'v'-line in object file.");
  }

  figure->vertexes_.push_back(s21::Vertex(temp_vertex_arr[0], temp_vertex_arr[1], temp_vertex_arr[2]));
}

void s21::Figure::FileParser::ParsFLine(std::string line, s21::Figure* figure) {
  int num_int = 0;
  unsigned edge_counter = 0;
  unsigned index_to_loop;
  unsigned space_1 = 0;
  unsigned space_couter = 0;
  unsigned length = line.size();
  unsigned index = 0;

  try {
    for (index = 0; index < length; ++index) {
      if (line[index] == ' ') {
        if (line[index + 1] == ' ') {
          continue;
        }
        if (space_couter == 0) {
          ++space_couter;
          space_1 = index;
        } else {
          num_int = std::stoi(line.substr(space_1 + 1, index - (space_1 + 1)));
          if (num_int < 0) {
            num_int = figure->vertexes_.size() + num_int + 1;
          }
          if (edge_counter == 0) {
            figure->edges_.push_back(num_int - 1);
            edge_counter++;
          } else {
            figure->edges_.push_back(num_int - 1);
            figure->edges_.push_back(num_int - 1);
            edge_counter += 2;
          }
          space_1 = index;
        }
      }
    }
    if (edge_counter != 0) {
      if ((index - 1 - space_1) > 1) {
        num_int = std::stoi(line.substr(space_1 + 1, index - (space_1 + 1)));
        if (num_int < 0) {
          num_int = figure->vertexes_.size() + num_int + 1;
        }
        figure->edges_.push_back(num_int - 1);
        figure->edges_.push_back(num_int - 1);
        edge_counter += 2;
      }
      index_to_loop = figure->edges_.size() - edge_counter;
      figure->edges_.push_back(figure->edges_[index_to_loop]);
    }
  } catch(const std::exception& e) {
    throw std::invalid_argument("ERROR: Invalid data in 'f'-line in object file.");
  }
}
