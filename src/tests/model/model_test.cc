#include <gtest/gtest.h>
#include <vector>
#include <iostream>

#include "../main_test.h"
#include "../../model/FileParser.h"

void printToFile(s21::Figure figure) {
    std::ofstream out;
    out.open("tests/model/test_result.txt");
    if(!out) { std::cerr << "Could not open file" << std::endl; }
    if (out.is_open()) {
        for (auto i : figure.GetVertexesVector()) {
            out << std::setprecision(11) << i.GetX() << " " << i.GetY() << " " << i.GetZ() << std::endl;
        }

        out << "\n";
        unsigned index = figure.GetPoligonsSizesVector()[0];
        for (unsigned i = 0, j =0; i < figure.GetEdgesVector().size(); ++i) {
            out << figure.GetEdgesVector()[i] << " ";
            if (i == index -1) {
                out << "\n";
                ++j;
                index += figure.GetPoligonsSizesVector()[j];
            }
        }

        out << "\n";
        out << "max_=" << figure.Get_Max() << std::endl;
    }
    out.close(); 
}

#include <fstream>
using namespace std;
 
bool compareFile(std::string path_f1, std::string path_f2){
    bool result = true;
    std::string sf1, sf2;
    std::ifstream f1(path_f1);
    std::ifstream f2(path_f2);
    if(!f1) { std::cerr << "Could not open file" << std::endl; }
    if(!f2) { std::cerr << "Could not open file" << std::endl; }
    if(f1.is_open() && f2.is_open()) {
        while(getline(f1, sf1) && getline(f2, sf2)) {
            if(sf1 != sf2) {
                result = false;
                break;
            }
        }
        f1.close();
        f2.close();
    } else {
        throw std::invalid_argument("ERROR: failed to open files.");
    }
    return result;
}

TEST(model, parser_1) {
    std::string path_file = "tests/model/test_result.txt";
    std::string path_etalon_file = "tests/model//parser_1_result_to_assert.txt";
    s21::FileParser file_parser = s21::FileParser();
    s21::Figure figure = file_parser.Parser("3d_objects/cube.obj");
    printToFile(figure);
    bool result = compareFile(path_file, path_etalon_file);
    ASSERT_TRUE(result);
    // ASSERT_FALSE(result);
}
