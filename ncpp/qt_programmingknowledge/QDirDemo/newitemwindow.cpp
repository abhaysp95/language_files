#include "newitemwindow.hpp"
#include "ui_newitemwindow.h"

#include <QDebug>

NewItemWindow::NewItemWindow(const QDir& dir, QWidget *parent) :
	QDialog(parent),
	ui(new Ui::NewItemWindow),
	dir(dir)
{
	ui->setupUi(this);
	qDebug() << "newItemWindow, dir: " << this->dir.dirName() << '\n';
}

NewItemWindow::~NewItemWindow()
{
	delete ui;
}

void NewItemWindow::on_pushButton_clicked()
{

}

void NewItemWindow::on_pushButton_2_clicked() {

}

