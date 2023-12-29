void OGLwidget::paintGL() {
  std::vector<float> cubeVertices = {
      // Верхняя грань
      -0.5, 0.5, -0.5, -0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, -0.5,
      // Нижняя грань
      -0.5, -0.5, -0.5, -0.5, -0.5, 0.5, 0.5, -0.5, 0.5, 0.5, -0.5, -0.5,
      // Боковые грани
      -0.5, -0.5, -0.5, -0.5, 0.5, -0.5, -0.5, 0.5, 0.5, -0.5, -0.5, 0.5, 0.5,
      -0.5, -0.5, 0.5, 0.5, -0.5, 0.5, 0.5, 0.5, 0.5, -0.5, 0.5};

  std::vector<unsigned int> cubeIndices = {// Верхняя грань
                                           0, 1, 1, 2, 2, 3, 3, 0,
                                           // Нижняя грань
                                           4, 5, 5, 6, 6, 7, 7, 4,
                                           // Боковые грани
                                           0, 4, 1, 5, 2, 6, 3, 7};

  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glLoadIdentity();

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(-2, 2, -2, 2, -2, 2);

  // shift to x,y,z
  glTranslated(shift_x, shift_y, shift_z);

  // rotate to x,y,z
  glRotated(rot_x, 1, 0, 0);
  glRotated(rot_y, 0, 1, 0);
  glRotated(rot_z, 0, 0, 1);

  //      glTranslatef(0.0f, 0.0f, 0.0f); // Перенос фигуры
  //              glRotatef(20.0f, 10.0f, 1.0f, 0.0f); // Поворот фигуры

  //      // Установка параметров проекции
  //              glMatrixMode(GL_PROJECTION);
  //              glLoadIdentity();
  //              qreal aspectRatio = qreal(1000) / qreal(700);
  //              glFrustum(-aspectRatio, aspectRatio, -1.0, 1.0, 1.0, 10.0);

  //      // Установка параметров камеры
  //      glMatrixMode(GL_MODELVIEW);
  //      glLoadIdentity();
  //      gluLookAt(3, 3, 3, 0, 0, 0, 0, 1, 0);

  // Создание буфера вершин
  GLuint vertexBuffer;
  glGenBuffers(1, &vertexBuffer);
  glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
  glBufferData(GL_ARRAY_BUFFER, cubeVertices.size() * sizeof(float),
               cubeVertices.data(), GL_STATIC_DRAW);

  // Создание буфера полигонов
  GLuint indexBuffer;
  glGenBuffers(1, &indexBuffer);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBuffer);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER,
               cubeIndices.size() * sizeof(unsigned int), cubeIndices.data(),
               GL_STATIC_DRAW);

  // Включение атрибута вершин
  glEnableClientState(GL_VERTEX_ARRAY);
  glVertexPointer(3, GL_FLOAT, 0, 0);

  // Отрисовка куба
  glDrawElements(GL_LINES, cubeIndices.size(), GL_UNSIGNED_INT, 0);

  // Отключение атрибута вершин
  glDisableClientState(GL_VERTEX_ARRAY);

  // Освобождение буфера вершин
  glDeleteBuffers(1, &vertexBuffer);

  // Освобождение буфера полигонов
  glDeleteBuffers(1, &indexBuffer);
}