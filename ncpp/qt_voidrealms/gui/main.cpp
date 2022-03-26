#include "mainwindow.hpp"

#include <QApplication>
#include <QStyleFactory>

int main(int argc, char *argv[])
{
  QApplication a(argc, argv);
  QApplication::setStyle(QStyleFactory::create("Adwaita-Dark"));
  MainWindow w;
  w.show();
  return a.exec();
}
