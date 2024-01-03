#include "oglwidget.h"

void OGLwidget::initializeGL() {}

void OGLwidget::init_setttings() {
  //  init_set = &main_window->user_settings;
  //  view_type = (int)init_set->projection_type;

  //  line_type = (int)init_set->polygon_type;
  //  line_size = init_set->polygon_width;
  //  line_color_r = init_set->polygon_color.red;
  //  line_color_g = init_set->polygon_color.green;
  //  line_color_b = init_set->polygon_color.blue;

  //  vertex_type = (int)init_set->vertex_type;
  //  vertex_size = init_set->vertex_size;
  //  vertex_color_r = init_set->vertex_color.red;
  //  vertex_color_g = init_set->vertex_color.green;
  //  vertex_color_b = init_set->vertex_color.blue;

  //  background_color_r = init_set->background_color.red;
  //  background_color_g = init_set->background_color.green;
  //  background_color_b = init_set->background_color.blue;
}

// void OGLwidget::paintGL() {
//   if (!init_key) {
//     init_setttings();
//     init_key = 1;
//   }
//   if (need_paint) {

////      gl_model glModel(vertex_array, polygons_array, edges_counter,
/// total_edges); /      dto_buff *dto_b = glModel.getBuffer();

//      // Создание буфера вершин
//      glGenBuffers(1, &vertexBuffer);
//      glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
//      glBufferData(GL_ARRAY_BUFFER, sizeof(vertex_array), vertex_array,
//      GL_STATIC_DRAW);

//      // Создание буфера индексов
//      glGenBuffers(1, &indexBuffer);
//      glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBuffer);
//      glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(polygons_array),
//      polygons_array, GL_STATIC_DRAW);

//      glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
//      glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBuffer);

//      glEnableClientState(GL_VERTEX_ARRAY);
//       glVertexPointer(3, GL_FLOAT, sizeof(double)*3, BUFFER_OFFSET(0));    //
//       The starting point of the VBO, for the vertices

//    glClearColor(1.0 * background_color_r / 255, 1.0 * background_color_g /
//    255,
//                 1.0 * background_color_b / 255, 0);
//    glClear(GL_COLOR_BUFFER_BIT);

//    // buffer for z coord
//    glEnable(GL_DEPTH_TEST);

//    // for painting vertex
//    if (vertex_type != NONE) glMatrixMode(GL_MODELVIEW);

//    // load clear matrix
//    glLoadIdentity();

//    // defining the rendering mode
//    glEnableClientState(GL_VERTEX_ARRAY);

////     central projection
//    if (view_type) {
//      double fov = frustum_fov * M_PI / 180;
//      double frustum_near = frustum_hight / (2 * tan(fov / 2));
//      frustum_near *= fabs(scale);
//      glFrustum(-frustum_widht, frustum_widht, -frustum_hight, frustum_hight,
//                frustum_near, frustum_far);

//    } else {
//      glOrtho(-scale, scale, -scale, scale, -scale, scale);
//    }

//    // shift to x,y,z
//    glTranslated(shift_x, shift_y, shift_z);

//    // rotate to x,y,z
//    glRotated(rot_x, 1, 0, 0);
//    glRotated(rot_y, 0, 1, 0);
//    glRotated(rot_z, 0, 0, 1);

//    // get vertex_array to render
//    glVertexPointer(3, GL_DOUBLE, 0, vertex_array);
////    if (vertex_type != NONE) {
////      // size and color of vertex
////      glPointSize(vertex_size);
////      glColor3d(1.0 * vertex_color_r / 255, 1.0 * vertex_color_g / 255,
////                1.0 * vertex_color_b / 255);

////      if (vertex_type == CIRCLE) glEnable(GL_POINT_SMOOTH);

////      // paint vertex
////      glDrawArrays(GL_POINTS, 0, vertex_count);
////      if (vertex_type == CIRCLE) glDisable(GL_POINT_SMOOTH);
////    }

//    glVertexAttribPointer(vertexBuffer, 3, GL_FLOAT, GL_FALSE, 0, 0);
//        glEnableVertexAttribArray(vertexBuffer);

//    // type of dotted line
//    glLineStipple(1, 0x3333);

