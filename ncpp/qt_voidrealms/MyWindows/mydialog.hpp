#ifndef MYDIALOG_HPP
#define MYDIALOG_HPP

#include <QDialog>

namespace Ui {
  class MyDialog;
}

class MyDialog : public QDialog
{
  Q_OBJECT

public:
  explicit MyDialog(QWidget *parent = nullptr);
  ~MyDialog();

private:
  Ui::MyDialog *ui;
};

#endif // MYDIALOG_HPP
