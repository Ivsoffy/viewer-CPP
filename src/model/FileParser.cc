#include "FileParser.h"

s21::Figure s21::FileParser::Parser(std::string file_name) {
    s21::Figure figure = s21::Figure();
    std::ifstream file;
    file.open(file_name);
    if (file.is_open()) {
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

    return figure;
}

void s21::FileParser::ParsVLine(std::string line, s21::Figure *figure) {
    std::string token;
    double num_double = 0;
    unsigned v_counter = 0;
    std::stringstream strstr(line);
    std::vector<double> temp_vertex;
    std::getline(strstr, token, ' ');
    while (std::getline(strstr, token, ' ')) {
        if (++v_counter > 3) {
            throw std::invalid_argument("ERROR: Invalid data in 'v'-line in objest file. Too many arguments.");
        }
        try {
            num_double = std::stod(token);
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
    double num_double = 0;
    unsigned edge_counter = 0;
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
