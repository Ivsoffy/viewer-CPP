#include <QApplication>

#include "mainwindow.h"
#include "../controller/Controller.h"
#include "../model/Fasad.h"

int main(int argc, char *argv[]) {
  setlocale(LC_ALL, "C");
  QApplication a(argc, argv);

  MainWindow w;
  w.show();
  return a.exec();
}
