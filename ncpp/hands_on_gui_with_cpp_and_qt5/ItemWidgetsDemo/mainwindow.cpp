#include "mainwindow.hpp"
#include "./ui_mainwindow.h"

#include <QDebug>
#include <QListWidgetItem>
#include <QTreeWidgetItem>
#include <QTableWidgetItem>

MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent)
	, ui(new Ui::MainWindow)
{
	ui->setupUi(this);

	// listWidget
	ui->listWidget->addItem("test item");

	QListWidgetItem* listItem = new QListWidgetItem;
	listItem->setText("test item2");
	listItem->setData(100, 1000);
	ui->listWidget->addItem(listItem);

	qDebug() << ui->listWidget->item(6)->data(100);

	// treewidget
	QTreeWidgetItem* testTreeItem1 = new QTreeWidgetItem;
	testTreeItem1->setText(0, "Test Item");
	ui->treeWidget->addTopLevelItem(testTreeItem1);

	QTreeWidgetItem* testTreeItem2 = new QTreeWidgetItem();
	testTreeItem2->setText(0, "Test Item2");
	testTreeItem2->setText(1, "Test Value2");
	ui->treeWidget->topLevelItem(2)->addChild(testTreeItem2);

	// tableWidget
	QTableWidgetItem *testTableItem1 = new QTableWidgetItem();
	testTableItem1->setText("t.1");
	ui->tableWidget->setItem(1, 2, testTableItem1);

	QTableWidget* tb = new QTableWidget();
	tb->setRowCount(2);
	tb->setColumnCount(3);
	// tb->setItem(1, 2, testTableItem1);
	// qDebug() << tb->itemAt(1, 2)->text();

	if (listItem) delete listItem;
	if (testTreeItem1) delete testTreeItem1;
	if (testTreeItem2) delete testTreeItem2;
	if (testTableItem1) delete testTableItem1;
}

MainWindow::~MainWindow()
{
	delete ui;
}

