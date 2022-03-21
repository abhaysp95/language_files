#include "mainwindow.hpp"
#include "./ui_mainwindow.h"

#include <QListWidgetItem>
#include <QPalette>

MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent)
	, ui(new Ui::MainWindow)
{
	ui->setupUi(this);
	setupListWidget(ui->listWidget);
}

MainWindow::~MainWindow()
{
	delete ui;
}


void MainWindow::on_pushButton_clicked()
{
	static size_t selectedQListWidgetItemIndex = 0;
	QPalette lwPalette {};

	if (selectedQListWidgetItemIndex != ui->listWidget->currentRow()) {
		// reset previous selected item
		QListWidgetItem* selectedItem = ui->listWidget->item(selectedQListWidgetItemIndex);
		selectedItem->setBackground(lwPalette.brush(QPalette::Base));
		selectedItem->setForeground(lwPalette.brush(QPalette::ToolTipText));

		// set new color for current item
		// ui->listWidget->currentItem()->setBackground(Qt::gray);
		ui->listWidget->currentItem()->setBackground(lwPalette.brush(QPalette::Highlight));
		ui->listWidget->currentItem()->setForeground(lwPalette.brush(QPalette::HighlightedText));

		// set selected text to bold
		selectedQListWidgetItemIndex = ui->listWidget->currentRow();
	}
}

void setupListWidget(QListWidget* lWidget) {
	QList<QIcon> icons {
		QIcon(":/icons/icons/document-new.png"),
		QIcon(":/icons/icons/document-open.png"),
		QIcon(":/icons/icons/document-save.png")
	};
	QList<QString> names {"James", "Mark", "Harry"};

	for (size_t i {}; i < 3; i++) {
		lWidget->addItem(new QListWidgetItem(icons.at(i), names.at(i)));  // <-- attention
	}

	QList<QString> items = { "something", "nothing" };
	lWidget->addItems(items);
}


// QPalette::Window -> a general background color
// QPalette::WindowText -> a general foreground color
