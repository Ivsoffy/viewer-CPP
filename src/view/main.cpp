#include <QApplication>

#include "mainwindow.h"
#include "../controller/Controller.h"
#include "../model/Facade.h"

int main(int argc, char *argv[]) {
  setlocale(LC_ALL, "C");
  QApplication a(argc, argv);
  s21::Facade model;
  s21::Controller controller(&model);
  MainWindow w(&controller);
  w.show();
  return a.exec();
}