#include "confirmdialog.hpp"
#include "ui_confirmdialog.h"

#include <QDebug>

ConfirmDialog::ConfirmDialog(QWidget *parent) :
	QDialog(parent),
	ui(new Ui::ConfirmDialog)
{
	ui->setupUi(this);
	ui->label->setText(this->_filename_label + " already exists. Want to overwrite ?");
}

ConfirmDialog::~ConfirmDialog()
{
	delete ui;
}

// void ConfirmDialog::on_buttonBox_accepted()
// {
	// emit update_choice(true);
// }


// void ConfirmDialog::on_buttonBox_rejected()
// {
	// emit update_choice(false);
// }

void ConfirmDialog::updateRecieveFilename(QString name) {
	qDebug() << "updateRecieveFilename: " << name << '\n';
	this->_filename_label = name;
}

void ConfirmDialog::on_pushButton_clicked()
{
	emit updateChoice(true);
}


void ConfirmDialog::on_pushButton_2_clicked()
{
	emit updateChoice(false);
}

