#include "mainwindow.hpp"

#include <QApplication>
#include <QStyleFactory>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	// give style
	QApplication::setStyle(QStyleFactory::create("Adwaita-Dark"));

	MainWindow w;
	w.show();
	return a.exec();
}
