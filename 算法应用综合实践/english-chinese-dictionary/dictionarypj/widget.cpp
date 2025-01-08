#include "widget.h"
#include "ui_widget.h"
#include <QProgressDialog>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->setFixedSize(this->width(),this->height());
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_clicked()
{   QProgressDialog *pd=new QProgressDialog("load...","cancel",0,100,this);
    pd->setWindowTitle("loading now");
    pd->setValue(50);
    pd->show();
    Form1 *f1 = new Form1;
    f1->work();
    pd->setValue(100);
    f1->show();
    this->close();
}

void Widget::on_pushButton_2_clicked()
{
    QProgressDialog *pd=new QProgressDialog("load...","cancel",0,100,this);
    pd->setWindowTitle("loading now");
    pd->setValue(50);
    pd->show();
    Form2 *f2 = new Form2;
    f2->work();
    pd->setValue(100);
    f2->show();
    this->close();
}

void Widget::on_pushButton_3_clicked()
{
    QProgressDialog *pd=new QProgressDialog("load...","cancel",0,100,this);
    pd->setWindowTitle("loading now");
    pd->setValue(50);
    pd->show();
    Form3 *f3 = new Form3;
    f3->work();
    pd->setValue(100);
    f3->show();
    this->close();
}
