#include "Facade.h"

#include <chrono>  /////////////////////TODO
#include <ctime>   /////////////////////////////TODO
#include <iostream>
using std::chrono::duration_cast;  ////////////////////////////TODO
using std::chrono::milliseconds;   ////////////////////////////TODO
using std::chrono::system_clock;   ////////////////////////////TODO

s21::Facade::Facade() {
  affineTransformations_ = new AffineTransformations();
  fileParser_ = new Figure::FileParser();
}

void s21::Facade::SetPathToObject(std::string path) {
  // delete figure_def_;
  delete figure_draw_;
  // figure_def_ = new Figure();
  figure_draw_ = new Figure();
  fileParser_->Parser(GetFigureDraw(), path);
  // figure_draw_->copy_figure(figure_def_);
}

void s21::Facade::TrasformateFigure() {
  auto millisec_start =
      duration_cast<milliseconds>(system_clock::now().time_since_epoch())
          .count();  /////////////////////TODO
  //
  // figure_draw_->copy_figure(figure_def_);//90ms
  //
  auto millisec_end =
      duration_cast<milliseconds>(system_clock::now().time_since_epoch())
          .count();  /////////////////////TODO
  std::cerr << millisec_end - millisec_start << "<<copy_figure>>"
            << std::endl;  /////////////////////TODO

  millisec_start =
      duration_cast<milliseconds>(system_clock::now().time_since_epoch())
          .count();  /////////////////////TODO
  //
  //  affineTransformations_->TrasformateVectorOfVerteces(figure_draw_);//80ms
  figure_draw_->TransformFigure();  // 53ms
  // affineTransformations_->Trasformate();// ->TransformFigure();

  millisec_end =
      duration_cast<milliseconds>(system_clock::now().time_since_epoch())
          .count();  /////////////////////TODO
  std::cerr << millisec_end - millisec_start
            << "<<TrasformateVectorOfVerteces>>"
            << std::endl;  /////////////////////TODO
}
