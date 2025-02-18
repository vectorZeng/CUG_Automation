#include "querystu.h"
#include "ui_querystu.h"
#include "changestu.h"

querystu::querystu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::querystu)
{
    ui->setupUi(this);
    readFile();
    this->model=new QStandardItemModel;//表格模型
    this->ui->tableView->setModel(model);//
}

querystu::~querystu()
{
    delete model;
    delete ui;
}
void querystu::readFile()//读文件
{
    stu_lines.clear();//清空
    QFile file("stu.txt");
    if(!file.open(QIODevice::ReadOnly|QIODevice::Text))//打开不成功
    {
        QMessageBox::critical(this,"错误","文件打开失败");
        this->close();//关闭窗口
    }
    QTextStream in(&file);

    while(!in.atEnd())//没读到文件尾则继续读
    {
          QString line =in.readLine();//读取一行
          stu_lines.append(line);//每行都存放到list中
    }
    file.close();//关闭
}

void querystu::on_findbtn_clicked()//点击搜索！！！
{
    readFile();//更新
    int what =this->ui->findwhat->currentIndex();//获取就读情况编号
    cleartable(what);
    int index =this->ui->findway->currentIndex();//获取查询方式编号
    QString cnt=this->ui->findkey->text();//获取查询关键字
    doFind(what,index,cnt);
}
void querystu::doFind(int what, int index, QString cnt)//按所选条件查找
{
    int flag=0;
    int row=0;//从第一行开始查找
    for(int i=0;i<stu_lines.length();i++)//遍历容器
    {
        QString line =stu_lines.at(i);//取出信息
        line=line.trimmed();//去掉空字符
        QStringList subs=line.split(" ");//按空格分开
        if(index==1)//按学号查询
        {
            if(cnt==subs.at(1)&&this->ui->findwhat->itemText(what)==subs.at(0))//符合
            {
                disPlay(what,row++,subs);
                flag=1;
            }
        }
        else if(index==2)//按姓名查询
        {
            if(cnt==subs.at(2)&&this->ui->findwhat->itemText(what)==subs.at(0))//符合
            {
                disPlay(what,row++,subs);
                flag=1;
            }
        }
        else if(index==3)//按专业查询
        {
            if(cnt==subs.at(6)&&this->ui->findwhat->itemText(what)==subs.at(0))//符合
            {
                disPlay(what,row++,subs);
                flag=1;
            }
        }
    }
    if(flag==0)//查找失败
    {
        QMessageBox::warning(this,"查找失败","没有找到相关学生信息");
        this->model->clear();//清空信息
    }
}
void querystu::cleartable(int what)//清空并设置表头
{
    this->model->clear();
    this->model->setHorizontalHeaderItem(0,new QStandardItem("就读状况"));
    this->model->setHorizontalHeaderItem(1,new QStandardItem("学号"));
    this->model->setHorizontalHeaderItem(2,new QStandardItem("姓名"));
    this->model->setHorizontalHeaderItem(3,new QStandardItem("性别"));
    this->model->setHorizontalHeaderItem(4,new QStandardItem("年龄"));
    this->model->setHorizontalHeaderItem(5,new QStandardItem("班级"));
    if(what==1)
    {
        this->model->setHorizontalHeaderItem(6,new QStandardItem("英语成绩"));
        this->model->setHorizontalHeaderItem(7,new QStandardItem("数学成绩"));
        this->model->setHorizontalHeaderItem(8,new QStandardItem("语文成绩"));
    }
    else if(what==2)
    {
        this->model->setHorizontalHeaderItem(6,new QStandardItem("英语成绩"));
        this->model->setHorizontalHeaderItem(7,new QStandardItem("数学成绩"));
        this->model->setHorizontalHeaderItem(8,new QStandardItem("语文成绩"));
        this->model->setHorizontalHeaderItem(9,new QStandardItem("地理成绩"));
        this->model->setHorizontalHeaderItem(10,new QStandardItem("历史成绩"));
    }
    else if(what==3)
    {
        this->model->setHorizontalHeaderItem(6,new QStandardItem("专业"));
        this->model->setHorizontalHeaderItem(7,new QStandardItem("英语成绩"));
        this->model->setHorizontalHeaderItem(8,new QStandardItem("程序成绩"));
        this->model->setHorizontalHeaderItem(9,new QStandardItem("高数成绩"));
    }
}

void querystu::disPlay(int what,int row,QStringList subs)//显示信息
{
    for(int i=0;i<subs.length();i++)
    {
        this->model->setItem(row,i,new QStandardItem(subs.at(i)));//传递字符串
    }
}

void querystu::on_tableView_clicked(const QModelIndex &index)//点击tableview获取某行学号
{
     QAbstractItemModel *model = ui->tableView->model();
     int row = ui-> tableView ->currentIndex().row();//获取行
     QModelIndex index1 =model->index(row,1);
     QString id=model->data(index1).toString();//获取学号
     ui->idChange->setText(id);
}

int querystu::findID(QString id)//查找是否有该学号
{
    int row=0;//从第一行开始查找
    for(int i=0;i<stu_lines.length();i++)//遍历容器
    {
        QString line =stu_lines.at(i);//取出信息
        line=line.trimmed();//去掉空字符
        QStringList subs=line.split(" ");//按空格分开
        if(id==subs.at(1))//存在该学号
        {
            return 0;
        }
    }
    return 1;
}
//以下是修改和删除的操作-----------------------------------------------------
void querystu::on_btnChange_clicked()//点击修改
{
    readFile();//更新
    QString id=ui->idChange->text();//获取填写学号
    if(findID(id)==1)//该学号不存在
    {
        QMessageBox::warning(this,"错误","该学生不存在","确定");
        return;
    }
    changestu a;
    a.changeShow(getIDLine(id),stu_lines);//弹出修改窗口并传入对应行信息
    a.exec();
    this->model->clear();//清空表格信息
    ui->idChange->clear();//清空修改学号
}



void querystu::on_btnDelete_clicked()//点击删除
{

    readFile();//更新
    QString id=ui->idChange->text();//获取填写学号
    if(findID(id)==1)//该学号不存在
    {
        QMessageBox::warning(this,"错误","该学生不存在","确定");
        return;
    }
    int ret =QMessageBox::question(this,"警告","确认要删除该学生信息？","确定","取消");
    if(ret==0)//确认删除
    {
        deleteID(id);//删除该信息
    }
    this->model->clear();//清空表格信息
    ui->idChange->clear();//清空修改学号
}
void querystu::deleteID(QString id)//按照学号删除信息
{
    QFile f("stu.txt");
        if (!f.open(QIODevice::WriteOnly | QIODevice::Text))
        {
            QMessageBox::critical(this,"错误","文件打开失败！信息未保存！");
            return;
        }

        for(int i=0;i<stu_lines.size();i++)
        {
            QString temp=stu_lines[i].trimmed();//trimmed()用去去除前后的空格
                                                //以防万一
                                                //如果不用应该也没关系
            if(temp.mid(4,9)==id) continue;//跳过需要删除的学生信息
            QTextStream out(&f);
            out<<stu_lines[i];
            out<<"\n";

        }
        QMessageBox::warning(this,"提示","成功删除该条信息");
        f.close();
}
QString querystu::getIDLine(QString id)//得到学号对应文件信息
{

        for(int i=0;i<stu_lines.size();i++)//遍历list获得信息
        {
            QString temp=stu_lines[i].trimmed();//trimmed()用去去除前后的空格
                                                //以防万一
                                                //如果不用应该也没关系
            if(temp.mid(4,9)==id) return temp;

        }
}
