#include "FileParser.h"

s21::Figure s21::FileParser::Parser(std::string file_name) {
    s21::Figure figure = s21::Figure();
    std::ifstream file;
    file.open(file_name);
    if (file.is_open()) {
        std::string line;
        // double x, y, z;
        // std::string first;
        // double num;
        // std::string curr_substring;
        // unsigned edge_counter;
        // unsigned index_to_loop
        std::string token;
        double num_double;
        while (std::getline(file,line)) {
            std::stringstream strstr(line);
            std::getline(strstr, token, ' ');
            if (token == "v") {
                for (auto i = 0; i < 3; ++i) {
                    std::getline(strstr, token, ' ');
                    try {
                        num_double = std::stod(token);
                    } catch (const std::exception& e) {
                        throw std::invalid_argument("ERROR: Invalid data in 'v'-line in objest file.");
                    }
                    std::cout << num_double << " ";////////
                }
                std::cout << "\n";
            } else if (token == "f") {
                for (auto i = 0; i < 3; ++i) {
                    std::getline(strstr, token, ' ');
                    std::cout << token << " ";////////
                }
                std::cout << "\n";
            }
        }
    }
    file.close();

    return figure;
}


            
            // std::stringstream strstr(line);
        //     strstr >> first;
        //     if (first == "v") {
        //         strstr >> x >> y >> z;
        //         // std::cout << x << " " << y << " " << z << std::endl;////////
        //         if (figure.GetX_Max() < std::fabs(x)) {
        //             figure.SetX_Max(std::fabs(x));
        //         }
        //         if (figure.GetY_Max() < std::fabs(y)) {
        //             figure.SetY_Max(std::fabs(y));
        //         }
        //         if (figure.GetZ_Max() < std::fabs(z)) {
        //             figure.SetZ_Max(std::fabs(z));
        //         }
        //         figure.AddVertex(x, y, z);
        //     } else if (first == "f") {
        //         edge_counter = 0;
        //         while ((strstr >> curr_substring)) {
        //             if (curr_substring.size() == 0 && edge_counter == 0) {
        //                     break;
        //             }
        //             std::stringstream strstr2(curr_substring);
        //             strstr2 >> num;
        //             if (num < 0) {
        //                 num = figure.GetVertexesVector().size() + num + 1;
        //                 // std::cout << num << "<<\n";////////////
        //             }

        //             if (edge_counter == 0) {
        //                 figure.AddVertexToEdgesVector(num);
        //                 edge_counter++;
        //             } else {
        //                 figure.AddVertexToEdgesVector(num);
        //                 figure.AddVertexToEdgesVector(num);
        //                 edge_counter+=2;
        //             }
        //             // std::cout << num << " ";////////////
        //         }
        //         if (edge_counter != 0) {
        //             index_to_loop = figure.GetEdgesVector().size() - edge_counter;
        //             figure.AddVertexToEdgesVector(figure.GetEdgesVector()[index_to_loop]);
        //             edge_counter++;
        //         }
        //         figure.AddPolygonsSize(edge_counter);
        //         // std::cout << "\n";
        //     }
        // }
//     }
//     file.close();

//     ///TODO//checks////////////////////////////////////////////////////////////////////
//     for (auto i : figure.GetVertexesVector()) {
//         std::cout << i.GetX() << " " << i.GetY() << " " << i.GetZ() << std::endl;
//     }
//     std::cout << "\n";
//     unsigned index = figure.GetPoligonsSizesVector()[0];
//     for (auto i = 0, j =0; i < figure.GetEdgesVector().size(); ++i) {
//         std::cout << figure.GetEdgesVector()[i] << " ";
//         if (i == index -1) {
//             std::cout << "\n";
//             // std::cout << "index=" << index << "\n";
//             ++j;
//             index += figure.GetPoligonsSizesVector()[j];
//         }
//     }
//     // std::cout << "\n";
//     // for (auto i : figure.GetPoligonsSizesVector()) {
//     //     std::cout << i << " ";
//     // }
//     std::cout << "\n";
//     std::cout << "x_max_=" << figure.GetX_Max() << " " 
//             << "x_max_=" << figure.GetY_Max() << " " 
//             << "x_max_=" << figure.GetZ_Max() << std::endl;////////

//     return figure;
// }

