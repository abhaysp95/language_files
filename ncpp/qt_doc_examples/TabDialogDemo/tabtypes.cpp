#include "tabtypes.hpp"

#include <QLabel>
#include <QLineEdit>
#include <QDateTime>
#include <QVBoxLayout>
#include <QGroupBox>
#include <QCheckBox>
#include <QListWidget>
#include <QStringList>

GeneralTab::GeneralTab(const QFileInfo &fileInfo, QWidget *parent)
	: QWidget(parent)
{
	QLabel *fileNameLabel = new QLabel(tr("File Name:"));
	QLineEdit *fileNameEdit = new QLineEdit(fileInfo.fileName());

	QLabel *pathLabel = new QLabel(tr("Path:"));
	QLabel *pathValueLabel = new QLabel(fileInfo.absoluteFilePath());
	pathValueLabel->setFrameStyle(QFrame::StyledPanel | QFrame::Sunken);

	QLabel *sizeLabel = new QLabel(tr("Size:"));
	qlonglong size = fileInfo.size() / 1024;
	QLabel *sizeValueLabel = new QLabel(tr("%1 K").arg(size));
	sizeValueLabel->setFrameStyle(QFrame::StyledPanel | QFrame::Sunken);

	QLabel *lastReadLabel = new QLabel(tr("Last Read:"));
	QLabel *lastReadValueLabel = new QLabel(fileInfo.lastRead().toString());
	lastReadValueLabel->setFrameStyle(QFrame::StyledPanel | QFrame::Sunken);

	QLabel *lastModLabel = new QLabel(tr("Last Modified:"));
	QLabel *lastModValueLabel = new QLabel(fileInfo.lastModified().toString());
	lastModValueLabel->setFrameStyle(QFrame::StyledPanel | QFrame::Sunken);

	QVBoxLayout *mainLayout = new QVBoxLayout;
	mainLayout->addWidget(fileNameLabel);
	mainLayout->addWidget(fileNameEdit);
	mainLayout->addWidget(pathLabel);
	mainLayout->addWidget(pathValueLabel);
	mainLayout->addWidget(sizeLabel);
	mainLayout->addWidget(sizeValueLabel);
	mainLayout->addWidget(lastReadLabel);
	mainLayout->addWidget(lastReadValueLabel);
	mainLayout->addWidget(lastModLabel);
	mainLayout->addWidget(lastModValueLabel);
	mainLayout->addStretch(1);
	setLayout(mainLayout);
}

PermissionsTab::PermissionsTab(const QFileInfo &fileInfo, QWidget *parent)
	: QWidget(parent)
{
	QGroupBox *permissionsGroup = new QGroupBox(tr("Permissions"));

	QCheckBox *readable = new QCheckBox(tr("Readable"));
	if (fileInfo.isReadable())
		readable->setChecked(true);

	QCheckBox *writable = new QCheckBox(tr("Writeable"));
	if (fileInfo.isWritable())
		readable->setChecked(true);

	QCheckBox *executable = new QCheckBox(tr("Executable"));
	if (fileInfo.isExecutable())
		executable->setChecked(true);

	QGroupBox *ownerGroup = new QGroupBox(tr("Ownership"));

	QLabel *ownerLabel = new QLabel(tr("Owner"));
	QLabel *ownerValueLabel = new QLabel(fileInfo.owner());
	ownerValueLabel->setFrameStyle(QFrame::StyledPanel | QFrame::Sunken);

	QLabel *groupLabel = new QLabel(tr("Group"));
	QLabel *groupValueLabel = new QLabel(fileInfo.group());
	groupValueLabel->setFrameStyle(QFrame::StyledPanel | QFrame::Sunken);

	QVBoxLayout *permissionsLayout = new QVBoxLayout;
	permissionsLayout->addWidget(readable);
	permissionsLayout->addWidget(writable);
	permissionsLayout->addWidget(executable);
	permissionsGroup->setLayout(permissionsLayout);

	QVBoxLayout *ownerLayout = new QVBoxLayout;
	ownerLayout->addWidget(ownerLabel);
	ownerLayout->addWidget(ownerValueLabel);
	ownerLayout->addWidget(groupLabel);
	ownerLayout->addWidget(groupValueLabel);
	ownerGroup->setLayout(ownerLayout);

	QVBoxLayout *mainLayout = new QVBoxLayout;
	mainLayout->addWidget(permissionsGroup);
	mainLayout->addWidget(ownerGroup);
	mainLayout->addStretch(1);
	setLayout(mainLayout);
}

ApplicationsTab::ApplicationsTab(const QFileInfo &fileInfo, QWidget *parent)
	: QWidget(parent)
{
	QLabel *topLabel = new QLabel(tr("Open With:"));

	QListWidget *applicationsListBox = new QListWidget;
	QStringList applications;

	for (size_t i {}; i <= 30; i++)
		applications.append(tr("Application %1").arg(i));

	applicationsListBox->insertItems(0, applications);

	QCheckBox *alwaysCheckBox;

	if (fileInfo.suffix().isEmpty())
		alwaysCheckBox = new QCheckBox(tr("Always use this application to open this type of file"));
	else
		alwaysCheckBox = new QCheckBox(tr("Always use this application to open this type of extension '%1'")
									   .arg(fileInfo.suffix()));

	QVBoxLayout *layout = new QVBoxLayout;
	layout->addWidget(topLabel);
	layout->addWidget(applicationsListBox);
	layout->addWidget(alwaysCheckBox);
	setLayout(layout);
}
