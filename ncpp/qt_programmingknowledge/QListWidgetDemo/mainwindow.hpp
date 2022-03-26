#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>
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

	private:
		Ui::MainWindow *ui;
};

void setupListWidget(QListWidget* lWidget);

#endif // MAINWINDOW_HPP
