#include "mainwindow.hpp"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent)
	, ui(new Ui::MainWindow)
{
	ui->setupUi(this);

}

void setupComboBox(QComboBox* cmbBox) {
	for (size_t i {}; i < 10; i++) {
		cmbBox->addItem("item :" + QString::number(i + 1) );
	}
}

MainWindow::~MainWindow()
{
	delete ui;
}

