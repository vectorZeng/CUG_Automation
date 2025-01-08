#include "show.h"
#include "ui_show.h"
#include "head.h"

Show::Show(nodePtr first, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Show) {
    ui->setupUi(this);
    ui->result->document()->setDefaultTextOption(QTextOption(Qt::AlignHCenter));
    //START UP
    recursion_output(first);
    ui->result->append("END OF THE LINE");
}

int Show::recursion_output(nodePtr node) {
    if (node != NULL) {
        int i = recursion_output(node->hide_pre);

        if (i == 0) {
            QString result_str;
            result_str = QString::number(node->matrix[0][0]) + " " + QString::number(node->matrix[0][1]) + " " + QString::number(node->matrix[0][2]) + "\n";
            result_str += QString::number(node->matrix[1][0]) + " " + QString::number(node->matrix[1][1]) + " " + QString::number(node->matrix[1][2]) + "\n";
            result_str += QString::number(node->matrix[2][0]) + " " + QString::number(node->matrix[2][1]) + " " + QString::number(node->matrix[2][2]) + "\n";
            result_str += "------------";
            ui->result->setText(result_str);
            return findZero(node);
        }
        else {
            QString result_str;
            result_str = QString::number(node->matrix[0][0]) + " " + QString::number(node->matrix[0][1]) + " " + QString::number(node->matrix[0][2]) + "\n";
            result_str += QString::number(node->matrix[1][0]) + " " + QString::number(node->matrix[1][1]) + " " + QString::number(node->matrix[1][2]) + "\n";
            result_str += QString::number(node->matrix[2][0]) + " " + QString::number(node->matrix[2][1]) + " " + QString::number(node->matrix[2][2]) + "\n";
            result_str += "------------";
            ui->result->append(result_str);
            return findZero(node);
        }
    }
    else {
        return 0;
    }
}

//找到0在那个格子
int Show::findZero(nodePtr node) {
    int temp_i = 0, temp_j = 0, result = 0;
    for (temp_i = 0; temp_i < M; ++temp_i) {
        for (temp_j = 0; temp_j < N; ++temp_j) {
            if (node->matrix[temp_i][temp_j] == 0) {
                result = (temp_i+1)*10 + temp_j;
            }
        }
    }
    return result;
}
Show::~Show() {
    delete ui;
}

void Show::on_done_clicked()
{
    this->close();
}
