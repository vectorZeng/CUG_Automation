/********************************************************************************
** Form generated from reading UI file 'show.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SHOW_H
#define UI_SHOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Show
{
public:
    QPushButton *done;
    QTextBrowser *result;

    void setupUi(QWidget *Show)
    {
        if (Show->objectName().isEmpty())
            Show->setObjectName(QStringLiteral("Show"));
        Show->resize(288, 398);
        done = new QPushButton(Show);
        done->setObjectName(QStringLiteral("done"));
        done->setGeometry(QRect(90, 320, 112, 32));
        result = new QTextBrowser(Show);
        result->setObjectName(QStringLiteral("result"));
        result->setGeometry(QRect(30, 30, 231, 281));

        retranslateUi(Show);

        QMetaObject::connectSlotsByName(Show);
    } // setupUi

    void retranslateUi(QWidget *Show)
    {
        Show->setWindowTitle(QApplication::translate("Show", "Form", Q_NULLPTR));
        done->setText(QApplication::translate("Show", "\345\245\275\357\275\236", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Show: public Ui_Show {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SHOW_H
