#include "FileParser.h"

s21::Figure s21::FileParser::Parser(std::string file_name) {
    s21::Figure figure = s21::Figure();
    // std::ifstream file;
    std::ifstream(file);
    file.open(file_name);
    // std::cout << "||||||||||||||||||||||||||||||||" << std::endl;/////////////////
    if (file.is_open()) {
        // std::cout << "||||||||||||||||||||||||||||||||" << std::endl;/////////////////
        std::string line;
        std::string token;
        double num_double;
        int num_int;
        unsigned v_counter;
        while (std::getline(file,line)) {
            std::stringstream strstr(line);
            std::getline(strstr, token, ' ');
            if (token == "v") {
                s21::FileParser::ParsVLine(strstr.str(), &figure);
            } else if (token == "f") {
                s21::FileParser::ParsFLine(strstr.str(), &figure);
            }
        }
    }
    file.close();

    // //////TODO//checks////////////////////////////////////////////////////////////////////
    // for (auto i : figure.GetVertexesVector()) {
    //     std::cout << std::setprecision(11) << i.GetX() << " " << i.GetY() << " " << i.GetZ() << std::endl;
    // }

    // std::cout << "\n";
    // unsigned index = figure.GetPoligonsSizesVector()[0];
    // for (auto i = 0, j =0; i < figure.GetEdgesVector().size(); ++i) {
    //     std::cout << figure.GetEdgesVector()[i] << " ";
    //     if (i == index -1) {
    //         std::cout << "\n";
    //         ++j;
    //         index += figure.GetPoligonsSizesVector()[j];
    //     }
    // }

    // std::cout << "\n";
    // std::cout << "max_=" << figure.Get_Max() << std::endl;

    // // std::cout << "\n";
    // // for (auto i : figure.GetPoligonsSizesVector()) {
    // //     std::cout << i << " ";
    // // }

    // // std::cout << "\n";
    // // std::cout << "x_max_=" << figure.GetX_Max() << " " 
    // //         << "x_max_=" << figure.GetY_Max() << " " 
    // //         << "x_max_=" << figure.GetZ_Max() << std::endl;
    // //////////////////////////////////////////////////////////////////////////////////////

    return figure;
}

void s21::FileParser::ParsVLine(std::string line, s21::Figure *figure) {
    std::string token;
    double num_double;
    unsigned v_counter;
    std::stringstream strstr(line);
    std::vector<double> temp_vertex;
    std::getline(strstr, token, ' ');
    while (std::getline(strstr, token, ' ')) {
        if (++v_counter > 4) {
            throw std::invalid_argument("ERROR: Invalid data in 'v'-line in objest file. Too many arguments.");
        }
        try {
            num_double = std::stod(token);
            // std::cout << num_double << "|||";//////////////////////////////////
            temp_vertex.push_back(num_double);
            if (figure->Get_Max() < std::fabs(num_double)) {
                figure->Set_Max(std::fabs(num_double));
            }
            // if (figure.GetX_Max() < std::fabs(x)) {
            //     figure.SetX_Max(std::fabs(x));
            // }
            // if (figure.GetY_Max() < std::fabs(y)) {
            //     figure.SetY_Max(std::fabs(y));
            // }
            // if (figure.GetZ_Max() < std::fabs(z)) {
            //     figure.SetZ_Max(std::fabs(z));
            // }
        } catch (const std::exception& e) {
            throw std::invalid_argument("ERROR: Invalid data in 'v'-line in objest file.");
        }
    }
    figure->AddVertex(temp_vertex[0], temp_vertex[1], temp_vertex[2]);
}

void s21::FileParser::ParsFLine(std::string line, s21::Figure *figure) {
    std::string token;
    double num_double;
    unsigned edge_counter;
    std::stringstream strstr(line);
    unsigned index_to_loop;
    std::getline(strstr, token, ' ');
    while (std::getline(strstr, token, ' ')) {
        try {
            num_double = std::stod(token);

            if (num_double < 0) {
                num_double = figure->GetVertexesVector().size() + num_double + 1;
            }

            if (edge_counter == 0) {
                figure->AddVertexToEdgesVector(num_double);
                edge_counter++;
            } else {
                figure->AddVertexToEdgesVector(num_double);
                figure->AddVertexToEdgesVector(num_double);
                edge_counter+=2;
            }
        } catch (const std::exception& e) {
            throw std::invalid_argument("ERROR: Invalid data in 'f'-line in objest file.");
        }
    }
    if (edge_counter != 0) {
        index_to_loop = figure->GetEdgesVector().size() - edge_counter;
        figure->AddVertexToEdgesVector(figure->GetEdgesVector()[index_to_loop]);
        edge_counter++;
    }
    figure->AddPolygonsSize(edge_counter);
}
