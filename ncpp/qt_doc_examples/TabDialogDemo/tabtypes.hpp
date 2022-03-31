#ifndef TABTYPES_H
#define TABTYPES_H

#include <QWidget>
#include <QFileInfo>

class GeneralTab : public QWidget
{
		Q_OBJECT

	public:
		explicit GeneralTab(const QFileInfo &fileInfo, QWidget *parent = nullptr);
};

class PermissionsTab : public QWidget
{
		Q_OBJECT

	public:
		explicit PermissionsTab(const QFileInfo &fileInfo, QWidget *parent = nullptr);
};

class ApplicationsTab : public QWidget
{
		Q_OBJECT

	public:
		explicit ApplicationsTab(const QFileInfo &fileInfo, QWidget *parent = nullptr);
};

#endif
