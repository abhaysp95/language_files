#include "mainwindow.hpp"
#include "./ui_mainwindow.h"

#include <QMessageBox>
#include <QPixmap>

MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent)
	, ui(new Ui::MainWindow)
{
	ui->setupUi(this);
	QPixmap loginPic(":/resources/login_pic.jpg");
	ui->label_loginPic->setPixmap(loginPic.scaled(ui->label_loginPic->width(),
												  ui->label_loginPic->height(), Qt::KeepAspectRatio));
}

MainWindow::~MainWindow()
{
	delete ui;
	delete secDialog;
}


void MainWindow::on_pushButton_login_clicked()
{
	QString userName = ui->lineEdit_userName->text();
	QString password = ui->lineEdit_password->text();

	if (userName == "test" && password == "test") {
		QMessageBox::information(this, "Login Successful", "Entered UserName and Password are correct.");
		this->secDialog = new SecDialog(this);
		secDialog->show();
	}
	else {
		QMessageBox::warning(this, "Login Failed", "Entered credentials are wrong");
	}
}

