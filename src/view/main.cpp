#include <QApplication>

#include "../controller/controller.h"
#include "../model/facade.h"
#include "mainwindow.h"

int main(int argc, char *argv[]) {
  setlocale(LC_ALL, "C");
  QApplication a(argc, argv);
  s21::Facade model;
  s21::Controller controller(&model);
  MainWindow w(&controller);
  w.show();
  return a.exec();
}
