#include "tabdialog.hpp"

#include <QApplication>
#include <QStyleFactory>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	// set style
	QApplication::setStyle(QStyleFactory::create("Adwaita-Dark"));

	TabDialog w("~/.cache/temp");
	w.show();
	return a.exec();
}
