#include "mainwindow.hpp"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
  : QMainWindow(parent)
  , ui(new Ui::MainWindow)
{
  ui->setupUi(this);

  // connect first progressbar with slider
  connect(ui->horizontalSlider, SIGNAL(valueChanged(int)),
          ui->progressBar, SLOT(setValue(int)));
  // connect second progressbar with slider
  connect(ui->horizontalSlider, SIGNAL(valueChanged(int)),
          ui->progressBar_2, SLOT(setValue(int)));

  // disconnect first progressbar with slider
  disconnect(ui->horizontalSlider, SIGNAL(valueChanged(int)),
          ui->progressBar, SLOT(setValue(int)));
}

MainWindow::~MainWindow()
{
  delete ui;
}

