#include "mainwindow.hpp"
#include "./ui_mainwindow.h"

#include <QDir>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QDebug>

#include <confirmdialog.hpp>

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
	QString fileName = ui->lineEdit->text();
	if (fileName.isEmpty()) {
		fileName = QDir::currentPath() + "/new.txt";
	}

	qDebug() << "fileName (write): " << fileName << '\n';

	QFile file {fileName};

	if (file.exists()) {
		this->_choice_dialog = new ConfirmDialog(this);
		this->_choice_dialog->setModal(true);
		this->_choice_dialog->show();

		emit provideFilename(file.fileName());

		// signal and slot to provide filename
		connect(this, SIGNAL(provideFilename(QString)), this->_choice_dialog, SLOT(updateRecieveFilename(QString)));

		// signal and slot to update choice
		// connect(this->_choice_dialog, &ConfirmDialog::update_choice, this, &MainWindow::on_update_choice);
		connect(this->_choice_dialog, SIGNAL(updateChoice(bool)), this, SLOT(performUpdateChoice(bool)));

		qDebug() << "fileOverrideChoice: " << this->_file_override_choice << '\n';

		if (!this->_file_override_choice) {
			file.close();
			return;
		}
	}

	if (!file.open(QFile::WriteOnly | QFile::Text)) {
		QMessageBox::warning(this, "Error opening", "file not open");
	}

	QTextStream stream {&file};
	QString text = ui->plainTextEdit->toPlainText();
	stream << text;
	// stream.flush();
	file.flush();
	file.close();

	qDebug() << "at end" << '\n';
}


void MainWindow::on_pushButton_2_clicked()
{
	QString fileName = ui->lineEdit->text();
	if (fileName.isEmpty()) {
		fileName = QDir::currentPath() + "new.txt";
	}

	qDebug() << "fileName (read): " << fileName << '\n';

	QFile file {fileName};

	if (!file.open(QFile::ReadOnly | QFile::Text)) {
		QMessageBox::warning(this, "Error opening", "file not open");
	}

	QTextStream stream {&file};
	ui->plainTextEdit->setPlainText(stream.readAll());
	// stream.flush();
	file.flush();
	file.close();
}

void MainWindow::performUpdateChoice(bool choice) {
	qDebug() << "choice recieved: " << choice << '\n';
	this->_file_override_choice = choice;
}
