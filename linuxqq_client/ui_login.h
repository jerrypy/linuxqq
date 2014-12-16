/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created: Wed Mar 12 08:22:55 2014
**      by: Qt User Interface Compiler version 4.8.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Login
{
public:
    QLabel *lblName;
    QLabel *lblPass;
    QLineEdit *editName;
    QLineEdit *editPass;
    QPushButton *pbLogin;
    QPushButton *pbRegister;
    QLabel *label;
    QLineEdit *editServerIP;

    void setupUi(QDialog *Login)
    {
        if (Login->objectName().isEmpty())
            Login->setObjectName(QString::fromUtf8("Login"));
        Login->resize(324, 211);
        lblName = new QLabel(Login);
        lblName->setObjectName(QString::fromUtf8("lblName"));
        lblName->setGeometry(QRect(60, 80, 66, 17));
        lblPass = new QLabel(Login);
        lblPass->setObjectName(QString::fromUtf8("lblPass"));
        lblPass->setGeometry(QRect(62, 127, 66, 17));
        editName = new QLineEdit(Login);
        editName->setObjectName(QString::fromUtf8("editName"));
        editName->setGeometry(QRect(130, 74, 151, 27));
        editName->setMaxLength(10);
        editPass = new QLineEdit(Login);
        editPass->setObjectName(QString::fromUtf8("editPass"));
        editPass->setGeometry(QRect(130, 120, 151, 27));
        editPass->setMaxLength(16);
        editPass->setEchoMode(QLineEdit::Password);
        pbLogin = new QPushButton(Login);
        pbLogin->setObjectName(QString::fromUtf8("pbLogin"));
        pbLogin->setGeometry(QRect(80, 170, 61, 27));
        pbRegister = new QPushButton(Login);
        pbRegister->setObjectName(QString::fromUtf8("pbRegister"));
        pbRegister->setGeometry(QRect(190, 170, 61, 27));
        label = new QLabel(Login);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(60, 34, 66, 17));
        editServerIP = new QLineEdit(Login);
        editServerIP->setObjectName(QString::fromUtf8("editServerIP"));
        editServerIP->setGeometry(QRect(130, 30, 151, 27));

        retranslateUi(Login);

        QMetaObject::connectSlotsByName(Login);
    } // setupUi

    void retranslateUi(QDialog *Login)
    {
        Login->setWindowTitle(QApplication::translate("Login", "\347\231\273\345\275\225\346\241\206", 0, QApplication::UnicodeUTF8));
        lblName->setText(QApplication::translate("Login", "\347\224\250\346\210\267\345\220\215", 0, QApplication::UnicodeUTF8));
        lblPass->setText(QApplication::translate("Login", "\345\257\206\347\240\201", 0, QApplication::UnicodeUTF8));
        pbLogin->setText(QApplication::translate("Login", "\347\231\273\345\275\225", 0, QApplication::UnicodeUTF8));
        pbRegister->setText(QApplication::translate("Login", "\346\263\250\345\206\214", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Login", "\346\234\215\345\212\241\345\231\250IP", 0, QApplication::UnicodeUTF8));
        editServerIP->setText(QApplication::translate("Login", "127.0.0.1", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Login: public Ui_Login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
