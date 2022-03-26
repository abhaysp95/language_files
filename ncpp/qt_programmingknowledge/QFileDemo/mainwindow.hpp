#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>

#include <confirmdialog.hpp>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
		Q_OBJECT

	public:
		MainWindow(QWidget *parent = nullptr);
		~MainWindow();

	signals:
		void provideFilename(QString);

	private slots:
		void on_pushButton_clicked();

		void on_pushButton_2_clicked();

		void performUpdateChoice(bool);

	private:
		Ui::MainWindow *ui;
		ConfirmDialog *_choice_dialog;
		bool _file_override_choice;
};
#endif // MAINWINDOW_HPP
