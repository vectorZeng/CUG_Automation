#include "addstu.h"
#include "ui_addstu.h"
#include<QMessageBox>
#include<QPushButton>
#include<QString>
#include<QDebug>
#include<QList>
#include<QAbstractButton>
#include<QFile>
#include<QTextStream>
#include<QIODevice>

addstu::addstu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addstu)
{
    ui->setupUi(this);
    if(readFile()==-1)//打开失败
    {
        QMessageBox::critical(this,"错误","文件打开失败");
        this->close();//关闭窗口
    }
}

addstu::~addstu()
{
    delete ui;
}
//基本点击事件：
void addstu::on_btnok_clicked()//点击确认信息
{
    QString cnt;//最终信息
    QString name=this->ui->lname->text();//获取信息
    QString id=this->ui->lid->text();
    QString sex;
    QString age=this->ui->lage->currentText();
    QString stuclass=this->ui->lstuclass->currentText();
    int checkMark=1;//检查是否填写完成绩
    int flag=1;//初始化为信息无误
    //下面为判断性别
    if(this->ui->male->isChecked())//点击男
    {
        sex="男";
    }
    else if(this->ui->female->isChecked())//点击女
    {
        sex="女";
    }
    //下面为判断学生就读情况
    if(this->ui->stus->isChecked())//点击小学生
    {
        if(ui->stus_Emark->text()==""||ui->stus_Mmark->text()==""||ui->stus_Cmark->text()=="")
            checkMark=0;
        cnt="小学生 "+id+" "+name+" "+sex+" "+age+" "+stuclass+" "+this->ui->stus_Emark->text()
                +" "+this->ui->stus_Mmark->text()+" "+this->ui->stus_Cmark->text()+"\n";
    }
    else if(this->ui->stum->isChecked())//点击中学生
    {
        if(ui->stum_Emark->text()==""||ui->stum_Mmark->text()==""||ui->stum_Cmark->text()==""
                ||ui->stum_Gmark->text()==""||ui->stum_Hmark->text()=="") checkMark=0;
        cnt="中学生 "+id+" "+name+" "+sex+" "+age+" "+stuclass+" "+this->ui->stum_Emark->text()
                +" "+this->ui->stum_Mmark->text()+" "+this->ui->stum_Cmark->text()+" "+
                this->ui->stum_Gmark->text()+" "+this->ui->stum_Hmark->text()+"\n";
    }
    else if(this->ui->stul->isChecked())//点击大学生
    {
        if(ui->stul_Emark->text()==""||ui->stul_Pmark->text()==""||ui->stul_Mmark->text()=="")
            checkMark=0;
        QString major=this->ui->major->currentText();//获取专业
        cnt="大学生 "+id+" "+name+" "+sex+" "+age+" "+stuclass+" "+major+" "+this->ui->stul_Emark->text()
                +" "+this->ui->stul_Pmark->text()+" "+this->ui->stul_Mmark->text()+"\n";
    }
    qDebug("%d",flag);//输出flag
    //判断填写的信息是否合法
    if(name.length()<1||id.length()<9||flag==0||checkMark==0)//信息填写不全
    {
            QMessageBox::warning(this,"错误","信息填写不完整，请重新检查！","确定");
            flag=0;//信息有误
    }
    if(findID(id)==0)//学号重复
    {
        QMessageBox::warning(this,"错误","学号重复！！请重新填写");
        flag=0;//信息有误
    }
    if(flag==1)//信息无误
    {
            if(id=="202112150") QMessageBox::warning(this,"彩蛋","我永远喜欢唐可可！");
            if(name=="海蛋") QMessageBox::warning(this,"彩蛋","我永远喜欢七海娜娜米！\n神仙颜值娜娜米 人间理想娜娜米 温柔体贴娜娜米\n"
                                                          "治愈微笑娜娜米 不可替代娜娜米 深得我心娜娜米\n"
                                                          "星辰皓月娜娜米 金光闪闪娜娜米 一见钟情娜娜米\n"
                                                          "宝藏女孩娜娜米 今生挚爱娜娜米 余生只爱娜娜米\n");
            int ret =QMessageBox::question(this,"请确认信息","请确认是否填写无误？","保存","取消");
            if(ret==0)//确认保存
            {
                writeToFile(cnt);//写文件
                clearall();//清空
            }
    }
}