//    // size and color of polygon line
//    glLineWidth(line_size);
//    glColor3d(1.0 * line_color_r / 255, 1.0 * line_color_g / 255,
//              1.0 * line_color_b / 255);

//    uint pol_ar_shift = 0;

//    if (line_type) glEnable(GL_LINE_STIPPLE);
//    // paint polygons

////    for (uint i = 0; i < polygon_count; i++) {
//      glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT,0);
////      pol_ar_shift += edges_counter[i];
////    }
//    if (line_type) glDisable(GL_LINE_STIPPLE);

//    glDisableClientState(GL_VERTEX_ARRAY);

//  } else {
//    glClearColor(1.0 * background_color_r / 255, 1.0 * background_color_g /
//    255,
//                 1.0 * background_color_b / 255, 0);
//    glClear(GL_COLOR_BUFFER_BIT);
//  }
//}

// void OGLwidget::paintGL() {
// struct MyVertex
//   {
//     float x, y, z;        // Vertex
//   };

//  MyVertex pvertex[8];
//  // VERTEX 0
//  pvertex[0].x = 0.5;
//  pvertex[0].y = 0.5;
//  pvertex[0].z = 0.5;

//  // VERTEX 1
//  pvertex[1].x = 0.5;
//  pvertex[1].y = -0.5;
//  pvertex[1].z = 0.5;

//  // VERTEX 2
//  pvertex[2].x = -0.5;
//  pvertex[2].y = -0.5;
//  pvertex[2].z = 0.5;

//  // VERTEX 2
//  pvertex[3].x = -0.5;
//  pvertex[3].y = 0.5;
//  pvertex[3].z = 0.5;

//  pvertex[4].x = 0.5;
//  pvertex[4].y = 0.5;
//  pvertex[4].z = -0.5;

//  pvertex[5].x = 0.5;
//  pvertex[5].y = -0.5;
//  pvertex[5].z = -0.5;

//  pvertex[6].x = -0.5;
//  pvertex[6].y = 0.5;
//  pvertex[6].z = -0.5;

//  pvertex[7].x = -0.5;
//  pvertex[7].y = -0.5;
//  pvertex[7].z = -0.5;

//  glGenBuffers(1, &VertexVBOID);
//  glBindBuffer(GL_ARRAY_BUFFER, VertexVBOID);
//  glBufferData(GL_ARRAY_BUFFER, sizeof(MyVertex)*8, &pvertex[0].x,
//  GL_STATIC_DRAW);

//  ushort pindices[32];
//  pindices[0] = 0;
//  pindices[1] = 1;
//  pindices[2] = 1;
//  pindices[3] = 2;
//  pindices[4] = 2;
//  pindices[5] = 3;
//  pindices[6] = 3;
//  pindices[7] = 0;
//  pindices[8] = 0;
//  pindices[9] = 1;
//  pindices[10] = 1;
//  pindices[11] = 5;
//  pindices[12] = 5;
//  pindices[13] = 4;
//  pindices[14] = 4;
//  pindices[15] = 0;
//  pindices[16] = 4;
//  pindices[17] = 5;
//  pindices[18] = 5;
//  pindices[19] = 6;
//  pindices[20] = 6;
//  pindices[21] = 7;
//  pindices[22] = 7;
//  pindices[23] = 4;
//  pindices[24] = 6;
//  pindices[25] = 7;
//  pindices[26] = 7;
//  pindices[27] = 3;
//  pindices[28] = 3;
//  pindices[29] = 2;
//  pindices[30] = 2;
//  pindices[31] = 6;

//  glGenBuffers(1, &IndexVBOID);
//  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IndexVBOID);
//  glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(ushort)*32, pindices,
//  GL_STATIC_DRAW);

//  glBindBuffer(GL_ARRAY_BUFFER, VertexVBOID);
//  glEnableClientState(GL_VERTEX_ARRAY);

//  double fov = frustum_fov * M_PI / 180;
//        double frustum_near = frustum_hight / (2 * tan(fov / 2));
//        frustum_near *= fabs(scale);
//  glFrustum(-frustum_widht, frustum_widht, -frustum_hight, frustum_hight,
//                  frustum_near, frustum_far);

