#include <gtest/gtest.h>

#include <fstream>
#include <iostream>
#include <vector>

#include "../../model/AffineTransformations.h"
#include "../../model/Facade.h"
#include "../../model/Figure.h"

void printToFile(s21::Figure figure) {
  std::ofstream out;
  out.open("tests/model/test_result.txt");
  if (!out) {
    std::cerr << "Could not open file" << std::endl;
  }
  if (out.is_open()) {
    for (auto i : figure.GetVertexesVector()) {
      out << std::setprecision(11) << i.GetX() << " " << i.GetY() << " "
          << i.GetZ() << std::endl;
    }

    out << "\n";
    unsigned edgesSize = figure.GetEdgesVector().size();
    unsigned poligonsSize = figure.GetPoligonsSizesVector().size();
    unsigned index = figure.GetPoligonsSizesVector()[0];
    for (unsigned i = 0, j = 0; i < edgesSize && j < poligonsSize; ++i) {
      out << figure.GetEdgesVector()[i] << " ";
      if (i == index - 1) {
        out << "\n";
        ++j;
        if (j < figure.GetPoligonsSizesVector().size()) {
          index += figure.GetPoligonsSizesVector()[j];
        }
      }
    }

    out << "\n";
    out << "max_=" << figure.Get_Max() << std::endl;
  }
  out.close();
}

bool compareFile(std::string path_f1, std::string path_f2) {
  bool result = true;
  std::string sf1, sf2;
  std::ifstream f1(path_f1);
  std::ifstream f2(path_f2);
  if (!f1) {
    std::cerr << "Could not open file" << std::endl;
  }
  if (!f2) {
    std::cerr << "Could not open file" << std::endl;
  }
  if (f1.is_open() && f2.is_open()) {
    while (getline(f1, sf1) && getline(f2, sf2)) {
      if (sf1 != sf2) {
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

bool is_vertices_equal(s21::Vertex v1, s21::Vertex v2) {
  if (v1.GetX() - v2.GetX() > kEps) return false;
  if (v1.GetY() - v2.GetY() > kEps) return false;
  if (v1.GetZ() - v2.GetZ() > kEps) return false;
  return true;
}

TEST(model, parser_1) {
  std::string path_file = "tests/model/test_result.txt";
  std::string path_etalon_file = "tests/model/parser_1_result_to_assert.txt";
  s21::FileParser file_parser = s21::FileParser();
  s21::Figure figure =
      file_parser.Parser("tests/model/3d_objects/cube_good_1.obj");
  printToFile(figure);
  bool result = compareFile(path_file, path_etalon_file);
  ASSERT_TRUE(result);
}

TEST(model, parser_2) {
  std::string path_file = "tests/model/test_result.txt";
  std::string path_etalon_file = "tests/model/parser_2_result_to_assert.txt";
  s21::FileParser file_parser = s21::FileParser();
  s21::Figure figure =
      file_parser.Parser("tests/model/3d_objects/cube_good_2.obj");
  printToFile(figure);
  bool result = compareFile(path_file, path_etalon_file);
  ASSERT_TRUE(result);
}

TEST(model, parser_throw_1) {
  s21::FileParser file_parser = s21::FileParser();
  ASSERT_THROW(file_parser.Parser("tests/model/3d_objects/cube_bad_v_1.obj"),
               std::invalid_argument);
}

TEST(model, parser_throw_2) {
  s21::FileParser file_parser = s21::FileParser();
  ASSERT_THROW(file_parser.Parser("tests/model/3d_objects/cube_bad_v_2.obj"),
               std::invalid_argument);
}

TEST(model, parser_throw_3) {
  s21::FileParser file_parser = s21::FileParser();
  ASSERT_THROW(file_parser.Parser("tests/model/3d_objects/cube_bad_f.obj"),
               std::invalid_argument);
}

TEST(model, affine_1_move) {
  s21::Vertex vertex_to_move(1, 1, 1);
  s21::Vertex vertex_to_assert(2, 3, 4);
  s21::AffineTransformations aff_tran = s21::AffineTransformations();
  aff_tran.SetMoveX(1);
  aff_tran.SetMoveY(2);
  aff_tran.SetMoveZ(3);
  aff_tran.Trasformate(&vertex_to_move);
  ASSERT_TRUE(is_vertices_equal(vertex_to_move, vertex_to_assert));
}

TEST(model, affine_2_turn) {
  s21::Vertex vertex_to_turn(1, 1, 1);
  s21::Vertex vertex_to_assert(1, -1, 1);
  s21::AffineTransformations aff_tran = s21::AffineTransformations();
  aff_tran.SetAngleX(90);
  aff_tran.SetAngleY(90);
  aff_tran.SetAngleZ(90);
  aff_tran.Trasformate(&vertex_to_turn);
  ASSERT_TRUE(is_vertices_equal(vertex_to_turn, vertex_to_assert));
}

TEST(model, affine_3_scale) {
  s21::Vertex vertex_to_scale(1, 1, -1);
  s21::Vertex vertex_to_assert(3, 3, -3);
  s21::AffineTransformations aff_tran = s21::AffineTransformations();
  aff_tran.SetScale(3);
  aff_tran.Trasformate(&vertex_to_scale);
  ASSERT_TRUE(is_vertices_equal(vertex_to_scale, vertex_to_assert));
}

// TEST(model, XXXXXXXX) {
//     s21::FileParser file_parser = s21::FileParser();
//     s21::Figure figure =
//     file_parser.Parser("tests/model/3d_objects/cube_good_1.obj");
//     std::vector<double> result = file_parser.PrepareVertecesToOGL(&figure);
//     for (auto i = 0; i < result.size(); ++i) {
//         std::cout << result[i] << std::endl;
//     }
//     // ASSERT_TRUE(result);
//     s21::Facade facade = s21::Facade();
//     facade.SetPathToObject("tests/model/3d_objects/cube_good_1.obj");
//     printToFile(facade.figure_);
//     bool result = compareFile(path_file, path_etalon_file);
//     ASSERT_TRUE(result);
// }
