#ifndef ADDSTU_H
#define ADDSTU_H

#include <QDialog>

namespace Ui {
class addstu;
}

class addstu : public QDialog
{
    Q_OBJECT

public:
    explicit addstu(QWidget *parent = 0);
    ~addstu();
    void clearall();//清空所有窗口
    void writeToFile(QString cnt);//写文件
    int findID(QString id);//查找是否学号重复
    int readFile();//读取文件

private slots:
    void on_btnok_clicked();

    void on_btncancel_clicked();

    void on_stus_clicked();

    void on_stum_clicked();

    void on_stul_clicked();

private:
    Ui::addstu *ui;
    QList<QString>stu_lines;//读取列表存为list
};

#endif // ADDSTU_H
