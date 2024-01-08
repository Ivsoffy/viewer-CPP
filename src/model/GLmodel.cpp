#include "GLmodel.h"

GLmodel::GLmodel() {
//  // Создание буфера вершин
//  glGenBuffers(1, &VertexBuffer_);
//  glBindBuffer(GL_ARRAY_BUFFER, VertexBuffer_);

//  // Создание буфера индексов
//  glGenBuffers(1, &IndexBuffer_);
//  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IndexBuffer_);
}

void GLmodel::FillBufferData(std::vector<double> vertices,
                              std::vector<s21::Vertex> vertices_v,
                             std::vector<unsigned int> indices) {

  // Создание буфера вершин
  glGenBuffers(1, &VertexBuffer_);
  glBindBuffer(GL_ARRAY_BUFFER, VertexBuffer_);

  // Создание буфера индексов
  glGenBuffers(1, &IndexBuffer_);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IndexBuffer_);

  glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(double),
               vertices.data(), GL_STATIC_DRAW);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned int),
               indices.data(), GL_STATIC_DRAW);
  IndicesSize_ = indices.size();
  VerticesSize_ = vertices.size() / 3;

  Edges_ = indices;
  // Vertices_ = vertices;
  Vertices_ = vertices_v;
}

GLuint GLmodel::GetVertexBuffer() { return VertexBuffer_; }

GLuint GLmodel::GetIndexBuffer() { return IndexBuffer_; }

GLuint GLmodel::GetIndicesSize() { return IndicesSize_; }

GLuint GLmodel::GetVerticesSize() { return VerticesSize_; }

std::vector<unsigned int> GLmodel::GetEdges() { return Edges_; }/////
std::vector<s21::Vertex>  GLmodel::GetVertices() { return Vertices_; }/////
// std::vector<double>  GLmodel::GetVertices() { return Vertices_; }/////
