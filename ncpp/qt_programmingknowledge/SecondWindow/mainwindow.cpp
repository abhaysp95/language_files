#include "mainwindow.hpp"
#include "./ui_mainwindow.h"

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
	delete secDialog;
}


void MainWindow::on_pushButton_clicked()
{
	/** Hide the widget (equivalent to setVisible(false)) */
	// hide();  // hide the parent before opening child window

	// modeless approach
	secDialog = new SecDialog(this);
	qDebug() << "Opening child window";
	secDialog->show();

	connect(secDialog, SIGNAL(showClicked()), this, SLOT(showWindow()));
	connect(secDialog, SIGNAL(hideClicked()), this, SLOT(hideWindow()));
	connect(secDialog, SIGNAL(sliderValue(int)), ui->progressBar, SLOT(setValue(int)));
}

void MainWindow::showWindow()
{
	if (isHidden()) {
		qDebug() << "MainWindow is hidden, making Visible";
		show();
	} else {
		qDebug() << "MainWindow is already visible, press \"Hide Parent\" button from child window";
	}
}

void MainWindow::hideWindow() {
	if (!isHidden()) {
		qDebug() << "MainWindow is visible, making it hidden";
		hide();
	} else {
		qDebug() << "MainWindow is already hidden, press \"Show Parent\" button from child window";
	}
}


/** how Signal and Slot works
 *  I'm going to explain the working based on the example I wrote.
 *  Task: make connection with signal and slot between parent and child window.
 *  Signal: A signal is emitted when a particular event occurs.
 *  Slot: A function called in response to a particual Signal (event).
 *
 *  When a button is pressed from the child Window, that is signal and for that event,
 *  we give it slot, like "on_pushbutton_clicked()". In those slots we emit our custom written signal.
 *  This signal is used in the "connect()" in MainWindow, and for the respective signals,
 *  custom slot functions are written.
 */
