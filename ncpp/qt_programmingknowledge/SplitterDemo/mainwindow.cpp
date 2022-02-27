#include "mainwindow.hpp"
#include "./ui_mainwindow.h"

#include <QMessageBox>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent)
	, ui(new Ui::MainWindow)
{
	ui->setupUi(this);
}

MainWindow::~MainWindow()
{
	delete ui;
}


void MainWindow::on_pushButton_6_clicked()
{
	QMessageBox::about(this, "About", "Showing Demo for QMessageBox, Splitter, Buddy, Tab & Layouts");
}


void MainWindow::on_pushButton_7_clicked()
{
	QMessageBox::aboutQt(this, "About QT");
}


void MainWindow::on_pushButton_3_clicked()
{
	QMessageBox::information(this, "Information", "An information is shown here");
}


void MainWindow::on_pushButton_4_clicked()
{
	QMessageBox::warning(this, "Warning", "Don't press the button again");
}


void MainWindow::on_pushButton_5_clicked()
{
	QMessageBox::StandardButton choice = QMessageBox::question(this, "Choice", "Want to Exit",
						  QMessageBox::Yes | QMessageBox::No);
	if (choice == QMessageBox::Yes) {
		qDebug() << "Exiting Application!!!";
		QApplication::exit();
	} else {
		qDebug() << "Exit procedure cancelled";
	}
}


void MainWindow::on_pushButton_8_clicked()
{
	QMessageBox::critical(this, "Error", "Your system will explode in 5min");
}
