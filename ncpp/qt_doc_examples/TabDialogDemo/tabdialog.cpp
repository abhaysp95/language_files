#include "tabdialog.hpp"
#include "tabtypes.hpp"
#include "./ui_tabdialog.h"

#include <QFileInfo>
#include <QWidget>
#include <QVBoxLayout>

TabDialog::TabDialog(std::string_view fileName, QWidget *parent)
	: QDialog(parent)
	, ui(new Ui::TabDialog)
{
	QFileInfo fileInfo(fileName.data());

	this->tabWidget = new QTabWidget;
	this->tabWidget->addTab(new GeneralTab(fileInfo), tr("General"));
	this->tabWidget->addTab(new PermissionsTab(fileInfo), tr("Permissions"));
	this->tabWidget->addTab(new ApplicationsTab(fileInfo), tr("Applications"));

	this->buttonBox = new QDialogButtonBox(QDialogButtonBox::Ok
										   | QDialogButtonBox::Cancel);
	connect(this->buttonBox, &QDialogButtonBox::accepted, this, &QDialog::accept);
	connect(this->buttonBox, &QDialogButtonBox::rejected, this, &QDialog::reject);

	QVBoxLayout *mainLayout = new QVBoxLayout;
	mainLayout->addWidget(tabWidget);
	mainLayout->addWidget(buttonBox);
	setLayout(mainLayout);

	setWindowTitle(tr("Tab Dialog"));

	ui->setupUi(this);
}

TabDialog::~TabDialog()
{
	delete ui;
}

