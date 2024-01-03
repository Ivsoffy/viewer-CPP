#include "FileParser.h"
#include <iostream>

void s21::FileParser::Parser(s21::Figure *figure, std::string file_name) {
//  s21::Figure figure = s21::Figure();
  std::ifstream file;
  file.open(file_name);
  if (file.is_open()) {
    std::string line;
    std::string token;
    while (std::getline(file, line)) {
      std::stringstream strstr(line);
      std::getline(strstr, token, ' ');
      figure->Set_Max(9.99);
      if (token == "v") {
        // s21::FileParser::ParsVLine(strstr.str(), figure);
        s21::FileParser::ParsVLine(line, figure);
      } else if (token == "f") {
        s21::FileParser::ParsFLine(strstr.str(), figure);
      }
    }
  }
  file.close();
  

  // std::cerr << figure->GetPoligonsSizesVector().size() << std::endl;/////////////////////

  // for (unsigned i = 0; i < figure->GetEdgesVector().size(); ++i) {
  //   std::cerr << figure->GetEdgesVector().at(i) << "|";
  // }
  // std::cerr << std::endl;
  //   for (unsigned i = 0; i < figure->GetPoligonsSizesVector().size(); ++i) {
  //   std::cerr << figure->GetPoligonsSizesVector().at(i) << "|";
  // }
  // std::cerr << std::endl;
}

void s21::FileParser::ParsVLine(std::string line, s21::Figure* figure) {
  std::string token;
  double num_double = 0;
  unsigned v_counter = 0;
  std::stringstream strstr(line);
  std::vector<double> temp_vertex{};
  std::getline(strstr, token, ' ');
  while (std::getline(strstr, token, ' ')) {
    if (token == "") {
      continue;
    }

    try {
      num_double = std::stod(token);
      temp_vertex.push_back(num_double);
      if (figure->Get_Max() < std::fabs(num_double)) {
        figure->Set_Max(std::fabs(num_double));
      }
    } catch(const std::exception& e) {
      throw std::invalid_argument("ERROR: Invalid data in 'v'-line in object file.");
    }
  }

  if (temp_vertex.size() > 3) {
    throw std::invalid_argument("ERROR: Invalid data in 'v'-line in object file. Too many arguments.");
  }

  figure->AddVertex(temp_vertex[0], temp_vertex[1], temp_vertex[2]);
}

void s21::FileParser::ParsFLine(std::string line, s21::Figure* figure) {
  std::string token;
  double num_double = 0;
  unsigned edge_counter = 0;
  std::stringstream strstr(line);
  unsigned index_to_loop;
  std::getline(strstr, token, ' ');
  while (std::getline(strstr, token, ' ')) {
    if (token == "" || token == " " || token.size() == 1) {
      continue;
    }
    if (token == "\r") { // 13 - перевод каретки
      break;
    }

    try {
      num_double = std::stod(token);

      if (num_double < 0) {
        num_double = figure->GetVertexesVector().size() + num_double + 1;
      }

      if (edge_counter == 0) {
        figure->AddVertexToEdgesVector(num_double - 1);
        edge_counter++;
      } else {
        figure->AddVertexToEdgesVector(num_double - 1);
        figure->AddVertexToEdgesVector(num_double - 1);
        edge_counter += 2;
      }
    } catch (const std::exception& e) {
      throw std::invalid_argument(
          "ERROR: Invalid data in 'f'-line in objest file.");
    }
  }
  if (edge_counter != 0) {
    index_to_loop = figure->GetEdgesVector().size() - edge_counter;
    figure->AddVertexToEdgesVector(figure->GetEdgesVector()[index_to_loop]);
    edge_counter++;
  }
  figure->AddPolygonsSize(edge_counter);

}




////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// #include "FileParser.h"
// #include <iostream>

// void s21::FileParser::Parser(s21::Figure *figure, std::string file_name) {
// //  s21::Figure figure = s21::Figure();
//   std::ifstream file;
//   file.open(file_name);
//   if (file.is_open()) {
//     std::string line;
//     std::string token;
//     while (std::getline(file, line)) {
//       std::stringstream strstr(line);
//       std::getline(strstr, token, ' ');
//       figure->Set_Max(9.99);
//       if (token == "v") {
//         s21::FileParser::ParsVLine(strstr.str(), figure);
//       } else if (token == "f") {
//         s21::FileParser::ParsFLine(strstr.str(), figure);
//       }
//     }
//   }
//   file.close();
// }

