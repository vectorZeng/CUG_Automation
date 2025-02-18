/********************************************************************************
** Form generated from reading UI file 'querystu.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QUERYSTU_H
#define UI_QUERYSTU_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_querystu
{
public:
    QLabel *label;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QComboBox *findwhat;
    QComboBox *findway;
    QLineEdit *findkey;
    QPushButton *findbtn;
    QTableView *tableView;
    QPushButton *btnChange;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QLineEdit *idChange;
    QLabel *label_5;
    QPushButton *btnDelete;

    void setupUi(QDialog *querystu)
    {
        if (querystu->objectName().isEmpty())
            querystu->setObjectName(QStringLiteral("querystu"));
        querystu->resize(850, 605);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(querystu->sizePolicy().hasHeightForWidth());
        querystu->setSizePolicy(sizePolicy);
        querystu->setMinimumSize(QSize(850, 605));
        querystu->setMaximumSize(QSize(850, 605));
        querystu->setStyleSheet(QString::fromUtf8("background-image: url(:/images/\347\272\257\350\211\262.gif);"));
        label = new QLabel(querystu);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(230, 30, 391, 41));
        label->setStyleSheet(QString::fromUtf8("font: 24pt \"\351\273\221\344\275\223\";"));
        label->setAlignment(Qt::AlignCenter);
        layoutWidget = new QWidget(querystu);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 100, 811, 201));
        verticalLayout_2 = new QVBoxLayout(layoutWidget);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        findwhat = new QComboBox(layoutWidget);
        findwhat->setObjectName(QStringLiteral("findwhat"));
        QFont font;
        font.setFamily(QString::fromUtf8("Adobe \351\273\221\344\275\223 Std R"));
        font.setPointSize(12);
        findwhat->setFont(font);

        horizontalLayout->addWidget(findwhat);

        findway = new QComboBox(layoutWidget);
        findway->setObjectName(QStringLiteral("findway"));
        findway->setFont(font);
        findway->setEditable(false);
        findway->setDuplicatesEnabled(false);
        findway->setFrame(true);

        horizontalLayout->addWidget(findway);

        findkey = new QLineEdit(layoutWidget);
        findkey->setObjectName(QStringLiteral("findkey"));
        findkey->setFont(font);

        horizontalLayout->addWidget(findkey);

        findbtn = new QPushButton(layoutWidget);
        findbtn->setObjectName(QStringLiteral("findbtn"));
        findbtn->setFont(font);

        horizontalLayout->addWidget(findbtn);

        horizontalLayout->setStretch(1, 3);
        horizontalLayout->setStretch(2, 11);
        horizontalLayout->setStretch(3, 2);

        verticalLayout->addLayout(horizontalLayout);


        verticalLayout_2->addLayout(verticalLayout);

        tableView = new QTableView(layoutWidget);
        tableView->setObjectName(QStringLiteral("tableView"));

        verticalLayout_2->addWidget(tableView);

        verticalLayout_2->setStretch(0, 1);
        verticalLayout_2->setStretch(1, 6);
        btnChange = new QPushButton(querystu);
        btnChange->setObjectName(QStringLiteral("btnChange"));
        btnChange->setGeometry(QRect(240, 530, 161, 61));
        btnChange->setStyleSheet(QString::fromUtf8("font: 22pt \"\351\273\221\344\275\223\";"));
        layoutWidget1 = new QWidget(querystu);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(20, 320, 811, 181));
        verticalLayout_3 = new QVBoxLayout(layoutWidget1);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        label_2 = new QLabel(layoutWidget1);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setStyleSheet(QString::fromUtf8("font: 75 22pt \"\351\230\277\351\207\214\345\267\264\345\267\264\346\231\256\346\203\240\344\275\223 B\";"));
        label_2->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(label_2);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        horizontalLayout_3->setStretch(0, 1);
        horizontalLayout_3->setStretch(1, 2);
        horizontalLayout_3->setStretch(2, 1);

        verticalLayout_3->addLayout(horizontalLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_3 = new QLabel(layoutWidget1);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setStyleSheet(QString::fromUtf8("font: 20pt \"\351\273\221\344\275\223\";"));
        label_3->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(label_3);

        idChange = new QLineEdit(layoutWidget1);
        idChange->setObjectName(QStringLiteral("idChange"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(idChange->sizePolicy().hasHeightForWidth());
        idChange->setSizePolicy(sizePolicy1);
        idChange->setMinimumSize(QSize(300, 110));
        idChange->setMaximumSize(QSize(300, 110));
        idChange->setStyleSheet(QString::fromUtf8("font: 26pt \"\351\273\221\344\275\223\";\n"
"color: rgb(85, 170, 255);"));
        idChange->setMaxLength(11);
        idChange->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(idChange);

        label_5 = new QLabel(layoutWidget1);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setStyleSheet(QString::fromUtf8("font: 20pt \"\351\273\221\344\275\223\";"));
        label_5->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(label_5);

        horizontalLayout_2->setStretch(0, 1);
        horizontalLayout_2->setStretch(1, 1);
        horizontalLayout_2->setStretch(2, 1);

        verticalLayout_3->addLayout(horizontalLayout_2);

        verticalLayout_3->setStretch(0, 1);
        verticalLayout_3->setStretch(1, 2);
        btnDelete = new QPushButton(querystu);
        btnDelete->setObjectName(QStringLiteral("btnDelete"));
        btnDelete->setGeometry(QRect(430, 530, 161, 61));
        btnDelete->setStyleSheet(QString::fromUtf8("font: 22pt \"\351\273\221\344\275\223\";"));
        QWidget::setTabOrder(findkey, findwhat);
        QWidget::setTabOrder(findwhat, findway);
        QWidget::setTabOrder(findway, findbtn);
        QWidget::setTabOrder(findbtn, tableView);
        QWidget::setTabOrder(tableView, btnChange);

        retranslateUi(querystu);

        QMetaObject::connectSlotsByName(querystu);
    } // setupUi

    void retranslateUi(QDialog *querystu)
    {
        querystu->setWindowTitle(QApplication::translate("querystu", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("querystu", "\346\237\245\350\257\242\345\255\246\347\224\237\344\277\241\346\201\257", Q_NULLPTR));
        findwhat->clear();
        findwhat->insertItems(0, QStringList()
         << QApplication::translate("querystu", "\350\257\267\351\200\211\346\213\251\345\260\261\350\257\273\346\203\205\345\206\265", Q_NULLPTR)
         << QApplication::translate("querystu", "\345\260\217\345\255\246\347\224\237", Q_NULLPTR)
         << QApplication::translate("querystu", "\344\270\255\345\255\246\347\224\237", Q_NULLPTR)
         << QApplication::translate("querystu", "\345\244\247\345\255\246\347\224\237", Q_NULLPTR)
        );
        findway->clear();
        findway->insertItems(0, QStringList()
         << QApplication::translate("querystu", "\350\257\267\351\200\211\346\213\251\346\237\245\350\257\242\346\226\271\345\274\217", Q_NULLPTR)
         << QApplication::translate("querystu", "\346\214\211\345\255\246\345\217\267\346\237\245\350\257\242", Q_NULLPTR)
         << QApplication::translate("querystu", "\346\214\211\345\247\223\345\220\215\346\237\245\350\257\242", Q_NULLPTR)
         << QApplication::translate("querystu", "\346\214\211\344\270\223\344\270\232\346\237\245\350\257\242", Q_NULLPTR)
        );
        findkey->setPlaceholderText(QApplication::translate("querystu", "\350\257\267\350\276\223\345\205\245\345\205\263\351\224\256\345\255\227\350\277\233\350\241\214\346\220\234\347\264\242", Q_NULLPTR));
        findbtn->setText(QApplication::translate("querystu", "\346\220\234\347\264\242", Q_NULLPTR));
        btnChange->setText(QApplication::translate("querystu", "\344\277\256\346\224\271", Q_NULLPTR));
        label_2->setText(QApplication::translate("querystu", "\344\277\256\346\224\271\344\277\241\346\201\257", Q_NULLPTR));
        label_3->setText(QApplication::translate("querystu", "\347\241\256\350\256\244\344\277\256\346\224\271\345\255\246\345\217\267\344\270\272", Q_NULLPTR));
        label_5->setText(QApplication::translate("querystu", "\347\232\204\345\255\246\347\224\237\344\277\241\346\201\257", Q_NULLPTR));
        btnDelete->setText(QApplication::translate("querystu", "\345\210\240\351\231\244", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class querystu: public Ui_querystu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QUERYSTU_H
