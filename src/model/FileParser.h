#ifndef MODEL_FILEPARSER_H_
#define MODEL_FILEPARSER_H_

namespace s21 {

#include "Figure.h"

class FileParser {
    public:
        FileParser(){};
        ~FileParser(){};
        s21::Figure Parser();
};

} //namespace s21

#endif //MODEL_FILEPARSER_H_
