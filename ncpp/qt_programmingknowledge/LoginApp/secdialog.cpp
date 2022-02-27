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
