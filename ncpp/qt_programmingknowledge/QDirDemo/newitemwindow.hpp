#ifndef NEWITEMWINDOW_HPP
#define NEWITEMWINDOW_HPP

#include <QDialog>
#include <QDir>

namespace Ui {
	class NewItemWindow;
}

class NewItemWindow : public QDialog
{
		Q_OBJECT

	public:
		explicit NewItemWindow(const QDir& dir, QWidget *parent = nullptr);
		~NewItemWindow();

	private slots:
		void on_pushButton_clicked();

		void on_pushButton_2_clicked();

	private:
		Ui::NewItemWindow *ui;
		const QDir& dir;
};

#endif // NEWITEMWINDOW_HPP
