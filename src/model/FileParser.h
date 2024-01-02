#ifndef MODEL_FILEPARSER_H_
#define MODEL_FILEPARSER_H_

#include <exception>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

#include "Figure.h"
#include "Vertex.h"

namespace s21 {

class FileParser {
 public:
  FileParser(){};
  ~FileParser(){};

  void Parser(s21::Figure *figure, std::string file_name);

  // std::vector<double> PrepareVertecesToOGL(s21::Figure *figure);

 private:
  void ParsVLine(std::string strstr, s21::Figure *figure);
  void ParsFLine(std::string strstr, s21::Figure *figure);
};

}  // namespace s21

#endif  // MODEL_FILEPARSER_H_
