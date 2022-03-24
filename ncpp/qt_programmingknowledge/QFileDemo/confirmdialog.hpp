#ifndef CONFIRMDIALOG_HPP
#define CONFIRMDIALOG_HPP

#include <QDialog>

namespace Ui {
	class ConfirmDialog;
}

class ConfirmDialog : public QDialog
{
		Q_OBJECT

	public:
		explicit ConfirmDialog(QWidget *parent = nullptr);
		~ConfirmDialog();

	signals:
		void updateChoice(bool);

	private slots:
		// void on_buttonBox_accepted();

		// void on_buttonBox_rejected();

		void updateRecieveFilename(QString);

		// void on_buttonBox_clicked(QAbstractButton *button);

		void on_pushButton_clicked();

		void on_pushButton_2_clicked();

	private:
		Ui::ConfirmDialog *ui;
		QString _filename_label;
};

#endif // CONFIRMDIALOG_HPP
