#ifndef FORM1_H
#define FORM1_H

#include <QWidget>
#include "orderedlist.h"

namespace Ui {
class Form1;
}

class Form1 : public QWidget
{
    Q_OBJECT

public:
    explicit Form1(QWidget *parent = nullptr);
    ~Form1();
    void work();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::Form1 *ui;
    OrderedList word[26];
    int sumn ;
    int currentPage; // 当前页码
    const int wordsPerPage = 10; // 每页显示的单词数量

    void updateLabel(); // 更新 label_3 显示内容
};

#endif // FORM1_H
