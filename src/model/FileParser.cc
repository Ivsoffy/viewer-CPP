#include "FileParser.h"

s21::Figure s21::FileParser::Parser(std::string file_name) {
    s21::Figure figure = s21::Figure();
    std::ifstream file;
    file.open(file_name);
    if (file.is_open()) {
        std::string line;
        double x, y, z;
        std::string first;
        double num;
        std::string curr_substring;
        unsigned edge_counter;
        unsigned index_to_loop;
        while (std::getline(file,line)) {
            std::stringstream strstr(line);
            strstr >> first;
            if (first == "v") {
                strstr >> x >> y >> z;
                // std::cout << x << " " << y << " " << z << std::endl;////////
                figure.AddVertex(x, y, z);
            } else if (first == "f") {
                edge_counter = 0;
                while ((strstr >> curr_substring)) {
                    if (curr_substring.size() == 0 && edge_counter == 0) {
                            break;
                    }
                    std::stringstream strstr2(curr_substring);
                    strstr2 >> num;
                    if (edge_counter == 0) {
                        figure.AddVertexToEdgesVector(num);
                        edge_counter++;
                    } else {
                        figure.AddVertexToEdgesVector(num);
                        figure.AddVertexToEdgesVector(num);
                        edge_counter+=2;
                    }
                    
                    // std::cout << num << " ";////////////
                }
                if (edge_counter != 0) {
                    index_to_loop = figure.GetEdgesVector().size() - edge_counter;
                    figure.AddVertexToEdgesVector(figure.GetEdgesVector()[index_to_loop]);
                    edge_counter++;
                }
                figure.AddPolygonsSize(edge_counter);
                // std::cout << "\n";
            }
        }
    }
    file.close();

    ///TODO//checks////////////////////////////////////////////////////////////////////
    for (auto i : figure.GetVertexesVector()) {
        std::cout << i.GetX() << " " << i.GetY() << " " << i.GetZ() << std::endl;
    }
    // std::cout << "\n";
    // for (auto i : figure.GetEdgesVector()) {
    //     std::cout << i << " ";
    // }
    // std::cout << "\n";
    // for (auto i : figure.GetPoligonsSizesVector()) {
    //     std::cout << i << " ";
    // }
    std::cout << "\n";
    unsigned index = figure.GetPoligonsSizesVector()[0];
    for (auto i = 0, j =0; i < figure.GetEdgesVector().size(); ++i) {
        // figure.GetEdgesVector()[i]
        std::cout << figure.GetEdgesVector()[i] << " ";
        if (i == index -1) {
            std::cout << "\n";
            std::cout << "index=" << index << "\n";
            ++j;
            index += figure.GetPoligonsSizesVector()[j];
        }
    }
    std::cout << "\n";
    for (auto i : figure.GetPoligonsSizesVector()) {
        std::cout << i << " ";
    }

    return figure;
}
