/********************************************************************************
** Form generated from reading UI file 'registerdialog.ui'
**
** Created: Wed Mar 12 08:22:55 2014
**      by: Qt User Interface Compiler version 4.8.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTERDIALOG_H
#define UI_REGISTERDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_RegisterDialog
{
public:
    QLabel *label_4;
    QLabel *label;
    QLineEdit *editName;
    QLabel *label_2;
    QLineEdit *editPass;
    QLineEdit *editNickName;
    QLabel *label_5;
    QLineEdit *editConfirmPass;
    QLabel *label_6;
    QComboBox *cbxSex;
    QLabel *label_3;
    QPushButton *pbQuit;
    QPushButton *pbOk;
    QLabel *label_7;
    QLineEdit *editServerIP;

    void setupUi(QDialog *RegisterDialog)
    {
        if (RegisterDialog->objectName().isEmpty())
            RegisterDialog->setObjectName(QString::fromUtf8("RegisterDialog"));
        RegisterDialog->resize(262, 300);
        label_4 = new QLabel(RegisterDialog);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(30, 100, 66, 17));
        label = new QLabel(RegisterDialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(80, 0, 121, 41));
        QFont font;
        font.setFamily(QString::fromUtf8("DejaVu Sans"));
        font.setPointSize(14);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        editName = new QLineEdit(RegisterDialog);
        editName->setObjectName(QString::fromUtf8("editName"));
        editName->setGeometry(QRect(100, 70, 113, 27));
        editName->setMaxLength(10);
        label_2 = new QLabel(RegisterDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(30, 72, 66, 17));
        editPass = new QLineEdit(RegisterDialog);
        editPass->setObjectName(QString::fromUtf8("editPass"));
        editPass->setGeometry(QRect(100, 100, 113, 27));
        editPass->setMaxLength(16);
        editPass->setEchoMode(QLineEdit::Password);
        editNickName = new QLineEdit(RegisterDialog);
        editNickName->setObjectName(QString::fromUtf8("editNickName"));
        editNickName->setGeometry(QRect(100, 160, 113, 27));
        editNickName->setMaxLength(12);
        label_5 = new QLabel(RegisterDialog);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(30, 130, 66, 17));
        editConfirmPass = new QLineEdit(RegisterDialog);
        editConfirmPass->setObjectName(QString::fromUtf8("editConfirmPass"));
        editConfirmPass->setGeometry(QRect(100, 130, 113, 27));
        editConfirmPass->setMaxLength(16);
        editConfirmPass->setEchoMode(QLineEdit::Password);
        label_6 = new QLabel(RegisterDialog);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(30, 200, 66, 17));
        cbxSex = new QComboBox(RegisterDialog);
        cbxSex->setObjectName(QString::fromUtf8("cbxSex"));
        cbxSex->setGeometry(QRect(100, 200, 78, 27));
        label_3 = new QLabel(RegisterDialog);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(30, 160, 66, 17));
        pbQuit = new QPushButton(RegisterDialog);
        pbQuit->setObjectName(QString::fromUtf8("pbQuit"));
        pbQuit->setGeometry(QRect(160, 250, 61, 27));
        pbOk = new QPushButton(RegisterDialog);
        pbOk->setObjectName(QString::fromUtf8("pbOk"));
        pbOk->setGeometry(QRect(50, 250, 61, 27));
        label_7 = new QLabel(RegisterDialog);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(30, 41, 66, 17));
        editServerIP = new QLineEdit(RegisterDialog);
        editServerIP->setObjectName(QString::fromUtf8("editServerIP"));
        editServerIP->setGeometry(QRect(100, 38, 113, 27));
        editServerIP->setMaxLength(10);
        QWidget::setTabOrder(editName, editPass);
        QWidget::setTabOrder(editPass, editConfirmPass);
        QWidget::setTabOrder(editConfirmPass, editNickName);
        QWidget::setTabOrder(editNickName, cbxSex);
        QWidget::setTabOrder(cbxSex, pbOk);
        QWidget::setTabOrder(pbOk, pbQuit);
        QWidget::setTabOrder(pbQuit, editServerIP);

        retranslateUi(RegisterDialog);
        QObject::connect(pbQuit, SIGNAL(clicked()), RegisterDialog, SLOT(close()));

        QMetaObject::connectSlotsByName(RegisterDialog);
    } // setupUi

    void retranslateUi(QDialog *RegisterDialog)
    {
        RegisterDialog->setWindowTitle(QApplication::translate("RegisterDialog", "\346\263\250\345\206\214\346\241\206", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("RegisterDialog", "\345\257\206\347\240\201", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("RegisterDialog", "\346\263\250\345\206\214\346\226\260\347\224\250\346\210\267", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("RegisterDialog", "\347\224\250\346\210\267\345\220\215", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("RegisterDialog", "\347\241\256\350\256\244\345\257\206\347\240\201", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("RegisterDialog", "\346\200\247\345\210\253", 0, QApplication::UnicodeUTF8));
        cbxSex->clear();
        cbxSex->insertItems(0, QStringList()
         << QApplication::translate("RegisterDialog", "\347\224\267", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("RegisterDialog", "\345\245\263", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("RegisterDialog", "\345\205\266\344\273\226", 0, QApplication::UnicodeUTF8)
        );
        label_3->setText(QApplication::translate("RegisterDialog", "\346\230\265\347\247\260", 0, QApplication::UnicodeUTF8));
        pbQuit->setText(QApplication::translate("RegisterDialog", "\345\217\226\346\266\210", 0, QApplication::UnicodeUTF8));
        pbOk->setText(QApplication::translate("RegisterDialog", " \347\241\256\345\256\232", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("RegisterDialog", "\346\234\215\345\212\241\345\231\250IP", 0, QApplication::UnicodeUTF8));
        editServerIP->setText(QApplication::translate("RegisterDialog", "127.0.0.1", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class RegisterDialog: public Ui_RegisterDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTERDIALOG_H
