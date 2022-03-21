#include "mainwindow.hpp"
#include "./ui_mainwindow.h"

#include <QMessageBox>

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


void MainWindow::on_actionNew_triggered()
{
	QMessageBox::information(this, "New File", "This dialog shows that new file will be added");
}


void MainWindow::on_actionOpen_triggered()
{
	QMessageBox::information(this, "Open File", "This dialog shows that a file will be opened");
}


void MainWindow::on_actionQuit_triggered()
{
	QMessageBox::information(this, "Quit File", "This dialog shows that the file will quit");
	QApplication::exit(0);
}

