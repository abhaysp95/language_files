#include "mydialog.hpp"
#include "ui_mydialog.h"

MyDialog::MyDialog(QWidget *parent) :
  QDialog(parent),
  ui(new Ui::MyDialog)
{
  ui->setupUi(this);
}

MyDialog::~MyDialog()
{
  delete ui;
}
