#ifndef SECDIALOG_HPP
#define SECDIALOG_HPP

#include <QDialog>

namespace Ui {
	class SecDialog;
}

class SecDialog : public QDialog
{
		Q_OBJECT

	public:
		explicit SecDialog(QWidget *parent = nullptr);
		~SecDialog();

	signals:
		void showClicked();
		void hideClicked();
		void sliderValue(int);

	private slots:
		void on_pushButton_clicked();

		void on_pushButton_2_clicked();

		void on_horizontalSlider_valueChanged(int value);

	private:
		Ui::SecDialog *ui;
};

#endif // SECDIALOG_HPP