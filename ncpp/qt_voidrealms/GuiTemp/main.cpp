#include "mainwindow.hpp"

#include <QApplication>
#include <QStyleFactory>
#include <QNetworkInformation>  // just for testing if project is using qt6 or not

int main(int argc, char *argv[])
{
  QApplication a(argc, argv);
  QApplication::setStyle(QStyleFactory::create("Adwaita-Dark"));
  MainWindow w;
  w.show();
  return a.exec();
}
