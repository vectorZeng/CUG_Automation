/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout_4;
    QPushButton *ButtonSync;
    QSpacerItem *verticalSpacer;
    QPushButton *Button_Setting;
    QSpacerItem *verticalSpacer_2;
    QFrame *line;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QTreeView *treeView;
    QLabel *label_3;
    QLineEdit *lineEdit;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_2;
    QTreeView *treeViews;
    QLabel *label_4;
    QLineEdit *lineEdits;
    QWidget *page_2;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_3;
    QCheckBox *checkBox;
    QSpacerItem *verticalSpacer_3;
    QCheckBox *checkBox_2;
    QSpacerItem *verticalSpacer_4;
    QCheckBox *checkBox_3;
    QDialogButtonBox *buttonBox;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_5;
    QCheckBox *checkBox_4;
    QSpacerItem *verticalSpacer_5;
    QCheckBox *checkBox_5;
    QFrame *line_2;
    QFrame *line_3;
    QFrame *line_4;
    QFrame *line_5;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout_3;
    QRadioButton *radioButton;
    QLabel *label_5;
    QHBoxLayout *horizontalLayout_2;
    QComboBox *comboBox;
    QRadioButton *radioButton_2;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1001, 727);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayout_4 = new QHBoxLayout(centralWidget);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        ButtonSync = new QPushButton(centralWidget);
        ButtonSync->setObjectName(QStringLiteral("ButtonSync"));

        verticalLayout_4->addWidget(ButtonSync);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer);

        Button_Setting = new QPushButton(centralWidget);
        Button_Setting->setObjectName(QStringLiteral("Button_Setting"));

        verticalLayout_4->addWidget(Button_Setting);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer_2);


        horizontalLayout_4->addLayout(verticalLayout_4);

        line = new QFrame(centralWidget);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        horizontalLayout_4->addWidget(line);

        stackedWidget = new QStackedWidget(centralWidget);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        gridLayout = new QGridLayout(page);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(page);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);

        treeView = new QTreeView(page);
        treeView->setObjectName(QStringLiteral("treeView"));

        verticalLayout->addWidget(treeView);

        label_3 = new QLabel(page);
        label_3->setObjectName(QStringLiteral("label_3"));

        verticalLayout->addWidget(label_3);

        lineEdit = new QLineEdit(page);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        verticalLayout->addWidget(lineEdit);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        label_2 = new QLabel(page);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout_2->addWidget(label_2);

        treeViews = new QTreeView(page);
        treeViews->setObjectName(QStringLiteral("treeViews"));

        verticalLayout_2->addWidget(treeViews);

        label_4 = new QLabel(page);
        label_4->setObjectName(QStringLiteral("label_4"));

        verticalLayout_2->addWidget(label_4);

        lineEdits = new QLineEdit(page);
        lineEdits->setObjectName(QStringLiteral("lineEdits"));

        verticalLayout_2->addWidget(lineEdits);


        horizontalLayout->addLayout(verticalLayout_2);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        layoutWidget = new QWidget(page_2);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(220, 110, 106, 521));
        verticalLayout_3 = new QVBoxLayout(layoutWidget);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        checkBox = new QCheckBox(layoutWidget);
        checkBox->setObjectName(QStringLiteral("checkBox"));

        verticalLayout_3->addWidget(checkBox);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_3);

        checkBox_2 = new QCheckBox(layoutWidget);
        checkBox_2->setObjectName(QStringLiteral("checkBox_2"));

        verticalLayout_3->addWidget(checkBox_2);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_4);

        checkBox_3 = new QCheckBox(layoutWidget);
        checkBox_3->setObjectName(QStringLiteral("checkBox_3"));

        verticalLayout_3->addWidget(checkBox_3);

        buttonBox = new QDialogButtonBox(page_2);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(620, 550, 193, 28));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        layoutWidget1 = new QWidget(page_2);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(20, 110, 93, 181));
        verticalLayout_5 = new QVBoxLayout(layoutWidget1);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        checkBox_4 = new QCheckBox(layoutWidget1);
        checkBox_4->setObjectName(QStringLiteral("checkBox_4"));

        verticalLayout_5->addWidget(checkBox_4);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_5->addItem(verticalSpacer_5);

        checkBox_5 = new QCheckBox(layoutWidget1);
        checkBox_5->setObjectName(QStringLiteral("checkBox_5"));

        verticalLayout_5->addWidget(checkBox_5);

        line_2 = new QFrame(page_2);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setGeometry(QRect(-10, 80, 881, 21));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);
        line_3 = new QFrame(page_2);
        line_3->setObjectName(QStringLiteral("line_3"));
        line_3->setGeometry(QRect(160, 90, 20, 551));
        line_3->setFrameShape(QFrame::VLine);
        line_3->setFrameShadow(QFrame::Sunken);
        line_4 = new QFrame(page_2);
        line_4->setObjectName(QStringLiteral("line_4"));
        line_4->setGeometry(QRect(410, 90, 21, 551));
        line_4->setFrameShape(QFrame::VLine);
        line_4->setFrameShadow(QFrame::Sunken);
        line_5 = new QFrame(page_2);
        line_5->setObjectName(QStringLiteral("line_5"));
        line_5->setGeometry(QRect(-10, 630, 881, 20));
        line_5->setFrameShape(QFrame::HLine);
        line_5->setFrameShadow(QFrame::Sunken);
        layoutWidget2 = new QWidget(page_2);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(480, 120, 341, 27));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget2);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        radioButton = new QRadioButton(layoutWidget2);
        radioButton->setObjectName(QStringLiteral("radioButton"));

        horizontalLayout_3->addWidget(radioButton);

        label_5 = new QLabel(layoutWidget2);
        label_5->setObjectName(QStringLiteral("label_5"));

        horizontalLayout_3->addWidget(label_5);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        comboBox = new QComboBox(layoutWidget2);
        comboBox->setObjectName(QStringLiteral("comboBox"));

        horizontalLayout_2->addWidget(comboBox);


        horizontalLayout_3->addLayout(horizontalLayout_2);

        radioButton_2 = new QRadioButton(page_2);
        radioButton_2->setObjectName(QStringLiteral("radioButton_2"));
        radioButton_2->setGeometry(QRect(480, 180, 115, 19));
        stackedWidget->addWidget(page_2);

        horizontalLayout_4->addWidget(stackedWidget);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1001, 26));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        ButtonSync->setText(QApplication::translate("MainWindow", "\345\220\214\346\255\245", Q_NULLPTR));
        Button_Setting->setText(QApplication::translate("MainWindow", "\350\256\276\347\275\256", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "\345\216\237\345\247\213\346\226\207\344\273\266\345\244\271", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "\346\226\207\344\273\266\350\267\257\345\276\204\357\274\232", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "\347\233\256\347\232\204\346\226\207\344\273\266\345\244\271", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "\346\226\207\344\273\266\350\267\257\345\276\204\357\274\232", Q_NULLPTR));
        checkBox->setText(QApplication::translate("MainWindow", "\345\267\246\344\276\247\344\274\230\345\205\210", Q_NULLPTR));
        checkBox_2->setText(QApplication::translate("MainWindow", "\345\217\263\344\276\247\344\274\230\345\205\210", Q_NULLPTR));
        checkBox_3->setText(QApplication::translate("MainWindow", "\346\226\260\346\226\207\344\273\266\344\274\230\345\205\210", Q_NULLPTR));
        checkBox_4->setText(QApplication::translate("MainWindow", "\345\215\225\345\220\221\345\220\214\346\255\245", Q_NULLPTR));
        checkBox_5->setText(QApplication::translate("MainWindow", "\345\217\214\345\220\221\345\220\214\346\255\245", Q_NULLPTR));
        radioButton->setText(QApplication::translate("MainWindow", "\345\256\232\346\227\266\346\233\264\346\226\260", Q_NULLPTR));
        label_5->setText(QApplication::translate("MainWindow", "\345\256\232\346\227\266\346\233\264\346\226\260\346\227\266\351\227\264", Q_NULLPTR));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "10\345\210\206\351\222\237", Q_NULLPTR)
         << QApplication::translate("MainWindow", "30\345\210\206\351\222\237", Q_NULLPTR)
         << QApplication::translate("MainWindow", "1\345\260\217\346\227\266", Q_NULLPTR)
         << QApplication::translate("MainWindow", "12\345\260\217\346\227\266", Q_NULLPTR)
         << QApplication::translate("MainWindow", "24\345\260\217\346\227\266", Q_NULLPTR)
        );
        radioButton_2->setText(QApplication::translate("MainWindow", "\350\207\252\345\212\250\345\220\214\346\255\245", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
