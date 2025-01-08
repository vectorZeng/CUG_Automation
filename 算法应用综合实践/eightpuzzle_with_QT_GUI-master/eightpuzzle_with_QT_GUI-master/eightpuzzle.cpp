#include "eightpuzzle.h"
#include "ui_eightpuzzle.h"
#include "show.h"
#include <QRegExpValidator>


eightPuzzle::eightPuzzle(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::eightPuzzle)
{
    ui->setupUi(this);
    //正则表达式确保方格中只有0-9
    QRegExp regx("[0-9]$");
    QValidator *validator = new QRegExpValidator(regx);
    ui->init1->setValidator( validator );
    ui->init2->setValidator( validator );
    ui->init3->setValidator( validator );
    ui->init4->setValidator( validator );
    ui->init5->setValidator( validator );
    ui->init6->setValidator( validator );
    ui->init7->setValidator( validator );
    ui->init8->setValidator( validator );
    ui->init9->setValidator( validator );
    ui->final1->setValidator( validator );
    ui->final2->setValidator( validator );
    ui->final3->setValidator( validator );
    ui->final4->setValidator( validator );
    ui->final5->setValidator( validator );
    ui->final6->setValidator( validator );
    ui->final7->setValidator( validator );
    ui->final8->setValidator( validator );
    ui->final9->setValidator( validator );
}

eightPuzzle::~eightPuzzle()
{
    free(first);
    //free链表函数待完成
    free_list(open);
    free_list(close);
    delete ui;
}


void eightPuzzle::on_runButton_clicked()
{
    if(first) {
        free(first);
        first = NULL;
    }
    if(open) {
        free_list(open);
        open = NULL;
    }
    if(close) {
        free_list(close);
        close = NULL;
    }
    open = eightPuzzle::initOpenList();
    close = initCloseList();
    //转换目标状态矩阵
    des_matrix[0][0] = ui->final1->text().toInt();
    des_matrix[0][1] = ui->final2->text().toInt();
    des_matrix[0][2] = ui->final3->text().toInt();
    des_matrix[1][0] = ui->final4->text().toInt();
    des_matrix[1][1] = ui->final5->text().toInt();
    des_matrix[1][2] = ui->final6->text().toInt();
    des_matrix[2][0] = ui->final7->text().toInt();
    des_matrix[2][1] = ui->final8->text().toInt();
    des_matrix[2][2] = ui->final9->text().toInt();

    if(open && close) { //所有条件都具备
        //数据合法
        int vali = check_des(open);
        if(vali == 1) {
            first = solve();
            //START UP
            recursion_output(first);
        }
        else if(vali == 0){
            QMessageBox::critical(this, "无解", "此问题状态下无解~换一组数据试一试吧", QMessageBox::Yes, QMessageBox::Yes);
        }
    }
}

void eightPuzzle::on_pushButton_clicked()
{
    new_about = new about;
    new_about->show();
}

void eightPuzzle::on_pushButton_2_clicked()
{

    Show* my_show = new Show(first);
    my_show->show();
}
