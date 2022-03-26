#include "mainwindow.hpp"
#include "./ui_mainwindow.h"
#include "mydialog.hpp"

#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
  : QMainWindow(parent)
  , ui(new Ui::MainWindow)
{
  ui->setupUi(this);
  setCentralWidget(ui->textEdit);
}

MainWindow::~MainWindow()
{
  delete ui;
}


void MainWindow::on_actionNew_Window_triggered()
{
  qDebug() << "New Window created";

  /** modal dialog (in stack), can't interact with parent in modal */
  // MyDialog mDialog;
  // mDialog.setModal(true);
  // mDialog.exec();

  mDialog = new MyDialog(this);
  mDialog->show();
}

