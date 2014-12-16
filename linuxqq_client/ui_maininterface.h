/********************************************************************************
** Form generated from reading UI file 'maininterface.ui'
**
** Created: Wed Mar 12 08:22:55 2014
**      by: Qt User Interface Compiler version 4.8.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAININTERFACE_H
#define UI_MAININTERFACE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QTableWidget>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainInterface
{
public:
    QTableWidget *tableWidget;
    QLabel *lblOnline;
    QPushButton *pbAll;
    QPushButton *pbExit;

    void setupUi(QWidget *MainInterface)
    {
        if (MainInterface->objectName().isEmpty())
            MainInterface->setObjectName(QString::fromUtf8("MainInterface"));
        MainInterface->resize(274, 384);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/ico/image/MSN-Messenger.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainInterface->setWindowIcon(icon);
        tableWidget = new QTableWidget(MainInterface);
        if (tableWidget->columnCount() < 2)
            tableWidget->setColumnCount(2);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/new/ico/image/User.png"), QSize(), QIcon::Normal, QIcon::Off);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setIcon(icon1);
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(3, 4, 271, 341));
        tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        lblOnline = new QLabel(MainInterface);
        lblOnline->setObjectName(QString::fromUtf8("lblOnline"));
        lblOnline->setGeometry(QRect(8, 350, 121, 31));
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        lblOnline->setFont(font);
        pbAll = new QPushButton(MainInterface);
        pbAll->setObjectName(QString::fromUtf8("pbAll"));
        pbAll->setGeometry(QRect(129, 350, 71, 31));
        pbExit = new QPushButton(MainInterface);
        pbExit->setObjectName(QString::fromUtf8("pbExit"));
        pbExit->setGeometry(QRect(202, 350, 71, 31));

        retranslateUi(MainInterface);

        QMetaObject::connectSlotsByName(MainInterface);
    } // setupUi

    void retranslateUi(QWidget *MainInterface)
    {
        MainInterface->setWindowTitle(QApplication::translate("MainInterface", "\347\224\250\346\210\267\345\210\227\350\241\250", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MainInterface", "\346\230\265\347\247\260", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("MainInterface", "\347\212\266\346\200\201", 0, QApplication::UnicodeUTF8));
        lblOnline->setText(QApplication::translate("MainInterface", "\345\234\250\347\272\277\347\224\250\346\210\267\357\274\232 0\344\272\272", 0, QApplication::UnicodeUTF8));
        pbAll->setText(QApplication::translate("MainInterface", "\347\276\244\350\201\212", 0, QApplication::UnicodeUTF8));
        pbExit->setText(QApplication::translate("MainInterface", "\351\200\200\345\207\272", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainInterface: public Ui_MainInterface {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAININTERFACE_H
