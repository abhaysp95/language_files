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


void MainWindow::on_pushButton_clicked()
{
	/** list of message using QMessageBox class */
	/**
	 * @brief QMessageBox::about
	 * void about
	 * void aboutQt
	 * StandardButton critical
	 * StandardButton information
	 * StandardButton question
	 * StandardButton warning
	 */
	// QMessageBox::about(this, "My Title", "This is my custom message");
	QMessageBox::aboutQt(this, "About QT");
	// QMessageBox::question(this, "Critical Box", "This one is critical message");
}