// s21::Figure s21::FileParser::Parser(std::string file_name) {
//     s21::Figure figure = s21::Figure();
//     // FILE *file = fopen(file_name.c_str(), "r");
//     // if (file == NULL) {
//     //     throw std::logic_error("ERROR: Invalid data in 'v'-line in objest file.");
//     // }
//     // s21::FileParser::ParsFile(file);
//     std::ifstream file;
//     file.open(file_name);
//     if (!file.is_open()) {
//         throw std::logic_error("ERROR: Can't open the file.");
//     }
//     std::stringstream strstr(line);
//     s21::FileParser::ParsFile(file);

//     return figure;
// }

// void s21::FileParser::ParsFile(FILE *file){

//     std::string line;
//     while (std::getline(*file, line)) {
    
//         if (sscanf(line.c_str(), "%s %lf %lf %lf", first, &x, &y, &z) == 4) {
//         }
//     }
// }

// void s21::FileParser::ParsVLine(FILE &file) {
//   double x, y, z;
//   int matches = fscanf(file, "%lf %lf %lf\n", &x, &y, &z);
//   if (matches == 3) {
//     obj_->vertex_vector.push_back(x);
//     obj_->vertex_vector.push_back(y);
//     obj_->vertex_vector.push_back(z);
//   } else {
//     fp_++;
//   }
// }

// s21::Figure s21::FileParser::Parser(std::string file_name) {
//     s21::Figure figure = s21::Figure();
//     // std::ifstream file;
//     // file.open(file_name);
//     // if (file.is_open()) {
//     //     std::string line;
//     //     double x, y, z;
//     //     std::string x_s, y_s, z_s;
//     //     std::string error;
//     //     std::string first;
//     //     double num;
//     //     std::string curr_substring;
//     //     unsigned edge_counter;
//     //     unsigned index_to_loop;
//     //     while (std::getline(file, line)) {
            
//             if (sscanf(line, "%s %lf %lf %lf", first, &x, &y, &z) == 4) {

//             }

//             // std::stringstream strstr(line);
//             // strstr >> first;
//             if (first == "v") {
//                 // strstr >> x >> y >> z >> error;
//                 // strstr >> x_s >> y_s >> z_s >> error;
//                 // std::cout << x << " " << y << " " << z << " " << error << std::endl;////////


//                 if (error.size() != 0) {
//                     throw std::logic_error("ERROR: Invalid data in 'v'-line in objest file.");
//                 }
//                 // std::cout << x << " " << y << " " << z << std::endl;////////
//                 if (figure.GetX_Max() < std::fabs(x)) {
//                     figure.SetX_Max(std::fabs(x));
//                 }
//                 if (figure.GetY_Max() < std::fabs(y)) {
//                     figure.SetY_Max(std::fabs(y));
//                 }
//                 if (figure.GetZ_Max() < std::fabs(z)) {
//                     figure.SetZ_Max(std::fabs(z));
//                 }
//                 figure.AddVertex(x, y, z);
//             } else if (first == "f") {
//                 edge_counter = 0;
//                 while ((strstr >> curr_substring)) {
//                     if (curr_substring.size() == 0 && edge_counter == 0) {
//                             break;
//                     }
//                     std::stringstream strstr2(curr_substring);
//                     strstr2 >> num;
//                     if (num < 0) {
//                         num = figure.GetVertexesVector().size() + num + 1;
//                         // std::cout << num << "<<\n";////////////
//                     }

//                     if (edge_counter == 0) {
//                         figure.AddVertexToEdgesVector(num);
//                         edge_counter++;
//                     } else {
//                         figure.AddVertexToEdgesVector(num);
//                         figure.AddVertexToEdgesVector(num);
//                         edge_counter+=2;
//                     }
//                     // std::cout << num << " ";////////////
//                 }
//                 if (edge_counter != 0) {
//                     index_to_loop = figure.GetEdgesVector().size() - edge_counter;
//                     figure.AddVertexToEdgesVector(figure.GetEdgesVector()[index_to_loop]);
//                     edge_counter++;
//                 }
//                 figure.AddPolygonsSize(edge_counter);
//                 // std::cout << "\n";
//             }
//         }
//     } else {
//         throw std::logic_error("ERROR: Can't open the file.");
//     }
//     file.close();

