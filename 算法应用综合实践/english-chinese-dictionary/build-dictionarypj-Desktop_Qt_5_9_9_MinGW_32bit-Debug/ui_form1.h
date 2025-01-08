/********************************************************************************
** Form generated from reading UI file 'form1.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORM1_H
#define UI_FORM1_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form1
{
public:
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_3;
    QGroupBox *groupBox_3;
    QVBoxLayout *verticalLayout_3;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_2;
    QFrame *frame_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_8;
    QFrame *frame;
    QHBoxLayout *horizontalLayout;
    QLabel *label_7;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QFrame *frame_3;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_9;
    QLabel *label_2;
    QLineEdit *lineEdit_4;
    QLabel *label;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_4;
    QFrame *frame_4;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_10;
    QLineEdit *lineEdit_3;
    QPushButton *pushButton_3;
    QLabel *label_5;
    QLabel *label_6;
    QPushButton *pushButton_4;
    QLabel *label_13;
    QPushButton *pushButton_2;
    QPushButton *pushButton;

    void setupUi(QWidget *Form1)
    {
        if (Form1->objectName().isEmpty())
            Form1->setObjectName(QStringLiteral("Form1"));
        Form1->resize(881, 513);
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(12);
        Form1->setFont(font);
        groupBox = new QGroupBox(Form1);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(170, 70, 541, 331));
        horizontalLayout_5 = new QHBoxLayout(groupBox);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(14);
        label_3->setFont(font1);

        horizontalLayout_5->addWidget(label_3);

        groupBox_3 = new QGroupBox(Form1);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(620, 490, 250, 20));
        verticalLayout_3 = new QVBoxLayout(groupBox_3);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        groupBox_2 = new QGroupBox(groupBox_3);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        verticalLayout_2 = new QVBoxLayout(groupBox_2);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        frame_2 = new QFrame(groupBox_2);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        horizontalLayout_2 = new QHBoxLayout(frame_2);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_8 = new QLabel(frame_2);
        label_8->setObjectName(QStringLiteral("label_8"));

        horizontalLayout_2->addWidget(label_8);

        frame = new QFrame(frame_2);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        horizontalLayout = new QHBoxLayout(frame);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_7 = new QLabel(frame);
        label_7->setObjectName(QStringLiteral("label_7"));

        horizontalLayout->addWidget(label_7);

        lineEdit = new QLineEdit(frame);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        horizontalLayout->addWidget(lineEdit);


        horizontalLayout_2->addWidget(frame);

        lineEdit_2 = new QLineEdit(frame_2);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));

        horizontalLayout_2->addWidget(lineEdit_2);


        verticalLayout_2->addWidget(frame_2);

        frame_3 = new QFrame(groupBox_2);
        frame_3->setObjectName(QStringLiteral("frame_3"));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        horizontalLayout_3 = new QHBoxLayout(frame_3);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_9 = new QLabel(frame_3);
        label_9->setObjectName(QStringLiteral("label_9"));

        horizontalLayout_3->addWidget(label_9);

        label_2 = new QLabel(frame_3);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_3->addWidget(label_2);

        lineEdit_4 = new QLineEdit(frame_3);
        lineEdit_4->setObjectName(QStringLiteral("lineEdit_4"));

        horizontalLayout_3->addWidget(lineEdit_4);


        verticalLayout_2->addWidget(frame_3);

        label = new QLabel(groupBox_2);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout_2->addWidget(label);

        label_11 = new QLabel(groupBox_2);
        label_11->setObjectName(QStringLiteral("label_11"));

        verticalLayout_2->addWidget(label_11);

        label_12 = new QLabel(groupBox_2);
        label_12->setObjectName(QStringLiteral("label_12"));

        verticalLayout_2->addWidget(label_12);

        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName(QStringLiteral("label_4"));

        verticalLayout_2->addWidget(label_4);


        verticalLayout_3->addWidget(groupBox_2);

        frame_4 = new QFrame(groupBox_3);
        frame_4->setObjectName(QStringLiteral("frame_4"));
        frame_4->setFrameShape(QFrame::StyledPanel);
        frame_4->setFrameShadow(QFrame::Raised);
        horizontalLayout_4 = new QHBoxLayout(frame_4);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_10 = new QLabel(frame_4);
        label_10->setObjectName(QStringLiteral("label_10"));

        horizontalLayout_4->addWidget(label_10);

        lineEdit_3 = new QLineEdit(frame_4);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));

        horizontalLayout_4->addWidget(lineEdit_3);


        verticalLayout_3->addWidget(frame_4);

        pushButton_3 = new QPushButton(groupBox_3);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));

        verticalLayout_3->addWidget(pushButton_3);

        label_5 = new QLabel(groupBox_3);
        label_5->setObjectName(QStringLiteral("label_5"));

        verticalLayout_3->addWidget(label_5);

        label_6 = new QLabel(groupBox_3);
        label_6->setObjectName(QStringLiteral("label_6"));

        verticalLayout_3->addWidget(label_6);

        pushButton_4 = new QPushButton(Form1);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(790, 470, 84, 24));
        label_13 = new QLabel(Form1);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(360, 10, 161, 41));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font2.setPointSize(19);
        label_13->setFont(font2);
        pushButton_2 = new QPushButton(Form1);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(530, 440, 161, 36));
        pushButton = new QPushButton(Form1);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(200, 440, 141, 36));

        retranslateUi(Form1);

        QMetaObject::connectSlotsByName(Form1);
    } // setupUi

    void retranslateUi(QWidget *Form1)
    {
        Form1->setWindowTitle(QApplication::translate("Form1", "\345\215\225\350\257\215\346\265\217\350\247\210", Q_NULLPTR));
        groupBox->setTitle(QString());
        label_3->setText(QString());
        groupBox_3->setTitle(QString());
        groupBox_2->setTitle(QApplication::translate("Form1", "\346\267\273\345\212\240\345\215\225\350\257\215O(logn + n)", Q_NULLPTR));
        label_8->setText(QApplication::translate("Form1", "\345\215\225\350\257\215", Q_NULLPTR));
        label_7->setText(QApplication::translate("Form1", "\345\215\225\350\257\215", Q_NULLPTR));
        label_9->setText(QApplication::translate("Form1", "\351\207\212\344\271\211", Q_NULLPTR));
        label_2->setText(QApplication::translate("Form1", "\346\261\211\345\255\227\350\247\243\351\207\212", Q_NULLPTR));
        label->setText(QApplication::translate("Form1", "\345\217\215\351\246\210\344\277\241\346\201\257", Q_NULLPTR));
        label_11->setText(QApplication::translate("Form1", "\345\205\261\350\256\241\345\275\225\345\205\245:", Q_NULLPTR));
        label_12->setText(QString());
        label_4->setText(QString());
        label_10->setText(QApplication::translate("Form1", "\345\215\225\350\257\215", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("Form1", "\345\210\240\351\231\244", Q_NULLPTR));
        label_5->setText(QApplication::translate("Form1", "\345\217\215\351\246\210\344\277\241\346\201\257", Q_NULLPTR));
        label_6->setText(QString());
        pushButton_4->setText(QApplication::translate("Form1", "\350\277\224\345\233\236", Q_NULLPTR));
        label_13->setText(QApplication::translate("Form1", "\345\215\225\350\257\215\346\265\217\350\247\210", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("Form1", "\344\270\212\344\270\200\351\241\265", Q_NULLPTR));
        pushButton->setText(QApplication::translate("Form1", "\344\270\213\344\270\200\351\241\265", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Form1: public Ui_Form1 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORM1_H
