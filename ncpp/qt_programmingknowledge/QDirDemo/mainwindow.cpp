#include "mainwindow.hpp"
#include "./ui_mainwindow.h"

#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent)
	, ui(new Ui::MainWindow)
	// , dir(QDir::rootPath())
{
	ui->setupUi(this);


	// ui->comboBox->addItem(dir.absoluteFilePath("/"));
	dir.setPath(QDir::rootPath());
	ui->comboBox->addItem(dir.dirName());
	ui->comboBox->setCurrentIndex(0);

}

void MainWindow::listDirectories() {
	qDebug() << "listDirectories: " << dir.dirName() << '\n';

	for (QFileInfo& finfo: dir.entryInfoList()) {
		if (finfo.isDir()) {
			qDebug() << "\tdir: " << finfo.absoluteFilePath();
			ui->comboBox->addItem(finfo.fileName());  // not using absolutePath() or similar functions
		}
	}
}

void MainWindow::listFiles() {
	qDebug() << "listFiles: " << dir.dirName() << '\n';

	for (QFileInfo& finfo: dir.entryInfoList()) {
		if (finfo.isFile()) {
			ui->listWidget->addItem(finfo.fileName());
		}
	}
}


MainWindow::~MainWindow()
{
	delete ui;
}


void MainWindow::on_pushButton_clicked()
{

	if (this->dir != QDir::root() || ui->comboBox->currentText() != "") {
		qDebug() << "pushbutton: " << ui->comboBox->currentText() << '\n';
		this->dir.setPath(ui->comboBox->currentText());
	}


	ui->comboBox->clear();
	ui->listWidget->clear();
	// connect(ui->pushButton, SIGNAL(clicked()), ui->comboBox, SLOT(clear()));

	this->listDirectories();

	this->listFiles();
}


// void MainWindow::on_comboBox_activated(int index)
// {
	// this->dir.setPath(ui->comboBox->currentText());
// }

