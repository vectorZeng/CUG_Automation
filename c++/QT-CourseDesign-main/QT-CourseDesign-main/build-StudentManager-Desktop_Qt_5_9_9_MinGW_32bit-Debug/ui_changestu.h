/********************************************************************************
** Form generated from reading UI file 'changestu.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHANGESTU_H
#define UI_CHANGESTU_H

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
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_changestu
{
public:
    QLabel *label_8;
    QWidget *layoutWidget_5;
    QHBoxLayout *horizontalLayout_12;
    QLabel *label_14;
    QLineEdit *stus_Cmark;
    QWidget *layoutWidget_11;
    QHBoxLayout *horizontalLayout_18;
    QLabel *label_20;
    QLineEdit *stum_Gmark;
    QWidget *layoutWidget_7;
    QHBoxLayout *horizontalLayout_14;
    QLabel *label_16;
    QLineEdit *stum_Emark;
    QWidget *layoutWidget_6;
    QHBoxLayout *horizontalLayout_13;
    QLabel *label_15;
    QLineEdit *stus_Mmark;
    QWidget *layoutWidget_2;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_10;
    QLineEdit *stus_Emark;
    QWidget *layoutWidget_8;
    QHBoxLayout *horizontalLayout_15;
    QLabel *label_17;
    QLineEdit *stum_Mmark;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_9;
    QLineEdit *stul_Emark;
    QWidget *layoutWidget_9;
    QHBoxLayout *horizontalLayout_16;
    QLabel *label_18;
    QLineEdit *stum_Cmark;
    QWidget *layoutWidget_3;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_7;
    QComboBox *major;
    QSpacerItem *horizontalSpacer_6;
    QWidget *layoutWidget_4;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lid;
    QSpacerItem *horizontalSpacer_5;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *lname;
    QSpacerItem *horizontalSpacer_7;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QRadioButton *male;
    QRadioButton *female;
    QSpacerItem *horizontalSpacer_3;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QComboBox *lage;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_5;
    QComboBox *lstuclass;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_6;
    QRadioButton *stum;
    QWidget *layoutWidget_10;
    QHBoxLayout *horizontalLayout_17;
    QPushButton *btnok;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *btncancel;
    QWidget *layoutWidget_12;
    QHBoxLayout *horizontalLayout_19;
    QLabel *label_21;
    QLineEdit *stum_Hmark;
    QRadioButton *stul;
    QWidget *layoutWidget_13;
    QHBoxLayout *horizontalLayout_11;
    QLabel *label_13;
    QLineEdit *stul_Pmark;
    QRadioButton *stus;
    QWidget *layoutWidget_14;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_12;
    QLineEdit *stul_Mmark;
    QButtonGroup *buttonGroup;

    void setupUi(QDialog *changestu)
    {
        if (changestu->objectName().isEmpty())
            changestu->setObjectName(QStringLiteral("changestu"));
        changestu->resize(550, 630);
        changestu->setMinimumSize(QSize(550, 630));
        changestu->setMaximumSize(QSize(550, 630));
        QFont font;
        font.setFamily(QString::fromUtf8("Adobe \351\273\221\344\275\223 Std R"));
        changestu->setFont(font);
        changestu->setStyleSheet(QString::fromUtf8("background-image: url(:/images/\347\272\257\350\211\262.gif);"));
        label_8 = new QLabel(changestu);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(20, 10, 501, 41));
        label_8->setStyleSheet(QString::fromUtf8("font: 16pt \"\351\273\221\344\275\223\";"));
        label_8->setAlignment(Qt::AlignCenter);
        layoutWidget_5 = new QWidget(changestu);
        layoutWidget_5->setObjectName(QStringLiteral("layoutWidget_5"));
        layoutWidget_5->setGeometry(QRect(380, 310, 161, 27));
        horizontalLayout_12 = new QHBoxLayout(layoutWidget_5);
        horizontalLayout_12->setObjectName(QStringLiteral("horizontalLayout_12"));
        horizontalLayout_12->setContentsMargins(0, 0, 0, 0);
        label_14 = new QLabel(layoutWidget_5);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setStyleSheet(QStringLiteral("font: 10pt \"Agency FB\";"));

        horizontalLayout_12->addWidget(label_14);

        stus_Cmark = new QLineEdit(layoutWidget_5);
        stus_Cmark->setObjectName(QStringLiteral("stus_Cmark"));
        stus_Cmark->setStyleSheet(QStringLiteral("font: 10pt \"Agency FB\";"));
        stus_Cmark->setMaxLength(3);

        horizontalLayout_12->addWidget(stus_Cmark);

        horizontalLayout_12->setStretch(0, 3);
        horizontalLayout_12->setStretch(1, 1);
        layoutWidget_11 = new QWidget(changestu);
        layoutWidget_11->setObjectName(QStringLiteral("layoutWidget_11"));
        layoutWidget_11->setGeometry(QRect(20, 420, 161, 27));
        horizontalLayout_18 = new QHBoxLayout(layoutWidget_11);
        horizontalLayout_18->setObjectName(QStringLiteral("horizontalLayout_18"));
        horizontalLayout_18->setContentsMargins(0, 0, 0, 0);
        label_20 = new QLabel(layoutWidget_11);
        label_20->setObjectName(QStringLiteral("label_20"));
        label_20->setStyleSheet(QStringLiteral("font: 10pt \"Agency FB\";"));

        horizontalLayout_18->addWidget(label_20);

        stum_Gmark = new QLineEdit(layoutWidget_11);
        stum_Gmark->setObjectName(QStringLiteral("stum_Gmark"));
        stum_Gmark->setStyleSheet(QStringLiteral("font: 10pt \"Agency FB\";"));
        stum_Gmark->setMaxLength(3);

        horizontalLayout_18->addWidget(stum_Gmark);

        horizontalLayout_18->setStretch(0, 3);
        horizontalLayout_18->setStretch(1, 1);
        layoutWidget_7 = new QWidget(changestu);
        layoutWidget_7->setObjectName(QStringLiteral("layoutWidget_7"));
        layoutWidget_7->setGeometry(QRect(20, 380, 161, 27));
        horizontalLayout_14 = new QHBoxLayout(layoutWidget_7);
        horizontalLayout_14->setObjectName(QStringLiteral("horizontalLayout_14"));
        horizontalLayout_14->setContentsMargins(0, 0, 0, 0);
        label_16 = new QLabel(layoutWidget_7);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setStyleSheet(QStringLiteral("font: 10pt \"Agency FB\";"));

        horizontalLayout_14->addWidget(label_16);

        stum_Emark = new QLineEdit(layoutWidget_7);
        stum_Emark->setObjectName(QStringLiteral("stum_Emark"));
        stum_Emark->setStyleSheet(QStringLiteral("font: 10pt \"Agency FB\";"));
        stum_Emark->setMaxLength(3);

        horizontalLayout_14->addWidget(stum_Emark);

        horizontalLayout_14->setStretch(0, 3);
        horizontalLayout_14->setStretch(1, 1);
        layoutWidget_6 = new QWidget(changestu);
        layoutWidget_6->setObjectName(QStringLiteral("layoutWidget_6"));
        layoutWidget_6->setGeometry(QRect(200, 310, 161, 27));
        horizontalLayout_13 = new QHBoxLayout(layoutWidget_6);
        horizontalLayout_13->setObjectName(QStringLiteral("horizontalLayout_13"));
        horizontalLayout_13->setContentsMargins(0, 0, 0, 0);
        label_15 = new QLabel(layoutWidget_6);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setStyleSheet(QStringLiteral("font: 10pt \"Agency FB\";"));

        horizontalLayout_13->addWidget(label_15);

        stus_Mmark = new QLineEdit(layoutWidget_6);
        stus_Mmark->setObjectName(QStringLiteral("stus_Mmark"));
        stus_Mmark->setStyleSheet(QStringLiteral("font: 10pt \"Agency FB\";"));
        stus_Mmark->setMaxLength(3);

        horizontalLayout_13->addWidget(stus_Mmark);

        horizontalLayout_13->setStretch(0, 3);
        horizontalLayout_13->setStretch(1, 1);
        layoutWidget_2 = new QWidget(changestu);
        layoutWidget_2->setObjectName(QStringLiteral("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(20, 310, 161, 27));
        horizontalLayout_8 = new QHBoxLayout(layoutWidget_2);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        horizontalLayout_8->setContentsMargins(0, 0, 0, 0);
        label_10 = new QLabel(layoutWidget_2);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setStyleSheet(QStringLiteral("font: 10pt \"Agency FB\";"));

        horizontalLayout_8->addWidget(label_10);

        stus_Emark = new QLineEdit(layoutWidget_2);
        stus_Emark->setObjectName(QStringLiteral("stus_Emark"));
        stus_Emark->setStyleSheet(QStringLiteral("font: 10pt \"Agency FB\";"));
        stus_Emark->setMaxLength(3);

        horizontalLayout_8->addWidget(stus_Emark);

        horizontalLayout_8->setStretch(0, 3);
        horizontalLayout_8->setStretch(1, 1);
        layoutWidget_8 = new QWidget(changestu);
        layoutWidget_8->setObjectName(QStringLiteral("layoutWidget_8"));
        layoutWidget_8->setGeometry(QRect(200, 380, 161, 27));
        horizontalLayout_15 = new QHBoxLayout(layoutWidget_8);
        horizontalLayout_15->setObjectName(QStringLiteral("horizontalLayout_15"));
        horizontalLayout_15->setContentsMargins(0, 0, 0, 0);
        label_17 = new QLabel(layoutWidget_8);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setStyleSheet(QStringLiteral("font: 10pt \"Agency FB\";"));

        horizontalLayout_15->addWidget(label_17);

        stum_Mmark = new QLineEdit(layoutWidget_8);
        stum_Mmark->setObjectName(QStringLiteral("stum_Mmark"));
        stum_Mmark->setStyleSheet(QStringLiteral("font: 10pt \"Agency FB\";"));
        stum_Mmark->setMaxLength(3);

        horizontalLayout_15->addWidget(stum_Mmark);

        horizontalLayout_15->setStretch(0, 3);
        horizontalLayout_15->setStretch(1, 1);
        layoutWidget = new QWidget(changestu);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 530, 161, 27));
        horizontalLayout_7 = new QHBoxLayout(layoutWidget);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        horizontalLayout_7->setContentsMargins(0, 0, 0, 0);
        label_9 = new QLabel(layoutWidget);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setStyleSheet(QStringLiteral("font: 10pt \"Agency FB\";"));

        horizontalLayout_7->addWidget(label_9);

        stul_Emark = new QLineEdit(layoutWidget);
        stul_Emark->setObjectName(QStringLiteral("stul_Emark"));
        stul_Emark->setStyleSheet(QStringLiteral("font: 10pt \"Agency FB\";"));
        stul_Emark->setMaxLength(3);

        horizontalLayout_7->addWidget(stul_Emark);

        horizontalLayout_7->setStretch(0, 3);
        horizontalLayout_7->setStretch(1, 1);
        layoutWidget_9 = new QWidget(changestu);
        layoutWidget_9->setObjectName(QStringLiteral("layoutWidget_9"));
        layoutWidget_9->setGeometry(QRect(380, 380, 161, 27));
        horizontalLayout_16 = new QHBoxLayout(layoutWidget_9);
        horizontalLayout_16->setObjectName(QStringLiteral("horizontalLayout_16"));
        horizontalLayout_16->setContentsMargins(0, 0, 0, 0);
        label_18 = new QLabel(layoutWidget_9);
        label_18->setObjectName(QStringLiteral("label_18"));
        label_18->setStyleSheet(QStringLiteral("font: 10pt \"Agency FB\";"));

        horizontalLayout_16->addWidget(label_18);

        stum_Cmark = new QLineEdit(layoutWidget_9);
        stum_Cmark->setObjectName(QStringLiteral("stum_Cmark"));
        stum_Cmark->setStyleSheet(QStringLiteral("font: 10pt \"Agency FB\";"));
        stum_Cmark->setMaxLength(3);

        horizontalLayout_16->addWidget(stum_Cmark);

        horizontalLayout_16->setStretch(0, 3);
        horizontalLayout_16->setStretch(1, 1);
        layoutWidget_3 = new QWidget(changestu);
        layoutWidget_3->setObjectName(QStringLiteral("layoutWidget_3"));
        layoutWidget_3->setGeometry(QRect(20, 490, 471, 26));
        layoutWidget_3->setStyleSheet(QStringLiteral("font: 10pt \"Agency FB\";"));
        horizontalLayout_6 = new QHBoxLayout(layoutWidget_3);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
        label_7 = new QLabel(layoutWidget_3);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setStyleSheet(QStringLiteral("font: 10pt \"Agency FB\";"));

        horizontalLayout_6->addWidget(label_7);

        major = new QComboBox(layoutWidget_3);
        major->setObjectName(QStringLiteral("major"));
        major->setStyleSheet(QStringLiteral("font: 10pt \"Agency FB\";"));

        horizontalLayout_6->addWidget(major);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_6);

        horizontalLayout_6->setStretch(0, 1);
        horizontalLayout_6->setStretch(1, 3);
        horizontalLayout_6->setStretch(2, 8);
        layoutWidget_4 = new QWidget(changestu);
        layoutWidget_4->setObjectName(QStringLiteral("layoutWidget_4"));
        layoutWidget_4->setGeometry(QRect(20, 71, 501, 191));
        verticalLayout = new QVBoxLayout(layoutWidget_4);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(layoutWidget_4);
        label->setObjectName(QStringLiteral("label"));
        label->setStyleSheet(QStringLiteral("font: 10pt \"Agency FB\";"));

        horizontalLayout->addWidget(label);

        lid = new QLineEdit(layoutWidget_4);
        lid->setObjectName(QStringLiteral("lid"));
        lid->setStyleSheet(QStringLiteral("font: 10pt \"Agency FB\";"));
        lid->setMaxLength(11);
        lid->setEchoMode(QLineEdit::Normal);
        lid->setClearButtonEnabled(true);

        horizontalLayout->addWidget(lid);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_5);

        horizontalLayout->setStretch(0, 1);
        horizontalLayout->setStretch(1, 8);

        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_2 = new QLabel(layoutWidget_4);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setStyleSheet(QStringLiteral("font: 10pt \"Agency FB\";"));

        horizontalLayout_2->addWidget(label_2);

        lname = new QLineEdit(layoutWidget_4);
        lname->setObjectName(QStringLiteral("lname"));
        lname->setStyleSheet(QStringLiteral("font: 10pt \"Agency FB\";"));
        lname->setMaxLength(5);
        lname->setClearButtonEnabled(true);

        horizontalLayout_2->addWidget(lname);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_7);

        horizontalLayout_2->setStretch(0, 1);
        horizontalLayout_2->setStretch(1, 8);

        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_3 = new QLabel(layoutWidget_4);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setStyleSheet(QStringLiteral("font: 10pt \"Agency FB\";"));

        horizontalLayout_3->addWidget(label_3);

        male = new QRadioButton(layoutWidget_4);
        male->setObjectName(QStringLiteral("male"));
        male->setStyleSheet(QStringLiteral("font: 10pt \"Agency FB\";"));
        male->setCheckable(true);
        male->setChecked(false);

        horizontalLayout_3->addWidget(male);

        female = new QRadioButton(layoutWidget_4);
        female->setObjectName(QStringLiteral("female"));
        female->setStyleSheet(QStringLiteral("font: 10pt \"Agency FB\";"));

        horizontalLayout_3->addWidget(female);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);

        horizontalLayout_3->setStretch(0, 1);
        horizontalLayout_3->setStretch(1, 1);
        horizontalLayout_3->setStretch(2, 1);
        horizontalLayout_3->setStretch(3, 4);

        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_4 = new QLabel(layoutWidget_4);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setStyleSheet(QStringLiteral("font: 10pt \"Agency FB\";"));

        horizontalLayout_4->addWidget(label_4);

        lage = new QComboBox(layoutWidget_4);
        lage->setObjectName(QStringLiteral("lage"));

        horizontalLayout_4->addWidget(lage);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);

        horizontalLayout_4->setStretch(0, 1);
        horizontalLayout_4->setStretch(1, 6);
        horizontalLayout_4->setStretch(2, 12);

        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_5 = new QLabel(layoutWidget_4);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setStyleSheet(QStringLiteral("font: 10pt \"Agency FB\";"));

        horizontalLayout_5->addWidget(label_5);

        lstuclass = new QComboBox(layoutWidget_4);
        lstuclass->setObjectName(QStringLiteral("lstuclass"));

        horizontalLayout_5->addWidget(lstuclass);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_2);

        horizontalLayout_5->setStretch(0, 1);
        horizontalLayout_5->setStretch(1, 6);
        horizontalLayout_5->setStretch(2, 12);

        verticalLayout->addLayout(horizontalLayout_5);

        label_6 = new QLabel(layoutWidget_4);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setStyleSheet(QStringLiteral("font: 10pt \"Agency FB\";"));

        verticalLayout->addWidget(label_6);

        stum = new QRadioButton(changestu);
        buttonGroup = new QButtonGroup(changestu);
        buttonGroup->setObjectName(QStringLiteral("buttonGroup"));
        buttonGroup->addButton(stum);
        stum->setObjectName(QStringLiteral("stum"));
        stum->setGeometry(QRect(20, 340, 471, 31));
        stum->setStyleSheet(QStringLiteral("font: 10pt \"Agency FB\";"));
        layoutWidget_10 = new QWidget(changestu);
        layoutWidget_10->setObjectName(QStringLiteral("layoutWidget_10"));
        layoutWidget_10->setGeometry(QRect(160, 580, 221, 41));
        horizontalLayout_17 = new QHBoxLayout(layoutWidget_10);
        horizontalLayout_17->setObjectName(QStringLiteral("horizontalLayout_17"));
        horizontalLayout_17->setContentsMargins(0, 0, 0, 0);
        btnok = new QPushButton(layoutWidget_10);
        btnok->setObjectName(QStringLiteral("btnok"));

        horizontalLayout_17->addWidget(btnok);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_17->addItem(horizontalSpacer_4);

        btncancel = new QPushButton(layoutWidget_10);
        btncancel->setObjectName(QStringLiteral("btncancel"));

        horizontalLayout_17->addWidget(btncancel);

        horizontalLayout_17->setStretch(0, 5);
        horizontalLayout_17->setStretch(1, 2);
        horizontalLayout_17->setStretch(2, 5);
        layoutWidget_12 = new QWidget(changestu);
        layoutWidget_12->setObjectName(QStringLiteral("layoutWidget_12"));
        layoutWidget_12->setGeometry(QRect(200, 420, 161, 27));
        horizontalLayout_19 = new QHBoxLayout(layoutWidget_12);
        horizontalLayout_19->setObjectName(QStringLiteral("horizontalLayout_19"));
        horizontalLayout_19->setContentsMargins(0, 0, 0, 0);
        label_21 = new QLabel(layoutWidget_12);
        label_21->setObjectName(QStringLiteral("label_21"));
        label_21->setStyleSheet(QStringLiteral("font: 10pt \"Agency FB\";"));

        horizontalLayout_19->addWidget(label_21);

        stum_Hmark = new QLineEdit(layoutWidget_12);
        stum_Hmark->setObjectName(QStringLiteral("stum_Hmark"));
        stum_Hmark->setStyleSheet(QStringLiteral("font: 10pt \"Agency FB\";"));
        stum_Hmark->setMaxLength(3);

        horizontalLayout_19->addWidget(stum_Hmark);

        horizontalLayout_19->setStretch(0, 3);
        horizontalLayout_19->setStretch(1, 1);
        stul = new QRadioButton(changestu);
        buttonGroup->addButton(stul);
        stul->setObjectName(QStringLiteral("stul"));
        stul->setGeometry(QRect(20, 450, 471, 31));
        stul->setStyleSheet(QStringLiteral("font: 10pt \"Agency FB\";"));
        layoutWidget_13 = new QWidget(changestu);
        layoutWidget_13->setObjectName(QStringLiteral("layoutWidget_13"));
        layoutWidget_13->setGeometry(QRect(200, 530, 161, 27));
        horizontalLayout_11 = new QHBoxLayout(layoutWidget_13);
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        horizontalLayout_11->setContentsMargins(0, 0, 0, 0);
        label_13 = new QLabel(layoutWidget_13);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setStyleSheet(QStringLiteral("font: 10pt \"Agency FB\";"));

        horizontalLayout_11->addWidget(label_13);

        stul_Pmark = new QLineEdit(layoutWidget_13);
        stul_Pmark->setObjectName(QStringLiteral("stul_Pmark"));
        stul_Pmark->setStyleSheet(QStringLiteral("font: 10pt \"Agency FB\";"));
        stul_Pmark->setMaxLength(3);

        horizontalLayout_11->addWidget(stul_Pmark);

        horizontalLayout_11->setStretch(0, 3);
        horizontalLayout_11->setStretch(1, 1);
        stus = new QRadioButton(changestu);
        buttonGroup->addButton(stus);
        stus->setObjectName(QStringLiteral("stus"));
        stus->setGeometry(QRect(20, 270, 471, 31));
        stus->setStyleSheet(QStringLiteral("font: 10pt \"Agency FB\";"));
        layoutWidget_14 = new QWidget(changestu);
        layoutWidget_14->setObjectName(QStringLiteral("layoutWidget_14"));
        layoutWidget_14->setGeometry(QRect(380, 530, 161, 27));
        horizontalLayout_10 = new QHBoxLayout(layoutWidget_14);
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        horizontalLayout_10->setContentsMargins(0, 0, 0, 0);
        label_12 = new QLabel(layoutWidget_14);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setStyleSheet(QStringLiteral("font: 10pt \"Agency FB\";"));

        horizontalLayout_10->addWidget(label_12);

        stul_Mmark = new QLineEdit(layoutWidget_14);
        stul_Mmark->setObjectName(QStringLiteral("stul_Mmark"));
        stul_Mmark->setStyleSheet(QStringLiteral("font: 10pt \"Agency FB\";"));
        stul_Mmark->setMaxLength(3);

        horizontalLayout_10->addWidget(stul_Mmark);

        horizontalLayout_10->setStretch(0, 3);
        horizontalLayout_10->setStretch(1, 1);
        QWidget::setTabOrder(lid, lname);
        QWidget::setTabOrder(lname, male);
        QWidget::setTabOrder(male, female);
        QWidget::setTabOrder(female, lage);
        QWidget::setTabOrder(lage, lstuclass);
        QWidget::setTabOrder(lstuclass, stus);
        QWidget::setTabOrder(stus, stus_Emark);
        QWidget::setTabOrder(stus_Emark, stus_Mmark);
        QWidget::setTabOrder(stus_Mmark, stus_Cmark);
        QWidget::setTabOrder(stus_Cmark, stum);
        QWidget::setTabOrder(stum, stum_Emark);
        QWidget::setTabOrder(stum_Emark, stum_Mmark);
        QWidget::setTabOrder(stum_Mmark, stum_Cmark);
        QWidget::setTabOrder(stum_Cmark, stum_Gmark);
        QWidget::setTabOrder(stum_Gmark, stum_Hmark);
        QWidget::setTabOrder(stum_Hmark, stul);
        QWidget::setTabOrder(stul, major);
        QWidget::setTabOrder(major, stul_Emark);
        QWidget::setTabOrder(stul_Emark, stul_Pmark);
        QWidget::setTabOrder(stul_Pmark, stul_Mmark);
        QWidget::setTabOrder(stul_Mmark, btnok);
        QWidget::setTabOrder(btnok, btncancel);

        retranslateUi(changestu);

        QMetaObject::connectSlotsByName(changestu);
    } // setupUi

    void retranslateUi(QDialog *changestu)
    {
        changestu->setWindowTitle(QApplication::translate("changestu", "Dialog", Q_NULLPTR));
        label_8->setText(QApplication::translate("changestu", "\344\277\256\346\224\271\345\255\246\347\224\237\344\277\241\346\201\257", Q_NULLPTR));
        label_14->setText(QApplication::translate("changestu", "\350\257\255\346\226\207\346\210\220\347\273\251\357\274\232", Q_NULLPTR));
        label_20->setText(QApplication::translate("changestu", "\345\234\260\347\220\206\346\210\220\347\273\251\357\274\232", Q_NULLPTR));
        label_16->setText(QApplication::translate("changestu", "\350\213\261\350\257\255\346\210\220\347\273\251\357\274\232", Q_NULLPTR));
        label_15->setText(QApplication::translate("changestu", "\346\225\260\345\255\246\346\210\220\347\273\251\357\274\232", Q_NULLPTR));
        label_10->setText(QApplication::translate("changestu", "\350\213\261\350\257\255\346\210\220\347\273\251\357\274\232", Q_NULLPTR));
        label_17->setText(QApplication::translate("changestu", "\346\225\260\345\255\246\346\210\220\347\273\251\357\274\232", Q_NULLPTR));
        label_9->setText(QApplication::translate("changestu", "\350\213\261\350\257\255\346\210\220\347\273\251\357\274\232", Q_NULLPTR));
        label_18->setText(QApplication::translate("changestu", "\350\257\255\346\226\207\346\210\220\347\273\251\357\274\232", Q_NULLPTR));
        label_7->setText(QApplication::translate("changestu", "\344\270\223\344\270\232\357\274\232", Q_NULLPTR));
        major->clear();
        major->insertItems(0, QStringList()
         << QApplication::translate("changestu", "\350\256\241\347\256\227\346\234\272\347\261\273", Q_NULLPTR)
         << QApplication::translate("changestu", "\346\234\272\346\242\260\347\261\273", Q_NULLPTR)
         << QApplication::translate("changestu", "\350\207\252\345\212\250\345\214\226\347\261\273", Q_NULLPTR)
         << QApplication::translate("changestu", "\347\224\265\345\255\220\344\277\241\346\201\257\347\261\273", Q_NULLPTR)
         << QApplication::translate("changestu", "\347\273\217\346\265\216\345\255\246\347\261\273", Q_NULLPTR)
        );
        label->setText(QApplication::translate("changestu", "\345\255\246\345\217\267\357\274\232", Q_NULLPTR));
        lid->setPlaceholderText(QApplication::translate("changestu", "\350\257\267\350\276\223\345\205\245\345\255\246\345\217\267\357\274\2109\344\275\215\357\274\211", Q_NULLPTR));
        label_2->setText(QApplication::translate("changestu", "\345\247\223\345\220\215\357\274\232", Q_NULLPTR));
        lname->setPlaceholderText(QApplication::translate("changestu", "\350\257\267\350\276\223\345\205\245\345\247\223\345\220\215", Q_NULLPTR));
        label_3->setText(QApplication::translate("changestu", "\346\200\247\345\210\253\357\274\232", Q_NULLPTR));
        male->setText(QApplication::translate("changestu", "\347\224\267", Q_NULLPTR));
        female->setText(QApplication::translate("changestu", "\345\245\263", Q_NULLPTR));
        label_4->setText(QApplication::translate("changestu", "\345\271\264\351\276\204\357\274\232", Q_NULLPTR));
        lage->clear();
        lage->insertItems(0, QStringList()
         << QApplication::translate("changestu", "6", Q_NULLPTR)
         << QApplication::translate("changestu", "7", Q_NULLPTR)
         << QApplication::translate("changestu", "8", Q_NULLPTR)
         << QApplication::translate("changestu", "9", Q_NULLPTR)
         << QApplication::translate("changestu", "10", Q_NULLPTR)
         << QApplication::translate("changestu", "11", Q_NULLPTR)
         << QApplication::translate("changestu", "12", Q_NULLPTR)
         << QApplication::translate("changestu", "13", Q_NULLPTR)
         << QApplication::translate("changestu", "14", Q_NULLPTR)
         << QApplication::translate("changestu", "15", Q_NULLPTR)
         << QApplication::translate("changestu", "16", Q_NULLPTR)
         << QApplication::translate("changestu", "17", Q_NULLPTR)
         << QApplication::translate("changestu", "18", Q_NULLPTR)
         << QApplication::translate("changestu", "19", Q_NULLPTR)
         << QApplication::translate("changestu", "20", Q_NULLPTR)
         << QApplication::translate("changestu", "21", Q_NULLPTR)
         << QApplication::translate("changestu", "22", Q_NULLPTR)
         << QApplication::translate("changestu", "23", Q_NULLPTR)
         << QApplication::translate("changestu", "24", Q_NULLPTR)
        );
        label_5->setText(QApplication::translate("changestu", "\347\217\255\347\272\247\357\274\232", Q_NULLPTR));
        lstuclass->clear();
        lstuclass->insertItems(0, QStringList()
         << QApplication::translate("changestu", "2101", Q_NULLPTR)
         << QApplication::translate("changestu", "2102", Q_NULLPTR)
         << QApplication::translate("changestu", "2103", Q_NULLPTR)
         << QApplication::translate("changestu", "2001", Q_NULLPTR)
         << QApplication::translate("changestu", "2002", Q_NULLPTR)
         << QApplication::translate("changestu", "1901", Q_NULLPTR)
        );
        label_6->setText(QApplication::translate("changestu", "*\346\240\271\346\215\256\345\234\250\350\257\273\347\212\266\345\206\265\345\241\253\345\206\231\346\210\220\347\273\251\357\274\232\357\274\210\346\234\252\345\241\253\345\206\231\345\210\231\351\273\230\350\256\244\344\270\2720\345\210\206\357\274\201\357\274\211", Q_NULLPTR));
        stum->setText(QApplication::translate("changestu", "\344\270\255\345\255\246\347\224\237", Q_NULLPTR));
        btnok->setText(QApplication::translate("changestu", "\347\241\256\350\256\244\344\277\256\346\224\271", Q_NULLPTR));
        btncancel->setText(QApplication::translate("changestu", "\345\217\226\346\266\210", Q_NULLPTR));
        label_21->setText(QApplication::translate("changestu", "\345\216\206\345\217\262\346\210\220\347\273\251\357\274\232", Q_NULLPTR));
        stul->setText(QApplication::translate("changestu", "\345\244\247\345\255\246\347\224\237", Q_NULLPTR));
        label_13->setText(QApplication::translate("changestu", "\347\250\213\345\272\217\346\210\220\347\273\251\357\274\232", Q_NULLPTR));
        stus->setText(QApplication::translate("changestu", "\345\260\217\345\255\246\347\224\237", Q_NULLPTR));
        label_12->setText(QApplication::translate("changestu", "\351\253\230\346\225\260\346\210\220\347\273\251\357\274\232", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class changestu: public Ui_changestu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHANGESTU_H
