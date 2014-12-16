/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Wed Mar 12 08:22:55 2014
**      by: Qt User Interface Compiler version 4.8.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QFontComboBox>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QPushButton>
#include <QtGui/QTextBrowser>
#include <QtGui/QTextEdit>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QTextBrowser *tbMsg;
    QFontComboBox *fontComboBox;
    QComboBox *comboBox;
    QTextBrowser *tbHistory;
    QTextEdit *teSendMsg;
    QPushButton *pbClose;
    QPushButton *pbSend;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(682, 375);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        tbMsg = new QTextBrowser(centralwidget);
        tbMsg->setObjectName(QString::fromUtf8("tbMsg"));
        tbMsg->setGeometry(QRect(6, 6, 411, 211));
        fontComboBox = new QFontComboBox(centralwidget);
        fontComboBox->setObjectName(QString::fromUtf8("fontComboBox"));
        fontComboBox->setGeometry(QRect(6, 220, 181, 27));
        comboBox = new QComboBox(centralwidget);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(190, 220, 51, 27));
        tbHistory = new QTextBrowser(centralwidget);
        tbHistory->setObjectName(QString::fromUtf8("tbHistory"));
        tbHistory->setGeometry(QRect(423, 6, 256, 361));
        teSendMsg = new QTextEdit(centralwidget);
        teSendMsg->setObjectName(QString::fromUtf8("teSendMsg"));
        teSendMsg->setGeometry(QRect(6, 250, 411, 91));
        pbClose = new QPushButton(centralwidget);
        pbClose->setObjectName(QString::fromUtf8("pbClose"));
        pbClose->setGeometry(QRect(292, 344, 61, 27));
        pbSend = new QPushButton(centralwidget);
        pbSend->setObjectName(QString::fromUtf8("pbSend"));
        pbSend->setGeometry(QRect(357, 344, 61, 27));
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "\350\201\212\345\244\251\346\241\206", 0, QApplication::UnicodeUTF8));
        pbClose->setText(QApplication::translate("MainWindow", "\345\205\263\351\227\255", 0, QApplication::UnicodeUTF8));
        pbSend->setText(QApplication::translate("MainWindow", "\345\217\221\351\200\201", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
