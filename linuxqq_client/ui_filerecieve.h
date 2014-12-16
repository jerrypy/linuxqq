/********************************************************************************
** Form generated from reading UI file 'filerecieve.ui'
**
** Created: Wed Mar 12 08:22:55 2014
**      by: Qt User Interface Compiler version 4.8.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FILERECIEVE_H
#define UI_FILERECIEVE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QProgressBar>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_FileRecieve
{
public:
    QProgressBar *progressBar;
    QPushButton *pbCancel;
    QLabel *label;
    QPushButton *pbClose;

    void setupUi(QDialog *FileRecieve)
    {
        if (FileRecieve->objectName().isEmpty())
            FileRecieve->setObjectName(QString::fromUtf8("FileRecieve"));
        progressBar = new QProgressBar(FileRecieve);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setGeometry(QRect(52, 76, 261, 23));
        progressBar->setValue(24);
        pbCancel = new QPushButton(FileRecieve);
        pbCancel->setObjectName(QString::fromUtf8("pbCancel"));
        pbCancel->setGeometry(QRect(88, 126, 81, 27));
        label = new QLabel(FileRecieve);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(105, 16, 171, 41));
        QFont font;
        font.setPointSize(18);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        pbClose = new QPushButton(FileRecieve);
        pbClose->setObjectName(QString::fromUtf8("pbClose"));
        pbClose->setGeometry(QRect(199, 126, 81, 27));

        retranslateUi(FileRecieve);

        QMetaObject::connectSlotsByName(FileRecieve);
    } // setupUi

    void retranslateUi(QDialog *FileRecieve)
    {
        FileRecieve->setWindowTitle(QApplication::translate("FileRecieve", "Dialog", 0, QApplication::UnicodeUTF8));
        pbCancel->setText(QApplication::translate("FileRecieve", "\345\217\226\346\266\210", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("FileRecieve", "\347\255\211\345\276\205\346\216\245\346\224\266\346\226\207\344\273\266...", 0, QApplication::UnicodeUTF8));
        pbClose->setText(QApplication::translate("FileRecieve", "\345\205\263\351\227\255", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class FileRecieve: public Ui_FileRecieve {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FILERECIEVE_H
