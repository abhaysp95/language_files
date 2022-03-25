#include "mainwindow.hpp"
#include "./ui_mainwindow.h"

#include <QMessageBox>
#include <QByteArray>

MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent)
	, ui(new Ui::MainWindow)
{
	ui->setupUi(this);

	this->_db = QSqlDatabase::addDatabase("QMYSQL");
	this->_db.setHostName("127.0.0.1");
	this->_db.setPort(3306);
	this->_db.setUserName("qt5demo");
	this->_db.setPassword("qt5password");
	this->_db.setDatabaseName("test");

	if (this->_db.open()) {
		qDebug() << "connected";

		QString command = "select * from login";
		QSqlQuery query {this->_db};

		if (query.exec(command)) {
			while(query.next()) {
				qDebug() << query.value("id").toString() << query.value("username").toString();
				QByteArray qba = query.value("password").toByteArray();
				for (auto b: qba) {
					qDebug() << "(for): " << b;
				}
				qDebug() << query.value("password").convert(12);
				qDebug() << query.value("password") << query.value("password").toString();
			}
		}
	} else {
		qDebug() << "not connected";
	}

}

MainWindow::~MainWindow()
{
	delete ui;
}


void MainWindow::on_submitButton_clicked()
{
	QString username = ui->userInput->text();
	QString password = ui->passwordInput->text();

	qDebug() << username << password;  // just to test (be careful)

	// QString command = "SELECT * FROM login WHERE username='" + username + "' AND AES_DECRYPT(" + password + "," + username + ")='" + password + "'";
	// qDebug() << command;
	// QSqlQuery query {this->_db};

	// if (query.exec()) {
		// if (query.size() > 0) {
			// QMessageBox::information(this, "Login Success", "Login successful. Welcome user id = " + query.value("id").toString());
		// } else {
			// QMessageBox::warning(this, "Login Failed", "Login failed. Check username and password again...");
		// }
	// }

	// get row for matching username
	QString command = "SELECT * FROM login WHERE username='" + username + "'";
	qDebug() << "(username): " << command;
	QSqlQuery query {this->_db};

	if (query.exec(command)) {
		if (query.size() > 0) {  // can't be more than 1 because of UNIQUE constraint
			command = "SELECT * FROM login WHERE username='"  + username + "' AND AES_DECRYPT(" + query.value("password").toByteArray() + "," + username + ")='" + password + "'";
			qDebug() << "(password): " << command;
			if (query.exec(command)) {
				if (query.size() > 0) {
					QMessageBox::information(this, "Login Success", "Login successful. Welcome user id = " + query.value("id").toString());
				} else {
					QMessageBox::warning(this, "Login Failed", "Login failed, password didn't matched. Try again....");
				}
			}
		} else {
			QMessageBox::warning(this, "Login Failed", "Login failed, username didn't matched. Try again....");
		}
	}
}

