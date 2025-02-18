#ifndef CHANGESTU_H
#define CHANGESTU_H

#include <QDialog>
#include<QMessageBox>
#include <QFile>
#include <QTextStream>


namespace Ui {
class changestu;
}

class changestu : public QDialog
{
    Q_OBJECT

public:
    explicit changestu(QWidget *parent = 0);
    ~changestu();
    void changeShow(QString idLine,QStringList stu_line);//弹出窗口并返回对应信息
    void processStu(QString idLine);//处理所得信息
    void writeStu(QString cnt);//修改前->修改后
private slots:
    void on_btncancel_clicked();

    void on_btnok_clicked();


    void on_stus_clicked();

    void on_stum_clicked();

    void on_stul_clicked();

private:
    Ui::changestu *ui;
    QList<QString>stu_lines;//读取列表存为list
    QString idLine;//对应行信息
};

#endif // CHANGESTU_H
