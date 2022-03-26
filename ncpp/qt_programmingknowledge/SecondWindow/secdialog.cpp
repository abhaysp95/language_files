#include "secdialog.hpp"
#include "ui_secdialog.h"

SecDialog::SecDialog(QWidget *parent) :
	QDialog(parent),
	ui(new Ui::SecDialog)
{
	ui->setupUi(this);
}

SecDialog::~SecDialog()
{
	delete ui;
}

void SecDialog::on_pushButton_clicked()
{
   emit showClicked();
}


void SecDialog::on_pushButton_2_clicked()
{
   emit hideClicked();
}


void SecDialog::on_horizontalSlider_valueChanged(int value)
{
	emit sliderValue(value);
}

