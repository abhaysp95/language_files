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

	private:
		Ui::SecDialog *ui;
};

#endif // SECDIALOG_HPP
