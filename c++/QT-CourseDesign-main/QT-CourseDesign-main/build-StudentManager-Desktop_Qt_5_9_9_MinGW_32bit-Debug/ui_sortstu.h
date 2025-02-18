/********************************************************************************
** Form generated from reading UI file 'sortstu.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SORTSTU_H
#define UI_SORTSTU_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_sortstu
{
public:
    QLabel *label;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QComboBox *sortwhat;
    QComboBox *sortway;
    QComboBox *sortflag;
    QPushButton *sortbtn;
    QHBoxLayout *horizontalLayout;
    QTableView *tableView3;
    QTableView *tableView;
    QWidget *layoutWidget_2;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_4;
    QLabel *sumShow1;
    QLabel *label_3;
    QLabel *sumShow2;
    QLabel *label_5;
    QTableView *tableView2;

    void setupUi(QDialog *sortstu)
    {
        if (sortstu->objectName().isEmpty())
            sortstu->setObjectName(QStringLiteral("sortstu"));
        sortstu->resize(1200, 851);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(sortstu->sizePolicy().hasHeightForWidth());
        sortstu->setSizePolicy(sizePolicy);
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        sortstu->setFont(font);
        sortstu->setStyleSheet(QString::fromUtf8("background-image: url(:/images/\347\272\257\350\211\262.gif);"));
        label = new QLabel(sortstu);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(490, 30, 241, 51));
        label->setStyleSheet(QString::fromUtf8("font: 24pt \"\351\273\221\344\275\223\";"));
        label->setAlignment(Qt::AlignCenter);
        layoutWidget = new QWidget(sortstu);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(30, 100, 1141, 501));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        sortwhat = new QComboBox(layoutWidget);
        sortwhat->setObjectName(QStringLiteral("sortwhat"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Adobe \351\273\221\344\275\223 Std R"));
        font1.setPointSize(12);
        sortwhat->setFont(font1);

        horizontalLayout_2->addWidget(sortwhat);

        sortway = new QComboBox(layoutWidget);
        sortway->setObjectName(QStringLiteral("sortway"));
        sortway->setFont(font1);

        horizontalLayout_2->addWidget(sortway);

        sortflag = new QComboBox(layoutWidget);
        sortflag->setObjectName(QStringLiteral("sortflag"));
        sortflag->setFont(font1);

        horizontalLayout_2->addWidget(sortflag);

        sortbtn = new QPushButton(layoutWidget);
        sortbtn->setObjectName(QStringLiteral("sortbtn"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(sortbtn->sizePolicy().hasHeightForWidth());
        sortbtn->setSizePolicy(sizePolicy1);
        sortbtn->setMinimumSize(QSize(120, 30));
        sortbtn->setMaximumSize(QSize(120, 30));
        sortbtn->setFont(font1);

        horizontalLayout_2->addWidget(sortbtn);

        horizontalLayout_2->setStretch(0, 2);
        horizontalLayout_2->setStretch(1, 2);
        horizontalLayout_2->setStretch(2, 1);
        horizontalLayout_2->setStretch(3, 1);

        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        tableView3 = new QTableView(layoutWidget);
        tableView3->setObjectName(QStringLiteral("tableView3"));

        horizontalLayout->addWidget(tableView3);

        tableView = new QTableView(layoutWidget);
        tableView->setObjectName(QStringLiteral("tableView"));

        horizontalLayout->addWidget(tableView);

        horizontalLayout->setStretch(0, 2);
        horizontalLayout->setStretch(1, 13);

        verticalLayout->addLayout(horizontalLayout);

        layoutWidget_2 = new QWidget(sortstu);
        layoutWidget_2->setObjectName(QStringLiteral("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(320, 610, 531, 41));
        verticalLayout_3 = new QVBoxLayout(layoutWidget_2);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        sumShow1 = new QLabel(layoutWidget_2);
        sumShow1->setObjectName(QStringLiteral("sumShow1"));
        sumShow1->setStyleSheet(QString::fromUtf8("font: 16pt \"\351\273\221\344\275\223\";\n"
"color: rgb(85, 170, 255);"));
        sumShow1->setAlignment(Qt::AlignCenter);

        horizontalLayout_4->addWidget(sumShow1);

        label_3 = new QLabel(layoutWidget_2);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setStyleSheet(QString::fromUtf8("font: 16pt \"\351\273\221\344\275\223\";"));
        label_3->setAlignment(Qt::AlignCenter);

        horizontalLayout_4->addWidget(label_3);

        sumShow2 = new QLabel(layoutWidget_2);
        sumShow2->setObjectName(QStringLiteral("sumShow2"));
        sumShow2->setStyleSheet(QString::fromUtf8("font: 16pt \"\351\273\221\344\275\223\";\n"
"color: rgb(85, 170, 255);"));
        sumShow2->setAlignment(Qt::AlignCenter);

        horizontalLayout_4->addWidget(sumShow2);

        label_5 = new QLabel(layoutWidget_2);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setStyleSheet(QString::fromUtf8("font: 16pt \"\351\273\221\344\275\223\";"));
        label_5->setAlignment(Qt::AlignCenter);

        horizontalLayout_4->addWidget(label_5);

        horizontalLayout_4->setStretch(0, 1);
        horizontalLayout_4->setStretch(1, 1);
        horizontalLayout_4->setStretch(2, 1);
        horizontalLayout_4->setStretch(3, 1);

        verticalLayout_3->addLayout(horizontalLayout_4);

        verticalLayout_3->setStretch(0, 2);
        tableView2 = new QTableView(sortstu);
        tableView2->setObjectName(QStringLiteral("tableView2"));
        tableView2->setGeometry(QRect(140, 670, 911, 151));
        layoutWidget->raise();
        label->raise();
        layoutWidget_2->raise();
        tableView2->raise();
        QWidget::setTabOrder(sortbtn, sortwhat);
        QWidget::setTabOrder(sortwhat, sortway);

        retranslateUi(sortstu);

        QMetaObject::connectSlotsByName(sortstu);
    } // setupUi

    void retranslateUi(QDialog *sortstu)
    {
        sortstu->setWindowTitle(QApplication::translate("sortstu", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("sortstu", "\347\273\237\350\256\241\345\222\214\346\216\222\345\272\217", Q_NULLPTR));
        sortwhat->clear();
        sortwhat->insertItems(0, QStringList()
         << QApplication::translate("sortstu", "\351\200\211\346\213\251\345\260\261\350\257\273\347\212\266\345\206\265", Q_NULLPTR)
         << QApplication::translate("sortstu", "\345\260\217\345\255\246\347\224\237", Q_NULLPTR)
         << QApplication::translate("sortstu", "\344\270\255\345\255\246\347\224\237", Q_NULLPTR)
         << QApplication::translate("sortstu", "\345\244\247\345\255\246\347\224\237", Q_NULLPTR)
        );
        sortway->clear();
        sortway->insertItems(0, QStringList()
         << QApplication::translate("sortstu", "\350\257\267\345\205\210\351\200\211\346\213\251\345\211\215\344\270\200\351\241\271", Q_NULLPTR)
        );
        sortflag->clear();
        sortflag->insertItems(0, QStringList()
         << QApplication::translate("sortstu", "\345\215\207\345\272\217", Q_NULLPTR)
         << QApplication::translate("sortstu", "\351\231\215\345\272\217", Q_NULLPTR)
        );
        sortbtn->setText(QApplication::translate("sortstu", "\346\216\222\345\272\217", Q_NULLPTR));
        sumShow1->setText(QApplication::translate("sortstu", "XXX", Q_NULLPTR));
        label_3->setText(QApplication::translate("sortstu", "\344\272\272\346\225\260\344\270\272", Q_NULLPTR));
        sumShow2->setText(QApplication::translate("sortstu", "XX", Q_NULLPTR));
        label_5->setText(QApplication::translate("sortstu", "\344\272\272\357\274\214\347\273\237\350\256\241\344\277\241\346\201\257\345\246\202\344\270\213", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class sortstu: public Ui_sortstu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SORTSTU_H
