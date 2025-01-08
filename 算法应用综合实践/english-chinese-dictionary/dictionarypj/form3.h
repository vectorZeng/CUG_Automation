#ifndef FORM3_H
#define FORM3_H
#include "trietree.h"
#include <QWidget>
#include "widget.h"
namespace Ui {
class Form3;
}

class Form3 : public QWidget
{
    Q_OBJECT

public:
    explicit Form3(QWidget *parent = nullptr);
    ~Form3();
    void work();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::Form3 *ui;
    TrieTree word[26];
    int sumn;
};

#endif // FORM3_H
