#include "Controller.h"

#include <ctime>/////////////////////////////TODO
#include <chrono>/////////////////////TODO
using std::chrono::duration_cast;////////////////////////////TODO
using std::chrono::milliseconds;////////////////////////////TODO
using std::chrono::system_clock;////////////////////////////TODO
#include <iostream>////////////////////////////TODO

void s21::Controller::TransferFigureParams() {////////////
  // call func from fasad
  facade_->TrasformateFigure(*paramDTO_);
}

void s21::Controller::TransferObject(std::string file_name) {
  // call func from fasad
  facade_->SetPathToObject(file_name);
}

s21::GLBufferDTO s21::Controller::TransferGLBuffer() {/////////////////////////
  // call func from fasad

  std::cerr << ">>>>>>>TransferGLBuffer<<<<<<<" << std::endl;/////////////////////TODO
  auto millisec_start = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();/////////////////////TODO

  facade_->GetBuffer();
  s21::GLBufferDTO GLBuffDTO = s21::GLBufferDTO(
      facade_->GetVertexBuffer(), facade_->GetIndexBuffer(),
      facade_->GetIndicesSize(), facade_->GetVerticesSize(),
      facade_->GetEdges(),/////////
      facade_->GetVertices()/////////
      );

  auto millisec_end = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();/////////////////////TODO
  std::cerr << millisec_end - millisec_start  << "<<<<<<<<TransferGLBuffer>>>>>>>" << std::endl;/////////////////////TODO
  

  return GLBuffDTO;
}
