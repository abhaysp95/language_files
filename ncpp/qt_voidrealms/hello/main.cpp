#include <QCoreApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
  QCoreApplication a(argc, argv);

  QString nStr = "Hello, World!!!";

  qDebug() << nStr;

  return a.exec();
}
