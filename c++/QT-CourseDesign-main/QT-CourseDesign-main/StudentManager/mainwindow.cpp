#include "mainwindow.h"
#include "addstu.h"
#include "querystu.h"
#include "sortstu.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()//点击添加
{
    addstu a;
    a.exec();//添加学生窗口
}

void MainWindow::on_pushButton_2_clicked()//点击查询
{
    querystu b;
    b.exec();//添加学生窗口
}

void MainWindow::on_pushButton_3_clicked()
{
    sortstu c;
    c.exec();
}
