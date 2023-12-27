#ifndef MODEL_FILEPARSER_H_
#define MODEL_FILEPARSER_H_

#include "Figure.h"
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <exception>

namespace s21 {

class FileParser {
    public:
        FileParser(){};
        ~FileParser(){};

        s21::Figure Parser(std::string file_name);
    
    private:
        // void ParsFile(std::stringstream strstr);
        void ParsVLine(std::string strstr, s21::Figure figure);
        void ParsFLine(std::string strstr, s21::Figure figure);
};

} //namespace s21

#endif //MODEL_FILEPARSER_H_
