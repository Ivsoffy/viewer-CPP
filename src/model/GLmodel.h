#ifndef GL_MODEL_H
#define GL_MODEL_H

#define GL_SILENCE_DEPRECATION

#include <QOpenGLFunctions>
#include <QOpenGLWidget>
#include <QWindow>

class GLmodel {
 public:
  GLmodel();

  void FillBufferData(std::vector<double> vertices,
                      std::vector<unsigned int> indices);

  GLuint GetVertexBuffer();
  GLuint GetIndexBuffer();
  uint GetIndicesSize();
  uint GetVerticesSize();

//  std::vector<double> cubeVertices = {
//      // Верхняя грань
//      -0.5, 0.5, -0.5, -0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, -0.5,
//      // Нижняя грань
//      -0.5, -0.5, -0.5, -0.5, -0.5, 0.5, 0.5, -0.5, 0.5, 0.5, -0.5, -0.5,
//      // Боковые грани
//      -0.5, -0.5, -0.5, -0.5, 0.5, -0.5, -0.5, 0.5, 0.5, -0.5, -0.5, 0.5, 0.5,
//      -0.5, -0.5, 0.5, 0.5, -0.5, 0.5, 0.5, 0.5, 0.5, -0.5, 0.5};

//  std::vector<unsigned int> cubeIndices = {
//      // Верхняя грань
//      0, 1, 1, 2, 2, 3, 3, 0,
//      // Нижняя грань
//      4, 5, 5, 6, 6, 7, 7, 4,
//      // Боковые грани
//      0, 4, 1, 5, 2, 6, 3, 7};

 private:
  GLuint VertexBuffer_;
  GLuint IndexBuffer_;
  uint IndicesSize_;
  uint VerticesSize_;
};

#endif  // GL_MODEL_H
