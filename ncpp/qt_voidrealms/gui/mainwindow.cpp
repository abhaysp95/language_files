#include "mainwindow.hpp"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
  : QMainWindow(parent)
  , ui(new Ui::MainWindow)
{
  ui->setupUi(this);
  ui->pushButton->setText(QString("Close"));
}

MainWindow::~MainWindow()
{
  delete ui;
}