////  for (int i=0; i < vertex_count; i++) {
////      std::cerr << vertex_array[i].x << " ";
////      std::cerr << vertex_array[i].y << " ";
////      std::cerr << vertex_array[i].z << std::endl;
////    }
////  std::cerr << "wut!?" << std::endl;

////    // Создание буфера вершин
////    glGenBuffers(1, &vertexBuffer);
////    glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
////    glBufferData(GL_ARRAY_BUFFER, sizeof(vertex_array), vertex_array,
/// GL_STATIC_DRAW);

////    // Создание буфера индексов
////    glGenBuffers(1, &indexBuffer);
////    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBuffer);
////    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(polygons_array),
/// polygons_array, GL_STATIC_DRAW);

////    glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);

//    glVertexPointer(3, GL_FLOAT, sizeof(MyVertex), 0);    // The starting
//    point of the VBO, for the vertices

//    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IndexVBOID);

////    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBuffer);

//  glDrawElements(GL_LINES, 32, GL_UNSIGNED_SHORT, 0);    // The starting point
//  of the IBO
////  uint pol_ar_shift = 0;
////  for (uint i = 0; i < polygon_count; i++) {
////    glDrawElements(GL_LINES, 8, GL_UNSIGNED_INT, 0);
////    pol_ar_shift += edges_counter[i];
////  }
//}

////}
///

void OGLwidget::SetVertexBuffer(GLuint vertex_buffer) {
  VertexBuffer_ = vertex_buffer;
}
void OGLwidget::SetIndexBuffer(GLuint index_buffer) {
  IndexBuffer_ = index_buffer;
}
void OGLwidget::SetIndicesSize(GLuint indices_size) {
  IndecesSize_ = indices_size;
}
void OGLwidget::SetVerticesSize(GLuint vertices_size) {
  VerticesSize_ = vertices_size;
}

void OGLwidget::paintGL() {
  if (need_paint) {
  glClearColor(1.0 * background_color_r / 255, 1.0 * background_color_g / 255,
               1.0 * background_color_b / 255, 0);

  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glLoadIdentity();

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();

  if (view_type) {
    double fov = frustum_fov * M_PI / 180;
    double frustum_near = frustum_hight / (2 * tan(fov / 2));
    frustum_near *= fabs(scale);
    glFrustum(-frustum_widht, frustum_widht, -frustum_hight, frustum_hight,
              frustum_near, frustum_far);

  } else {
    glOrtho(-scale, scale, -scale, scale, -scale, scale);
  }

  //      // shift to x,y,z
  //      glTranslated(shift_x, shift_y, shift_z);

  //      // rotate to x,y,z
  //      glRotated(rot_x, 1, 0, 0);
  //      glRotated(rot_y, 0, 1, 0);
  //      glRotated(rot_z, 0, 0, 1);

  // type of dotted line
  if (line_type) {
    glLineStipple(1, 0x3333);
    glEnable(GL_LINE_STIPPLE);
  }

  glBindBuffer(GL_ARRAY_BUFFER, VertexBuffer_);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IndexBuffer_);

  // Включение атрибута вершин
  glEnableClientState(GL_VERTEX_ARRAY);
  glVertexPointer(3, GL_DOUBLE, 0, 0);

  if (vertex_type != NONE) {
    // size and color of vertex
    glPointSize(vertex_size);
    glColor3d(1.0 * vertex_color_r / 255, 1.0 * vertex_color_g / 255,
              1.0 * vertex_color_b / 255);

    if (vertex_type == CIRCLE) glEnable(GL_POINT_SMOOTH);

    // paint vertex
    glDrawArrays(GL_POINTS, 0, VerticesSize_);
    if (vertex_type == CIRCLE) glDisable(GL_POINT_SMOOTH);
  }

  glLineWidth(line_size);
  glColor3d(1.0 * line_color_r / 255, 1.0 * line_color_g / 255,
            1.0 * line_color_b / 255);

  // Отрисовка куба
  glDrawElements(GL_LINES, IndecesSize_, GL_UNSIGNED_INT, 0);

  // Отключение атрибута вершин
  glDisableClientState(GL_VERTEX_ARRAY);

  // Освобождение буфера вершин
  glDeleteBuffers(1, &VertexBuffer_);

  // Освобождение буфера полигонов
  glDeleteBuffers(1, &IndexBuffer_);
}
}
