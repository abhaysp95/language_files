#ifndef TABDIALOG_HPP
#define TABDIALOG_HPP

#include <QDialog>
#include <QTabWidget>
#include <QDialogButtonBox>

QT_BEGIN_NAMESPACE
namespace Ui { class TabDialog; }
QT_END_NAMESPACE

class TabDialog : public QDialog
{
		Q_OBJECT

	public:
		explicit TabDialog(std::string_view fileName, QWidget *parent = nullptr);
		~TabDialog();

	private:
		QTabWidget *tabWidget;
		QDialogButtonBox *buttonBox;
		Ui::TabDialog *ui;
};
#endif // TABDIALOG_HPP
