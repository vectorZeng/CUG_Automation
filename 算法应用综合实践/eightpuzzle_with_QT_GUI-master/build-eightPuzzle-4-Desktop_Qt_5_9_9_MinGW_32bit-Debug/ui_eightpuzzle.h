/********************************************************************************
** Form generated from reading UI file 'eightpuzzle.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EIGHTPUZZLE_H
#define UI_EIGHTPUZZLE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_eightPuzzle
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *init1;
    QLineEdit *init2;
    QLineEdit *init3;
    QLineEdit *init4;
    QLineEdit *init5;
    QLineEdit *init6;
    QLineEdit *init7;
    QLineEdit *init8;
    QLineEdit *init9;
    QLineEdit *final1;
    QLineEdit *final2;
    QLineEdit *final3;
    QLineEdit *final4;
    QLineEdit *final5;
    QLineEdit *final6;
    QLineEdit *final7;
    QLineEdit *final8;
    QLineEdit *final9;
    QPushButton *runButton;
    QPushButton *pushButton;
    QPushButton *closeButton;
    QLabel *show1;
    QLabel *show6;
    QLabel *show2;
    QLabel *show3;
    QLabel *show4;
    QLabel *show5;
    QLabel *show7;
    QLabel *show8;
    QLabel *show9;
    QPushButton *pushButton_2;
    QLabel *label_3;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *eightPuzzle)
    {
        if (eightPuzzle->objectName().isEmpty())
            eightPuzzle->setObjectName(QStringLiteral("eightPuzzle"));
        eightPuzzle->resize(707, 365);
        centralwidget = new QWidget(eightPuzzle);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 60, 151, 51));
        QFont font;
        font.setPointSize(20);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(220, 60, 151, 51));
        label_2->setFont(font);
        label_2->setAlignment(Qt::AlignCenter);
        init1 = new QLineEdit(centralwidget);
        init1->setObjectName(QStringLiteral("init1"));
        init1->setGeometry(QRect(10, 120, 31, 31));
        init2 = new QLineEdit(centralwidget);
        init2->setObjectName(QStringLiteral("init2"));
        init2->setGeometry(QRect(70, 120, 31, 31));
        init3 = new QLineEdit(centralwidget);
        init3->setObjectName(QStringLiteral("init3"));
        init3->setGeometry(QRect(130, 120, 31, 31));
        init4 = new QLineEdit(centralwidget);
        init4->setObjectName(QStringLiteral("init4"));
        init4->setGeometry(QRect(10, 180, 31, 31));
        init5 = new QLineEdit(centralwidget);
        init5->setObjectName(QStringLiteral("init5"));
        init5->setGeometry(QRect(70, 180, 31, 31));
        init6 = new QLineEdit(centralwidget);
        init6->setObjectName(QStringLiteral("init6"));
        init6->setGeometry(QRect(130, 180, 31, 31));
        init7 = new QLineEdit(centralwidget);
        init7->setObjectName(QStringLiteral("init7"));
        init7->setGeometry(QRect(10, 240, 31, 31));
        init8 = new QLineEdit(centralwidget);
        init8->setObjectName(QStringLiteral("init8"));
        init8->setGeometry(QRect(70, 240, 31, 31));
        init9 = new QLineEdit(centralwidget);
        init9->setObjectName(QStringLiteral("init9"));
        init9->setGeometry(QRect(130, 240, 31, 31));
        final1 = new QLineEdit(centralwidget);
        final1->setObjectName(QStringLiteral("final1"));
        final1->setGeometry(QRect(220, 120, 31, 31));
        final2 = new QLineEdit(centralwidget);
        final2->setObjectName(QStringLiteral("final2"));
        final2->setGeometry(QRect(280, 120, 31, 31));
        final3 = new QLineEdit(centralwidget);
        final3->setObjectName(QStringLiteral("final3"));
        final3->setGeometry(QRect(340, 120, 31, 31));
        final4 = new QLineEdit(centralwidget);
        final4->setObjectName(QStringLiteral("final4"));
        final4->setGeometry(QRect(220, 180, 31, 31));
        final5 = new QLineEdit(centralwidget);
        final5->setObjectName(QStringLiteral("final5"));
        final5->setGeometry(QRect(280, 180, 31, 31));
        final6 = new QLineEdit(centralwidget);
        final6->setObjectName(QStringLiteral("final6"));
        final6->setGeometry(QRect(340, 180, 31, 31));
        final7 = new QLineEdit(centralwidget);
        final7->setObjectName(QStringLiteral("final7"));
        final7->setGeometry(QRect(220, 240, 31, 31));
        final8 = new QLineEdit(centralwidget);
        final8->setObjectName(QStringLiteral("final8"));
        final8->setGeometry(QRect(280, 240, 31, 31));
        final9 = new QLineEdit(centralwidget);
        final9->setObjectName(QStringLiteral("final9"));
        final9->setGeometry(QRect(340, 240, 31, 31));
        runButton = new QPushButton(centralwidget);
        runButton->setObjectName(QStringLiteral("runButton"));
        runButton->setGeometry(QRect(240, 300, 112, 32));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(580, 40, 112, 32));
        closeButton = new QPushButton(centralwidget);
        closeButton->setObjectName(QStringLiteral("closeButton"));
        closeButton->setGeometry(QRect(580, 240, 112, 32));
        show1 = new QLabel(centralwidget);
        show1->setObjectName(QStringLiteral("show1"));
        show1->setGeometry(QRect(420, 130, 21, 16));
        show6 = new QLabel(centralwidget);
        show6->setObjectName(QStringLiteral("show6"));
        show6->setGeometry(QRect(500, 190, 21, 16));
        show2 = new QLabel(centralwidget);
        show2->setObjectName(QStringLiteral("show2"));
        show2->setGeometry(QRect(460, 130, 21, 16));
        show3 = new QLabel(centralwidget);
        show3->setObjectName(QStringLiteral("show3"));
        show3->setGeometry(QRect(500, 130, 21, 16));
        show4 = new QLabel(centralwidget);
        show4->setObjectName(QStringLiteral("show4"));
        show4->setGeometry(QRect(420, 190, 21, 16));
        show5 = new QLabel(centralwidget);
        show5->setObjectName(QStringLiteral("show5"));
        show5->setGeometry(QRect(460, 190, 21, 16));
        show7 = new QLabel(centralwidget);
        show7->setObjectName(QStringLiteral("show7"));
        show7->setGeometry(QRect(420, 250, 21, 16));
        show8 = new QLabel(centralwidget);
        show8->setObjectName(QStringLiteral("show8"));
        show8->setGeometry(QRect(460, 250, 21, 16));
        show9 = new QLabel(centralwidget);
        show9->setObjectName(QStringLiteral("show9"));
        show9->setGeometry(QRect(500, 250, 21, 16));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(580, 150, 112, 32));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(400, 70, 151, 31));
        label_3->setFont(font);
        label_3->setAlignment(Qt::AlignCenter);
        eightPuzzle->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(eightPuzzle);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        eightPuzzle->setStatusBar(statusbar);

        retranslateUi(eightPuzzle);
        QObject::connect(closeButton, SIGNAL(clicked()), eightPuzzle, SLOT(close()));

        QMetaObject::connectSlotsByName(eightPuzzle);
    } // setupUi

    void retranslateUi(QMainWindow *eightPuzzle)
    {
        eightPuzzle->setWindowTitle(QApplication::translate("eightPuzzle", "eightPuzzle", Q_NULLPTR));
        label->setText(QApplication::translate("eightPuzzle", "\345\210\235\345\247\213\347\237\251\351\230\265", Q_NULLPTR));
        label_2->setText(QApplication::translate("eightPuzzle", "\347\233\256\346\240\207\347\237\251\351\230\265", Q_NULLPTR));
        runButton->setText(QApplication::translate("eightPuzzle", "\345\274\200\345\247\213", Q_NULLPTR));
        pushButton->setText(QApplication::translate("eightPuzzle", "\345\205\263\344\272\216", Q_NULLPTR));
        closeButton->setText(QApplication::translate("eightPuzzle", "\345\205\263\351\227\255\347\250\213\345\272\217", Q_NULLPTR));
        show1->setText(QApplication::translate("eightPuzzle", "___", Q_NULLPTR));
        show6->setText(QApplication::translate("eightPuzzle", "___", Q_NULLPTR));
        show2->setText(QApplication::translate("eightPuzzle", "___", Q_NULLPTR));
        show3->setText(QApplication::translate("eightPuzzle", "___", Q_NULLPTR));
        show4->setText(QApplication::translate("eightPuzzle", "___", Q_NULLPTR));
        show5->setText(QApplication::translate("eightPuzzle", "___", Q_NULLPTR));
        show7->setText(QApplication::translate("eightPuzzle", "___", Q_NULLPTR));
        show8->setText(QApplication::translate("eightPuzzle", "___", Q_NULLPTR));
        show9->setText(QApplication::translate("eightPuzzle", "___", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("eightPuzzle", "\350\277\207\347\250\213\345\261\225\347\244\272", Q_NULLPTR));
        label_3->setText(QApplication::translate("eightPuzzle", "\344\270\255\351\227\264\350\277\207\347\250\213", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class eightPuzzle: public Ui_eightPuzzle {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EIGHTPUZZLE_H
