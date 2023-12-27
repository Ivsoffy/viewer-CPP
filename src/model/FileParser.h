#ifndef MODEL_FILEPARSER_H_
#define MODEL_FILEPARSER_H_

#include "Figure.h"
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

namespace s21 {

class FileParser {
    public:
        FileParser(){};
        ~FileParser(){};

        s21::Figure Parser(std::string file_name);
};

} //namespace s21

#endif //MODEL_FILEPARSER_H_
