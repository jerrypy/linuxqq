/********************************************************************************
** Form generated from reading UI file 'filesend.ui'
**
** Created: Wed Mar 12 08:22:55 2014
**      by: Qt User Interface Compiler version 4.8.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FILESEND_H
#define UI_FILESEND_H

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

class Ui_FileSend
{
public:
    QPushButton *pbCancel;
    QProgressBar *progressBar;
    QLabel *label;

    void setupUi(QDialog *FileSend)
    {
        if (FileSend->objectName().isEmpty())
            FileSend->setObjectName(QString::fromUtf8("FileSend"));
        FileSend->resize(382, 186);
        pbCancel = new QPushButton(FileSend);
        pbCancel->setObjectName(QString::fromUtf8("pbCancel"));
        pbCancel->setGeometry(QRect(140, 130, 81, 27));
        progressBar = new QProgressBar(FileSend);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setGeometry(QRect(60, 80, 261, 23));
        progressBar->setValue(24);
        label = new QLabel(FileSend);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(120, 20, 161, 41));
        QFont font;
        font.setPointSize(18);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);

        retranslateUi(FileSend);

        QMetaObject::connectSlotsByName(FileSend);
    } // setupUi

    void retranslateUi(QDialog *FileSend)
    {
        FileSend->setWindowTitle(QApplication::translate("FileSend", "Dialog", 0, QApplication::UnicodeUTF8));
        pbCancel->setText(QApplication::translate("FileSend", "\345\217\226\346\266\210", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("FileSend", "\346\226\207\344\273\266\344\274\240\350\276\223\344\270\255...", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class FileSend: public Ui_FileSend {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FILESEND_H
