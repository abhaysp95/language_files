#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>
#include <secdialog.hpp>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
		Q_OBJECT

	public:
		MainWindow(QWidget *parent = nullptr);
		~MainWindow();

	private slots:
		void on_pushButton_clicked();
		void showWindow();
		void hideWindow();

	private:
		Ui::MainWindow *ui;
		SecDialog *secDialog;
};
#endif // MAINWINDOW_HPP
