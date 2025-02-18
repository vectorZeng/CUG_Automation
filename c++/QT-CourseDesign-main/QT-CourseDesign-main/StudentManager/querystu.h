#ifndef QUERYSTU_H
#define QUERYSTU_H

#include <QDialog>
#include <QFile>
#include <QList>
#include<QString>
#include <QStandardItem>
#include <QStandardItemModel>
#include <QTableView>
#include <QTextStream>
#include <QMessageBox>
#include <QDebug>
#include <QStringList>
#include <QModelIndex>

namespace Ui {
class querystu;
}

class querystu : public QDialog
{
    Q_OBJECT

public:
    explicit querystu(QWidget *parent = 0);
    ~querystu();
    void readFile();//读取文件
    void doFind(int what,int index,QString cnt);//查找
    void cleartable(int what);
    void disPlay(int what,int row,QStringList subs);//显示
    int findID(QString id);//查找学号
    void deleteID(QString id);//按照学号删除
    QString getIDLine(QString id);

private slots:
    void on_findbtn_clicked();

    void on_tableView_clicked(const QModelIndex &index);

    void on_btnChange_clicked();

    void on_btnDelete_clicked();

private:
    Ui::querystu *ui;
    QList<QString>stu_lines;//读取列表存为list
    QStandardItemModel *model;
};

#endif // QUERYSTU_H
