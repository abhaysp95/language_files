#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>
#include <QDir>
#include <QComboBox>
#include <QListWidget>

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


		void on_pushButton_2_clicked();

		void on_pushButton_3_clicked();

	private:
		Ui::MainWindow *ui;
		QDir dir;

		void listDirectories();
		void listFiles();
};
#endif // MAINWINDOW_HPP