void addstu::on_btncancel_clicked()//点击取消退出窗口
{
    this->close();
}
void addstu::clearall()//确认信息后清除界面
{
    this->ui->lid->clear();
    this->ui->lname->clear();
    this->ui->lage->setCurrentIndex(0);
    this->ui->lstuclass->setCurrentIndex(0);
    this->ui->male->setCheckable(false);this->ui->male->setCheckable(true);//取消按钮
    this->ui->female->setCheckable(false);this->ui->female->setCheckable(true);//取消按钮
    this->ui->stus->setCheckable(false);this->ui->stus->setCheckable(true);//取消按钮
    this->ui->stum->setCheckable(false);this->ui->stum->setCheckable(true);//取消按钮
    this->ui->stul->setCheckable(false);this->ui->stul->setCheckable(true);//取消按钮
    this->ui->stus_Cmark->clear();this->ui->stus_Emark->clear();this->ui->stus_Mmark->clear();//清空小学生
    this->ui->stum_Cmark->clear();this->ui->stum_Emark->clear();this->ui->stum_Gmark->clear();//清空中学生
    this->ui->stum_Hmark->clear();this->ui->stum_Mmark->clear();
    this->ui->stul_Emark->clear();this->ui->stul_Mmark->clear();this->ui->stul_Pmark->clear();//清空大学生
    this->ui->major->setCurrentIndex(0);//初始化专业
    this->ui->lid->setFocus();//初始化光标位置
}

//其他功能：
void addstu::on_stus_clicked()//点击小学生清空其他学生的成绩并默认成绩为0
{
    this->ui->stus_Cmark->setText("0");this->ui->stus_Emark->setText("0");this->ui->stus_Mmark->setText("0");//默认成绩为0
    this->ui->stum_Cmark->clear();this->ui->stum_Emark->clear();this->ui->stum_Gmark->clear();//清空中学生
    this->ui->stum_Hmark->clear();this->ui->stum_Mmark->clear();
    this->ui->stul_Emark->clear();this->ui->stul_Mmark->clear();this->ui->stul_Pmark->clear();//清空大学生
    this->ui->major->setCurrentIndex(0);//初始化专业
    this->ui->stum->setCheckable(false);this->ui->stum->setCheckable(true);//取消按钮
    this->ui->stul->setCheckable(false);this->ui->stul->setCheckable(true);//取消按钮
    this->ui->stus->setFocus();//初始化光标位置
}

void addstu::on_stum_clicked()//点击中学生清空
{
    this->ui->stum_Cmark->setText("0");this->ui->stum_Emark->setText("0");this->ui->stum_Gmark->setText("0");//默认成绩
    this->ui->stum_Hmark->setText("0");this->ui->stum_Mmark->setText("0");
    this->ui->stus_Cmark->clear();this->ui->stus_Emark->clear();this->ui->stus_Mmark->clear();//清空小学生
    this->ui->stul_Emark->clear();this->ui->stul_Mmark->clear();this->ui->stul_Pmark->clear();
    this->ui->major->setCurrentIndex(0);//初始化专业
    this->ui->stus->setCheckable(false);this->ui->stus->setCheckable(true);//取消按钮
    this->ui->stul->setCheckable(false);this->ui->stul->setCheckable(true);//取消按钮
    this->ui->stum->setFocus();//初始化光标位置
}

void addstu::on_stul_clicked()//点击大学生清空
{
    this->ui->stul_Emark->setText("0");this->ui->stul_Mmark->setText("0");this->ui->stul_Pmark->setText("0");//默认成绩
    this->ui->stus_Cmark->clear();this->ui->stus_Emark->clear();this->ui->stus_Mmark->clear();
    this->ui->stum_Cmark->clear();this->ui->stum_Emark->clear();this->ui->stum_Gmark->clear();
    this->ui->stum_Hmark->clear();this->ui->stum_Mmark->clear();
    this->ui->stus->setCheckable(false);this->ui->stus->setCheckable(true);//取消按钮
    this->ui->stum->setCheckable(false);this->ui->stum->setCheckable(true);//取消按钮
    this->ui->stul->setFocus();//初始化光标位置
}
int addstu::findID(QString id)//查找是否学号重复
{
    int row=0;//从第一行开始查找
    for(int i=0;i<stu_lines.length();i++)//遍历容器
    {
        QString line =stu_lines.at(i);//取出信息
        line=line.trimmed();//去掉空字符
        QStringList subs=line.split(" ");//按空格分开
        if(id==subs.at(1))//学号重复
        {
            return 0;
        }
    }
    return 1;
}
int addstu::readFile()//读文件
{
    QFile file("stu.txt");
    if(!file.open(QIODevice::ReadOnly|QIODevice::Text))//打开不成功
    {
        return -1;
    }
    QTextStream in(&file);

    while(!in.atEnd())//没读到文件尾则继续读
    {
          QString line =in.readLine();//读取一行
          stu_lines.append(line);//每行都存放到list中
    }
    file.close();//关闭
    return 0;//读取成功
}
//读写文件：
void addstu::writeToFile(QString cnt)//保存学生信息
{
    QFile file("stu.txt");
    if(!file.open(QIODevice::Append|QIODevice::Text))
    {
        QMessageBox::warning(this,"错误","文件打开失败，信息未保存","确定");
        return;
    }
    QTextStream out(&file);
    out<<cnt;//写cnt进文件中
    file.close();
}
