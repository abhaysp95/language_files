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
	QString name = ui->radioButton->isChecked()
			? ui->radioButton->text() : (ui->radioButton_2->isChecked()
										 ? ui->radioButton_2->text() : "Unknown");

	QString pet {};
	const QVBoxLayout* vLayout2 = ui->verticalLayout_2;
	for (size_t i = 0; i < ui->verticalLayout_2->count(); i++) {
		QRadioButton* rButton = qobject_cast<QRadioButton *>(vLayout2->itemAt(i)->widget());
		if (rButton->isChecked()) {
			pet = rButton->text();
			break;
		}
	}
	pet = pet.isEmpty() ? "Nothing" : pet;

	QMessageBox::information(this, "Favorite", name + " likes " + pet);
}
