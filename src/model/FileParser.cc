#include "FileParser.h"

s21::Figure s21::FileParser::Parser(std::string file_name) {
    s21::Figure figure = s21::Figure();
    std::ifstream file;
    file.open(file_name);
    if (file.is_open()) {
        std::string line;
        double x, y, z;
        std::string first;
        while (std::getline(file,line)) {
            // std::cout << line << std::endl;
            std::stringstream strstr(line);
            strstr >> first;
            if (first == "v") {
                strstr >> first >> x >> y >> z;
                std::cout << x << " " << y << " " << z << std::endl;
                figure.AddVertex(x, y, z);
            } else if (first == "f") {
                
            }
            

        }
    }
    file.close();

    return figure;
}