// void s21::FileParser::ParsVLine(std::string line, s21::Figure* figure) {
//   std::string token;
//   double num_double = 0;
//   unsigned v_counter = 0;
//   std::stringstream strstr(line);
//   std::vector<double> temp_vertex{};
//   std::getline(strstr, token, ' ');
//   while (std::getline(strstr, token, ' ')) {
//     if (token == "" || token == " ") {
//       // std::cerr << "7777777" << std::endl;/////////////////////
//       continue;
//     }
//     if ((int) token[0] == 13) { // 13 - перевод каретки
//       // std::cerr << "555555" << std::endl;/////////////////////
//       break;
//     }


//     // std::cerr << "11 | " << strstr.str() << std::endl;///////////////
//     // std::cerr << "33 | " << token << std::endl;/////////////////////

//     if (++v_counter > 3) {
//       throw std::invalid_argument(
//           "ERROR: Invalid data in 'v'-line in objest file. Too many "
//           "arguments.");
//     }
//     try {
//       num_double = 999;
//       temp_vertex.push_back(num_double);
//       if (figure->Get_Max() < std::fabs(num_double)) {
//         figure->Set_Max(std::fabs(num_double));
//       }

//       // if (figure.GetX_Max() < std::fabs(x)) {
//       //     figure.SetX_Max(std::fabs(x));
//       // }
//       // if (figure.GetY_Max() < std::fabs(y)) {
//       //     figure.SetY_Max(std::fabs(y));
//       // }
//       // if (figure.GetZ_Max() < std::fabs(z)) {
//       //     figure.SetZ_Max(std::fabs(z));
//       // }
//     } catch (const std::exception& e) {
//       std::cerr << "2 | " << strstr.str() << std::endl;
//       throw std::invalid_argument(
//           "ERROR: Invalid data in 'v'-line in objest file.");
//     }
//   }
//   figure->AddVertex(temp_vertex[0], temp_vertex[1], temp_vertex[2]);
// }

// void s21::FileParser::ParsFLine(std::string line, s21::Figure* figure) {
//   std::string token;
//   double num_double = 0;
//   unsigned edge_counter = 0;
//   std::stringstream strstr(line);
//   unsigned index_to_loop;
//   std::getline(strstr, token, ' ');
//   while (std::getline(strstr, token, ' ')) {
//     if (token == "" || token == " " || token.size() == 1) { // 13 - перевод каретки
//       // std::cerr << "555555" << std::endl;/////////////////////
//       // std::cerr << "11 | " << strstr.str() << std::endl;///////////////
//       continue;
//     }
//     // if ((int) token[0] == 13) { // 13 - перевод каретки
//     //   // std::cerr << "555555" << std::endl;/////////////////////
//     //   break;
//     // }
//     // std::cerr << "11 | " << strstr.str() << std::endl;///////////////
//     // std::cerr << "33 | " << token << std::endl;/////////////////////
//     // std::cerr << "33 | " << token.size() << std::endl;/////////////////////
//     // std::cerr << (int) token[0] << std::endl;/////////////////////

//     try {
//       num_double = std::stod(token);

//       if (num_double < 0) {
//         num_double = figure->GetVertexesVector().size() + num_double + 1;
//       }

//       if (edge_counter == 0) {
//         figure->AddVertexToEdgesVector(num_double);
//         edge_counter++;
//       } else {
//         figure->AddVertexToEdgesVector(num_double);
//         figure->AddVertexToEdgesVector(num_double);
//         edge_counter += 2;
//       }
//     } catch (const std::exception& e) {
//       throw std::invalid_argument(
//           "ERROR: Invalid data in 'f'-line in objest file.");
//     }
//   }
//   if (edge_counter != 0) {
//     index_to_loop = figure->GetEdgesVector().size() - edge_counter;
//     figure->AddVertexToEdgesVector(figure->GetEdgesVector()[index_to_loop]);
//     edge_counter++;
//   }
//   figure->AddPolygonsSize(edge_counter);
// }
