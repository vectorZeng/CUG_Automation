/********************************************************************************
** Form generated from reading UI file 'about.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ABOUT_H
#define UI_ABOUT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_about
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QPushButton *OKButton;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *about)
    {
        if (about->objectName().isEmpty())
            about->setObjectName(QStringLiteral("about"));
        about->resize(631, 336);
        centralwidget = new QWidget(about);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(210, 30, 191, 51));
        QFont font;
        font.setPointSize(20);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(180, 100, 261, 41));
        QFont font1;
        font1.setPointSize(15);
        label_2->setFont(font1);
        label_2->setAlignment(Qt::AlignCenter);
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(140, 200, 331, 51));
        label_3->setFont(font1);
        label_3->setAlignment(Qt::AlignCenter);
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(150, 150, 321, 61));
        label_4->setAlignment(Qt::AlignCenter);
        OKButton = new QPushButton(centralwidget);
        OKButton->setObjectName(QStringLiteral("OKButton"));
        OKButton->setGeometry(QRect(250, 250, 112, 32));
        about->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(about);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        about->setStatusBar(statusbar);

        retranslateUi(about);
        QObject::connect(OKButton, SIGNAL(clicked()), about, SLOT(close()));

        QMetaObject::connectSlotsByName(about);
    } // setupUi

    void retranslateUi(QMainWindow *about)
    {
        about->setWindowTitle(QApplication::translate("about", "MainWindow", Q_NULLPTR));
        label->setText(QApplication::translate("about", "\345\205\253\346\225\260\347\240\201\351\227\256\351\242\230\347\232\204\350\247\243\345\206\263", Q_NULLPTR));
        label_2->setText(QApplication::translate("about", "\344\275\234\350\200\205\357\274\232 CHENGWEN(@SENSENTE)", Q_NULLPTR));
        label_3->setText(QApplication::translate("about", "Copyright 2020. ALL RIGHTS RESERVED", Q_NULLPTR));
        label_4->setText(QApplication::translate("about", "\344\273\273\344\275\225\344\272\244\346\265\201/\351\227\256\351\242\230 \350\257\267\350\201\224\347\263\273 s1ensente@gmail.com", Q_NULLPTR));
        OKButton->setText(QApplication::translate("about", "\345\245\275\357\275\236", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class about: public Ui_about {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ABOUT_H