//     // ///TODO//checks////////////////////////////////////////////////////////////////////
//     // for (auto i : figure.GetVertexesVector()) {
//     //     std::cout << i.GetX() << " " << i.GetY() << " " << i.GetZ() << std::endl;
//     // }
//     // std::cout << "\n";
//     // unsigned index = figure.GetPoligonsSizesVector()[0];
//     // for (auto i = 0, j =0; i < figure.GetEdgesVector().size(); ++i) {
//     //     std::cout << figure.GetEdgesVector()[i] << " ";
//     //     if (i == index -1) {
//     //         std::cout << "\n";
//     //         // std::cout << "index=" << index << "\n";
//     //         ++j;
//     //         index += figure.GetPoligonsSizesVector()[j];
//     //     }
//     // }
//     // // std::cout << "\n";
//     // // for (auto i : figure.GetPoligonsSizesVector()) {
//     // //     std::cout << i << " ";
//     // // }
//     // std::cout << "\n";
//     // std::cout << "x_max_=" << figure.GetX_Max() << " " 
//     //         << "x_max_=" << figure.GetY_Max() << " " 
//     //         << "x_max_=" << figure.GetZ_Max() << std::endl;////////

//     return figure;
// }

// void s21::FileParser::ParsVLine(std::str) {
//   double x, y, z;
//   int matches = fscanf(fp_, "%lf %lf %lf\n", &x, &y, &z);
//   if (matches == 3) {
//     obj_->vertex_vector.push_back(x);
//     obj_->vertex_vector.push_back(y);
//     obj_->vertex_vector.push_back(z);
//   } else {
//     fp_++;
//   }
// }


// #include "FileParser.h"

// s21::Figure s21::FileParser::Parser(std::string file_name) {
//     s21::Figure figure = s21::Figure();
//     std::ifstream file;
//     file.open(file_name);
//     if (file.is_open()) {
//         std::string line;
//         double x, y, z;
//         std::string first;
//         double num;
//         std::string curr_substring;
//         unsigned edge_counter;
//         unsigned index_to_loop;
//         while (std::getline(file,line)) {
//             std::stringstream strstr(line);
//             strstr >> first;
//             if (first == "v") {
//                 strstr >> x >> y >> z;
//                 // std::cout << x << " " << y << " " << z << std::endl;////////
//                 if (figure.GetX_Max() < std::fabs(x)) {
//                     figure.SetX_Max(std::fabs(x));
//                 }
//                 if (figure.GetY_Max() < std::fabs(y)) {
//                     figure.SetY_Max(std::fabs(y));
//                 }
//                 if (figure.GetZ_Max() < std::fabs(z)) {
//                     figure.SetZ_Max(std::fabs(z));
//                 }
//                 figure.AddVertex(x, y, z);
//             } else if (first == "f") {
//                 edge_counter = 0;
//                 while ((strstr >> curr_substring)) {
//                     if (curr_substring.size() == 0 && edge_counter == 0) {
//                             break;
//                     }
//                     std::stringstream strstr2(curr_substring);
//                     strstr2 >> num;
//                     if (num < 0) {
//                         num = figure.GetVertexesVector().size() + num + 1;
//                         // std::cout << num << "<<\n";////////////
//                     }

//                     if (edge_counter == 0) {
//                         figure.AddVertexToEdgesVector(num);
//                         edge_counter++;
//                     } else {
//                         figure.AddVertexToEdgesVector(num);
//                         figure.AddVertexToEdgesVector(num);
//                         edge_counter+=2;
//                     }
//                     // std::cout << num << " ";////////////
//                 }
//                 if (edge_counter != 0) {
//                     index_to_loop = figure.GetEdgesVector().size() - edge_counter;
//                     figure.AddVertexToEdgesVector(figure.GetEdgesVector()[index_to_loop]);
//                     edge_counter++;
//                 }
//                 figure.AddPolygonsSize(edge_counter);
//                 // std::cout << "\n";
//             }
//         }
//     }
//     file.close();

//     ///TODO//checks////////////////////////////////////////////////////////////////////
//     for (auto i : figure.GetVertexesVector()) {
//         std::cout << i.GetX() << " " << i.GetY() << " " << i.GetZ() << std::endl;
//     }
//     std::cout << "\n";
//     unsigned index = figure.GetPoligonsSizesVector()[0];
//     for (auto i = 0, j =0; i < figure.GetEdgesVector().size(); ++i) {
//         std::cout << figure.GetEdgesVector()[i] << " ";
//         if (i == index -1) {
//             std::cout << "\n";
//             // std::cout << "index=" << index << "\n";
//             ++j;
//             index += figure.GetPoligonsSizesVector()[j];
//         }
//     }
//     // std::cout << "\n";
//     // for (auto i : figure.GetPoligonsSizesVector()) {
//     //     std::cout << i << " ";
//     // }
//     std::cout << "\n";
//     std::cout << "x_max_=" << figure.GetX_Max() << " " 
//             << "x_max_=" << figure.GetY_Max() << " " 
//             << "x_max_=" << figure.GetZ_Max() << std::endl;////////

//     return figure;
// }
