#include <gtest/gtest.h>

#include <fstream>
#include <iostream>
#include <vector>

#include "../main_test.h"

void printToFile(s21::Figure figure) {
  std::ofstream out;
  out.open("tests/model/test_result.txt");
  if (!out) {
    std::cerr << "Could not open file" << std::endl;
  }
  if (out.is_open()) {
    for (auto i : figure.GetVerticesVector()) {
      out << std::setprecision(11) << i.GetX() << " " << i.GetY() << " "
          << i.GetZ() << std::endl;
    }

    out << "\n";
    unsigned edgesVectorSize = figure.GetEdgesVector().size();
    for (unsigned i = 0; i < edgesVectorSize; ++i) {
      out << figure.GetEdgesVector().at(i) + 1 << " ";
    }

    out << "\n";
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
  if (abs(v1.GetX() - v2.GetX()) > kEps) return false;
  if (abs(v1.GetY() - v2.GetY()) > kEps) return false;
  if (abs(v1.GetZ() - v2.GetZ()) > kEps) return false;
  return true;
}

bool is_vertices_vectors_equal(std::vector<s21::Vertex> vector_1, std::vector<s21::Vertex> vector_2) {
  for (unsigned i = 0; i < vector_1.size(); ++i) {
    if (!is_vertices_equal(vector_1.at(i),vector_2.at(i))) {
      return false;
    }
  }
  return true;
}

TEST(model, parser_1) {
  std::string path_file = "tests/model/test_result.txt";
  std::string path_etalon_file = "tests/model/parser_1_result_to_assert.txt";
  s21::Figure* figure = new  s21::Figure();
  s21::Figure::FileParser *file_parser = new s21::Figure::FileParser();
  file_parser->Parser(figure, "tests/model/3d_objects/cube_good_1.obj");
  printToFile(*figure);
  bool result = compareFile(path_file, path_etalon_file);
  ASSERT_TRUE(result);
}

TEST(model, parser_2) {
  std::string path_file = "tests/model/test_result.txt";
  std::string path_etalon_file = "tests/model/parser_2_result_to_assert.txt";
  s21::Figure* figure = new  s21::Figure();
  s21::Figure::FileParser *file_parser = new s21::Figure::FileParser();
  file_parser->Parser(figure, "tests/model/3d_objects/cube_good_2.obj");
  printToFile(*figure);
  bool result = compareFile(path_file, path_etalon_file);
  ASSERT_TRUE(result);
}

TEST(model, parser_throw_1) {
  s21::Figure* figure = new  s21::Figure();
  s21::Figure::FileParser *file_parser = new s21::Figure::FileParser();
    ASSERT_THROW(file_parser->Parser(figure,"tests/model/3d_objects/cube_bad_v_1.obj"),
               std::invalid_argument);
}

TEST(model, parser_throw_2) {
  s21::Figure* figure = new  s21::Figure();
  s21::Figure::FileParser *file_parser = new s21::Figure::FileParser();
    ASSERT_THROW(file_parser->Parser(figure,"tests/model/3d_objects/cube_bad_v_2.obj"),
               std::invalid_argument);
}

TEST(model, parser_throw_3) {
  s21::Figure* figure = new  s21::Figure();
  s21::Figure::FileParser *file_parser = new s21::Figure::FileParser();
    ASSERT_THROW(file_parser->Parser(figure,"tests/model/3d_objects/cube_bad_f.obj"),
               std::invalid_argument);
}

TEST(model, affine_1_move) {
  s21::Figure *figure_from = new s21::Figure();
  s21::Figure *figure_to = new s21::Figure();
  figure_from->AddVertex(1, 1, 1);
  figure_from->AddVertex(2, 2, 2);
  figure_from->AddVertex(3, 3, 3);
  figure_to = figure_from;
  s21::Figure *figure_assert = new s21::Figure();
  figure_assert->AddVertex(6, 1, 1);
  figure_assert->AddVertex(7, 2, 2);
  figure_assert->AddVertex(8, 3, 3);
  s21::AffineTransformations* aff_tran = new s21::AffineTransformations();
  aff_tran->SetMoveX(5);
  figure_from->TransformFigure(figure_to);
  ASSERT_TRUE(is_vertices_vectors_equal(figure_to->GetVerticesVector(), figure_assert->GetVerticesVector()));
}

TEST(model, affine_2_turn) {
  s21::Figure *figure_from = new s21::Figure();
  s21::Figure *figure_to = new s21::Figure();
  figure_from->AddVertex(1, 1, 1);
  figure_from->AddVertex(2, 2, 2);
  figure_from->AddVertex(3, 3, 3);
  figure_to = figure_from;
  s21::Figure *figure_assert = new s21::Figure();
  figure_assert->AddVertex(1, 1, -1);
  figure_assert->AddVertex(2, 2, -2);
  figure_assert->AddVertex(3, 3, -3);
  s21::AffineTransformations* aff_tran = new s21::AffineTransformations();
  aff_tran->SetAngleY(90);
  figure_from->TransformFigure(figure_to);
  ASSERT_TRUE(is_vertices_vectors_equal(figure_to->GetVerticesVector(), figure_assert->GetVerticesVector()));
}

TEST(model, affine_3_scale) {
  s21::Figure *figure_from = new s21::Figure();
  s21::Figure *figure_to = new s21::Figure();
  figure_from->AddVertex(1, 1, 1);
  figure_from->AddVertex(2, 2, 2);
  figure_from->AddVertex(3, 3, 3);
  figure_to = figure_from;
  s21::Figure *figure_assert = new s21::Figure();
  figure_assert->AddVertex(3, 3, 3);
  figure_assert->AddVertex(6, 6, 6);
  figure_assert->AddVertex(9, 9, 9);
  s21::AffineTransformations* aff_tran = new s21::AffineTransformations();
  aff_tran->SetScale(100);
  figure_from->TransformFigure(figure_to);
  ASSERT_TRUE(is_vertices_vectors_equal(figure_to->GetVerticesVector(), figure_assert->GetVerticesVector()));
}
