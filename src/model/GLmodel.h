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

 private:
  GLuint VertexBuffer_;
  GLuint IndexBuffer_;
  uint IndicesSize_;
  uint VerticesSize_;
};

#endif  // GL_MODEL_H
